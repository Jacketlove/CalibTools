/*-------------------------------------------------------------------------------------
Copyright (C) 2010-2020 ShenZhen EasyMotion Technology Company

  Author: Amie
-------------------------------------------------------------------------------------*/
#ifndef __MOTION_API_TOOL_H
#define __MOTION_API_TOOL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "motion.h"
#include "motion_api.h"

MOTION_API _CHAR * MOTION_CDECL Comm_DLLVersion( _VOID );
MOTION_API _CHAR * MOTION_CDECL Comm_MCUVersion( _DWORD dwCardValid );
MOTION_API _VOID MOTION_CDECL Motion_SetResultSwitch( _DWORD dwIsEnable );
MOTION_API _CHAR * MOTION_CDECL Motion_GetLastResultInfo(_VOID);
MOTION_API _VOID MOTION_CDECL Comm_SetPrintf( _DWORD dwIsEnable );
MOTION_API _VOID MOTION_CDECL Comm_Debug( _VOID );
MOTION_API _DWORD MOTION_CDECL Comm_AxisGlobal2Local( _UCHAR ucAxisGlobal, _UCHAR *pucCardNo, _UCHAR *pucAxisLocal );
MOTION_API _DWORD MOTION_CDECL Comm_AxisLocal2Global( _UCHAR ucCardValid, _UCHAR ucAxisLocal, _UCHAR *pucAxisGlobal );
MOTION_API _DWORD MOTION_CDECL Comm_CardValid2Global( _UCHAR ucCardValid, _UCHAR *pucCardGlobal );
MOTION_API _VOID MOTION_CDECL motion_write_ERC_PIN(_WORD axis, _WORD on_off);
MOTION_API _INT MOTION_CDECL motion_read_ERC_PIN(_WORD axis);

#ifdef __cplusplus
}
#endif

#endif

