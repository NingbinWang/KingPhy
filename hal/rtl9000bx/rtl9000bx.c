#include <linux/delay.h>



int config_init(struct phy_device *phydev)
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
		phy_write(phydev, 0x1f, 0x0A42);
		mdio_data = phy_read(phydev, 0x10);
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
	phy_write(phydev, 31, 0x0A43);// 1f page select
	phy_write(phydev, 27, 0xDC06);
	phy_write(phydev, 28, 0xADFA);//Table 128. Parameter Setting for I/O Power Selection 

	phy_write(phydev, 0x1B, 0xDD00);
	mdio_data = phy_read(phydev, 0x1c);
	phy_write(phydev, 0x1C,(mdio_data | 0x0020));

	delay = 4;
	do{
		phy_write(phydev, 31, 0x0A42);
		mdio_data = phy_read(phydev, 0x10);
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

    phy_write(phydev, 0x1b, 0xd050);
	adv = phy_read(phydev, 0x1C);
	//printk("before read 0xd050 %x \n",adv);
	phy_write(phydev, 0x1b, 0xd050);
	adv = adv&0xe1ff;
	adv = adv | 0x600;
	//printk("adv: %x \n",adv);
	phy_write(phydev,0x1C,adv);
	phy_write(phydev, 0x1b, 0xd050);
	adv = phy_read(phydev, 0x1C);
	printk("after read 0xd050 %x \n",adv);


	phy_write(phydev, 0x00, 0x8000);

	delay = 20;
	do{
		mdio_data = phy_read(phydev, 0x0);
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