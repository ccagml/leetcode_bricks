/*
 * @lc app=leetcode.cn id=790 lang=cpp
 * @lcpr version=21113
 *
 * [790] 多米诺和托米诺平铺
 *
 * https://leetcode.cn/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (56.84%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    24.5K
 * Total Submissions: 43.1K
 * Testcase Example:  '3'
 *
 * 有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。
 *
 *
 *
 * 给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 10^9 + 7 取模 的值。
 *
 * 平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: n = 3
 * 输出: 5
 * 解释: 五种不同的方法如上所示。
 *
 *
 * 示例 2:
 *
 * 输入: n = 1
 * 输出: 1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
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
    int numTilings(int n)
    {
        int mod = 1e9 + 7;
        vector<vector<int>> vvi(n + 3, vector<int>(n + 3));
        // 铺满vvi[i][j] 铺满 i跟j的最多方法数
        vvi[0][0] = 1;
        vvi[0][1] = 1;
        vvi[1][0] = 1;
        vvi[1][1] = 2;
        for (int i = 2; i < n; i++)
        {
            // 铺满 vvi[i][i]
            // 1加竖
            vvi[i][i] += vvi[i - 1][i - 1];
            vvi[i][i] %= mod;

            // 两横
            vvi[i][i] += vvi[i - 2][i - 2];
            vvi[i][i] %= mod;
            // 上2下1
            vvi[i][i] += vvi[i - 2][i - 1];
            vvi[i][i] %= mod;
            // 上1下2
            vvi[i][i] += vvi[i - 1][i - 2];
            vvi[i][i] %= mod;

            vvi[i][i - 1] += vvi[i - 2][i - 2];
            vvi[i][i - 1] %= mod;
            vvi[i - 1][i] += vvi[i - 2][i - 2];
            vvi[i - 1][i] %= mod;

            vvi[i][i - 1] += vvi[i - 1][i - 2];
            vvi[i][i - 1] %= mod;
            vvi[i - 1][i] += vvi[i - 2][i - 1];
            vvi[i - 1][i] %= mod;

            // vvi[i][i + 1] += vvi[i - 1][i - 1];
            // vvi[i + 1][i] += vvi[i - 1][i - 1];

            // // 加下横
            // vvi[i][i + 1] += vvi[i][i - 1];
            // vvi[i + 1][i] += vvi[i - 1][i];
        }
        return vvi[n - 1][n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
