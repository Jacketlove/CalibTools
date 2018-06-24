/*-------------------------------------------------------------------------------------
Copyright (C) 2010-2020 ShenZhen EasyMotion Technology Company

  Author: david
-------------------------------------------------------------------------------------*/
#ifndef __P9016_H
#define __P9016_H

#ifdef __cplusplus
extern "C" {
#endif

typedef signed int      _INT;
typedef signed int      _LONG;
typedef double          _DOUBLE;
typedef unsigned short  _WORD;
typedef unsigned int    _DWORD;
typedef void            _VOID;
typedef unsigned char   _BOOL;
typedef char            _CHAR;
typedef unsigned char   _UCHAR;

#define P9016_API      __declspec(dllexport)
#define P9016_CDECL    __cdecl

#define P9016_FAIL     ((_INT)1)
#define P9016_OK       ((_INT)0)

P9016_API _INT P9016_CDECL p9016_initial( _INT *pCard_count, _INT *pBoard_id );
P9016_API _INT P9016_CDECL p9016_close( _VOID );
P9016_API _INT P9016_CDECL p9016_set_pls_outmode( _INT axis, _INT pls_outmode );
P9016_API _INT P9016_CDECL p9016_set_pls_iptmode( _INT axis, _INT pls_iptmode );
P9016_API _INT P9016_CDECL p9016_set_t_profile( _INT axis, _DOUBLE start_vel, _DOUBLE max_vel, _DOUBLE acc, _DOUBLE dec );
P9016_API _INT P9016_CDECL p9016_set_s_profile( _INT axis, _DOUBLE start_vel, _DOUBLE max_vel, _DOUBLE acc, _DOUBLE dec, _DOUBLE jerk_percent );
P9016_API _INT P9016_CDECL p9016_vmove( _INT axis, _INT plus_dir, _INT vel_mode );
P9016_API _INT P9016_CDECL p9016_stop( _INT axis, _INT EmgStop );
P9016_API _INT P9016_CDECL p9016_pmove( _INT axis, _INT dist, _INT dist_mode, _INT vel_mode );
P9016_API _INT P9016_CDECL p9016_set_home_config( _INT axis, _INT mode, _INT org_level, _INT ez_level );
P9016_API _INT P9016_CDECL p9016_home_move( _INT axis, _INT PlusDir );
P9016_API _INT P9016_CDECL p9016_get_motion_status( _INT axis, _DWORD *pStatus );
P9016_API _INT P9016_CDECL p9016_get_current_speed( _INT axis, _DOUBLE *pSpeed );
P9016_API _INT P9016_CDECL p9016_get_io_status( _INT axis, _DWORD *pStatus );
P9016_API _INT P9016_CDECL p9016_set_el_level( _INT axis, _INT active_level );
P9016_API _INT P9016_CDECL p9016_set_alram( _INT axis, _INT enable, _INT active_level );
P9016_API _INT P9016_CDECL p9016_get_pos( _INT axis, _INT cntr_no, _INT *pPos );
P9016_API _INT P9016_CDECL p9016_set_pos( _INT axis, _INT cntr_no, _INT pos );
P9016_API _INT P9016_CDECL p9016_set_do( _INT card_no, _DWORD data );
P9016_API _INT P9016_CDECL p9016_set_do_bit( _INT card_no, _DWORD bit_bo, _DWORD data );
P9016_API _INT P9016_CDECL p9016_get_do( _INT card_no, _DWORD *pData );
P9016_API _INT P9016_CDECL p9016_get_di( _INT card_no, _DWORD *pData );
P9016_API _INT P9016_CDECL p9016_get_di_bit( _INT card_no, _DWORD bit_no, _DWORD *pData );
P9016_API _INT P9016_CDECL p9016_get_driver_version( _CHAR *pDriver_ver );
P9016_API _INT P9016_CDECL p9016_get_card_version( _INT card_no, _CHAR *pCard_ver );

#ifdef __cplusplus
}
#endif

#endif

