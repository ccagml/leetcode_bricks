/*
 * @lc app=leetcode.cn id=2571 lang=cpp
 * @lcpr version=21704
 *
 * [2571] 将整数减少到零需要的最少操作数
 *
 * https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0/description/
 *
 * algorithms
 * Medium (49.20%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 8.7K
 * Testcase Example:  '39'
 *
 * 给你一个正整数 n ，你可以执行下述操作 任意 次：
 *
 *
 * n 加上或减去 2 的某个 幂
 *
 *
 * 返回使 n 等于 0 需要执行的 最少 操作数。
 *
 * 如果 x == 2^i 且其中 i >= 0 ，则数字 x 是 2 的幂。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 39
 * 输出：3
 * 解释：我们可以执行下述操作：
 * - n 加上 2^0 = 1 ，得到 n = 40 。
 * - n 减去 2^3 = 8 ，得到 n = 32 。
 * - n 减去 2^5 = 32 ，得到 n = 0 。
 * 可以证明使 n 等于 0 需要执行的最少操作数是 3 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 54
 * 输出：3
 * 解释：我们可以执行下述操作：
 * - n 加上 2^1 = 2 ，得到 n = 56 。
 * - n 加上 2^3 = 8 ，得到 n = 64 。
 * - n 减去 2^6 = 64 ，得到 n = 0 。
 * 使 n 等于 0 需要执行的最少操作数是 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
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
    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    int minOperations(int n)
    {

        return result;
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
// 39\n
// @lcpr case=end

// @lcpr case=start
// 54\n
// @lcpr case=end
// @lcpr case=start
// 7862\n
// @lcpr case=end

 */
