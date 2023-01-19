/*
 * @lc app=leetcode.cn id=2536 lang=cpp
 * @lcpr version=21110
 *
 * [2536] 子矩阵元素加 1
 *
 * https://leetcode.cn/problems/increment-submatrices-by-one/description/
 *
 * algorithms
 * Medium (57.87%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 8.5K
 * Testcase Example:  '3\n[[1,1,2,2],[0,0,1,1]]'
 *
 * 给你一个正整数 n ，表示最初有一个 n x n 、下标从 0 开始的整数矩阵 mat ，矩阵中填满了 0 。
 *
 * 另给你一个二维整数数组 query 。针对每个查询 query[i] = [row1i, col1i, row2i, col2i]
 * ，请你执行下述操作：
 *
 *
 * 找出 左上角 为 (row1i, col1i) 且 右下角 为 (row2i, col2i) 的子矩阵，将子矩阵中的 每个元素 加 1
 * 。也就是给所有满足 row1i <= x <= row2i 和 col1i <= y <= col2i 的 mat[x][y] 加 1 。
 *
 *
 * 返回执行完所有操作后得到的矩阵 mat 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 3, queries = [[1,1,2,2],[0,0,1,1]]
 * 输出：[[1,1,0],[1,2,1],[0,1,1]]
 * 解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后的矩阵。
 * - 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。
 * - 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 2, queries = [[0,0,1,1]]
 * 输出：[[1,1],[1,1]]
 * 解释：上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。
 * - 第一个操作：将矩阵中的每个元素加 1 。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 500
 * 1 <= queries.length <= 10^4
 * 0 <= row1i <= row2i < n
 * 0 <= col1i <= col2i < n
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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> result(n, vector<int>(n));
        for (int i = 0; i < queries.size(); i++)
        {
            int row1i = queries[i][0];
            int col1i = queries[i][1];
            int row2i = queries[i][2];
            int col2i = queries[i][3];
            for (int xx = row1i; xx <= row2i; xx++)
            {
                for (int yy = col1i; yy <= col2i; yy++)
                {
                    result[xx][yy]++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n[[1,1,2,2],[0,0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0,1,1]]\n
// @lcpr case=end

 */
