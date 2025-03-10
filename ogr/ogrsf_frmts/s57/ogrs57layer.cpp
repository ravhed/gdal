/******************************************************************************
 *
 * Project:  S-57 Translator
 * Purpose:  Implements OGRS57Layer class.
 * Author:   Frank Warmerdam, warmerdam@pobox.com
 *
 ******************************************************************************
 * Copyright (c) 1999, Frank Warmerdam
 * Copyright (c) 2009-2014, Even Rouault <even dot rouault at spatialys.com>
 *
 * SPDX-License-Identifier: MIT
 ****************************************************************************/

#include "cpl_conv.h"
#include "cpl_string.h"
#include "ogr_s57.h"

/************************************************************************/
/*                            OGRS57Layer()                             */
/*                                                                      */
/*      Note that the OGRS57Layer assumes ownership of the passed       */
/*      OGRFeatureDefn object.                                          */
/************************************************************************/

OGRS57Layer::OGRS57Layer(OGRS57DataSource *poDSIn, OGRFeatureDefn *poDefnIn,
                         int nFeatureCountIn, int nOBJLIn)
    : poDS(poDSIn), poFeatureDefn(poDefnIn), nCurrentModule(-1),
      nRCNM(100),  // Default to feature.
      nOBJL(nOBJLIn), nNextFEIndex(0), nFeatureCount(nFeatureCountIn)
{
    SetDescription(poFeatureDefn->GetName());
    if (poFeatureDefn->GetGeomFieldCount() > 0)
        poFeatureDefn->GetGeomFieldDefn(0)->SetSpatialRef(
            poDS->DSGetSpatialRef());

    if (EQUAL(poDefnIn->GetName(), OGRN_VI))
        nRCNM = RCNM_VI;
    else if (EQUAL(poDefnIn->GetName(), OGRN_VC))
        nRCNM = RCNM_VC;
    else if (EQUAL(poDefnIn->GetName(), OGRN_VE))
        nRCNM = RCNM_VE;
    else if (EQUAL(poDefnIn->GetName(), OGRN_VF))
        nRCNM = RCNM_VF;
    else if (EQUAL(poDefnIn->GetName(), "DSID"))
        nRCNM = RCNM_DSID;
    // Leave as feature.
}

/************************************************************************/
/*                           ~OGRS57Layer()                           */
/************************************************************************/

OGRS57Layer::~OGRS57Layer()

{
    if (m_nFeaturesRead > 0)
    {
        CPLDebug("S57", "%d features read on layer '%s'.",
                 static_cast<int>(m_nFeaturesRead), poFeatureDefn->GetName());
    }

    poFeatureDefn->Release();
}

/************************************************************************/
/*                            ResetReading()                            */
/************************************************************************/

void OGRS57Layer::ResetReading()

{
    nNextFEIndex = 0;
    nCurrentModule = -1;
}

/************************************************************************/
/*                      GetNextUnfilteredFeature()                      */
/************************************************************************/

OGRFeature *OGRS57Layer::GetNextUnfilteredFeature()

{
    /* -------------------------------------------------------------------- */
    /*      Are we out of modules to request features from?                 */
    /* -------------------------------------------------------------------- */
    if (nCurrentModule >= poDS->GetModuleCount())
        return nullptr;

    /* -------------------------------------------------------------------- */
    /*      Set the current position on the current module and fetch a      */
    /*      feature.                                                        */
    /* -------------------------------------------------------------------- */
    S57Reader *poReader = poDS->GetModule(nCurrentModule);
    OGRFeature *poFeature = nullptr;

    if (poReader != nullptr)
    {
        poReader->SetNextFEIndex(nNextFEIndex, nRCNM);
        poFeature = poReader->ReadNextFeature(poFeatureDefn);
        nNextFEIndex = poReader->GetNextFEIndex(nRCNM);
    }

    /* -------------------------------------------------------------------- */
    /*      If we didn't get a feature we need to move onto the next file.  */
    /* -------------------------------------------------------------------- */
    if (poFeature == nullptr)
    {
        nCurrentModule++;
        poReader = poDS->GetModule(nCurrentModule);

        if (poReader != nullptr && poReader->GetModule() == nullptr)
        {
            if (!poReader->Open(FALSE))
                return nullptr;
        }

        return GetNextUnfilteredFeature();
    }
    else
    {
        m_nFeaturesRead++;
        if (poFeature->GetGeometryRef() != nullptr)
            poFeature->GetGeometryRef()->assignSpatialReference(
                GetSpatialRef());
    }

    return poFeature;
}

/************************************************************************/
/*                           GetNextFeature()                           */
/************************************************************************/

OGRFeature *OGRS57Layer::GetNextFeature()

{
    OGRFeature *poFeature = nullptr;

    /* -------------------------------------------------------------------- */
    /*      Read features till we find one that satisfies our current       */
    /*      spatial criteria.                                               */
    /* -------------------------------------------------------------------- */
    while (true)
    {
        poFeature = GetNextUnfilteredFeature();
        if (poFeature == nullptr)
            break;

        if ((m_poFilterGeom == nullptr ||
             FilterGeometry(poFeature->GetGeometryRef())) &&
            (m_poAttrQuery == nullptr || m_poAttrQuery->Evaluate(poFeature)))
            break;

        delete poFeature;
    }

    return poFeature;
}

/************************************************************************/
/*                           TestCapability()                           */
/************************************************************************/

int OGRS57Layer::TestCapability(const char *pszCap)

{
    if (EQUAL(pszCap, OLCRandomRead))
        return false;

    if (EQUAL(pszCap, OLCSequentialWrite))
        return true;

    if (EQUAL(pszCap, OLCRandomWrite))
        return false;

    if (EQUAL(pszCap, OLCFastFeatureCount))
        return !(
            m_poFilterGeom != nullptr || m_poAttrQuery != nullptr ||
            nFeatureCount == -1 ||
            (EQUAL(poFeatureDefn->GetName(), "SOUNDG") &&
             poDS->GetModule(0) != nullptr &&
             (poDS->GetModule(0)->GetOptionFlags() & S57M_SPLIT_MULTIPOINT)));

    if (EQUAL(pszCap, OLCFastGetExtent))
    {
        OGREnvelope oEnvelope;

        return GetExtent(&oEnvelope, FALSE) == OGRERR_NONE;
    }

    if (EQUAL(pszCap, OLCFastSpatialFilter))
        return false;

    if (EQUAL(pszCap, OLCStringsAsUTF8))
    {
        return poDS->GetModule(0) != nullptr &&
               (poDS->GetModule(0)->GetOptionFlags() & S57M_RECODE_BY_DSSI);
    }

    if (EQUAL(pszCap, OLCZGeometries))
        return true;

    return false;
}

/************************************************************************/
/*                            IGetExtent()                              */
/************************************************************************/

OGRErr OGRS57Layer::IGetExtent(int /*iGeomField*/, OGREnvelope *psExtent,
                               bool bForce)

{
    if (GetGeomType() == wkbNone)
        return OGRERR_FAILURE;

    return poDS->GetDSExtent(psExtent, bForce);
}

/************************************************************************/
/*                          GetFeatureCount()                           */
/************************************************************************/
GIntBig OGRS57Layer::GetFeatureCount(int bForce)
{

    if (!TestCapability(OLCFastFeatureCount))
        return OGRLayer::GetFeatureCount(bForce);

    return nFeatureCount;
}

/************************************************************************/
/*                             GetFeature()                             */
/************************************************************************/

OGRFeature *OGRS57Layer::GetFeature(GIntBig nFeatureId)

{
    S57Reader *poReader = poDS->GetModule(0);  // not multi-reader aware

    if (poReader != nullptr && nFeatureId <= INT_MAX)
    {
        OGRFeature *poFeature =
            poReader->ReadFeature(static_cast<int>(nFeatureId), poFeatureDefn);

        if (poFeature != nullptr && poFeature->GetGeometryRef() != nullptr)
            poFeature->GetGeometryRef()->assignSpatialReference(
                GetSpatialRef());
        return poFeature;
    }

    return nullptr;
}

/************************************************************************/
/*                           ICreateFeature()                            */
/************************************************************************/

OGRErr OGRS57Layer::ICreateFeature(OGRFeature *poFeature)

{
    /* -------------------------------------------------------------------- */
    /*      Set RCNM if not already set.                                    */
    /* -------------------------------------------------------------------- */
    const int iRCNMFld = poFeature->GetFieldIndex("RCNM");

    if (iRCNMFld != -1)
    {
        if (!poFeature->IsFieldSetAndNotNull(iRCNMFld))
            poFeature->SetField(iRCNMFld, nRCNM);
        else
        {
            CPLAssert(poFeature->GetFieldAsInteger(iRCNMFld) == nRCNM);
        }
    }

    /* -------------------------------------------------------------------- */
    /*      Set OBJL if not already set.                                    */
    /* -------------------------------------------------------------------- */
    if (nOBJL != -1)
    {
        const int iOBJLFld = poFeature->GetFieldIndex("OBJL");

        if (!poFeature->IsFieldSetAndNotNull(iOBJLFld))
            poFeature->SetField(iOBJLFld, nOBJL);
        else
        {
            CPLAssert(poFeature->GetFieldAsInteger(iOBJLFld) == nOBJL);
        }
    }

    /* -------------------------------------------------------------------- */
    /*      Create the isolated node feature.                               */
    /* -------------------------------------------------------------------- */
    if (poDS->GetWriter()->WriteCompleteFeature(poFeature))
        return OGRERR_NONE;

    return OGRERR_FAILURE;
}
