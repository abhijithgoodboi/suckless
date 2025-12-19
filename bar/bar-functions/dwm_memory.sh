mem_info() {
	printf " ^c#81A1C1^^b#2E3440^  ^c#81A1C1^$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g) "
}

mem_info
