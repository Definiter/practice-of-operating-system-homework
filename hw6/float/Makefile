obj-m += float.o

#ccflags_y+=-O0 -msoft-float -msse
#ccflags_y+=-O0 -mhard-float
EXTRA_CFLAGS+=-O0 -mhard-float
#EXTRA_CFLAGS+=-O0 -msoft-float -msse -mpreferred-stack-boundary=4

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	insmod float.ko

uninstall:
	rmmod float

