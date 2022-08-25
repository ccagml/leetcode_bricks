
for file in `ls | grep question`
do
    if test -f $file
    then
        if [ $1 == "s" ]; 
        then
            
            mv $file "simple"
        elif [ $1 == "se" ]; 
        then
            
            mv $file "simple_error"
        elif [ $1 == "m" ]; 
        then
            
            mv $file "medium"
        elif [ $1 == "h" ]; 
        then
            
            mv $file "hard"
        fi
    fi
done