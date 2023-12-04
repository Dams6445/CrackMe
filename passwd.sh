minute=$(date +"%M") && ascii1=$(printf "\\$(printf "%o" "$((${minute#0} + 0x20))")") && ascii2=$(printf "\\$(printf "%o" "$((${minute#0} + 0x43))")") && echo "crack_en$ascii1$HOME$ascii2"

# Ne fonctionne qu'avec bash et "./"