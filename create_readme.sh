#!/bin/bash
CRTDIR=$(pwd)
echo "# 文件夹说明
- simple 不需要看答案 写完一次通过 秒杀没营养
- simple_time 不需要看答案 可是做了很久(20分钟以上)
- simple_error 不需要看答案 写完有一两个错误用例(说明 思考有处不周的地方 某个测试用例没思考全)
- time_limit 条件反射的解法 时间复杂度不行
- medium 想的有点久的(超过20分钟没思路)/想不出来,需要思路 看完思路可以做
- hard 光思路也不行,有知识点缺失(需要学习)
- old 在分类前做的旧题
- case.md 一些测试用例
- quick_start.cpp 快速掌握一些c++做题需要的基础操作
- makefile 编译quick_cpp.cpp验证结果
- f.sh 查找某一题是否做过?
# 备忘" > README.md

# |awk -F "/" '{print $NF}' | sort -n
a=`ls $CRTDIR/do_think/* | awk -F "/" '{print $NF}' | sort -n`
echo $a
for file in $a
do
    if test -f $CRTDIR/do_think/$file
    then
        echo -e "\n" >> README.md
        cat $CRTDIR/do_think/$file >> README.md
    fi
done