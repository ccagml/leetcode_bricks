
for file in `ls | grep question`
do
    if test -f $file
    then
        if [ $1 == "s" ]; 
        then
            
            mv $file "simple"
        elif [ $1 == "s2" ]; 
        then
            
            mv $file "simple_2"
        elif [ $1 == "m" ]; 
        then
            
            mv $file "medium"
        elif [ $1 == "h" ]; 
        then
            
            mv $file "hard"
        fi
    fi
done