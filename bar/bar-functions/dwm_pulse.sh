#!/bin/sh

# A dwm_bar function to show the master volume of PulseAudio
# Joe Standring <git@joestandring.com>
# GNU GPLv3

# Dependencies: pamixer, pactl

DARK="#4c566a"   # Dark color for the icons (background)
WHITE="#e5e9f0"  # White color for the volume percentage
GREEN="#89b482"

dwm_pulse () {
    VOL=$(pamixer --get-volume)
    STATE=$(pamixer --get-mute)

    # Check if audio jack is connected
    JACK_STATUS=$(pactl list sinks | grep 'Active Port' | grep -i 'analog-output-headphones')

    if [ -n "$JACK_STATUS" ]; then
        # Headphone is connected, display volume percentage with headphone icon
        if [ "$IDENTIFIER" = "unicode" ]; then
            if [ "$STATE" = "true" ] || [ "$VOL" -eq 0 ]; then
                printf " ^c$DARK^󰟎 ^c$WHITE^Muted ^d^ " # Muted icon with headphone icon
            elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 33 ]; then
                printf " ^c$GREEN^󰋋 ^c$WHITE^%s%% ^d^ " "$VOL" # Low volume icon with headphone icon
            elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 66 ]; then
                printf " ^c$GREEN^󰋋 ^c$WHITE^%s%% ^d^ " "$VOL" # Medium volume icon with headphone icon
            else
                printf " ^c$GREEN^󰋋 ^c$WHITE^%s%% ^d^ " "$VOL" # High volume icon with headphone icon
            fi
        else
            if [ "$STATE" = "true" ] || [ "$VOL" -eq 0 ]; then
                printf "MUTE Headphones connected"
            else
                printf "VOL %s%% Headphones connected" "$VOL"
            fi
        fi
    else
        # Headphone is not connected, display the volume icon
        if [ "$IDENTIFIER" = "unicode" ]; then
            if [ "$STATE" = "true" ] || [ "$VOL" -eq 0 ]; then
                printf " ^c$DARK^󰖁 ^c$WHITE^Muted ^d^ " # Muted icon
            elif [ "$VOL" -gt 0 ] && [ "$VOL" -le 33 ]; then
                printf " ^c$GREEN^󰕿 ^c$WHITE^%s%% ^d^ " "$VOL" # Low volume icon
            elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 66 ]; then
                printf " ^c$GREEN^󰖀 ^c$WHITE^%s%% ^d^ " "$VOL" # Medium volume icon
            else
                printf " ^c$GREEN^󰕾 ^c$WHITE^%s%% ^d^ " "$VOL" # High volume icon
            fi
        else
            if [ "$STATE" = "true" ] || [ "$VOL" -eq 0 ]; then
                printf "MUTE"
            else
                printf "VOL %s%%" "$VOL"
            fi
        fi
    fi
    #printf "%s\n" #"$SEP2"
}

dwm_pulse

