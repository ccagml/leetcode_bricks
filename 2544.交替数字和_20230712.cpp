/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 * @lcpr version=21909
 *
 * [2544] 交替数字和
 *
 * https://leetcode.cn/problems/alternating-digit-sum/description/
 *
 * algorithms
 * Easy (79.81%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 27.7K
 * Testcase Example:  '521'
 *
 * 给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：
 *
 *
 * 最高有效位 上的数字分配到 正 号。
 * 剩余每位上数字的符号都与其相邻数字相反。
 *
 *
 * 返回所有数字及其对应符号的和。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 521
 * 输出：4
 * 解释：(+5) + (-2) + (+1) = 4
 *
 * 示例 2：
 *
 * 输入：n = 111
 * 输出：1
 * 解释：(+1) + (-1) + (+1) = 1
 *
 *
 * 示例 3：
 *
 * 输入：n = 886996
 * 输出：0
 * 解释：(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^9
 *
 *
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
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
    int alternateDigitSum(int n)
    {
        int result = 0;
        string nn = std::to_string(n);
        for (int i = 0; i < nn.size(); i++)
        {
            int j = nn[i] - '0';
            result += (i % 2 == 0) ? j : -j;
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 521\n
// @lcpr case=end

// @lcpr case=start
// 111\n
// @lcpr case=end

// @lcpr case=start
// 886996\n
// @lcpr case=end

 */
