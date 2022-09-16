find ./hard |grep $1
find ./medium |grep $1
find ./time_limit |grep $1
find ./simple_time |grep $1
find ./simple |grep $1
find ./simple_error |grep $1
find ./old |grep $1

a=`find ./ | grep question | awk -F "/" '{print $NF}' | awk -F "_" '{print $2}' | awk -F "." '{print $1}' |sort | uniq | wc -l`
echo "$(tput setaf 2)已经做了"$(tput setaf 1) ${a}$(tput setaf 2)  "题(去重)"