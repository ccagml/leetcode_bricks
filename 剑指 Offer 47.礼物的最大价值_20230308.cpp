/*
 * @lc app=leetcode.cn id=剑指 Offer 47 lang=cpp
 * @lcpr version=21801
 *
 * [剑指 Offer 47] 礼物的最大价值
 *
 * https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
 *
 * LCOF
 * Medium (69.09%)
 * Likes:    389
 * Dislikes: 0
 * Total Accepted:    235.8K
 * Total Submissions: 340.5K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于
 * 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 *
 *
 *
 * 示例 1:
 *
 * 输入:
 * [
 * [1,3,1],
 * [1,5,1],
 * [4,2,1]
 * ]
 * 输出: 12
 * 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 *
 *
 *
 * 提示：
 *
 *
 * 0 < grid.length <= 200
 * 0 < grid[0].length <= 200
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
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                if (x == 0 && y == 0)
                {
                    result[y][x] = grid[y][x];
                }
                else if (x == 0)
                {
                    result[y][x] = result[y - 1][x] + grid[y][x];
                }
                else if (y == 0)
                {
                    result[y][x] = result[y][x - 1] + grid[y][x];
                }
                else
                {
                    result[y][x] = max(result[y - 1][x], result[y][x - 1]) + grid[y][x];
                }
            }
        }
        return result[m - 1][n - 1];
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
//
// @lcpr case=end

 */
