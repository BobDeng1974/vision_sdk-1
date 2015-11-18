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

#ifndef _chains_lvdsVipSurroundViewStandalone_H_
#define _chains_lvdsVipSurroundViewStandalone_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/dupLink.h>
//#include <include/link_api/algorithmLink_geometricAlignment.h>
//#include <include/link_api/algorithmLink_synthesis.h>
#include <include/link_api/ipcLink.h>
//#include <include/link_api/algorithmLink_photoAlignment.h>
//#include <include/link_api/selectLink.h>
///#include <include/link_api/vpeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_dmaSwMs.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

#include <include/link_api/saveLink.h>

#define CAMMSYS_LUT_AVME500	//ryuhs74@20151109 - Add Change From chains_lvdsVipSurroundViewStandalone Usecases To CAMMSYS LUT AVME500

typedef struct {
#ifdef CAMMSYS_LUT_AVME500
       UInt32    CaptureLinkID;
       UInt32    Sync_svLinkID;
       UInt32    Dup_svLinkID;
       UInt32    IPCOut_IPU1_0_IPU1_1LinkID;	//IPU1_0 -> IPU1_1, For Save Link in IPU1_0 Core
       UInt32    IPCIn_IPU1_IPU1_0_1LinkID; 	//IPU1_0 -> IPU1_1, For Save Link in IPU1_1 Core
       UInt32    IPCOut_IPU1_0_DSP1_0LinkID;	//IPU1_0 -> DSP1_0, For Cammsys LUT Link in IPU1_0 Core
       UInt32    IPCIn_DSP1_IPU1_0_0LinkID;		//IPU1_0 -> DSP1_0, For Cammsys LUT Link in DSP1_0 Core
       UInt32    IPCOut_DSP1_IPU1_0_0LinkID;	//DSP1_0 -> IPU1_0, For Cammsys LUT Link in DSP1_0 Core
       UInt32    IPCIn_IPU1_0_DSP1_0LinkID;		//DSP1_0 -> IPU1_0, For Cammsys LUT Link in IPU1_0 Core
       UInt32    Display_svLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;
       Uint32	 SaveLinkID;
       UInt32    Alg_DmaSwMsLinkID;				//Uint32	 CammsysLutLinkID;

       CaptureLink_CreateParams                CapturePrm;
       SyncLink_CreateParams                   Sync_svPrm;
       DupLink_CreateParams                    Dup_svPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_IPU1_1Prm;	//IPU1_0 -> IPU1_1, For Save Link in IPU1_0 Core
       IpcLink_CreateParams                    IPCIn_IPU1_IPU1_0_1Prm;	//IPU1_0 -> IPU1_1, For Save Link in IPU1_1 Core
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_0Prm;	//IPU1_0 -> DSP1_0, For Cammsys LUT Link in IPU1_0 Core
       IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_0Prm;	//IPU1_0 -> DSP1_0, For Cammsys LUT Link in DSP1_0 Core
       IpcLink_CreateParams                    IPCOut_DSP1_IPU1_0_0Prm;	//DSP1_0 -> IPU1_0, For Cammsys LUT Link in DSP1_0 Core
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP1_0Prm;	//DSP1_0 -> IPU1_0, For Cammsys LUT Link in IPU1_0 Core
       DisplayLink_CreateParams                Display_svPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;

       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMsPrm;
       SaveLink_CreateParams				   SavePrm;	//ryuhs74@20151027 - Add Save Link
#else
      UInt32    CaptureLinkID;
	  UInt32    Dup_sv_orgLinkID;
	  UInt32    Sync_svLinkID;
	  UInt32    Dup_svLinkID;
	  UInt32    IPCOut_IPU1_0_DSP1_1LinkID;
	  UInt32    IPCIn_DSP1_IPU1_0_1LinkID;
	  UInt32    IPCOut_IPU1_0_DSP1_0LinkID;
	  UInt32    IPCIn_DSP1_IPU1_0_0LinkID;
	  UInt32    Alg_GeoAlignLinkID;
	  UInt32    Alg_SynthesisLinkID;
	  UInt32    IPCOut_DSP1_IPU1_0_0LinkID;
	  UInt32    IPCIn_IPU1_0_DSP1_0LinkID;
	  UInt32    Display_svLinkID;
	  UInt32    Alg_PhotoAlignLinkID;
	  UInt32    SelectLinkID;
	  UInt32    VPE_sv_org2LinkID;
	  UInt32    Sync_sv_org2LinkID;
	  UInt32    Alg_DmaSwMs_sv_org2LinkID;
	  UInt32    Display_sv_org2LinkID;
	  UInt32    VPE_sv_org1LinkID;
	  UInt32    Sync_sv_org1LinkID;
	  UInt32    Alg_DmaSwMs_sv_org1LinkID;
	  UInt32    Display_sv_org1LinkID;
	  UInt32    GrpxSrcLinkID;
	  UInt32    Display_GrpxLinkID;
	  Uint32	 SaveLinkID;

	  CaptureLink_CreateParams                CapturePrm;
	  DupLink_CreateParams                    Dup_sv_orgPrm;
	  SyncLink_CreateParams                   Sync_svPrm;
	  DupLink_CreateParams                    Dup_svPrm;
	  IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_1Prm;
	  IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_1Prm;
	  IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_0Prm;
	  IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_0Prm;
	  AlgorithmLink_GAlignCreateParams        Alg_GeoAlignPrm;
	  AlgorithmLink_SynthesisCreateParams     Alg_SynthesisPrm;
	  IpcLink_CreateParams                    IPCOut_DSP1_IPU1_0_0Prm;
	  IpcLink_CreateParams                    IPCIn_IPU1_0_DSP1_0Prm;
	  DisplayLink_CreateParams                Display_svPrm;
	  AlgorithmLink_PAlignCreateParams        Alg_PhotoAlignPrm;
	  SelectLink_CreateParams                 SelectPrm;
	  VpeLink_CreateParams                    VPE_sv_org2Prm;
	  SyncLink_CreateParams                   Sync_sv_org2Prm;
	  AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMs_sv_org2Prm;
	  DisplayLink_CreateParams                Display_sv_org2Prm;
	  VpeLink_CreateParams                    VPE_sv_org1Prm;
	  SyncLink_CreateParams                   Sync_sv_org1Prm;
	  AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMs_sv_org1Prm;
	  DisplayLink_CreateParams                Display_sv_org1Prm;
	  GrpxSrcLink_CreateParams                GrpxSrcPrm;
	  DisplayLink_CreateParams                Display_GrpxPrm;

	  SaveLink_CreateParams				   SavePrm;	//ryuhs74@20151027 - Add Save Link
#endif
} chains_lvdsVipSurroundViewStandaloneObj;

Void chains_lvdsVipSurroundViewStandalone_SetLinkId(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Void chains_lvdsVipSurroundViewStandalone_ResetLinkPrms(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Void chains_lvdsVipSurroundViewStandalone_SetPrms(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Void chains_lvdsVipSurroundViewStandalone_ConnectLinks(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Int32 chains_lvdsVipSurroundViewStandalone_Create(chains_lvdsVipSurroundViewStandaloneObj *pObj, Void *appObj);

Int32 chains_lvdsVipSurroundViewStandalone_Start(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Int32 chains_lvdsVipSurroundViewStandalone_Stop(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Int32 chains_lvdsVipSurroundViewStandalone_Delete(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Void chains_lvdsVipSurroundViewStandalone_printBufferStatistics(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Void chains_lvdsVipSurroundViewStandalone_printStatistics(chains_lvdsVipSurroundViewStandaloneObj *pObj);

Void chains_lvdsVipSurroundViewStandalone_SetAppPrms(chains_lvdsVipSurroundViewStandaloneObj *pObj, Void *appObj);

#endif /* _chains_lvdsVipSurroundViewStandalone_H_ */
