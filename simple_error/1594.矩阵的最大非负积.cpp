/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 *
 * https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/description/
 *
 * algorithms
 * Medium (32.98%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 16.8K
 * Testcase Example:  '[[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]'
 *
 * 给你一个大小为 rows x cols 的矩阵 grid 。最初，你位于左上角 (0, 0) ，每一步，你可以在矩阵中 向右 或 向下 移动。
 *
 * 在从左上角 (0, 0) 开始到右下角 (rows - 1, cols - 1) 结束的所有路径中，找出具有 最大非负积
 * 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。
 *
 * 返回 最大非负积 对 10^9 + 7 取余 的结果。如果最大积为负数，则返回 -1 。
 *
 * 注意，取余是在得到最大积之后执行的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid = [[-1,-2,-3],
 * [-2,-3,-3],
 * [-3,-3,-2]]
 * 输出：-1
 * 解释：从 (0, 0) 到 (2, 2) 的路径中无法得到非负积，所以返回 -1
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[1,-2,1],
 * [1,-2,1],
 * [3,-4,1]]
 * 输出：8
 * 解释：最大非负积对应的路径已经用粗体标出 (1 * 1 * -2 * -4 * 1 = 8)
 *
 *
 * 示例 3：
 *
 * 输入：grid = [[1, 3],
 * [0,-4]]
 * 输出：0
 * 解释：最大非负积对应的路径已经用粗体标出 (1 * 0 * -4 = 0)
 *
 *
 * 示例 4：
 *
 * 输入：grid = [[ 1, 4,4,0],
 * [-2, 0,0,1],
 * [ 1,-1,1,1]]
 * 输出：2
 * 解释：最大非负积对应的路径已经用粗体标出 (1 * -2 * 1 * -1 * 1 * 1 = 2)
 *
 *
 * [[1,-1,0,-3,4,3,-3,3,-1,3,0,0,-4,2],[2,-2,-3,-4,0,-2,-3,3,1,4,1,-3,-1,-4],[-4,4,-4,-4,2,-4,3,0,-2,-4,3,4,-1,0],[-3,3,-4,-4,3,4,4,1,-1,-1,0,3,4,1],[1,3,-4,2,2,-3,1,-3,-4,-4,-1,-4,-4,4],[1,1,-1,1,-1,-1,3,-4,-1,2,-2,3,-4,0],[1,0,3,3,1,4,1,1,-4,-1,-3,4,-4,4],[4,3,2,3,0,-1,2,-4,1,0,0,1,3,4],[-4,4,-4,-4,2,-2,2,-1,0,-2,2,4,-2,-1],[-2,3,4,-4,3,3,-2,-1,0,-3,4,-2,-1,-4],[4,3,3,3,-3,1,2,-4,-1,4,-3,-3,2,0],[3,3,0,1,-4,-4,-3,3,-2,-4,2,4,-3,3],[-3,0,1,3,0,0,0,-4,-1,4,-1,-3,1,1],[-1,4,0,-3,1,-3,-1,2,1,-3,-1,-4,4,1]]
 *
 * 提示：
 *
 *
 * 1 <= rows, cols <= 15
 * -4 <= grid[i][j] <= 4
 *
 *
 */

// @lc code=start
// 动态规划 求余数的位置不对,中间过程求余数 会有问题

class Solution
{
public:
    int maxProductPath(vector<vector<int>> &grid)
    {
        long long aaa = 1e9 + 7;
        long long y = grid.size();
        long long x = grid[0].size();
        vector<vector<pair<long long, long long>>> flag(y, vector<pair<long long, long long>>(x, {0, 0}));
        bool has_zero = false;
        if (grid[0][0] < 0)
        {
            flag[0][0].second = grid[0][0];
        }
        else
        {
            flag[0][0].first = grid[0][0];
        }
        if (grid[0][0] == 0)
        {
            has_zero = true;
        }
        for (long long yy = 1; yy < y; yy++)
        {
            if (grid[yy][0] < 0)
            {
                flag[yy][0].first = max(flag[yy][0].first, flag[yy - 1][0].second * grid[yy][0]);
                flag[yy][0].second = min(flag[yy][0].second, flag[yy - 1][0].first * grid[yy][0]);
            }
            else
            {
                flag[yy][0].first = max(flag[yy][0].first, flag[yy - 1][0].first * grid[yy][0]);
                flag[yy][0].second = min(flag[yy][0].second, flag[yy - 1][0].second * grid[yy][0]);
            }
            if (grid[yy][0] == 0)
            {
                has_zero = true;
            }
        }
        for (long long xx = 1; xx < x; xx++)
        {
            if (grid[0][xx] < 0)
            {
                flag[0][xx].first = max(flag[0][xx].first, flag[0][xx - 1].second * grid[0][xx]);
                flag[0][xx].second = min(flag[0][xx].second, flag[0][xx - 1].first * grid[0][xx]);
            }
            else
            {
                flag[0][xx].first = max(flag[0][xx].first, flag[0][xx - 1].first * grid[0][xx]);
                flag[0][xx].second = min(flag[0][xx].second, flag[0][xx - 1].second * grid[0][xx]);
            }
            if (grid[0][xx] == 0)
            {
                has_zero = true;
            }
        }
        for (long long yy = 1; yy < y; yy++)
        {
            for (long long xx = 1; xx < x; xx++)
            {
                if (grid[yy][xx] < 0)
                {
                    flag[yy][xx].first = max(flag[yy][xx].first, max(flag[yy][xx - 1].second * grid[yy][xx], flag[yy - 1][xx].second * grid[yy][xx]));
                    flag[yy][xx].second = min(flag[yy][xx].second, min(flag[yy][xx - 1].first * grid[yy][xx], flag[yy - 1][xx].first * grid[yy][xx]));
                }
                else
                {
                    flag[yy][xx].first = max(flag[yy][xx].first, max(flag[yy][xx - 1].first * grid[yy][xx], flag[yy - 1][xx].first * grid[yy][xx]));
                    flag[yy][xx].second = min(flag[yy][xx].second, min(flag[yy][xx - 1].second * grid[yy][xx], flag[yy - 1][xx].second * grid[yy][xx]));
                }
                if (grid[yy][xx] == 0)
                {
                    has_zero = true;
                }
            }
        }
        if (flag[y - 1][x - 1].first > 0)
        {
            return flag[y - 1][x - 1].first % aaa;
        }
        else if (flag[y - 1][x - 1].first == 0 && has_zero)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
