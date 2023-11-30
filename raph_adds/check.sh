while [ true ] 
do
    echo $(date +"%M")
    arg=$(./passwd.sh) && ./my_crackme $arg
    sleep 60
done
