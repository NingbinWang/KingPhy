#include "core.h"
#include "rtl9000bx.h"
#include "halrtl9000bxReg.h"

int rtl9000bx_config_aneg(PHY_T *phydev)
{
	return 0;
}

int rtl9000bx_aneg_done(PHY_T *phydev)
{
	return 0;
}

int rtl9000bx_soft_reset(PHY_T *phydev)
{
	return 0;
}

int rtl9000bx_read_status(PHY_T *phydev)
{
	return 0;
}


int rtl9000bx_config_init(PHY_T *phydev)
{
    /* The phy don't support auto-negotiation */
	u32 features;
	u32 delay = 0;
	u16 mdio_data = 0;
	int err;
	int adv;

	features = (SUPPORTED_TP | SUPPORTED_MII
			| SUPPORTED_AUI | SUPPORTED_FIBRE |
			SUPPORTED_BNC | SUPPORTED_Pause | SUPPORTED_Asym_Pause | SUPPORTED_100baseT_Full);

	phydev->supported &= features;
	phydev->advertising &= features;
	phydev->autoneg = AUTONEG_DISABLE;
	phydev->duplex = DUPLEX_FULL;
	phydev->speed = SPEED_100;

	delay = 4;
	do{
		phy_write(phydev, PAGSR, PAGEA42);
		mdio_data = phy_read(phydev, PHYSFR);
		if((mdio_data & 0x7) == 0x03)
		{
			printk("phy is ready");
			break;
		}
		else
		{
			printk("phy is not ready");
		}
		 mdelay(1);
	}while(delay--);
	phy_write(phydev, PAGSR, 0x0A43);// 1f page select
	phy_write(phydev, PHYSRAD, 0xDC06);
	phy_write(phydev, PHYSRC, 0xADFA);//Table 128. Parameter Setting for I/O Power Selection 

	phy_write(phydev, PHYSRAD, 0xDD00);
	mdio_data = phy_read(phydev, PHYSRC);
	phy_write(phydev, PHYSRC,(mdio_data | 0x0020));

	delay = 4;
	do{
		phy_write(phydev, PAGSR, PAGEA42);
		mdio_data = phy_read(phydev, PHYSFR);
		if((mdio_data & 0x7) == 0x03)
		{
			printk("phy is ready");
			break;
		}
		else
		{
			printk("phy is not ready");
		}
		mdelay(1);
	}while(delay--);
	

	/* set phy Slave */
	adv = phy_read(phydev, MII_CTRL1000);
	if (adv < 0)
		return adv;
	adv &= ~((0x01) << 11);
	err = phy_write(phydev, MII_CTRL1000, adv);
	if (err < 0)
		return err;

	phy_write(phydev, BMCR, 0x8000);

	delay = 20;
	do{
		mdio_data = phy_read(phydev, BMCR);
		if(mdio_data == 0x2100)
		{
			printk("soft reset is ready");
			break;
		}
		else
		{
			printk("soft reset is not ready");
		}
		 mdelay(1);
	}while(delay--);
    return 0;
}