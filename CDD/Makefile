INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := mycdd.o
CC_VERSION_TEXT = $(subst $(pound),,$(shell LC_ALL=C $(CC) --version 2>/dev/null | head -n 1))
$(info $(KERNELRELEASE) $(CONFIG_CC_VERSION_TEXT) $(CC_VERSION_TEXT))

$(info $(CC) )
$(info $(LLVM) )
mycdd-objs := initDev.o cleanup.o openDev.o releaseDev.o trimDev.o writeDev.o readDev.o

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
