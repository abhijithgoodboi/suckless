#!/bin/bash

# Prints out the date

#YELLOW="#ebcb8b"
#BLUE="#81a1c1"

black="#2E3440"
#GREEN="#A3BE8C"
#WHITE="#D8DEE9"
#GREY="#373d49"
blue="#81A1C1"
#red=#BF616A
darkblue="#7292b2"

#PREFIX=''

get_date()
{
  printf "^c$black^ ^b$darkblue^ 󱑆 "
	printf "^c$black^^b$blue^ $(date '+%a, %H:%M:%S') ^d^"
  #  echo "  ^c$YELLOW^ ^d^^c$BLUE^$(date '+%d-%m-%y') ^d^  "
}



get_date
