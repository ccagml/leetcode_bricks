/*
 * @lc app=leetcode.cn id=面试题 01.08 lang=cpp
 *
 * [面试题 01.08] 零矩阵
 *
 * https://leetcode.cn/problems/zero-matrix-lcci/description/
 *
 * LCCI
 * Medium (61.77%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    83.1K
 * Total Submissions: 131.2K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
 *
 *
 *
 * 示例 1：
 *
 * 输入：
 * [
 * ⁠ [1,1,1],
 * ⁠ [1,0,1],
 * ⁠ [1,1,1]
 * ]
 * 输出：
 * [
 * ⁠ [1,0,1],
 * ⁠ [0,0,0],
 * ⁠ [1,0,1]
 * ]
 *
 *
 * 示例 2：
 *
 * 输入：
 * [
 * ⁠ [0,1,2,0],
 * ⁠ [3,4,5,2],
 * ⁠ [1,3,1,5]
 * ]
 * 输出：
 * [
 * ⁠ [0,0,0,0],
 * ⁠ [0,4,5,0],
 * ⁠ [0,3,1,0]
 * ]
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool x = false;
        bool y = false;
        int my = matrix.size();
        int nx = matrix[0].size();
        for (int yy = 0; yy < my; yy++)
        {
            if (matrix[yy][0] == 0)
            {
                y = true;
                break;
            }
        }
        for (int xx = 0; xx < nx; xx++)
        {
            if (matrix[0][xx] == 0)
            {
                x = true;
                break;
            }
        }
        for (int yy = 1; yy < my; yy++)
        {
            for (int xx = 1; xx < nx; xx++)
            {
                if (matrix[yy][xx] == 0)
                {
                    matrix[yy][0] = 0;
                    matrix[0][xx] = 0;
                }
            }
        }

        for (int yy = 1; yy < my; yy++)
        {
            if (matrix[yy][0] == 0)
            {
                for (int xx = 1; xx < nx; xx++)
                {
                    matrix[yy][xx] = 0;
                }
            }
        }
        for (int xx = 0; xx < nx; xx++)
        {
            if (matrix[0][xx] == 0)
            {
                for (int yy = 0; yy < my; yy++)
                {
                    matrix[yy][xx] = 0;
                }
            }
        }
        if (x)
        {
            for (int xx = 0; xx < nx; xx++)
            {
                matrix[0][xx] = 0;
            }
        }
        if (y)
        {
            for (int yy = 0; yy < my; yy++)
            {
                matrix[yy][0] = 0;
            }
        }
     }
};
// @lc code=end
