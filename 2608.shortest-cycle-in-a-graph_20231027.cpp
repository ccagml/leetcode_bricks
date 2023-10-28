// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2608 lang=cpp
 * @lcpr version=30102
 *
 * [2608] 图中的最短环
 *
 * https://leetcode.cn/problems/shortest-cycle-in-a-graph/description/
 *
 * algorithms
 * Hard (40.71%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 8.2K
 * Testcase Example:  '7\n[[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]'
 *
 * 现有一个含 n 个顶点的 双向 图，每个顶点按从 0 到 n - 1 标记。图中的边由二维整数数组 edges 表示，其中 edges[i] =
 * [ui, vi] 表示顶点 ui 和 vi 之间存在一条边。每对顶点最多通过一条边连接，并且不存在与自身相连的顶点。
 *
 * 返回图中 最短 环的长度。如果不存在环，则返回 -1 。
 *
 * 环 是指以同一节点开始和结束，并且路径中的每条边仅使用一次。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
 * 输出：3
 * 解释：长度最小的循环是：0 -> 1 -> 2 -> 0
 *
 *
 * 示例 2：
 *
 * 输入：n = 4, edges = [[0,1],[0,2]]
 * 输出：-1
 * 解释：图中不存在循环
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 1000
 * 1 <= edges.length <= 1000
 * edges[i].length == 2
 * 0 <= ui, vi < n
 * ui != vi
 * 不存在重复的边
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    unordered_map<int, vector<int>> uivi;
    int result;

    void check(int i)
    {
        std::queue<pair<int, int>> myQueue;
        unordered_set<int> flag;
        for (int next_i : uivi[i])
        {
            myQueue.push({next_i, i});
        }

        int loop = 1;
        while (myQueue.size() > 0)
        {
            int my_n = myQueue.size();
            for (int mmq = 0; mmq < my_n; mmq++)
            {
                pair<int, int> next_check = myQueue.front();
                myQueue.pop();
                // 检查next_check的下一级
                for (int next_i : uivi[next_check.first])
                {

                    if (next_i == i)
                    {
                        if (loop > 1)
                        {
                            result = min(result, loop + 1);
                            return;
                        }
                    }
                    else
                    {
                        if (next_i != next_check.second)
                        {
                            myQueue.push({next_i, next_check.first});
                        }
                    }
                }
            }
            loop++;
            if (loop > result)
            {
                return;
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        result = 9999999;
        for (int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            uivi[x].push_back(y);
            uivi[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            check(i);
        }
        return result == 9999999 ? -1 : result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findShortestCycle
// paramTypes= ["number","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 7\n[[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0,1],[0,2]]\n
// @lcpr case=end

 */
