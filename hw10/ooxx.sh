#!/bin/bash
if [ $# -eq 1 ]; then
	for i in `seq 1 5`;
	do
		echo The $i round:

		echo -n "$1" > /sys/bus/usb/drivers/usb/unbind
		tree /sys/bus/usb/drivers/usb
		echo Device is unbinded.

		echo -n "$1" > /sys/bus/usb/drivers/usb/bind
		tree /sys/bus/usb/drivers/usb
		echo Device is binded.
	done    
else
	echo Usage: bash $0 BusID
fi


