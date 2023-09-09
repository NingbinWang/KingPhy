#include "core.h"
#include "osdep_linux.h"
#include "rtl9000bx.h"

int KingPhy_config_aneg(struct phy_device *phydev)
{
	return 0;
}

int KingPhy_aneg_done(struct phy_device *phydev)
{
	return 0;
}

int KingPhy_soft_reset(struct phy_device *phydev)
{
	return 0;
}

int KingPhy_config_init(struct phy_device *phydev)
{
   return 0;
}

int KingPhy_read_status(struct phy_device *phydev)
{
	return 0;
}

static struct phy_driver KingPhy_drvs[] = {
     {
		.phy_id		= RTL9000BX_ID,
		.name		= "rtl9000bx Ethernet",
		.phy_id_mask  = RTL9000BX_MASK,
        .features	    = PHY_GBIT_FEATURES | SUPPORTED_MII |
			  SUPPORTED_AUI | SUPPORTED_FIBRE |SUPPORTED_BNC,
	    .flags		= PHY_HAS_INTERRUPT,
        .config_init    = rtl9000bx_config_init,
        .read_status    = rtl9000bx_read_status,
		.soft_reset     = rtl9000bx_soft_reset,
		.config_aneg    = rtl9000bx_config_aneg,
		.aneg_done      = rtl9000bx_aneg_done,
	},
};

module_phy_driver(KingPhy_drvs);


static struct mdio_device_id __maybe_unused KingPhy_tbl[] = {
	{ 0x001ccb00, 0x001fffff },
	{ }
};

MODULE_DEVICE_TABLE(mdio, KingPhy_tbl);

MODULE_DESCRIPTION("KingPhy PHY driver");
MODULE_LICENSE("GPL");