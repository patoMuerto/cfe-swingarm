/*
**  File: 
**  cfe_es_cds_mempool.h
**
**
**
**      Copyright (c) 2004-2012, United States government as represented by the 
**      administrator of the National Aeronautics Space Administration.  
**      All rights reserved. This software(cFE) was created at NASA's Goddard 
**      Space Flight Center pursuant to government contracts.
**
**      This is governed by the NASA Open Source Agreement and may be used, 
**      distributed and modified only pursuant to the terms of that agreement.
** 
**  Purpose:
**  This file contains the Internal interface for the cFE Critical Data Store 
**  memory pool functions.
**
**  References:
**     Flight Software Branch C Coding Standard Version 1.0a
**     cFE Flight Software Application Developers Guide
**
**  Notes:
**  $Log: cfe_es_cds_mempool.h  $
**  Revision 1.4 2012/01/13 11:50:00EST acudmore 
**  Changed license text to reflect open source
**  Revision 1.3 2010/10/04 17:00:56EDT jmdagost 
**  Cleaned up copyright symbol.
**  Revision 1.2 2010/10/04 15:36:30EDT jmdagost 
**  Cleaned up copyright symbol.
**  Revision 1.1 2008/04/17 08:05:04EDT ruperera 
**  Initial revision
**  Member added to project c:/MKSDATA/MKS-REPOSITORY/MKS-CFE-PROJECT/fsw/cfe-core/src/es/project.pj
**  Revision 1.2 2007/05/15 11:16:06EDT apcudmore 
**  Added modification log tags.
*/


#ifndef _cfe_es_cds_mempool_
#define _cfe_es_cds_mempool_

/*
** Include Files
*/
#include "common_types.h"

/*
** Macro Definitions
*/

/*
** Type Definitions
*/

typedef uint32 CFE_ES_CDSBlockHandle_t;

/*****************************************************************************/
/*
** Function prototypes
*/

/*****************************************************************************/
/**
** \brief Creates a CDS memory pool from scratch
**
** \par Description
**        Creates a memory pool of the specified size starting at the specified
**        offset into the CDS memory.
**
** \par Assumptions, External Events, and Notes:
**          None
**
** \return #CFE_SUCCESS                     \copydoc CFE_SUCCESS
**                     
******************************************************************************/
int32 CFE_ES_CreateCDSPool(uint32 CDSPoolSize, uint32 StartOffset);


int32 CFE_ES_RebuildCDSPool(uint32 CDSPoolSize, uint32 StartOffset);

int32 CFE_ES_GetCDSBlock(CFE_ES_CDSBlockHandle_t *BlockHandle, uint32  BlockSize);

int32 CFE_ES_PutCDSBlock(CFE_ES_CDSBlockHandle_t BlockHandle);

int32 CFE_ES_CDSBlockWrite(CFE_ES_CDSBlockHandle_t BlockHandle, void *DataToWrite);

int32 CFE_ES_CDSBlockRead(void *DataRead, CFE_ES_CDSBlockHandle_t BlockHandle);

uint32 CFE_ES_CDSReqdMinSize(uint32 MaxNumBlocksToSupport);

#endif  /* _cfe_es_cds_mempool_ */
