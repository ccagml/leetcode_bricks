/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=21504
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (67.68%)
 * Likes:    1668
 * Dislikes: 0
 * Total Accepted:    564.1K
 * Total Submissions: 833.5K
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 示例 1：
 *
 * 输入：m = 3, n = 7
 * 输出：28
 *
 * 示例 2：
 *
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 *
 *
 * 示例 3：
 *
 * 输入：m = 7, n = 3
 * 输出：28
 *
 *
 * 示例 4：
 *
 * 输入：m = 3, n = 3
 * 输出：6
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int y = m;
        int x = n;
        vector<vector<int>> temp(y, vector<int>(x, 0));
        temp[0][0] = 1;
        for (int yy = 0; yy < y; yy++)
        {
            temp[yy][0] = 1;
        }
        for (int xxx = 0; xxx < x; xxx++)
        {
            temp[0][xxx] = 1;
        }
        for (int yy = 1; yy < y; yy++)
        {
            for (int xx = 1; xx < x; xx++)
            {
                temp[yy][xx] = temp[yy - 1][xx] + temp[yy][xx - 1];
            }
        }
        return temp[y - 1][x - 1];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */
