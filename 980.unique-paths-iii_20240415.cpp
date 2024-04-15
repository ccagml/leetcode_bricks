// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=980 lang=cpp
 * @lcpr version=30122
 *
 * [980] 不同路径 III
 *
 * https://leetcode.cn/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (77.82%)
 * Likes:    354
 * Dislikes: 0
 * Total Accepted:    38.1K
 * Total Submissions: 49K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * 在二维网格 grid 上，有 4 种类型的方格：
 *
 *
 * 1 表示起始方格。且只有一个起始方格。
 * 2 表示结束方格，且只有一个结束方格。
 * 0 表示我们可以走过的空方格。
 * -1 表示我们无法跨越的障碍。
 *
 *
 * 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。
 *
 * 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * [[1,0,0,0],
 *  [0,0,0,0],
 *  [0,0,2,-1]]
 * 输出：2
 * 解释：我们有以下两条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 *
 * 示例 2：
 *
 * 输入：[[1,0,0,0],
 *       [0,0,0,0],
 *       [0,0,0,2]]
 * 输出：4
 * 解释：我们有以下四条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 *
 * 示例 3：
 *
 * 输入：[[0,1],
 *       [2,0]]
 * 输出：0
 * 解释：
 * 没有一条路能完全穿过每一个空的方格一次。
 * 请注意，起始和结束方格可以位于网格中的任意位置。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length * grid[0].length <= 20
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
    int result;
    int all_flag = 0;
    int all_x = 0;
    int start_flag = 0;

    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }
    int set_bit_0(int x, int index)
    {
        x &= ~(1 << index);
        return x;
    }

    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    void dfs(vector<vector<int>> &grid, int start_x, int start_y, int flag)
    {

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int dir_index = 0; dir_index < dir.size(); dir_index++)
        {
            int next_x = start_x + dir[dir_index][0];
            int next_y = start_y + dir[dir_index][1];
            if (next_x >= 0 && next_y >= 0)
            {
                if (next_x < grid[0].size() && next_y < grid.size())
                {
                    if (grid[next_y][next_x] == 0 && not is_bit_1(flag, xy_to_num(next_x, next_y)))
                    {
                        int next_flag = set_bit_1(flag, xy_to_num(next_x, next_y));
                        dfs(grid, next_x, next_y, next_flag);
                    }
                    if (grid[next_y][next_x] == 2)
                    {
                        int next_flag = set_bit_1(flag, xy_to_num(next_x, next_y));
                        if (next_flag == all_flag)
                        {
                            result++;
                        }
                    }
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        result = 0;
        all_x = grid[0].size();
        int start_x = 0;
        int start_y = 0;
        for (int yy = 0; yy < grid.size(); yy++)
        {
            for (int xx = 0; xx < grid[0].size(); xx++)
            {
                if (grid[yy][xx] != -1)
                {
                    all_flag = set_bit_1(all_flag, xy_to_num(xx, yy));
                }
                if (grid[yy][xx] == 1)
                {
                    start_y = yy;
                    start_x = xx;
                    start_flag = set_bit_1(start_flag, xy_to_num(xx, yy));
                }
            }
        }
        dfs(grid, start_x, start_y, start_flag);

        return result;
    }

    int xy_to_num(int x, int y)
    {
        return y * all_x + x;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0],[0,0,0,0],[0,0,0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[2,0]]\n
// @lcpr case=end

 */
