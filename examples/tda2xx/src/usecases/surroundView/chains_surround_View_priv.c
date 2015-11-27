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
#include "chains_surround_View_priv.h"

#include <src/utils_common/include/utils_lut.h> //ryuhs74@20151112 - Add
#include <examples/tda2xx/src/links/uartCmd/uartCmd_priv.h> //ryuhs74@20151105 - Test UI CMD
#include <include/link_api/system_common.h>

extern UInt32 gGrpxSrcLinkID;
UInt32 gE500LUTLinkID; //ryuhs74@20151112 - Add
extern UInt32 gFullFront;

Void chains_surround_View_SetLinkId(chains_surround_ViewObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE;
       pObj->DupLinkID                      = IPU1_0_LINK (SYSTEM_LINK_ID_DUP_0);
       pObj->SyncLinkID                     = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_0);
       pObj->IPCOut_IPU1_0_DSP_0_0LinkID    = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_DSP_0_IPU1_0_0LinkID     = DSP1_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Alg_SurroundViewLinkID         = DSP1_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->IPCOut_DSP_0_IPU1_0_0LinkID    = DSP1_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_IPU1_0_DSP_0_0LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->MergeLinkID                    = IPU1_0_LINK (SYSTEM_LINK_ID_MERGE_0);
       pObj->Display_videoLinkID            = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_1;


       //pObj->Save_SaveLinkID                = IPU1_0_LINK (SYSTEM_LINT_SAVE_0); //ryuhs74@20151027 - Add Save Link
       gGrpxSrcLinkID = pObj->GrpxSrcLinkID;
       gE500LUTLinkID = pObj->Alg_SurroundViewLinkID;
}

Void chains_surround_View_ResetLinkPrms(chains_surround_ViewObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       DupLink_CreateParams_Init(&pObj->DupPrm);
       SyncLink_CreateParams_Init(&pObj->SyncPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_DSP_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_DSP_0_IPU1_0_0Prm);
       AlgorithmLink_SurroundViewCreateParams_Init(&pObj->Alg_SurroundViewPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_DSP_0_IPU1_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_IPU1_0_DSP_0_0Prm);
       MergeLink_CreateParams_Init(&pObj->MergePrm);
       DisplayLink_CreateParams_Init(&pObj->Display_videoPrm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);

       //ryuhs74@20151027 - Add Save Link
       //SaveLink_CreateParams_Init(&pObj->Save_Prm);

}

Void chains_surround_View_SetPrms(chains_surround_ViewObj *pObj){
       (pObj->DupPrm).numOutQue = 2;
       (pObj->Alg_SurroundViewPrm).baseClassCreate.size  = sizeof(AlgorithmLink_SurroundViewCreateParams);
       (pObj->Alg_SurroundViewPrm).baseClassCreate.algId  = ALGORITHM_LINK_DSP_ALG_SURROUND_VIEW;
       (pObj->MergePrm).numInQue = 2;
}

Void chains_surround_View_ConnectLinks(chains_surround_ViewObj *pObj){

       //Capture -> Dup
       pObj->CapturePrm.outQueParams.nextLink = pObj->DupLinkID;
       pObj->DupPrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->DupPrm.inQueParams.prevLinkQueId = 0;

       //Dup -> VPE
       pObj->DupPrm.outQueParams[0].nextLink = pObj->SyncLinkID;
       pObj->SyncPrm.inQueParams.prevLinkId = pObj->DupLinkID;
       pObj->SyncPrm.inQueParams.prevLinkQueId = 0;

       //Dup -> Merge
       pObj->DupPrm.outQueParams[1].nextLink = pObj->MergeLinkID;
       pObj->MergePrm.inQueParams[1].prevLinkId = pObj->DupLinkID;
       pObj->MergePrm.inQueParams[1].prevLinkQueId = 1;


       //Sync -> Alg_SurroundView
       pObj->SyncPrm.outQueParams.nextLink = pObj->IPCOut_IPU1_0_DSP_0_0LinkID;
       pObj->IPCOut_IPU1_0_DSP_0_0Prm.inQueParams.prevLinkId = pObj->SyncLinkID;
       pObj->IPCOut_IPU1_0_DSP_0_0Prm.inQueParams.prevLinkQueId = 0;


       //IPCOut_IPU1_0_DSP_0_0 -> IPCIn_DSP_0_IPU1_0_0
       pObj->IPCOut_IPU1_0_DSP_0_0Prm.outQueParams.nextLink = pObj->IPCIn_DSP_0_IPU1_0_0LinkID;
       pObj->IPCIn_DSP_0_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_DSP_0_0LinkID;
       pObj->IPCIn_DSP_0_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_DSP_0_IPU1_0_0 -> Alg_FullView
       pObj->IPCIn_DSP_0_IPU1_0_0Prm.outQueParams.nextLink = pObj->Alg_SurroundViewLinkID;
       pObj->Alg_SurroundViewPrm.inQueParams.prevLinkId = pObj->IPCIn_DSP_0_IPU1_0_0LinkID;
       pObj->Alg_SurroundViewPrm.inQueParams.prevLinkQueId = 0;

       //Alg_FullView -> IPCOut_DSP_0_IPU1_0_0
       pObj->Alg_SurroundViewPrm.outQueParams.nextLink = pObj->IPCOut_DSP_0_IPU1_0_0LinkID;
       pObj->IPCOut_DSP_0_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->Alg_SurroundViewLinkID;
       pObj->IPCOut_DSP_0_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_DSP_0_IPU1_0_0 -> IPCIn_IPU1_0_DSP_0_0
       pObj->IPCOut_DSP_0_IPU1_0_0Prm.outQueParams.nextLink = pObj->IPCIn_IPU1_0_DSP_0_0LinkID;
       pObj->IPCIn_IPU1_0_DSP_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_DSP_0_IPU1_0_0LinkID;
       pObj->IPCIn_IPU1_0_DSP_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_IPU1_0_DSP_0_0 -> Display_Video
       pObj->IPCIn_IPU1_0_DSP_0_0Prm.outQueParams.nextLink = pObj->MergeLinkID;
       pObj->MergePrm.inQueParams[0].prevLinkId = pObj->IPCIn_IPU1_0_DSP_0_0LinkID;
       pObj->MergePrm.inQueParams[0].prevLinkQueId = 0;


       //Merge -> Display_video
       pObj->MergePrm.outQueParams.nextLink = pObj->Display_videoLinkID;
       pObj->Display_videoPrm.inQueParams.prevLinkId = pObj->MergeLinkID;
       pObj->Display_videoPrm.inQueParams.prevLinkQueId = 0;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;



}

Int32 chains_surround_View_Create(chains_surround_ViewObj *pObj, Void *appObj){

       Int32 status;

       chains_surround_View_SetLinkId(pObj);
       chains_surround_View_ResetLinkPrms(pObj);

       chains_surround_View_SetPrms(pObj);
       chains_surround_View_SetAppPrms(pObj, appObj);

       chains_surround_View_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->DupLinkID, &pObj->DupPrm, sizeof(pObj->DupPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->SyncLinkID, &pObj->SyncPrm, sizeof(pObj->SyncPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_DSP_0_0LinkID, &pObj->IPCOut_IPU1_0_DSP_0_0Prm, sizeof(pObj->IPCOut_IPU1_0_DSP_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_DSP_0_IPU1_0_0LinkID, &pObj->IPCIn_DSP_0_IPU1_0_0Prm, sizeof(pObj->IPCIn_DSP_0_IPU1_0_0Prm));

       status = System_linkCreate(pObj->Alg_SurroundViewLinkID, &pObj->Alg_SurroundViewPrm, sizeof(pObj->Alg_SurroundViewPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_DSP_0_IPU1_0_0LinkID, &pObj->IPCOut_DSP_0_IPU1_0_0Prm, sizeof(pObj->IPCOut_DSP_0_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_IPU1_0_DSP_0_0LinkID, &pObj->IPCIn_IPU1_0_DSP_0_0Prm, sizeof(pObj->IPCIn_IPU1_0_DSP_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->MergeLinkID, &pObj->MergePrm, sizeof(pObj->MergePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_videoLinkID, &pObj->Display_videoPrm, sizeof(pObj->Display_videoPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_surround_View_Start(chains_surround_ViewObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_videoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->MergeLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_SurroundViewLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->DupLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       //ryyuhs74@20151028 - Add Save Link
       //status = System_linkStart(pObj->Save_SaveLinkID);
       //UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_surround_View_Stop(chains_surround_ViewObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_videoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->MergeLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_SurroundViewLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);


       status = System_linkStop(pObj->DupLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_surround_View_Delete(chains_surround_ViewObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_videoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->MergeLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_SurroundViewLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_DSP_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_DSP_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->DupLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_surround_View_printBufferStatistics(chains_surround_ViewObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->DupLinkID);
       System_linkPrintBufferStatistics(pObj->SyncLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_DSP_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_DSP_0_IPU1_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_SurroundViewLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_DSP_0_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_IPU1_0_DSP_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->MergeLinkID);
       System_linkPrintBufferStatistics(pObj->Display_videoLinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

Void chains_surround_View_printStatistics(chains_surround_ViewObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->DupLinkID);
       System_linkPrintStatistics(pObj->SyncLinkID);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_DSP_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_DSP_0_IPU1_0_0LinkID);
       System_linkPrintStatistics(pObj->Alg_SurroundViewLinkID);
       System_linkPrintStatistics(pObj->IPCOut_DSP_0_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_IPU1_0_DSP_0_0LinkID);
       System_linkPrintStatistics(pObj->MergeLinkID);
       System_linkPrintStatistics(pObj->Display_videoLinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

AlgorithmLink_SurroundViewCreateParams       Alg_SurroundViewPrm;

void E500ViewMode_putCmd( uint8_t _cmd )
{
	/*
	#define IRDA_KEY_PWR	(0x09)
		#define IRDA_KEY_FULL	(0x05)
		#define IRDA_KEY_LOCK	(0x5C)
		#define IRDA_KEY_UP		(0x0F)
		#define IRDA_KEY_DOWN	(0x0E)
		#define IRDA_KEY_LEFT	(0x0B)
		#define IRDA_KEY_RIGHT	(0x0A)
	 */
#if 1

	Int32 status;

	if( _cmd == IRDA_KEY_UP ){
		Vps_printf("In E500ViewMode_putCmd, IRDA_KEY_UP");

		Alg_SurroundViewPrm.sViewmode.viewmode =  TOP_VIEW;
		Alg_SurroundViewPrm.sViewmode.viewnt = FRONT_VIEW;
		_cmd = SYSTEM_CMD_FRONT_SIDE_VIEW;
	} else if( _cmd == IRDA_KEY_DOWN ){
		Vps_printf("In E500ViewMode_putCmd, IRDA_KEY_DOWN");

		Alg_SurroundViewPrm.sViewmode.viewmode =  TOP_VIEW;
		Alg_SurroundViewPrm.sViewmode.viewnt = REAR_VIEW;
		_cmd = SYSTEM_CMD_REAR_SIDE_VIEW;
	} else if( _cmd == IRDA_KEY_RIGHT ){
		Vps_printf("In E500ViewMode_putCmd, IRDA_KEY_RIGHT");

		Alg_SurroundViewPrm.sViewmode.viewmode =  TOP_VIEW;
		Alg_SurroundViewPrm.sViewmode.viewnt = RIGHT_VIEW;
		_cmd = SYSTEM_CMD_RIGH_SIDE_VIEW;
	} else if( _cmd == IRDA_KEY_LEFT ){
		Vps_printf("In E500ViewMode_putCmd, IRDA_KEY_LEFT");

		Alg_SurroundViewPrm.sViewmode.viewmode =  TOP_VIEW;
		Alg_SurroundViewPrm.sViewmode.viewnt = LEFT_VIEW;
		_cmd = SYSTEM_CMD_LEFT_SIDE_VIEW;
	}else if( _cmd == IRDA_KEY_FULL ){
		if( gFullFront == 0 )//Front Full View
		{
			Vps_printf("In E500ViewMode_putCmd, IRDA_KEY_FULL");
			Alg_SurroundViewPrm.sViewmode.viewmode =  FULL_VIEW;
			Alg_SurroundViewPrm.sViewmode.viewnt = FRONT_VIEW;
			_cmd = SYSTEM_CMD_FULL_FRONT_VIEW;
		} else {
			Vps_printf("In E500ViewMode_putCmd, IRDA_KEY_FULL");
			Alg_SurroundViewPrm.sViewmode.viewmode =  FULL_VIEW;
			Alg_SurroundViewPrm.sViewmode.viewnt = REAR_VIEW;
			_cmd = SYSTEM_CMD_FULL_REAR_VIEW;
		}
	}

	status = System_linkControl(gE500LUTLinkID, _cmd, &Alg_SurroundViewPrm, sizeof(Alg_SurroundViewPrm), TRUE); //gGrpxSrcLinkID ��ü�� �ΰ�.
	Vps_printf("   CMD Send %s E500ViewMode_putCmd\n", ( status == 0x0)?"Success":"Fail");
#endif
}

