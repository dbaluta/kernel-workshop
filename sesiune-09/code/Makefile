ARCH := avr32
CROSS_COMPILE := /opt/buildroot-avr32-v3.0.0/output/staging/usr/bin/avr32-linux-
KDIR := /opt/buildroot-avr32-v3.0.0/output/build/linux-2.6.35.4
PWD := $(shell pwd)

obj-m := leds.o

kbuild:
	make -C $(KDIR) M=`pwd` ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	make -C $(KDIR) M=`pwd` clean
	-rm -f *~ Module.symvers Module.markers modules.order 
