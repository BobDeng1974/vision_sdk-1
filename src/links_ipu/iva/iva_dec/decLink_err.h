/*
 *******************************************************************************
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
 */

/**
 *******************************************************************************
 *
 * \file decLink_err.h Defines the Decode Link error types
 *
 * \brief  Defines the Decode Link error types
 *
 * \version 0.0 (Jan 2014) : [SS] First version
 *
 *******************************************************************************
 */

#ifndef _DEC_LINK_ERR_H_
#define _DEC_LINK_ERR_H_

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */
#include <include/link_api/decLink.h>

/* =============================================================================
 * All success and failure codes for the Dec link module
 * ========================================================================== */

/** @brief Operation successful. */
#define DEC_LINK_S_SUCCESS                   (0)

/** @brief General Failure */
#define DEC_LINK_E_FAIL                      (-1)

/** @brief Argument passed to function is invalid. */
#define DEC_LINK_E_INVALIDARG                (-2)

/** @brief Decoder algorithm create failed */
#define DEC_LINK_E_ALGCREATEFAILED           (-3)

/** @brief RMAN assign resource failed */
#define DEC_LINK_E_RMANRSRCASSIGNFAILED      (-4)

/** @brief XDM_SETPARAM failed */
#define DEC_LINK_E_ALGSETPARAMSFAILED        (-5)

/** @brief Unknown codec type failed */
#define DEC_LINK_E_UNSUPPORTEDCODEC          (-6)

/** @brief Creation of task failed */
#define DEC_LINK_E_TSKCREATEFAILED           (-7)

/** @brief Invalid control cmd */
#define DEC_LINK_E_INVALIDCMD                (-8)

/** @brief Creationg of dup object failed */
#define DEC_LINK_E_DUPOBJ_CREATE_FAILED      (-9)

/** @brief Deletion of dup object failed */
#define DEC_LINK_E_DUPOBJ_DELETE_FAILED      (-10)

#endif


/* Nothing beyond this point */
