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
#include "chains_vipSingleCameraObjectDetect_priv.h"
Void chains_vipSingleCameraObjectDetect_SetLinkId(chains_vipSingleCameraObjectDetectObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE;
       pObj->Dup_captureLinkID              = IPU1_0_LINK (SYSTEM_LINK_ID_DUP_0);
       pObj->IPCOut_IPU1_0_EVE1_0LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_EVE1_IPU1_0_0LinkID      = EVE1_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Alg_FeaturePlaneComputationLinkID = EVE1_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->IPCOut_EVE1_DSP1_0LinkID       = EVE1_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_DSP1_EVE1_0LinkID        = DSP1_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Alg_ObjectDetectionLinkID      = DSP1_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->IPCOut_DSP1_IPU1_0_0LinkID     = DSP1_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_IPU1_0_DSP1_0LinkID      = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Merge_algLinkID                = IPU1_0_LINK (SYSTEM_LINK_ID_MERGE_0);
       pObj->Sync_algLinkID                 = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_0);
       pObj->Alg_ObjectDrawLinkID           = IPU1_0_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->Display_algLinkID              = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_1;
}

Void chains_vipSingleCameraObjectDetect_ResetLinkPrms(chains_vipSingleCameraObjectDetectObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       DupLink_CreateParams_Init(&pObj->Dup_capturePrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_EVE1_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_EVE1_IPU1_0_0Prm);
       AlgorithmLink_FeatureComputation_Init(&pObj->Alg_FeaturePlaneComputationPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_EVE1_DSP1_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_DSP1_EVE1_0Prm);
       AlgorithmLink_ObjectDetection_Init(&pObj->Alg_ObjectDetectionPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_DSP1_IPU1_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_IPU1_0_DSP1_0Prm);
       MergeLink_CreateParams_Init(&pObj->Merge_algPrm);
       SyncLink_CreateParams_Init(&pObj->Sync_algPrm);
       AlgorithmLink_ObjectDraw_Init(&pObj->Alg_ObjectDrawPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_algPrm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);
}

Void chains_vipSingleCameraObjectDetect_SetPrms(chains_vipSingleCameraObjectDetectObj *pObj){
       (pObj->Dup_capturePrm).numOutQue = 2;
       (pObj->Alg_FeaturePlaneComputationPrm).baseClassCreate.size  = sizeof(AlgorithmLink_FeaturePlaneComputationCreateParams);
       (pObj->Alg_FeaturePlaneComputationPrm).baseClassCreate.algId  = ALGORITHM_LINK_EVE_ALG_FEATUREPLANECOMPUTE;
       (pObj->Alg_ObjectDetectionPrm).baseClassCreate.size  = sizeof(AlgorithmLink_ObjectDetectionCreateParams);
       (pObj->Alg_ObjectDetectionPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_OBJECTDETECTION;
       (pObj->Merge_algPrm).numInQue = 2;
       (pObj->Alg_ObjectDrawPrm).baseClassCreate.size  = sizeof(AlgorithmLink_ObjectDrawCreateParams);
       (pObj->Alg_ObjectDrawPrm).baseClassCreate.algId  = ALGORITHM_LINK_IPU_ALG_PD_DRAW;
}

Void chains_vipSingleCameraObjectDetect_ConnectLinks(chains_vipSingleCameraObjectDetectObj *pObj){

       //Capture -> Dup_capture
       pObj->CapturePrm.outQueParams.nextLink = pObj->Dup_captureLinkID;
       pObj->Dup_capturePrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->Dup_capturePrm.inQueParams.prevLinkQueId = 0;

       //Dup_capture -> Merge_alg
       pObj->Dup_capturePrm.outQueParams[0].nextLink = pObj->Merge_algLinkID;
       pObj->Merge_algPrm.inQueParams[0].prevLinkId = pObj->Dup_captureLinkID;
       pObj->Merge_algPrm.inQueParams[0].prevLinkQueId = 0;

       //Dup_capture -> IPCOut_IPU1_0_EVE1_0
       pObj->Dup_capturePrm.outQueParams[1].nextLink = pObj->IPCOut_IPU1_0_EVE1_0LinkID;
       pObj->IPCOut_IPU1_0_EVE1_0Prm.inQueParams.prevLinkId = pObj->Dup_captureLinkID;
       pObj->IPCOut_IPU1_0_EVE1_0Prm.inQueParams.prevLinkQueId = 1;

       //IPCOut_IPU1_0_EVE1_0 -> IPCIn_EVE1_IPU1_0_0
       pObj->IPCOut_IPU1_0_EVE1_0Prm.outQueParams.nextLink = pObj->IPCIn_EVE1_IPU1_0_0LinkID;
       pObj->IPCIn_EVE1_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_EVE1_0LinkID;
       pObj->IPCIn_EVE1_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_EVE1_IPU1_0_0 -> Alg_FeaturePlaneComputation
       pObj->IPCIn_EVE1_IPU1_0_0Prm.outQueParams.nextLink = pObj->Alg_FeaturePlaneComputationLinkID;
       pObj->Alg_FeaturePlaneComputationPrm.inQueParams.prevLinkId = pObj->IPCIn_EVE1_IPU1_0_0LinkID;
       pObj->Alg_FeaturePlaneComputationPrm.inQueParams.prevLinkQueId = 0;

       //Alg_FeaturePlaneComputation -> IPCOut_EVE1_DSP1_0
       pObj->Alg_FeaturePlaneComputationPrm.outQueParams.nextLink = pObj->IPCOut_EVE1_DSP1_0LinkID;
       pObj->IPCOut_EVE1_DSP1_0Prm.inQueParams.prevLinkId = pObj->Alg_FeaturePlaneComputationLinkID;
       pObj->IPCOut_EVE1_DSP1_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_EVE1_DSP1_0 -> IPCIn_DSP1_EVE1_0
       pObj->IPCOut_EVE1_DSP1_0Prm.outQueParams.nextLink = pObj->IPCIn_DSP1_EVE1_0LinkID;
       pObj->IPCIn_DSP1_EVE1_0Prm.inQueParams.prevLinkId = pObj->IPCOut_EVE1_DSP1_0LinkID;
       pObj->IPCIn_DSP1_EVE1_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_DSP1_EVE1_0 -> Alg_ObjectDetection
       pObj->IPCIn_DSP1_EVE1_0Prm.outQueParams.nextLink = pObj->Alg_ObjectDetectionLinkID;
       pObj->Alg_ObjectDetectionPrm.inQueParams.prevLinkId = pObj->IPCIn_DSP1_EVE1_0LinkID;
       pObj->Alg_ObjectDetectionPrm.inQueParams.prevLinkQueId = 0;

       //Alg_ObjectDetection -> IPCOut_DSP1_IPU1_0_0
       pObj->Alg_ObjectDetectionPrm.outQueParams.nextLink = pObj->IPCOut_DSP1_IPU1_0_0LinkID;
       pObj->IPCOut_DSP1_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->Alg_ObjectDetectionLinkID;
       pObj->IPCOut_DSP1_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_DSP1_IPU1_0_0 -> IPCIn_IPU1_0_DSP1_0
       pObj->IPCOut_DSP1_IPU1_0_0Prm.outQueParams.nextLink = pObj->IPCIn_IPU1_0_DSP1_0LinkID;
       pObj->IPCIn_IPU1_0_DSP1_0Prm.inQueParams.prevLinkId = pObj->IPCOut_DSP1_IPU1_0_0LinkID;
       pObj->IPCIn_IPU1_0_DSP1_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_IPU1_0_DSP1_0 -> Merge_alg
       pObj->IPCIn_IPU1_0_DSP1_0Prm.outQueParams.nextLink = pObj->Merge_algLinkID;
       pObj->Merge_algPrm.inQueParams[1].prevLinkId = pObj->IPCIn_IPU1_0_DSP1_0LinkID;
       pObj->Merge_algPrm.inQueParams[1].prevLinkQueId = 0;

       //Merge_alg -> Sync_alg
       pObj->Merge_algPrm.outQueParams.nextLink = pObj->Sync_algLinkID;
       pObj->Sync_algPrm.inQueParams.prevLinkId = pObj->Merge_algLinkID;
       pObj->Sync_algPrm.inQueParams.prevLinkQueId = 0;

       //Sync_alg -> Alg_ObjectDraw
       pObj->Sync_algPrm.outQueParams.nextLink = pObj->Alg_ObjectDrawLinkID;
       pObj->Alg_ObjectDrawPrm.inQueParams.prevLinkId = pObj->Sync_algLinkID;
       pObj->Alg_ObjectDrawPrm.inQueParams.prevLinkQueId = 0;

       //Alg_ObjectDraw -> Display_alg
       pObj->Alg_ObjectDrawPrm.outQueParams.nextLink = pObj->Display_algLinkID;
       pObj->Display_algPrm.inQueParams.prevLinkId = pObj->Alg_ObjectDrawLinkID;
       pObj->Display_algPrm.inQueParams.prevLinkQueId = 0;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_vipSingleCameraObjectDetect_Create(chains_vipSingleCameraObjectDetectObj *pObj, Void *appObj){

       Int32 status;

       chains_vipSingleCameraObjectDetect_SetLinkId(pObj);
       chains_vipSingleCameraObjectDetect_ResetLinkPrms(pObj);

       chains_vipSingleCameraObjectDetect_SetPrms(pObj);
       chains_vipSingleCameraObjectDetect_SetAppPrms(pObj, appObj);

       chains_vipSingleCameraObjectDetect_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Dup_captureLinkID, &pObj->Dup_capturePrm, sizeof(pObj->Dup_capturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_EVE1_0LinkID, &pObj->IPCOut_IPU1_0_EVE1_0Prm, sizeof(pObj->IPCOut_IPU1_0_EVE1_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_EVE1_IPU1_0_0LinkID, &pObj->IPCIn_EVE1_IPU1_0_0Prm, sizeof(pObj->IPCIn_EVE1_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_FeaturePlaneComputationLinkID, &pObj->Alg_FeaturePlaneComputationPrm, sizeof(pObj->Alg_FeaturePlaneComputationPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_EVE1_DSP1_0LinkID, &pObj->IPCOut_EVE1_DSP1_0Prm, sizeof(pObj->IPCOut_EVE1_DSP1_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_DSP1_EVE1_0LinkID, &pObj->IPCIn_DSP1_EVE1_0Prm, sizeof(pObj->IPCIn_DSP1_EVE1_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_ObjectDetectionLinkID, &pObj->Alg_ObjectDetectionPrm, sizeof(pObj->Alg_ObjectDetectionPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_DSP1_IPU1_0_0LinkID, &pObj->IPCOut_DSP1_IPU1_0_0Prm, sizeof(pObj->IPCOut_DSP1_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_IPU1_0_DSP1_0LinkID, &pObj->IPCIn_IPU1_0_DSP1_0Prm, sizeof(pObj->IPCIn_IPU1_0_DSP1_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Merge_algLinkID, &pObj->Merge_algPrm, sizeof(pObj->Merge_algPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Sync_algLinkID, &pObj->Sync_algPrm, sizeof(pObj->Sync_algPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_ObjectDrawLinkID, &pObj->Alg_ObjectDrawPrm, sizeof(pObj->Alg_ObjectDrawPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_algLinkID, &pObj->Display_algPrm, sizeof(pObj->Display_algPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCameraObjectDetect_Start(chains_vipSingleCameraObjectDetectObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_ObjectDrawLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Sync_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Merge_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_ObjectDetectionLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_DSP1_EVE1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_EVE1_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_FeaturePlaneComputationLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_EVE1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_EVE1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Dup_captureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCameraObjectDetect_Stop(chains_vipSingleCameraObjectDetectObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_ObjectDrawLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Sync_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Merge_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_ObjectDetectionLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP1_EVE1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_EVE1_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_FeaturePlaneComputationLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_EVE1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_EVE1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Dup_captureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCameraObjectDetect_Delete(chains_vipSingleCameraObjectDetectObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_ObjectDrawLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Sync_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Merge_algLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_ObjectDetectionLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_DSP1_EVE1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_EVE1_DSP1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_FeaturePlaneComputationLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_EVE1_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_EVE1_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Dup_captureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_vipSingleCameraObjectDetect_printBufferStatistics(chains_vipSingleCameraObjectDetectObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->Dup_captureLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_EVE1_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_EVE1_IPU1_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_FeaturePlaneComputationLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_EVE1_DSP1_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_DSP1_EVE1_0LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_ObjectDetectionLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       System_linkPrintBufferStatistics(pObj->Merge_algLinkID);
       System_linkPrintBufferStatistics(pObj->Sync_algLinkID);
       System_linkPrintBufferStatistics(pObj->Alg_ObjectDrawLinkID);
       System_linkPrintBufferStatistics(pObj->Display_algLinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

Void chains_vipSingleCameraObjectDetect_printStatistics(chains_vipSingleCameraObjectDetectObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->Dup_captureLinkID);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_EVE1_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_EVE1_IPU1_0_0LinkID);
       System_linkPrintStatistics(pObj->Alg_FeaturePlaneComputationLinkID);
       System_linkPrintStatistics(pObj->IPCOut_EVE1_DSP1_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_DSP1_EVE1_0LinkID);
       System_linkPrintStatistics(pObj->Alg_ObjectDetectionLinkID);
       System_linkPrintStatistics(pObj->IPCOut_DSP1_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_IPU1_0_DSP1_0LinkID);
       System_linkPrintStatistics(pObj->Merge_algLinkID);
       System_linkPrintStatistics(pObj->Sync_algLinkID);
       System_linkPrintStatistics(pObj->Alg_ObjectDrawLinkID);
       System_linkPrintStatistics(pObj->Display_algLinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

