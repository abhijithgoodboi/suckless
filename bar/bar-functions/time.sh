#!/bin/bash

# Prints out the time

BLUE="#81a1c1"
GREEN="#a3be8c"

PREFIX=''

get_time()
{
    echo "  ^c$BLUE^$PREFIX^d^ ^c$GREEN^$(date '+%H:%M:%S') ^d^"
}

get_time
