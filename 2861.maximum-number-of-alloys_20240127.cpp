// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 * @lcpr version=30113
 *
 * [2861] 最大合金数
 *
 * https://leetcode.cn/problems/maximum-number-of-alloys/description/
 *
 * algorithms
 * Medium (34.57%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 22.1K
 * Testcase Example:  '3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]'
 *
 * 假设你是一家合金制造公司的老板，你的公司使用多种金属来制造合金。现在共有 n 种不同类型的金属可以使用，并且你可以使用 k
 * 台机器来制造合金。每台机器都需要特定数量的每种金属来创建合金。
 *
 * 对于第 i 台机器而言，创建合金需要 composition[i][j] 份 j 类型金属。最初，你拥有 stock[i] 份 i
 * 类型金属，而每购入一份 i 类型金属需要花费 cost[i] 的金钱。
 *
 * 给你整数 n、k、budget，下标从 1 开始的二维数组 composition，两个下标从 1 开始的数组 stock 和
 * cost，请你在预算不超过 budget 金钱的前提下，最大化 公司制造合金的数量。
 *
 * 所有合金都需要由同一台机器制造。
 *
 * 返回公司可以制造的最大合金数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock =
 * [0,0,0], cost = [1,2,3]
 * 输出：2
 * 解释：最优的方法是使用第 1 台机器来制造合金。
 * 要想制造 2 份合金，我们需要购买：
 * - 2 份第 1 类金属。
 * - 2 份第 2 类金属。
 * - 2 份第 3 类金属。
 * 总共需要 2 * 1 + 2 * 2 + 2 * 3 = 12 的金钱，小于等于预算 15 。
 * 注意，我们最开始时候没有任何一类金属，所以必须买齐所有需要的金属。
 * 可以证明在示例条件下最多可以制造 2 份合金。
 *
 *
 * 示例 2：
 *
 * 输入：n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock =
 * [0,0,100], cost = [1,2,3]
 * 输出：5
 * 解释：最优的方法是使用第 2 台机器来制造合金。
 * 要想制造 5 份合金，我们需要购买：
 * - 5 份第 1 类金属。
 * - 5 份第 2 类金属。
 * - 0 份第 3 类金属。
 * 总共需要 5 * 1 + 5 * 2 + 0 * 3 = 15 的金钱，小于等于预算 15 。
 * 可以证明在示例条件下最多可以制造 5 份合金。
 *
 *
 * 示例 3：
 *
 * 输入：n = 2, k = 3, budget = 10, composition = [[2,1],[1,2],[1,1]], stock =
 * [1,1], cost = [5,5]
 * 输出：2
 * 解释：最优的方法是使用第 3 台机器来制造合金。
 * 要想制造 2 份合金，我们需要购买：
 * - 1 份第 1 类金属。
 * - 1 份第 2 类金属。
 * 总共需要 1 * 5 + 1 * 5 = 10 的金钱，小于等于预算 10 。
 * 可以证明在示例条件下最多可以制造 2 份合金。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, k <= 100
 * 0 <= budget <= 10^8
 * composition.length == k
 * composition[i].length == n
 * 1 <= composition[i][j] <= 100
 * stock.length == cost.length == n
 * 0 <= stock[i] <= 10^8
 * 1 <= cost[i] <= 100
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool can_finish(int budget, vector<int> &stock, vector<int> &cost, vector<int> &zhonglei, int need_cnt)
    {
        long long buy = 0;
        for (int j = 0; j < zhonglei.size(); j++)
        {
            long long need_cnt1 = need_cnt;
            long long zlj = zhonglei[j];
            long long jj = zlj * need_cnt1;

            long long need_zhonglei_geshu = jj - stock[j];
            if (need_zhonglei_geshu > 0)
            {
                buy += (need_zhonglei_geshu * cost[j]);
            }
            if (buy > budget)
            {
                return false;
            }
        }
        return buy <= budget;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {

        // 看起来像二分找答案    int left = 0;
        int left = 0;
        int right = 900000000;

        auto check = [&](int need_cnt)
        {
            for (int gongc = 0; gongc < composition.size(); gongc++)
            {
                if (can_finish(budget, stock, cost, composition[gongc], need_cnt))
                {
                    return true;
                }
            }
            return false;
        };

        while (left < right)
        {
            int mid = (left + right + 1) / 2;

            // [left, mid - 1]
            // [mid, right]
            if (check(mid))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxNumberOfAlloys
// paramTypes= ["number","number","number","number[][]","number[]","number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,0]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n15\n[[1,1,1],[1,1,10]]\n[0,0,100]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n10\n[[2,1],[1,2],[1,1]]\n[1,1]\n[5,5]\n
// @lcpr case=end

 */
