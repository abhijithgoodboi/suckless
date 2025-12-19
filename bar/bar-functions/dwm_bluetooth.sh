#!/bin/sh

# A dwm_bar function to show Bluetooth connection status
# Dependencies: bluetoothctl

GREEN="#8fbcbb"
BLUE="#81a1c1"
DARK="#4c566a"


dwm_bluetooth () {
    # Check if Bluetooth is powered on
    BT_POWER=$(bluetoothctl show | grep "Powered: yes")

    if [ -z "$BT_POWER" ]; then
        # Bluetooth is off
        printf "^c$DARK^󰂲 Bluetooth off ^d^ "
    else
        # Check if any Bluetooth device is connected
        BT_DEVICE=$(bluetoothctl info | grep "Name:" | awk '{print substr($0, index($0,$2))}') 
        BT_STATUS=$(bluetoothctl devices Connected | grep "Device")

        if [ -n "$BT_STATUS" ]; then
            printf "^c$GREEN^󰂱 %s ^d^ " "^c$BLUE^$BT_DEVICE ^d^ "  # Icon for connected
        else
            printf "^c$DARK^ NC ^d^  "  # Icon for disconnected
        fi
    fi
    #printf "%s\n" "$SEP2"
}

dwm_bluetooth

