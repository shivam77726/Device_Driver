INSTALL_DIR=modules


CROSS_COMPILE=

ifneq (${KERNELRELEASE},)
	obj-m := mycdd.o
mycdd-objs := initDev.o cleanup.o openDev.o releaseDev.o trimDev.o writeDev.o readDev.o createScull.o lseekDev.o

else
#	KERNELDIR ?= /lib/modules/4.13.12/build
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
#	@echo "Kernel DIR:$(KERNELDIR)"
	PWD := $(shell pwd)
default:
	$(MAKE) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) M=$(PWD) modules
	rm -rf ${INSTALL_DIR}
	mkdir ${INSTALL_DIR}
	mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
