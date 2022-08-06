/*
 * @lc app=leetcode.cn id=2352 lang=cpp
 *
 * [2352] 相等行列对
 *
 * https://leetcode.cn/problems/equal-row-and-column-pairs/description/
 *
 * algorithms
 * Medium (72.16%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 12.7K
 * Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
 *
 * 给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。
 *
 * 如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
 * 输出：1
 * 解释：存在一对相等行列对：
 * - (第 2 行，第 1 列)：[2,7,7]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * 输出：3
 * 解释：存在三对相等行列对：
 * - (第 0 行，第 0 列)：[3,1,2,2]
 * - (第 2 行, 第 2 列)：[2,4,2,2]
 * - (第 3 行, 第 2 列)：[2,4,2,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * 1 <= grid[i][j] <= 10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> temp_grid;
    int size_n;
    bool check(int x, int y)
    {
        for (int i = 0; i < size_n; i++)
        {
            if (temp_grid[x][i] != temp_grid[i][y])
            {
                return false;
            }
        }
        return true;
    }
    int equalPairs(vector<vector<int>> &grid)
    {
        temp_grid = grid;
        size_n = grid.size();
        int result = 0;
        for (int x = 0; x < size_n; x++)
        {
            for (int y = 0; y < size_n; y++)
            {
                if (check(x, y))
                {
                    result++;
                }
            }
        }
        return result;
    }
};
// @lc code=end
