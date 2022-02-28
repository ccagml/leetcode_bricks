function rand(){
    min=$1
    max=$(($2-$min+1))
    num=$(cat /dev/urandom | head -n 10 | cksum | awk -F ' ' '{print $1}')
    echo $(($num%$max+$min))
}

sudo service ntp stop
start_date=20220301
end_date=20220310
start_sec=`date -d "$start_date" "+%s"`
end_sec=`date -d "$end_date" "+%s"`
for((i=start_sec;i<=end_sec;i+=86400)); do
    day=$(date -d "@$i" "+%Y-%m-%d")
    rnd=$(rand 0 2)
    sudo date -s ${day}
    echo $day $rnd
    for((j=0;j<rnd;j++));do
        echo $day  $rnd >> $day.cpp
        git add .
        git commit -m "add"
    done
done
sudo service ntp start