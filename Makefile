
PWD	:= $(shell pwd)
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
ifneq ($(KERNELRELEASE),)
RTL_DIR :=  $(mkfile_dir)/
LINUXINCLUDE += -I$(RTL_DIR)/core
LINUXINCLUDE += -I$(RTL_DIR)/include
# call from kernel build system
obj-m += rtl9000bx.o
rtl9000bx-y += core/rtl_mdio.o 

PWD	:= $(shell pwd)
KDIR	?= /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

endif

.PHONY : all 
