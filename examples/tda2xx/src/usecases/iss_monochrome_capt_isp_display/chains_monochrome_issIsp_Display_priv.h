/*
*******************************************************************************
*
* Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
* ALL RIGHTS RESERVED
*
*******************************************************************************
*/

/*
*******************************************************************************
*
* IMPORTANT NOTE:
*  This file is AUTO-GENERATED by Vision SDK use case generation tool
*
*******************************************************************************
*/

#ifndef _chains_monochrome_issIsp_Display_H_
#define _chains_monochrome_issIsp_Display_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/issM2mIspLink.h>
#include <include/link_api/algorithmLink_issAewb.h>
#include <include/link_api/issM2mSimcopLink.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

typedef struct {
       UInt32    CaptureLinkID;
       UInt32    IssM2mIspLinkID;
       UInt32    Alg_IssAewbLinkID;
       UInt32    IssM2mSimcopLinkID;
       UInt32    Display_VideoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       IssM2mIspLink_CreateParams              IssM2mIspPrm;
       AlgorithmLink_IssAewbCreateParams       Alg_IssAewbPrm;
       IssM2mSimcopLink_CreateParams           IssM2mSimcopPrm;
       DisplayLink_CreateParams                Display_VideoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_monochrome_issIsp_DisplayObj;

Void chains_monochrome_issIsp_Display_SetLinkId(chains_monochrome_issIsp_DisplayObj *pObj);

Void chains_monochrome_issIsp_Display_ResetLinkPrms(chains_monochrome_issIsp_DisplayObj *pObj);

Void chains_monochrome_issIsp_Display_SetPrms(chains_monochrome_issIsp_DisplayObj *pObj);

Void chains_monochrome_issIsp_Display_ConnectLinks(chains_monochrome_issIsp_DisplayObj *pObj);

Int32 chains_monochrome_issIsp_Display_Create(chains_monochrome_issIsp_DisplayObj *pObj, Void *appObj);

Int32 chains_monochrome_issIsp_Display_Start(chains_monochrome_issIsp_DisplayObj *pObj);

Int32 chains_monochrome_issIsp_Display_Stop(chains_monochrome_issIsp_DisplayObj *pObj);

Int32 chains_monochrome_issIsp_Display_Delete(chains_monochrome_issIsp_DisplayObj *pObj);

Void chains_monochrome_issIsp_Display_printBufferStatistics(chains_monochrome_issIsp_DisplayObj *pObj);

Void chains_monochrome_issIsp_Display_printStatistics(chains_monochrome_issIsp_DisplayObj *pObj);

Void chains_monochrome_issIsp_Display_SetAppPrms(chains_monochrome_issIsp_DisplayObj *pObj, Void *appObj);

#endif /* _chains_monochrome_issIsp_Display_H_ */
