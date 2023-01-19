/*
 * @lc app=leetcode.cn id=2538 lang=cpp
 * @lcpr version=21113
 *
 * [2538] 最大价值和与最小价值和的差值
 *
 * https://leetcode.cn/problems/difference-between-maximum-and-minimum-price-sum/description/
 *
 * algorithms
 * Hard (45.64%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    2.1K
 * Total Submissions: 4.5K
 * Testcase Example:  '6\n[[0,1],[1,2],[1,3],[3,4],[3,5]]\n[9,8,7,6,10,5]'
 *
 * 给你一个 n 个节点的无向无根图，节点编号为 0 到 n - 1 。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中
 * edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。
 *
 * 每个节点都有一个价值。给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价值。
 *
 * 一条路径的 价值和 是这条路径上所有节点的价值之和。
 *
 * 你可以选择树中任意一个节点作为根节点 root 。选择 root 为根的 开销 是以 root 为起点的所有路径中，价值和
 * 最大的一条路径与最小的一条路径的差值。
 *
 * 请你返回所有节点作为根节点的选择中，最大 的 开销 为多少。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
 * 输出：24
 * 解释：上图展示了以节点 2 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
 * - 第一条路径节点为 [2,1,3,4]：价值为 [7,8,6,10] ，价值和为 31 。
 * - 第二条路径节点为 [2] ，价值为 [7] 。
 * 最大路径和与最小路径和的差值为 24 。24 是所有方案中的最大开销。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
 * 输出：2
 * 解释：上图展示了以节点 0 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
 * - 第一条路径包含节点 [0,1,2]：价值为 [1,1,1] ，价值和为 3 。
 * - 第二条路径节点为 [0] ，价值为 [1] 。
 * 最大路径和与最小路径和的差值为 2 。2 是所有方案中的最大开销。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * 0 <= ai, bi <= n - 1
 * edges 表示一棵符合题面要求的树。
 * price.length == n
 * 1 <= price[i] <= 10^5
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
    long long result;

public:
    pair<long long, long long> dfs(int cur, int fa, vector<int> &price, vector<vector<int>> &g)
    {
        int cur_price = price[cur];
        long long max_s1 = cur_price;
        long long max_s2 = 0;
        for (int next : g[cur])
        {
            if (next != fa)
            {

                auto son = dfs(next, cur, price, g);
                result = max(result, max(max_s1 + son.second, max_s2 + son.first));

                max_s1 = max(max_s1, son.first + cur_price);
                max_s2 = max(max_s2, son.second + cur_price);
            }
        }
        return {max_s1, max_s2};
    }

    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price)
    {
        result = 0;
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }
        dfs(0, -1, price, g);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 6\n[[0,1],[1,2],[1,3],[3,4],[3,5]]\n[9,8,7,6,10,5]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[0,1],[1,2]]\n[1,1,1]\n
// @lcpr case=end

 */
