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

#ifndef _chains_vipSingleCameraDenseOpticalFlow_1eve_H_
#define _chains_vipSingleCameraDenseOpticalFlow_1eve_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/algorithmLink_denseOpticalFlow.h>
#include <include/link_api/algorithmLink_vectorToImage.h>
#include <include/link_api/ipcLink.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

typedef struct {
       UInt32    CaptureLinkID;
       UInt32    IPCOut_IPU1_0_EVE1_0LinkID;
       UInt32    IPCIn_EVE1_IPU1_0_0LinkID;
       UInt32    Alg_DenseOptFlow_1LinkID;
       UInt32    IPCOut_EVE1_DSP1_0LinkID;
       UInt32    IPCIn_DSP1_EVE1_0LinkID;
       UInt32    Alg_VectorToImageLinkID;
       UInt32    IPCOut_DSP1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_DSP1_0LinkID;
       UInt32    Display_VideoDofLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE1_0Prm;
       IpcLink_CreateParams                    IPCIn_EVE1_IPU1_0_0Prm;
       AlgorithmLink_DenseOptFlowCreateParams  Alg_DenseOptFlow_1Prm;
       IpcLink_CreateParams                    IPCOut_EVE1_DSP1_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_EVE1_0Prm;
       AlgorithmLink_VectorToImageCreateParams Alg_VectorToImagePrm;
       IpcLink_CreateParams                    IPCOut_DSP1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP1_0Prm;
       DisplayLink_CreateParams                Display_VideoDofPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_vipSingleCameraDenseOpticalFlow_1eveObj;

Void chains_vipSingleCameraDenseOpticalFlow_1eve_SetLinkId(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Void chains_vipSingleCameraDenseOpticalFlow_1eve_ResetLinkPrms(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Void chains_vipSingleCameraDenseOpticalFlow_1eve_SetPrms(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Void chains_vipSingleCameraDenseOpticalFlow_1eve_ConnectLinks(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Int32 chains_vipSingleCameraDenseOpticalFlow_1eve_Create(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj, Void *appObj);

Int32 chains_vipSingleCameraDenseOpticalFlow_1eve_Start(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Int32 chains_vipSingleCameraDenseOpticalFlow_1eve_Stop(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Int32 chains_vipSingleCameraDenseOpticalFlow_1eve_Delete(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Void chains_vipSingleCameraDenseOpticalFlow_1eve_printBufferStatistics(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Void chains_vipSingleCameraDenseOpticalFlow_1eve_printStatistics(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj);

Void chains_vipSingleCameraDenseOpticalFlow_1eve_SetAppPrms(chains_vipSingleCameraDenseOpticalFlow_1eveObj *pObj, Void *appObj);

#endif /* _chains_vipSingleCameraDenseOpticalFlow_1eve_H_ */
