/*
 * @lc app=leetcode.cn id=931 lang=cpp
 * @lcpr version=21909
 *
 * [931] 下降路径最小和
 *
 * https://leetcode.cn/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (67.12%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    67.3K
 * Total Submissions: 99.4K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
 *
 * 下降路径
 * 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置
 * (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1)
 * 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * 输出：13
 * 解释：如图所示，为和最小的两条下降路径
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：matrix = [[-19,57],[-40,-5]]
 * 输出：-59
 * 解释：如图所示，为和最小的下降路径
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int y = matrix.size();
        int x = matrix[0].size();
        vector<vector<int>> temp(y, vector<int>(x, 100000));
        for (int yy = 0; yy < y; yy++)
        {
            for (int xx = 0; xx < x; xx++)
            {
                if (yy == 0)
                {
                    temp[yy][xx] = matrix[yy][xx];
                }
                else if (xx == 0)
                {
                    temp[yy][xx] = min(temp[yy - 1][xx], temp[yy - 1][xx + 1]) + matrix[yy][xx];
                }
                else if (xx == x - 1)
                {
                    temp[yy][xx] = min(temp[yy - 1][xx], temp[yy - 1][xx - 1]) + matrix[yy][xx];
                }
                else
                {
                    temp[yy][xx] = min(min(temp[yy - 1][xx], temp[yy - 1][xx - 1]), temp[yy - 1][xx + 1]) + matrix[yy][xx];
                }
            }
        }
        int ans = 999999;
        for (int xx = 0; xx < x; xx++)
        {
            ans = min(ans, temp[y - 1][xx]);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,3],[6,5,4],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[-19,57],[-40,-5]]\n
// @lcpr case=end

 */
