while [ true ] 
do
    echo $(date +"%M")
    arg=$(./passwd.sh) && ./crack_en $arg
    sleep 60
done
