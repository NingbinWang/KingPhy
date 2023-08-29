#include "rtl9000bx.h"

static int rtl9000bx_config_aneg(struct phy_device *phydev)
{
	return 0;
}

static int rtl9000bx_aneg_done(struct phy_device *phydev)
{
	return 0;
}

static int rtl9000bx_soft_reset(struct phy_device *phydev)
{
	return 0;
}

static int rtl9000bx_config_init(struct phy_device *phydev)
{
   return config_init(phydev);
}

static int rtl9000bx_read_status(struct phy_device *phydev)
{
	return 0;
}

static struct phy_driver rtl9000bx_drvs[] = {
     {
		.phy_id		= 0x001ccb00,
		.name		= "RTL9000Bx Ethernet",
		.phy_id_mask  = 0x001fffff,
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

module_phy_driver(rtl9000bx_drvs);


static struct mdio_device_id __maybe_unused rtl9000bx_tbl[] = {
	{ 0x001ccb00, 0x001fffff },
	{ }
};

MODULE_DEVICE_TABLE(mdio, rtl9000bx_tbl);

MODULE_DESCRIPTION("rtl9000bx PHY driver");
MODULE_LICENSE("GPL");