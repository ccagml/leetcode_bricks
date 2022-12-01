/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=20601
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.15%)
 * Likes:    2211
 * Dislikes: 0
 * Total Accepted:    555.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
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
    // 完全背包 外n内 正t, t >= n[i]
    int coinChange(vector<int> &coins, int amount)
    {
        vector<long long> vll(amount + 1, 9999999);
        vll[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (coins[i] <= j)
                {
                    vll[j] = min(vll[j], vll[j - coins[i]] + 1);
                }
            }
        }
        return vll[amount] == 9999999 ? -1 : vll[amount];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
