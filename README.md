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
# 备忘


1

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

## [652.寻找重复的子树](https://leetcode.cn/problems/find-duplicate-subtrees/description/)
### 反思
- 思路不对 原本以为会相同层比较,结果需要序列化成字符串比较,不是同层比较
### 时间
- 22.09.05

## [667.优美的排列 II](https://leetcode.cn/problems/k-th-symbol-in-grammar/description/)
### 反思
- 构造的思路不一样, 都想到可能需要 一个前一个后来控制差值
### 时间
- 22.09.05

## [761.特殊的二进制序列](https://leetcode.cn/problems/special-binary-string/description/)
### 反思
1. 看题目觉得可能是动态规划, 看着交换规则看不出递推式
2. 按照题目的规则, 每个部分一定是 1开头 0结尾
3. 从题目看不出是要分治,然后每个小部分可以交换(题目的规则是前后相等才能交换)
4. 从3看 如果 首位的1可以交换来, 那么 就是 0xxxy1 1yyyy0交换的情况, 那么他们本身就可以拆分成2个子结构
5. 因为我们的每一个子串都是 1开头 0结尾,  （两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)
6. 所以可以直接排序
### 时间
- 22.09.05

## [779.第K个语法符号](https://leetcode.cn/problems/k-th-symbol-in-grammar/description/)
### 反思
- 通过规律可以看出是不断在翻转
- 没想到可以用递归,每一层往下计算就行
### 时间
- 22.10.20

## [828.统计子串中的唯一字符](https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/)
### 反思
1. 想到第一步 应该是需要 按 字符 的位置插入 不同的vector
1. 想不到第二步, 每个字符对 子字符串的贡献 是 上一个 到本字符  跟 本字符到下一个的乘积
### 时间
- 22.09.05

## [2328.网格图中递增路径的数目](https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/description/)
### 反思
1. 思考1: 把每个格子的数值从小到大分类
1. 思考2: 根据数值大小开始收集(这样能保证比我小的已经算完了)
### 时间
- 22.10.20

## [2435.矩阵中和能被 K 整除的路径](https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/)
### 反思
1. 看题目是普通的动态规划,可能是每个格子需要一个长度k的vector存余数数据的数量
1. 在+的时候 可以直接对结果 % (1e9 + 7),这样不需要long long, long long也无法通过所有用例
1. 结果直接返回余数0的部分就行了,这点弄了很久
### 时间
- 22.10.20