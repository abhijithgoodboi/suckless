cpu_info() {
	cpu_load=$(grep -o "^[^ ]*" /proc/loadavg)

	printf "^c#3b414d^ ^b#7ec7a2^ CPU"
	printf "^c#abb2bf^ ^b#353b45^ $cpu_load"
}

cpu_info
