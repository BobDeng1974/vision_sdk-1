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

#ifndef _chains_lvdsVipMultiCam_Display_tda2xx_H_
#define _chains_lvdsVipMultiCam_Display_tda2xx_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/dupLink.h>
#include <include/link_api/vpeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_surroundView.h>
#include <include/link_api/mergeLink.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>
#include <include/link_api/ipcLink.h>

#include <include/link_api/saveLink.h> //ryuhs74@20151027 - Add Save Link

#define E500_SV_MULTICAM
typedef struct {
       UInt32    CaptureLinkID;
       UInt32    DupLinkID;
       UInt32    VPELinkID;
       UInt32    SyncLinkID;
       UInt32    IPCOut_IPU1_0_A15_0_0LinkID;
       UInt32    IPCIn_A15_0_IPU1_0_0LinkID;
       UInt32    Alg_SurroundViewLinkID;
       UInt32    IPCOut_A15_0_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_A15_0_0LinkID;
       UInt32    MergeLinkID;
       UInt32    Display_videoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       DupLink_CreateParams                    DupPrm;
       VpeLink_CreateParams                    VPEPrm;
       SyncLink_CreateParams                   SyncPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_A15_0_0Prm;
       IpcLink_CreateParams                    IPCIn_A15_0_IPU1_0_0Prm;
       AlgorithmLink_SurroundViewCreateParams       Alg_SurroundViewPrm;
       IpcLink_CreateParams                    IPCOut_A15_0_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_A15_0_0Prm;
       MergeLink_CreateParams                  MergePrm;
       DisplayLink_CreateParams                Display_videoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;

#ifdef E500_SV_MULTICAM
       //Add
       UInt32    IPCOut_IPU1_0_DSP1_0LinkID;	//IPU1_0 -> DSP1_0, For Cammsys LUT Link in IPU1_0 Core
       UInt32    IPCIn_DSP1_IPU1_0_0LinkID;		//IPU1_0 -> DSP1_0, For Cammsys LUT Link in DSP1_0 Core
       UInt32    IPCOut_DSP1_IPU1_0_0LinkID;	//DSP1_0 -> IPU1_0, For Cammsys LUT Link in DSP1_0 Core
       UInt32    IPCIn_IPU1_0_DSP1_0LinkID;		//DSP1_0 -> IPU1_0, For Cammsys LUT Link in IPU1_0 Core

       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_0Prm;	//IPU1_0 -> DSP1_0, For Cammsys LUT Link in IPU1_0 Core
       IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_0Prm;	//IPU1_0 -> DSP1_0, For Cammsys LUT Link in DSP1_0 Core
       IpcLink_CreateParams                    IPCOut_DSP1_IPU1_0_0Prm;	//DSP1_0 -> IPU1_0, For Cammsys LUT Link in DSP1_0 Core
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP1_0Prm;	//DSP1_0 -> IPU1_0, For Cammsys LUT Link in IPU1_0 Core

       //UInt32    IPCOut_IPU1_0_IPU1_1LinkID;	//IPU1_0 -> IPU1_1, For Save Link in IPU1_0 Core
       //UInt32    IPCIn_IPU1_IPU1_0_1LinkID; 	//IPU1_0 -> IPU1_1, For Save Link in IPU1_1 Core
       //Uint32	 SaveLinkID;

       // IpcLink_CreateParams                    IPCOut_IPU1_0_IPU1_1Prm;	//IPU1_0 -> IPU1_1, For Save Link in IPU1_0 Core
       // IpcLink_CreateParams                    IPCIn_IPU1_IPU1_0_1Prm;	//IPU1_0 -> IPU1_1, For Save Link in IPU1_1 Core
       // SaveLink_CreateParams				Save_Prm;//ryuhs74220151027 - Add Save Link
#endif
} chains_lvdsVipMultiCam_Display_tda2xxObj;

Void chains_lvdsVipMultiCam_Display_tda2xx_SetLinkId(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Void chains_lvdsVipMultiCam_Display_tda2xx_ResetLinkPrms(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Void chains_lvdsVipMultiCam_Display_tda2xx_SetPrms(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Void chains_lvdsVipMultiCam_Display_tda2xx_ConnectLinks(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Int32 chains_lvdsVipMultiCam_Display_tda2xx_Create(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj, Void *appObj);

Int32 chains_lvdsVipMultiCam_Display_tda2xx_Start(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Int32 chains_lvdsVipMultiCam_Display_tda2xx_Stop(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Int32 chains_lvdsVipMultiCam_Display_tda2xx_Delete(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Void chains_lvdsVipMultiCam_Display_tda2xx_printBufferStatistics(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Void chains_lvdsVipMultiCam_Display_tda2xx_printStatistics(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj);

Void chains_lvdsVipMultiCam_Display_tda2xx_SetAppPrms(chains_lvdsVipMultiCam_Display_tda2xxObj *pObj, Void *appObj);

#endif /* _chains_lvdsVipMultiCam_Display_tda2xx_H_ */
