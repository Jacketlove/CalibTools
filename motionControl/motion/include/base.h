/*-------------------------------------------------------------------------------------
Copyright (C) 2010-2020 ShenZhen EasyMotion Technology Company

Author: amie
-------------------------------------------------------------------------------------*/

#ifndef __BASE_H
#define __BASE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#ifdef __MINGW32__
#include <windows.h>
#include <winuser.h>
#include <pthread.h>
#elif defined(OS_LINUX)
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/utsname.h>
#include <arpa/telnet.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <sys/param.h>
#include <syslog.h>
#elif defined(OS_WINDOWS)
#pragma warning(disable : 4101)
#pragma warning(disable : 4102)
#pragma warning(disable : 4761)

#include <windows.h>
#include <winuser.h>
#endif

#ifndef TRUE
    #define TRUE    1
#endif
#ifndef FALSE
    #define FALSE   0
#endif

#ifndef OS_OK
    #define OS_OK   (unsigned long)1
#endif
#ifndef OS_FAIL
    #define OS_FAIL (unsigned long)0
#endif

#ifdef NULL
    #undef NULL
#endif
#ifndef NULL
    #define NULL    0
#endif

#ifdef NULL_PTR
    #undef NULL_PTR
#endif
#ifndef NULL_PTR
    #define NULL_PTR    0
#endif

#define NULL_BYTE   0xFF
#define NULL_WORD   0xFFFF
#define NULL_DWORD  0xFFFFFFFF

typedef unsigned char   _BYTE;
typedef unsigned char   _UCHAR;
typedef   signed char   _SCHAR;
typedef          char   _CHAR;
typedef unsigned char   _BOOL;

typedef unsigned short  _WORD;
typedef   signed short  _SHORT;

typedef unsigned int    _DWORD;
typedef   signed int    _LONG;
typedef   signed int    _INT;

typedef          float  _FLOAT;
typedef          double _DOUBLE;

typedef          void   _VOID;

typedef unsigned char   u8;
typedef char            c8;
typedef signed char     s8;

typedef unsigned short  u16;

typedef unsigned long   u32;
typedef signed long     s32;

#define RUN_R(function) \
    if( OS_OK != (function) ) \
    { \
        _SYS_ASSERT(0); \
        return OS_FAIL; \
    }
#define RUN_A(function) \
    if( OS_OK != (function) ) \
    { \
        _SYS_ASSERT(0); \
    }

#if defined(OS_WINDOWS) || defined(__MINGW32__)
    typedef CRITICAL_SECTION _LOCK;

    #define INIT_LOCK(s)    InitializeCriticalSection( &(s) )
    #define FREE_LOCK(s)    DeleteCriticalSection( &(s) )

    #define LOCK(s)         EnterCriticalSection( &(s) )
    #define UNLOCK(s)       LeaveCriticalSection( &(s) )
#elif defined(OS_LINUX)
    typedef pthread_mutex_t  _LOCK;

    #define INIT_LOCK(s)    pthread_mutex_init( &(s), NULL )
    #define FREE_LOCK(s)

    #define LOCK(s)         pthread_mutex_lock( &(s) )
    #define UNLOCK(s)       pthread_mutex_unlock( &(s) )
#endif

#ifdef __MINGW32__
#define TASK_PRIORITY_ABOVEDEFAULT      THREAD_PRIORITY_ABOVE_NORMAL
#define TASK_PRIORITY_BELOWDEFAULT      THREAD_PRIORITY_BELOW_NORMAL
#define TASK_PRIORITY_DEFAULT           THREAD_PRIORITY_NORMAL
#define TASK_PRIORITY_HIGHEST           THREAD_PRIORITY_HIGHEST
#define TASK_PRIORITY_IDLE              THREAD_PRIORITY_IDLE
#define TASK_PRIORITY_LOWEST            THREAD_PRIORITY_LOWEST
#define TASK_PRIORITY_REALTIME          THREAD_PRIORITY_TIME_CRITICAL
typedef pthread_t*   OS_TASK_ID;
#elif defined(OS_LINUX)
#define TASK_PRIORITY_ABOVEDEFAULT      149
#define TASK_PRIORITY_BELOWDEFAULT      151
#define TASK_PRIORITY_DEFAULT           150
#define TASK_PRIORITY_HIGHEST           148
#define TASK_PRIORITY_IDLE              200
#define TASK_PRIORITY_LOWEST            152
#define TASK_PRIORITY_REALTIME          10
typedef pthread_t   OS_TASK_ID;
#elif defined(OS_WINDOWS)
#define TASK_PRIORITY_ABOVEDEFAULT      THREAD_PRIORITY_ABOVE_NORMAL
#define TASK_PRIORITY_BELOWDEFAULT      THREAD_PRIORITY_BELOW_NORMAL
#define TASK_PRIORITY_DEFAULT           THREAD_PRIORITY_NORMAL
#define TASK_PRIORITY_HIGHEST           THREAD_PRIORITY_HIGHEST
#define TASK_PRIORITY_IDLE              THREAD_PRIORITY_IDLE
#define TASK_PRIORITY_LOWEST            THREAD_PRIORITY_LOWEST
#define TASK_PRIORITY_REALTIME          THREAD_PRIORITY_TIME_CRITICAL
typedef HANDLE   OS_TASK_ID;
#endif

#define STRLEN(a)                       ((_WORD)(strlen((c8 *)(a))))
#define ATOI                            atoi

#define MOTION_API                      __declspec(dllexport)
#define MOTION_CDECL                    __cdecl

#define MAX_ASSERT_REAL_FILENAME_LEN     32
#define MAX_ASSERT_FULL_FILENAME_LEN     256
#define MAX_ASSERT_LINE_LEN              8

extern _BOOL m_boolIsPRINTout;
#define _SYS_Printf     if(m_boolIsPRINTout) PRINT_Out
#define _SYS_ASSERT(c)  ((c)?(_VOID)0:ASSERT_Out((_CHAR*)#c,(_CHAR*)__FILE__,__LINE__) )

#define US_PER_MS   1000
#define SYS_TICKS   GetSysUss()

extern _DWORD PRINT_Out( _CHAR *pcFormat,... );
extern _VOID ASSERT_Out( _CHAR *pcCondition, _CHAR *pcFileName, _DWORD dwLineNo );
extern _DWORD APP_PrintInit(_VOID);
extern _VOID APP_PrintExit(_VOID);
extern _VOID Log_SetPrintf( _BOOL bPrint );
extern int OS_SPrintf(char *pString,char *pcFormat,...);
extern int OS_SScanf( char * pcBuf, char * pcFormat, ...);
extern _VOID TASK_MssDelay( _DWORD dwMss );

extern _DWORD GetSysUss( _VOID );

typedef _VOID (* PFN_SERIALRECVPKT)( _BYTE bSerialNo, _CHAR *pcPacket );
typedef _VOID  (*PFN_Print)( _CHAR *pcString );

//#define STATISTIC_QUIRY

#ifdef __cplusplus
}
#endif

#endif

