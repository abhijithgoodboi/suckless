#!/bin/bash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
. ~/suckless/bar/themes/decayce

cpu() {
  cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)
  printf "^c$black^ ^b$green^ CPU"
  printf "^c$white^ ^b$grey^ $cpu_val"
}

CHARGING_ICON='   '
BATTERY_FULL_ICON='   '
BATTERY_1_ICON='   '
BATTERY_2_ICON='   '
BATTERY_3_ICON='   '
BATTERY_4_ICON='   '
BATTERY_5_ICON='   '

get_battery() {
  COLOR="$white"
  ICON=""
  BAT_ICON=""

  if [ -d /sys/class/power_supply/BAT1 ]; then
    capacity=$(cat /sys/class/power_supply/BAT1/capacity)
    charging=$(cat /sys/class/power_supply/BAT1/status)

    if [[ "$charging" == "Charging" && $capacity -lt 100 ]]; then
      COLOR="$blue"
      ICON="$CHARGING_ICON"
    elif [[ "$charging" == "Charging" && $capacity -eq 100 ]]; then
      COLOR="$red"
      BAT_ICON="$BATTERY_FULL_ICON"
    fi

    if [[ "$charging" != "Charging" ]]; then
      if (( capacity <= 20 )); then
        COLOR="$red"
        BAT_ICON="$BATTERY_1_ICON"
      elif (( capacity <= 40 )); then
        COLOR="$green"
        BAT_ICON="$BATTERY_2_ICON"
      elif (( capacity <= 60 )); then
        COLOR="$green"
        BAT_ICON="$BATTERY_3_ICON"
      elif (( capacity <= 80 )); then
        COLOR="$green"
        BAT_ICON="$BATTERY_4_ICON"
      else
        COLOR="$green"
        BAT_ICON="$BATTERY_5_ICON"
      fi
    fi

    if [[ "$charging" == "Charging" && $capacity -lt 100 ]]; then
      echo "^c$COLOR^$ICON $capacity%^d^"
    else
      echo "^c$COLOR^$BAT_ICON $capacity%^d^"
    fi
  fi
}




get_bluetooth() {
  DEVICE=$(upower -e | grep -i "headset\|bluetooth" | head -n 1)

  if [ -n "$DEVICE" ]; then
    PERCENT=$(upower -i "$DEVICE" | awk '/percentage/ {print $2}' | tr -d '%')
    NAME=$(upower -i "$DEVICE" | awk -F: '/model/ {print $2}' | xargs)

    if [ -n "$PERCENT" ]; then
      if [ "$PERCENT" -ge 80 ]; then
        color=$green     # High battery
      elif [ "$PERCENT" -ge 40 ]; then
        color=$blue      # Medium battery
      elif [ "$PERCENT" -ge 20 ]; then
        color=$darkblue  # Low-mid battery
      else
        color=$red       # Critical battery
      fi

      printf "^c$color^  %s%%" "$PERCENT" #"$NAME"
    fi
  fi
}




get_backlight() {
  LIGHT=$(printf "%.0f\n" $(light -G))
  if (( LIGHT <= 25 )); then
    printf "^c$red^  $LIGHT%%"
  elif (( LIGHT <= 50 )); then
    printf "^c$red^  $LIGHT%%"
  elif (( LIGHT <= 75 )); then
    printf "^c$red^  $LIGHT%%"
  else
    printf "^c$red^  $LIGHT%%"
  fi
}

mem_info() {
  mem_used=$(free -h | awk '/^Mem/ { print $3 }' | sed 's/i//g')
  printf "^c$blue^^b$black^  ^c$blue^$mem_used"
}

WIFI_FULL_ICON="󰤨"
WIFI_MID_ICON="󰤥"
WIFI_LOW_ICON="󰤟"
WIFI_DISCONNECTED_ICON="󰤭"

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

get_wifi() {
  iface=$(ls /sys/class/net | grep -E '^wl' | head -n 1)
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

get_date() {
  printf "^c$black^ ^b$darkblue^ 󱑆 "
  printf "^c$black^^b$blue^ $(date '+%a [%b %d], %H:%M') ^d^"
}

while true; do
    output="$(get_battery) $(get_backlight) $(get_bluetooth) $(cpu) $(mem_info) $(get_wifi) $(get_date)"
  xsetroot -name "$output"
  sleep 1
  interval=$((interval + 1))
done

