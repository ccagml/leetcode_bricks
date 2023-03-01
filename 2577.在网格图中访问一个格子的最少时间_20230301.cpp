// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2577 lang=cpp
 * @lcpr version=21707
 *
 * [2577] 在网格图中访问一个格子的最少时间
 *
 * https://leetcode.cn/problems/minimum-time-to-visit-a-cell-in-a-grid/description/
 *
 * algorithms
 * Hard (37.52%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 7.3K
 * Testcase Example:  '[[0,1,3,2],[5,1,2,5],[4,3,8,6]]'
 *
 * 给你一个 m x n 的矩阵 grid ，每个元素都为 非负 整数，其中 grid[row][col] 表示可以访问格子 (row, col) 的 最早
 * 时间。也就是说当你访问格子 (row, col) 时，最少已经经过的时间为 grid[row][col] 。
 *
 * 你从 最左上角 出发，出发时刻为 0 ，你必须一直移动到上下左右相邻四个格子中的 任意 一个格子（即不能停留在格子上）。每次移动都需要花费 1
 * 单位时间。
 *
 * 请你返回 最早 到达右下角格子的时间，如果你无法到达右下角的格子，请你返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[0,1,3,2],
 *              [5,1,2,5],
 *              [4,3,8,6]]
 * 输出：7
 * 解释：一条可行的路径为：
 * - 时刻 t = 0 ，我们在格子 (0,0) 。
 * - 时刻 t = 1 ，我们移动到格子 (0,1) ，可以移动的原因是 grid[0][1] <= 1 。
 * - 时刻 t = 2 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] <= 2 。
 * - 时刻 t = 3 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] <= 3 。
 * - 时刻 t = 4 ，我们移动到格子 (1,1) ，可以移动的原因是 grid[1][1] <= 4 。
 * - 时刻 t = 5 ，我们移动到格子 (1,2) ，可以移动的原因是 grid[1][2] <= 5 。
 * - 时刻 t = 6 ，我们移动到格子 (1,3) ，可以移动的原因是 grid[1][3] <= 6 。
 * - 时刻 t = 7 ，我们移动到格子 (2,3) ，可以移动的原因是 grid[2][3] <= 7 。
 * 最终到达时刻为 7 。这是最早可以到达的时间。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：grid = [[0,2,4],[3,2,1],[1,0,4]]
 * 输出：-1
 * 解释：没法从左上角按题目规定走到右下角。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 1000
 * 4 <= m * n <= 10^5
 * 0 <= grid[i][j] <= 10^5
 * grid[0][0] == 0
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
    int minimumTime(vector<vector<int>> &grid)
    {
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int y = grid.size(), x = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        vector<vector<int>> dp(y, vector<int>(x, 9999999));
        dp[0][0] = 0;
        std::priority_queue<tuple<int, int, int>, std::vector<tuple<int, int, int>>, std::greater<tuple<int, int, int>>> q;
        q.push({0, 0, 0});
        while (q.size() > 0)
        {
            auto [j, cur_x, cur_y] = q.top();
            q.pop();
            if (cur_x == x - 1 && cur_y == y - 1)
            {
                return j;
            }
            // cur_x,cur_y 可以去到哪个点
            for (int dir_index = 0; dir_index < dir.size(); dir_index++)
            {
                int next_x = cur_x + dir[dir_index][0];
                int next_y = cur_y + dir[dir_index][1];
                if (next_x >= 0 && next_x < x && next_y >= 0 && next_y < y)
                {

                    int temp_j_max = 0;
                    if (j >= grid[next_y][next_x])
                    {
                        temp_j_max = j + 1;
                    }
                    else
                    {
                        temp_j_max = grid[next_y][next_x];
                        if ((j % 2) == (grid[next_y][next_x] % 2))
                        {
                            temp_j_max++;
                        }
                    }

                    if (dp[next_y][next_x] > temp_j_max)
                    {
                        dp[next_y][next_x] = temp_j_max;
                        q.push({temp_j_max, next_x, next_y});
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minimumTime
// paramTypes=["number[][]"]
// returnType=number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[0,1,3,2],[5,1,2,5],[4,3,8,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2,4],[3,2,1],[1,0,4]]\n
// @lcpr case=end

 */
