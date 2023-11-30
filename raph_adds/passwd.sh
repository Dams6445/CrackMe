minute=$(date +"%M") && hex1=$(printf "%x\n" "$((${minute#0} + 0x20))") && hex2=$(printf "%x\n" "$((${minute#0} + 0x43))") && echo -e "crack_en\x$hex1$HOME\x$hex2"

# Ne fonctionne qu'avec bash et "./"