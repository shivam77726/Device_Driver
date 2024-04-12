INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := mybdd.o

mybdd-objs := initDev.o cleanup.o 

else
#	KERNELDIR ?= /lib/modules/4.13.12/build
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
#	@echo "Kernel DIR:$(KERNELDIR)"
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	rm -rf ${INSTALL_DIR}
	mkdir ${INSTALL_DIR}
	mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
