// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=518 lang=cpp
 * @lcpr version=21907
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode.cn/problems/coin-change-ii/description/
 *
 * algorithms
 * Medium (70.31%)
 * Likes:    1059
 * Dislikes: 0
 * Total Accepted:    235.2K
 * Total Submissions: 334.3K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 *
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 *
 * 假设每一种面额的硬币有无限个。 
 *
 * 题目数据保证结果符合 32 位带符号整数。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 * 示例 2：
 *
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 *
 *
 * 示例 3：
 *
 * 输入：amount = 10, coins = [10]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * coins 中的所有值 互不相同
 * 0 <= amount <= 5000
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
    int change(int amount, vector<int> &coins)
    {
        vector<int> vi(amount + 1);
        vi[0] = 1;
        for (int c : coins)
        {
            for (int pri = c; pri <= amount; pri++)
            {
                vi[pri] = vi[pri] + (vi[pri - c]);
            }
        }
        return vi[amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n[1, 2, 5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[2]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[10]\n
// @lcpr case=end

 */
