#!/bin/sh

# Prints out battery percentage

CHARGING_ICON=' '
WARNING_ICON=' '
BATTERY_FULL_ICON=''
BATTERY_2_ICON=''
BATTERY_3_ICON=''
BATTERY_4_ICON=''

FULL_AT=98

BAT_ICON=""
ICON=""



# A dwm_bar function to read the battery level and status
# Joe Standring <git@joestandring.com>
# GNU GPLv3

dwm_battery () {
    # Change BAT1 to whatever your battery is identified as. Typically BAT0 or BAT1
    if [ -d /sys/class/power_supply/BAT1 ]; then
		capacity=$(cat /sys/class/power_supply/BAT1/capacity)
		charging=$(cat /sys/class/power_supply/BAT1/status)
		if [[ "$charging" == "Charging" ]]; then
			ICON="$CHARGING_ICON"
		elif [[ $capacity -le 20 ]]; then
			ICON="$WARNING_ICON"
		fi

		if [[ $capacity -ge $FULL_AT ]]; then
			BAT_ICON=$BATTERY_FULL_ICON
		elif [[ $capacity -le 25 ]]; then
			BAT_ICON=$BATTERY_4_ICON
		elif [[ $capacity -le 60 ]]; then
			BAT_ICON=$BATTERY_3_ICON
		elif [[ $capacity -le $FULL_AT ]]; then
			BAT_ICON=$BATTERY_2_ICON
		fi
	fi
	echo "$ICON$BAT_ICON $capacity%"
       printf "%s\n" "$SEP2"
}

dwm_battery

