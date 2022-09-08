find ./ |grep $1

a=`find ./ | grep question | awk -F "/" '{print $NF}' | awk -F "_" '{print $2}' | awk -F "." '{print $1}' |sort | uniq | wc -l`
echo "$(tput setaf 2)已经做了"$(tput setaf 1) ${a}$(tput setaf 2)  "题(去重)"