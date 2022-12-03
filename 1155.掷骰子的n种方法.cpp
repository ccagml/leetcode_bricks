/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 * @lcpr version=20603
 *
 * [1155] 掷骰子的N种方法
 *
 * https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (50.14%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 34.6K
 * Testcase Example:  '1\n6\n3'
 *
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
 *
 * 给定三个整数 n ,  k 和 target ，返回可能的方式(从总共 k^n 种方式中)滚动骰子的数量，使正面朝上的数字之和等于 target 。
 *
 * 答案可能很大，你需要对 10^9 + 7 取模 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 1, k = 6, target = 3
 * 输出：1
 * 解释：你扔一个有6张脸的骰子。
 * 得到3的和只有一种方法。
 *
 *
 * 示例 2：
 *
 * 输入：n = 2, k = 6, target = 7
 * 输出：6
 * 解释：你扔两个骰子，每个骰子有6个面。
 * 得到7的和有6种方法1+6 2+5 3+4 4+3 5+2 6+1。
 *
 *
 * 示例 3：
 *
 * 输入：n = 30, k = 30, target = 500
 * 输出：222616187
 * 解释：返回的结果必须是对 10^9 + 7 取模。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
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
    int numRollsToTarget(int n, int k, int target)
    {
        // i次点数为j的方法
        vector<vector<long long>> vvll(n, vector<long long>(target + 1, 0));
        int mod = 1e9 + 7;
        for (int nn = 0; nn < n; nn++)
        {
            int big = k * (nn + 1);
            int small = (nn + 1);
            for (int kk = 1; kk <= k; kk++)
            {
                if (nn == 0)
                {
                    if (kk <= target)
                    {
                        vvll[nn][kk] = 1;
                    }
                }
                else
                {
                    for (int jj = min(big, target); jj >= small; jj--)
                    {
                        if (jj - kk < 0)
                        {
                            break;
                        }
                        vvll[nn][jj] += vvll[nn - 1][jj - kk];
                        vvll[nn][jj] %= mod;
                    }
                }
            }
            // for (int jj = min(big, target); jj >= small; jj--)
            // {
            //     std::cout << "(投" << nn + 1 << "凑出:" << jj << "=" << vvll[nn][jj] << ")";
            // }
        }
        return vvll[n - 1][target];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n7\n
// @lcpr case=end

// @lcpr case=start
// 30\n30\n500\n
// @lcpr case=end

 */
