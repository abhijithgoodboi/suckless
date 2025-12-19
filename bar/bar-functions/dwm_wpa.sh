# #!/bin/bash
#
# black="#2E3440"
# #green="#A3BE8C"
# #white=#D8DEE9
# #grey=#373d49
# blue="#81A1C1"
# #red=#BF616A
# darkblue="#7292b2"
#
#
# # WiFi icons
# WIFI_CONNECTED_ICON=''
# WIFI_DISCONNECTED_ICON=' 睊'
#
# # Function to get WiFi status
# get_wifi() {
#     # Check if wireless interface is available
#     if [[ -e "/sys/class/net/wlan0/operstate" ]]; then
#         # Get the operational status of wireless interface
#         wifi_status=$(cat /sys/class/net/wlan0/operstate)
#         if [[ "$wifi_status" == "up" ]]; then
#             # Get the connected WiFi name
#             wifi_name=$(iwgetid -r)
#             echo "^c$black^^b$blue^ $WIFI_CONNECTED_ICON ^d^" "^c$blue^$wifi_name "   
#         else
#             echo " ^c$black^ ^b$blue^ $WIFI_DISCONNECTED_ICON ^d^ " "^c$blue^Disconnected " 
#         fi
#     else
#         # Wireless interface not found
#         echo " ^c$RED^$WIFI_DISCONNECTED_ICON ^d^ " 
#     fi
# }
#
# # Call the function to get WiFi status
# get_wifi


#!/bin/bash


. ~/suckless/bar/themes/onedark
# Nord Color Scheme
# black="#2E3440"
# blue="#81A1C1"
# white="#D8DEE9"
# red="#BF616A"

# WiFi Signal Icons (Font Awesome or Nerd Font)
WIFI_FULL_ICON="󰤨"     # strong
WIFI_MID_ICON="󰤥"      # medium
WIFI_LOW_ICON="󰤟"      # weak
WIFI_DISCONNECTED_ICON="󰤭"  # disconnected

# Function to get WiFi signal icon based on quality %
get_wifi_icon() {
    percentage=$(grep "^\s*w" /proc/net/wireless | awk '{ print int($3 * 100 / 70) }')
    
    if (( percentage >= 70 )); then
        echo "$WIFI_FULL_ICON"
    elif (( percentage >= 30 )); then
        echo "$WIFI_MID_ICON"
    elif (( percentage >= 1 )); then
        echo "$WIFI_LOW_ICON"
    else
        echo "$WIFI_DISCONNECTED_ICON"
    fi
}

# Function to get WiFi status
get_wifi() {
    # Detect wireless interface dynamically (e.g., wlan0 or wlp*)
    iface=$(ls /sys/class/net | grep -E '^wl')

    if [[ -n "$iface" && -e "/sys/class/net/$iface/operstate" ]]; then
        status=$(cat /sys/class/net/$iface/operstate)
        if [[ "$status" == "up" ]]; then
            ssid=$(iwgetid -r)
            icon=$(get_wifi_icon)
            echo "^c$black^^b$blue^ $icon ^d^ ^c$blue^$ssid^d^"
        else
            echo "^c$black^^b$red^ $WIFI_DISCONNECTED_ICON ^d^ ^c$red^Disconnected^d^"
        fi
    else
        echo "^c$black^^b$red^ $WIFI_DISCONNECTED_ICON ^d^ ^c$red^No WiFi Interface^d^"
    fi
}

# Call the function
get_wifi

