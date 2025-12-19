#!/bin/sh

# A dwm_bar function that shows the current date and time
# Joe Standring <git@joestandring.com>
# GNU GPLv3

YELLOW="#ebcb8b"
BLUE="#81a1c1"

# Date is formatted like like this: "[Mon 01-01-00 00:00:00]"
dwm_date () {
#    printf "%s" "$SEP1"
    if [ "$IDENTIFIER" = "unicode" ]; then
        printf "^c$YELLOW %s ^d^" "^c$BLUE^$(date "+%a %d-%m-%y %T") ^d^ "
    else
        printf "DAT %s" "$(date "+%a %d-%m-%y %T")"
    fi
    #printf "%s\n" "$SEP2"
}

dwm_date
