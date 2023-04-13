// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2596 lang=cpp
 * @lcpr version=21906
 *
 * [2596] 检查骑士巡视方案
 *
 * https://leetcode.cn/problems/check-knight-tour-configuration/description/
 *
 * algorithms
 * Medium (52.66%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 13.7K
 * Testcase Example:  '[[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]'
 *
 * 骑士在一张 n x n 的棋盘上巡视。在有效的巡视方案中，骑士会从棋盘的 左上角 出发，并且访问棋盘上的每个格子 恰好一次 。
 *
 * 给你一个 n x n 的整数矩阵 grid ，由范围 [0, n * n - 1] 内的不同整数组成，其中 grid[row][col] 表示单元格
 * (row, col) 是骑士访问的第 grid[row][col] 个单元格。骑士的行动是从下标 0 开始的。
 *
 * 如果 grid 表示了骑士的有效巡视方案，返回 true；否则返回 false。
 *
 * 注意，骑士行动时可以垂直移动两个格子且水平移动一个格子，或水平移动两个格子且垂直移动一个格子。下图展示了骑士从某个格子出发可能的八种行动路线。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid =
 * [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
 * 输出：true
 * 解释：grid 如上图所示，可以证明这是一个有效的巡视方案。
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[0,3,6],[5,8,1],[2,7,4]]
 * 输出：false
 * 解释：grid 如上图所示，考虑到骑士第 7 次行动后的位置，第 8 次行动是无效的。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length == grid[i].length
 * 3 <= n <= 7
 * 0 <= grid[row][col] < n * n
 * grid 中的所有整数 互不相同
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
    bool checkValidGrid(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int end = n * n;

        int x = 0;
        int y = 0;
        vector<vector<int>> dir = {{-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}};
        if (grid[x][y] != 0)
        {
            return false;
        }
        for (int i = 0; i < end; i++)
        {
            int next = i + 1;
            if (next >= end)
            {
                return true;
            }
            bool found = false;
            for (int j = 0; j < dir.size(); j++)
            {
                int next_x = x + dir[j][0];
                int next_y = y + dir[j][1];
                if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && grid[next_x][next_y] == next)
                {
                    x = next_x;
                    y = next_y;
                    found = true;
                    break;
                }
            }
            if (found)
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=checkValidGrid
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,3,6],[5,8,1],[2,7,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]\n
// @lcpr case=end

 */
