/*
 * Copyright (c) 2002-2012, California Institute of Technology.
 * All rights reserved.  Based on Government Sponsored Research under contracts
 * NAS7-1407 and/or NAS7-03001.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *   3. Neither the name of the California Institute of Technology (Caltech),
 * its operating division the Jet Propulsion Laboratory (JPL), the National
 * Aeronautics and Space Administration (NASA), nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE CALIFORNIA INSTITUTE OF TECHNOLOGY BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Copyright 2014-2021 Esri
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *  Functions used by the driver, should have prototypes in the header file
 *
 *  Author: Lucian Plesea
 */

#include "mrfdrivercore.h"
#include "cpl_string.h"

#if defined(LERC)
static bool IsLerc1(const char *s)
{
    static const char L1sig[] = "CntZImage ";
    return !strncmp(s, L1sig, sizeof(L1sig) - 1);
}

static bool IsLerc2(const char *s)
{
    static const char L2sig[] = "Lerc2 ";
    return !strncmp(s, L2sig, sizeof(L2sig) - 1);
}
#endif

/************************************************************************/
/*                     MRFDriverIdentify()                              */
/************************************************************************/

/**
 *\brief Idenfity a MRF file, lightweight
 *
 * Lightweight test, otherwise Open gets called.
 *
 */
int MRFDriverIdentify(GDALOpenInfo *poOpenInfo)

{
    if (STARTS_WITH(poOpenInfo->pszFilename, "<MRF_META>"))
        return TRUE;

    CPLString fn(poOpenInfo->pszFilename);
    if (fn.find(":MRF:") != std::string::npos)
        return TRUE;

    if (poOpenInfo->nHeaderBytes < 10)
        return FALSE;

    const char *pszHeader = reinterpret_cast<char *>(poOpenInfo->pabyHeader);
    fn.assign(pszHeader, pszHeader + poOpenInfo->nHeaderBytes);
    if (STARTS_WITH(fn, "<MRF_META>"))
        return TRUE;

#if defined(LERC)  // Could be single LERC tile
    if (IsLerc1(fn) || IsLerc2(fn))
        return TRUE;
#endif

    // accept a tar file if the first file has no folder look like an MRF
    if (poOpenInfo->eAccess == GA_ReadOnly && fn.size() > 600 &&
        (fn[262] == 0 || fn[262] == 32) && STARTS_WITH(fn + 257, "ustar") &&
        strlen(CPLGetPathSafe(fn).c_str()) == 0 &&
        STARTS_WITH(fn + 512, "<MRF_META>"))
    {
        return TRUE;
    }

    return FALSE;
}

/************************************************************************/
/*                      MRFDriverSetCommonMetadata()                    */
/************************************************************************/

void MRFDriverSetCommonMetadata(GDALDriver *poDriver)
{
    poDriver->SetDescription(DRIVER_NAME);
    poDriver->SetMetadataItem(GDAL_DMD_LONGNAME, "Meta Raster Format");
    poDriver->SetMetadataItem(GDAL_DMD_HELPTOPIC, "drivers/raster/marfa.html");
    poDriver->SetMetadataItem(GDAL_DMD_EXTENSION, "mrf");
    poDriver->SetMetadataItem(GDAL_DCAP_VIRTUALIO, "YES");
    poDriver->SetMetadataItem(GDAL_DCAP_RASTER, "YES");

    poDriver->SetMetadataItem(
        GDAL_DMD_OPENOPTIONLIST,
        "<OpenOptionList>"
        "    <Option name='NOERRORS' type='boolean' description='Ignore "
        "decompression errors' default='FALSE'/>"
        "    <Option name='ZSLICE' type='int' description='For a third "
        "dimension MRF, pick a slice' default='0'/>"
        "</OpenOptionList>");

    // These will need to be revisited, do we support complex data types too?
    poDriver->SetMetadataItem(
        GDAL_DMD_CREATIONDATATYPES,
        "Byte Int8 Int16 UInt16 Int32 UInt32 Int64 UInt64 Float32 Float64");

    poDriver->pfnIdentify = MRFDriverIdentify;
    poDriver->SetMetadataItem(GDAL_DCAP_OPEN, "YES");
    poDriver->SetMetadataItem(GDAL_DCAP_CREATE, "YES");
    poDriver->SetMetadataItem(GDAL_DCAP_CREATECOPY, "YES");
}

/************************************************************************/
/*                     DeclareDeferredMRFPlugin()                       */
/************************************************************************/

#ifdef PLUGIN_FILENAME
void DeclareDeferredMRFPlugin()
{
    if (GDALGetDriverByName(DRIVER_NAME) != nullptr)
    {
        return;
    }
    auto poDriver = new GDALPluginDriverProxy(PLUGIN_FILENAME);
#ifdef PLUGIN_INSTALLATION_MESSAGE
    poDriver->SetMetadataItem(GDAL_DMD_PLUGIN_INSTALLATION_MESSAGE,
                              PLUGIN_INSTALLATION_MESSAGE);
#endif
    MRFDriverSetCommonMetadata(poDriver);
    GetGDALDriverManager()->DeclareDeferredPluginDriver(poDriver);
}
#endif
