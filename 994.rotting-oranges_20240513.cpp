// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30202
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode.cn/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (51.35%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    173K
 * Total Submissions: 334.5K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。
 *
 * 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[2,1,1],
 *              [0,1,1],
 *              [1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个方向上。
 *
 *
 * 示例 3：
 *
 * 输入：grid = [[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] 仅为 0、1 或 2
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
    int cnt;
    void dfs(vector<vector<int>> &grid)
    {
        int y = grid.size();
        int x = grid[0].size();
        unordered_set<int> usi;
        vector<vector<int>> vvi = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int xx = 0; xx < x; xx++)
        {
            for (int yy = 0; yy < y; yy++)
            {
                int flag = yy * 10000 + xx;
                // 不是刚被感染的
                if (usi.count(flag) == 0 && grid[yy][xx] == 2)
                {
                    for (int ii = 0; ii < vvi.size(); ii++)
                    {
                        int next_x = xx + vvi[ii][0];
                        int next_y = yy + vvi[ii][1];
                        if (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y)
                        {
                            if (grid[next_y][next_x] == 1)
                            {
                                int flag = next_y * 10000 + next_x;
                                usi.insert(flag);
                                grid[next_y][next_x] = 2;
                            }
                        }
                    }
                }
            }
            cnt += usi.size();
        }
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        for (int i = 0; i < 100; i++)
        {
            cnt = 0;
            dfs(grid);
            if (cnt == 0)
            {
                int y = grid.size();
                int x = grid[0].size();
                for (int xx = 0; xx < x; xx++)
                {
                    for (int yy = 0; yy < y; yy++)
                    {
                        if (grid[yy][xx] == 1)
                        {
                            return -1;
                        }
                    }
                }
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
