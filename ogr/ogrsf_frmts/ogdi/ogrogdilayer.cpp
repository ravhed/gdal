/******************************************************************************
 *
 * Project:  OGDI Bridge
 * Purpose:  Implements OGROGDILayer class.
 * Author:   Daniel Morissette, danmo@videotron.ca
 *           (Based on some code contributed by Frank Warmerdam :)
 *
 ******************************************************************************
 * Copyright (c) 2000, Daniel Morissette
 * Copyright (c) 2008-2013, Even Rouault <even dot rouault at spatialys.com>
 *
 * SPDX-License-Identifier: MIT
 ******************************************************************************
 */

#include "ogrogdi.h"
#include "cpl_conv.h"
#include "cpl_string.h"

/************************************************************************/
/*                           OGROGDILayer()                            */
/************************************************************************/

OGROGDILayer::OGROGDILayer(OGROGDIDataSource *poODS, const char *pszName,
                           ecs_Family eFamily)
    : m_poODS(poODS), m_nClientID(poODS->GetClientID()),
      m_pszOGDILayerName(CPLStrdup(pszName)), m_eFamily(eFamily),
      m_poFeatureDefn(nullptr),
      // Keep a reference on the SpatialRef (owned by the dataset).
      m_poSpatialRef(m_poODS->DSGetSpatialRef()),
      m_sFilterBounds(*(m_poODS->GetGlobalBounds())), m_iNextShapeId(0),
      m_nTotalShapeCount(-1), m_nFilteredOutShapes(0)
{

    // Select layer and feature family.
    OGROGDILayer::ResetReading();

    BuildFeatureDefn();
}

/************************************************************************/
/*                           ~OGROGDILayer()                           */
/************************************************************************/

OGROGDILayer::~OGROGDILayer()

{
    if (m_nFeaturesRead > 0 && m_poFeatureDefn != nullptr)
    {
        CPLDebug("OGDI", "%d features read on layer '%s'.",
                 (int)m_nFeaturesRead, m_poFeatureDefn->GetName());
    }

    if (m_poFeatureDefn)
        m_poFeatureDefn->Release();

    CPLFree(m_pszOGDILayerName);

    // Note: we do not delete m_poSpatialRef since it is owned by the dataset
}

/************************************************************************/
/*                          ISetSpatialFilter()                         */
/************************************************************************/

OGRErr OGROGDILayer::ISetSpatialFilter(int, const OGRGeometry *poGeomIn)

{
    if (InstallFilter(poGeomIn))
    {
        ResetReading();
        m_nTotalShapeCount = -1;
    }
    return OGRERR_NONE;
}

/************************************************************************/
/*                         SetAttributeFilter()                         */
/************************************************************************/

OGRErr OGROGDILayer::SetAttributeFilter(const char *pszQuery)
{
    OGRErr eErr = OGRLayer::SetAttributeFilter(pszQuery);

    ResetReading();

    m_nTotalShapeCount = -1;

    return eErr;
}

/************************************************************************/
/*                            ResetReading()                            */
/************************************************************************/

void OGROGDILayer::ResetReading()

{
    ecs_LayerSelection sSelectionLayer;

    sSelectionLayer.Select = m_pszOGDILayerName;
    sSelectionLayer.F = m_eFamily;

    ecs_Result *psResult = cln_SelectLayer(m_nClientID, &sSelectionLayer);
    if (ECSERROR(psResult))
    {
        CPLError(CE_Failure, CPLE_AppDefined,
                 "Access to layer '%s' Failed: %s\n", m_pszOGDILayerName,
                 psResult->message ? psResult->message : "(no message string)");
        return;
    }

    /* Reset spatial filter */
    if (m_poFilterGeom != nullptr)
    {
        OGREnvelope oEnv;

        m_poFilterGeom->getEnvelope(&oEnv);

        m_sFilterBounds.north = oEnv.MaxY;
        m_sFilterBounds.south = oEnv.MinY;
        m_sFilterBounds.west = oEnv.MinX;
        m_sFilterBounds.east = oEnv.MaxX;

        psResult = cln_SelectRegion(m_nClientID, &m_sFilterBounds);
        if (ECSERROR(psResult))
        {
            CPLError(CE_Failure, CPLE_AppDefined, "SelectRegion failed: %s",
                     psResult->message ? psResult->message
                                       : "(no message string)");
            return;
        }
    }
    else
    {
        /* Reset to global bounds */
        psResult = cln_SelectRegion(m_nClientID, m_poODS->GetGlobalBounds());
        if (ECSERROR(psResult))
        {
            CPLError(CE_Failure, CPLE_AppDefined, "SelectRegion failed: %s",
                     psResult->message ? psResult->message
                                       : "(no message string)");
            return;
        }
    }

    m_iNextShapeId = 0;
    m_nFilteredOutShapes = 0;
}

/************************************************************************/
/*                           GetNextFeature()                           */
/************************************************************************/

OGRFeature *OGROGDILayer::GetNextFeature()

{

    /* Reset reading if we are not the current layer */
    /* WARNING : this does not allow interleaved reading of layers */
    if (m_poODS->GetCurrentLayer() != this)
    {
        m_poODS->SetCurrentLayer(this);
        ResetReading();
    }

    while (true)
    {
        OGRFeature *poFeature = GetNextRawFeature();
        if (poFeature == nullptr)
            return nullptr;

        /* --------------------------------------------------------------------
         */
        /*      Do we need to apply an attribute test? */
        /* --------------------------------------------------------------------
         */
        if ((m_poAttrQuery != nullptr && !m_poAttrQuery->Evaluate(poFeature)) ||
            (m_poFilterGeom != nullptr &&
             !FilterGeometry(poFeature->GetGeometryRef())))
        {
            m_nFilteredOutShapes++;
            delete poFeature;
        }
        else
            return poFeature;
    }
}

/************************************************************************/
/*                           GetNextFeature()                           */
/************************************************************************/

OGRFeature *OGROGDILayer::GetNextRawFeature()
{
    /* -------------------------------------------------------------------- */
    /*      Retrieve object from OGDI server and create new feature         */
    /* -------------------------------------------------------------------- */
    ecs_Result *psResult = cln_GetNextObject(m_nClientID);
    if (!ECSSUCCESS(psResult))
    {
        if (ECSERROR(psResult) &&
            (psResult->message == nullptr ||
             strstr(psResult->message, "End of selection") == nullptr))
        {
            CPLError(CE_Failure, CPLE_AppDefined,
                     "Access to next object of layer '%s' failed: %s\n",
                     m_pszOGDILayerName,
                     psResult->message ? psResult->message
                                       : "(no error string)");
        }
        // We probably reached EOF... keep track of shape count.
        m_nTotalShapeCount = m_iNextShapeId - m_nFilteredOutShapes;
        return nullptr;
    }

    OGRFeature *poFeature = new OGRFeature(m_poFeatureDefn);

    poFeature->SetFID(m_iNextShapeId++);
    m_nFeaturesRead++;

    /* -------------------------------------------------------------------- */
    /*      Process geometry                                                */
    /* -------------------------------------------------------------------- */
    if (m_eFamily == Point)
    {
        ecs_Point *psPoint = &(ECSGEOM(psResult).point);
        OGRPoint *poOGRPoint = new OGRPoint(psPoint->c.x, psPoint->c.y);

        poOGRPoint->assignSpatialReference(m_poSpatialRef);
        poFeature->SetGeometryDirectly(poOGRPoint);
    }
    else if (m_eFamily == Line)
    {
        ecs_Line *psLine = &(ECSGEOM(psResult).line);
        OGRLineString *poOGRLine = new OGRLineString();

        poOGRLine->setNumPoints(psLine->c.c_len);

        for (int i = 0; i < (int)psLine->c.c_len; i++)
        {
            poOGRLine->setPoint(i, psLine->c.c_val[i].x, psLine->c.c_val[i].y);
        }

        poOGRLine->assignSpatialReference(m_poSpatialRef);
        poFeature->SetGeometryDirectly(poOGRLine);
    }
    else if (m_eFamily == Area)
    {
        ecs_Area *psArea = &(ECSGEOM(psResult).area);
        OGRPolygon *poOGRPolygon = new OGRPolygon();

        for (int iRing = 0; iRing < (int)psArea->ring.ring_len; iRing++)
        {
            ecs_FeatureRing *psRing = &(psArea->ring.ring_val[iRing]);
            OGRLinearRing *poOGRRing = new OGRLinearRing();

            poOGRRing->setNumPoints(psRing->c.c_len);

            for (int i = 0; i < (int)psRing->c.c_len; i++)
            {
                poOGRRing->setPoint(i, psRing->c.c_val[i].x,
                                    psRing->c.c_val[i].y);
            }
            poOGRPolygon->addRingDirectly(poOGRRing);
        }

        // __TODO__
        // When OGR supports polygon centroids then we should carry them here

        poOGRPolygon->assignSpatialReference(m_poSpatialRef);
        poFeature->SetGeometryDirectly(poOGRPolygon);
    }
    else if (m_eFamily == Text)
    {
        // __TODO__
        // For now text is treated as a point and string is lost
        //
        ecs_Text *psText = &(ECSGEOM(psResult).text);
        OGRPoint *poOGRPoint = new OGRPoint(psText->c.x, psText->c.y);

        poOGRPoint->assignSpatialReference(m_poSpatialRef);
        poFeature->SetGeometryDirectly(poOGRPoint);
    }
    else
    {
        CPLAssert(false);
    }

    /* -------------------------------------------------------------------- */
    /*      Set attributes                                                  */
    /* -------------------------------------------------------------------- */
    char *pszAttrList = ECSOBJECTATTR(psResult);

    for (int iField = 0; iField < m_poFeatureDefn->GetFieldCount(); iField++)
    {
        char *pszFieldStart = nullptr;
        int nNameLen = 0;

        /* parse out the next attribute value */
        if (!ecs_FindElement(pszAttrList, &pszFieldStart, &pszAttrList,
                             &nNameLen, nullptr))
        {
            nNameLen = 0;
            pszFieldStart = pszAttrList;
        }

        /* Skip any trailing white space (for string constants). */

        if (nNameLen > 0 && pszFieldStart[nNameLen - 1] == ' ')
            nNameLen--;

        /* skip leading white space */
        while (pszFieldStart[0] == ' ' && nNameLen > 0)
        {
            pszFieldStart++;
            nNameLen--;
        }

        /* zero terminate the single field value, but save the          */
        /* character we overwrote, so we can restore it when done.      */

        char chSavedChar = pszFieldStart[nNameLen];
        pszFieldStart[nNameLen] = '\0';

        /* OGR takes care of all field type conversions for us! */

        poFeature->SetField(iField, pszFieldStart);

        pszFieldStart[nNameLen] = chSavedChar;
    }

    /* -------------------------------------------------------------------- */
    /*      Apply the text associated with text features if appropriate.    */
    /* -------------------------------------------------------------------- */
    if (m_eFamily == Text)
    {
        poFeature->SetField("text", ECSGEOM(psResult).text.desc);
    }

    return poFeature;
}

/************************************************************************/
/*                             GetFeature()                             */
/************************************************************************/

OGRFeature *OGROGDILayer::GetFeature(GIntBig nFeatureId)

{

    if (m_nTotalShapeCount != -1 && nFeatureId > m_nTotalShapeCount)
        return nullptr;

    /* Unset spatial filter */
    OGRGeometry *poOldFilterGeom =
        (m_poFilterGeom != nullptr) ? m_poFilterGeom->clone() : nullptr;
    if (poOldFilterGeom != nullptr)
        SetSpatialFilter(nullptr);

    /* Reset reading if we are not the current layer */
    /* WARNING : this does not allow interleaved reading of layers */
    if (m_poODS->GetCurrentLayer() != this)
    {
        m_poODS->SetCurrentLayer(this);
        ResetReading();
    }
    else if (nFeatureId < m_iNextShapeId)
        ResetReading();

    while (m_iNextShapeId != nFeatureId)
    {
        ecs_Result *psResult = cln_GetNextObject(m_nClientID);
        if (ECSSUCCESS(psResult))
            m_iNextShapeId++;
        else
        {
            // We probably reached EOF... keep track of shape count.
            m_nTotalShapeCount = m_iNextShapeId;
            if (poOldFilterGeom != nullptr)
            {
                SetSpatialFilter(poOldFilterGeom);
                delete poOldFilterGeom;
            }
            return nullptr;
        }
    }

    // OK, we're ready to read the requested feature...
    OGRFeature *poFeature = GetNextRawFeature();
    if (poOldFilterGeom != nullptr)
    {
        SetSpatialFilter(poOldFilterGeom);
        delete poOldFilterGeom;
    }
    return poFeature;
}

/************************************************************************/
/*                          GetFeatureCount()                           */
/*                                                                      */
/*      If a spatial filter is in effect, we turn control over to       */
/*      the generic counter.  Otherwise we return the total count.      */
/*      Eventually we should consider implementing a more efficient     */
/*      way of counting features matching a spatial query.              */
/************************************************************************/

GIntBig OGROGDILayer::GetFeatureCount(int bForce)

{
    if (m_nTotalShapeCount == -1)
    {
        m_nTotalShapeCount =
            static_cast<int>(OGRLayer::GetFeatureCount(bForce));
    }

    return m_nTotalShapeCount;
}

/************************************************************************/
/*                           TestCapability()                           */
/************************************************************************/

int OGROGDILayer::TestCapability(const char *pszCap)

{
/* -------------------------------------------------------------------- */
/*      Hummm... what are the proper capabilities...                    */
/*      Does OGDI have any idea of capabilities???                      */
/*      For now just return FALSE for everything.                       */
/* -------------------------------------------------------------------- */
#ifdef __TODO__
    if (EQUAL(pszCap, OLCFastFeatureCount))
        return m_poFilterGeom == NULL && m_poAttrQuery == NULL;

    else if (EQUAL(pszCap, OLCFastSpatialFilter))
        return FALSE;

    else
        return FALSE;
#endif

    if (EQUAL(pszCap, OLCRandomRead))
        return TRUE;

    else
        return FALSE;
}

/************************************************************************/
/*                          BuildFeatureDefn()                          */
/*                                                                      */
/*      (private) Initializes the schema in m_poFeatureDefn             */
/************************************************************************/

void OGROGDILayer::BuildFeatureDefn()
{
    const char *pszGeomName = nullptr;
    OGRwkbGeometryType eLayerGeomType = wkbUnknown;

    /* -------------------------------------------------------------------- */
    /*      Feature Defn name will be "<OGDILyrName>_<FeatureFamily>"       */
    /* -------------------------------------------------------------------- */

    switch (m_eFamily)
    {
        case Point:
            pszGeomName = "point";
            eLayerGeomType = wkbPoint;
            break;
        case Line:
            pszGeomName = "line";
            eLayerGeomType = wkbLineString;
            break;
        case Area:
            pszGeomName = "area";
            eLayerGeomType = wkbPolygon;
            break;
        case Text:
            pszGeomName = "text";
            eLayerGeomType = wkbPoint;
            break;
        default:
            pszGeomName = "unknown";
            eLayerGeomType = wkbUnknown;
            break;
    }

    char *pszFeatureDefnName = nullptr;
    if (m_poODS->LaunderLayerNames())
    {
        pszFeatureDefnName = CPLStrdup(m_pszOGDILayerName);
        char *pszAt = strchr(pszFeatureDefnName, '@');
        if (pszAt)
            *pszAt = '_';
        char *pszLeftParenthesis = strchr(pszFeatureDefnName, '(');
        if (pszLeftParenthesis)
            *pszLeftParenthesis = '\0';
    }
    else
        pszFeatureDefnName =
            CPLStrdup(CPLSPrintf("%s_%s", m_pszOGDILayerName, pszGeomName));

    m_poFeatureDefn = new OGRFeatureDefn(pszFeatureDefnName);
    SetDescription(m_poFeatureDefn->GetName());
    CPLFree(pszFeatureDefnName);
    pszFeatureDefnName = nullptr;

    m_poFeatureDefn->SetGeomType(eLayerGeomType);
    m_poFeatureDefn->Reference();
    m_poFeatureDefn->GetGeomFieldDefn(0)->SetSpatialRef(m_poSpatialRef);

    /* -------------------------------------------------------------------- */
    /*      Fetch schema from OGDI server and map to OGR types              */
    /* -------------------------------------------------------------------- */
    ecs_Result *psResult = cln_GetAttributesFormat(m_nClientID);
    if (ECSERROR(psResult))
    {
        CPLError(CE_Failure, CPLE_AppDefined, "ECSERROR: %s\n",
                 psResult->message ? psResult->message : "(no message string)");
        return;
    }

    ecs_ObjAttributeFormat *oaf = &(ECSRESULT(psResult).oaf);
    const int numFields = oaf->oa.oa_len;
    for (int i = 0; i < numFields; i++)
    {
        OGRFieldDefn oField("", OFTInteger);

        oField.SetName(oaf->oa.oa_val[i].name);
        oField.SetPrecision(0);

        switch (oaf->oa.oa_val[i].type)
        {
            case Decimal:
            case Smallint:
            case Integer:
                oField.SetType(OFTInteger);
                // TODO: Fix spelling - lenght -> length
                if (oaf->oa.oa_val[i].lenght > 0)
                    oField.SetWidth(oaf->oa.oa_val[i].lenght);
                else
                    oField.SetWidth(11);
                break;

            case Numeric:
            case Real:
            case Float:
            case Double:
                oField.SetType(OFTReal);
                if (oaf->oa.oa_val[i].lenght > 0)
                {
                    oField.SetWidth(oaf->oa.oa_val[i].lenght);
                    oField.SetPrecision(oaf->oa.oa_val[i].precision);
                }
                else
                {
                    oField.SetWidth(18);
                    oField.SetPrecision(7);
                }
                break;

            case Char:
            case Varchar:
            case Longvarchar:
            default:
                oField.SetType(OFTString);
                if (oaf->oa.oa_val[i].lenght > 0)
                    oField.SetWidth(oaf->oa.oa_val[i].lenght);
                else
                    oField.SetWidth(64);
                break;
        }

        m_poFeatureDefn->AddFieldDefn(&oField);
    }

    /* -------------------------------------------------------------------- */
    /*      Add a text attribute for text objects.                          */
    /* -------------------------------------------------------------------- */
    if (m_eFamily == Text)
    {
        OGRFieldDefn oField("text", OFTString);

        m_poFeatureDefn->AddFieldDefn(&oField);
    }
}
