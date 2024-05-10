// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 * @lcpr version=30202
 *
 * [1463] 摘樱桃 II
 *
 * https://leetcode.cn/problems/cherry-pickup-ii/description/
 *
 * algorithms
 * Hard (62.82%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 19.2K
 * Testcase Example:  '[[3,1,1],[2,5,1],[1,5,5],[2,1,1]]'
 *
 * 给你一个 rows x cols 的矩阵 grid 来表示一块樱桃地。 grid 中每个格子的数字表示你能获得的樱桃数目。
 *
 * 你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 (0,0) 出发，机器人 2 从右上角格子 (0, cols-1) 出发。
 *
 * 请你按照如下规则，返回两个机器人能收集的最多樱桃数目：
 *
 *
 * 从格子 (i,j) 出发，机器人可以移动到格子 (i+1, j-1)，(i+1, j) 或者 (i+1, j+1) 。
 * 当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
 * 当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
 * 两个机器人在任意时刻都不能移动到 grid 外面。
 * 两个机器人最后都要到达 grid 最底下一行。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
 * 输出：24
 * 解释：机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
 * 机器人 1 摘的樱桃数目为 (3 + 2 + 5 + 2) = 12 。
 * 机器人 2 摘的樱桃数目为 (1 + 5 + 5 + 1) = 12 。
 * 樱桃总数为： 12 + 12 = 24 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：grid =
 * [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
 * 输出：28
 * 解释：机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
 * 机器人 1 摘的樱桃数目为 (1 + 9 + 5 + 2) = 17 。
 * 机器人 2 摘的樱桃数目为 (1 + 3 + 4 + 3) = 11 。
 * 樱桃总数为： 17 + 11 = 28 。
 *
 *
 * 示例 3：
 *
 * 输入：grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
 * 输出：22
 *
 *
 * 示例 4：
 *
 * 输入：grid = [[1,1],[1,1]]
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * rows == grid.length
 * cols == grid[i].length
 * 2 <= rows, cols <= 70
 * 0 <= grid[i][j] <= 100 
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
    int cherryPickup(vector<vector<int>> &grid)
    {
        int y = grid.size();
        int x = grid[0].size();
        vector<vector<int>> vii(x, vector<int>(x, -9999999));
        // vii[a][b] 的最大值
        vii[0][x - 1] = grid[0][0] + grid[0][x - 1];

        if (x - 1 == 0)
        {
            vii[0][x - 1] = grid[0][0];
        }
        vii[0][x - 1] == 0;

        for (int yy = 1; yy < y; yy++)
        {
            std::vector<std::vector<int>> copy_vii(vii);

            vector<int> &y_ceng = grid[yy];
            for (int new_a = 0; new_a < x; new_a++)
            {
                for (int new_b = 0; new_b < x; new_b++)
                {
                    // // 有三种到达new_a
                    // int new_a_max = 0;

                    // // 有三种到达new_b
                    // int new_b_max = 0;
                    int temp_new_ab_max = -1;
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            int last_a = new_a - 1 + i;
                            int last_b = new_b - 1 + j;
                            if (last_a >= 0 && last_a < x && last_b >= 0 && last_b < x)
                            {
                                temp_new_ab_max = max(temp_new_ab_max, vii[last_a][last_b]);
                            }
                        }
                    }
                    if ((temp_new_ab_max) >= 0)
                    {
                        int add = 0;
                        if (new_a == new_b)
                        {
                            add += y_ceng[new_a];
                        }
                        else
                        {
                            add += y_ceng[new_a];
                            add += y_ceng[new_b];
                        }
                        copy_vii[new_a][new_b] = temp_new_ab_max + add;
                    }
                }
            }
            vii = copy_vii;
        }
        int max_result = 0;
        for (int new_a = 0; new_a < x; new_a++)
        {
            for (int new_b = 0; new_b < x; new_b++)
            {
                max_result = max(max_result, vii[new_a][new_b]);
            }
        }
        return max_result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=cherryPickup
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

 */
