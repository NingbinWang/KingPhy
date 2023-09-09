#ifndef _RTL9000BX_H_
#define _RTL9000BX_H_
#include "core.h"
#define RTL9000BX_ID 0x001ccb00
#define RTL9000BX_MASK 0x001fffff
int rtl9000bx_config_aneg(PHY_T *phydev);
int rtl9000bx_aneg_done(PHY_T *phydev);
int rtl9000bx_soft_reset(PHY_T *phydev);
int rtl9000bx_read_status(PHY_T *phydev);
int rtl9000bx_config_init(PHY_T *phydev);
#endif