#!/bin/sh

# A dwm_bar module to display the current backlight brighness with xbacklight
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: xbacklight

RED="#bf616a"

dwm_backlight () {
     # printf " ^c$RED^%s󰃟 %.0f%s ^d^ " "$SEP1" "$(light -G)" #"$SEP2"
	   LIGHT=$(printf "%.0f\n" `light -G`)

	if [[ ("$LIGHT" -ge "0") && ("$LIGHT" -le "25") ]]; then
		printf "^c#bf616a^  $LIGHT%% "
	elif [[ ("$LIGHT" -ge "25") && ("$LIGHT" -le "50") ]]; then
		printf "^c#bf616a^  $LIGHT%% "
	elif [[ ("$LIGHT" -ge "50") && ("$LIGHT" -le "75") ]]; then
		printf "^c#bf616a^  $LIGHT%% "
	elif [[ ("$LIGHT" -ge "75") && ("$LIGHT" -le "100") ]]; then
		printf "^c#bf616a^  $LIGHT%% "
	fi
}

dwm_backlight
