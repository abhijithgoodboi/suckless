#!/bin/bash


# Nord color scheme
GREEN="#a3be8c"  # Battery 100%-20%
YELLOW="#ebcb8b"  # Charging below 90%
RED="#bf616a"  # Battery below 20%
BLUE="#81a1c1"


# Prints out battery percentage

CHARGING_ICON='   '
BATTERY_FULL_ICON='   '

BATTERY_1_ICON='   '
BATTERY_2_ICON='   '
BATTERY_3_ICON='   '
BATTERY_4_ICON='   '
BATTERY_5_ICON='   '

FULL_AT=100

BAT_ICON=""
ICON=""

get_battery()
{
	# The vast majority of people only use one battery.

	if [ -d /sys/class/power_supply/BAT1 ]; then
		capacity=$(cat /sys/class/power_supply/BAT1/capacity)
		charging=$(cat /sys/class/power_supply/BAT1/status)
    
     # Set the icon based on battery percentage
    if [[ "$charging" == "Charging" ]]; then
        COLOR="$BLUE" ICON="$CHARGING_ICON"
    elif [[ "$charging" == "Charging" && $capacity == 100 ]]; then
        COLOR="$RED" ICON="$BATTERY_FULL_ICON"
    fi

if [[ $capacity == 100 ]]; then
    COLOR="$GREEN" BAT_ICON=$BATTERY_FULL_ICON
  elif [[ $charging != "Charging" ]]; then
    if [[ $capacity -ge 0 && $capacity -le 20 ]]; then
      COLOR="$RED" BAT_ICON=$BATTERY_1_ICON
    elif [[ $capacity -ge 20 && $capacity -le 40 ]]; then
      COLOR="$GREEN" BAT_ICON=$BATTERY_2_ICON
    elif [[ $capacity -ge 40 && $capacity -le 60 ]]; then
      COLOR="$GREEN" BAT_ICON=$BATTERY_3_ICON
    elif [[ $capacity -ge 60 && $capacity -le 80 ]]; then
      COLOR="$GREEN" BAT_ICON=$BATTERY_4_ICON
    elif [[ $capacity -ge 80 && $capacity -le 100 ]]; then
      COLOR="$GREEN" BAT_ICON=$BATTERY_5_ICON

    fi
fi
  if [[ "$charging" == "Charging" ]]; then
    echo "  ^c$COLOR^$ICON $capacity% ^d^"
else
  echo "  ^c$COLOR^$BAT_ICON $capacity% ^d^"
fi

fi

}


get_battery
