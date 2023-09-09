
PWD	:= $(shell pwd)
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))
ifneq ($(KERNELRELEASE),)
KING_DIR :=  $(mkfile_dir)/
LINUXINCLUDE += -I$(KING_DIR)/hal/rtl9000bx
LINUXINCLUDE += -I$(KING_DIR)/include
# call from kernel build system
obj-m += kingphy.o
kingphy-y += hal/rtl9000bx/rtl9000bx.o 
kingphy-y += os_dep/osdep_linux.o 

PWD	:= $(shell pwd)
KDIR	?= /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

endif

.PHONY : all 
