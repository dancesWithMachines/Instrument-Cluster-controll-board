#!/bin/bash
stty 9600 < /dev/ttyUSB0
while true
do
	SPEED=$((1 + RANDOM % 250))
	RPM=$((1 + RANDOM % 5000))
	TEMP=$((1 + RANDOM % 120))
	FUEL=$((1 + RANDOM % 100))
	echo -e "$RPM;$SPEED;$TEMP;$FUEL;" > /dev/ttyUSB0
	echo "$SPEED;$RPM;$TEMP;$FUEL;"
	sleep 5
done


