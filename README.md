# 文件夹说明
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
# 反思


## [315.计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/)
### 反思
- 范围查询->线段树
- 从右往左找结果, 当要计算右边的值,可以从右到左计算,计算完后在加入线段树.
### 时间
- 22.09.13

## [493.翻转对](https://leetcode.cn/problems/reverse-pairs/description/)
### 反思
- 从后往前找
- 想不到的点: 1离散化:把值按大小顺序排到vector中, 这时候查找的点从值范围变成索引
- 想不到的点: 2 set 的 lower_bound 会比vector 的lower_bound 慢
### 时间
- 22.09.13
- 22.09.19