/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 * @lcpr version=21113
 *
 * [1504] 统计全 1 子矩形
 *
 * https://leetcode.cn/problems/count-submatrices-with-all-ones/description/
 *
 * algorithms
 * Medium (61.97%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 17.5K
 * Testcase Example:  '[[1,0,1],[1,1,0],[1,1,0]]'
 *
 * 给你一个 m x n 的二进制矩阵 mat ，请你返回有多少个 子矩形 的元素全部都是 1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：mat = [[1,0,1],[1,1,0],[1,1,0]]
 * 输出：13
 * 解释：
 * 有 6 个 1x1 的矩形。
 * 有 2 个 1x2 的矩形。
 * 有 3 个 2x1 的矩形。
 * 有 1 个 2x2 的矩形。
 * 有 1 个 3x1 的矩形。
 * 矩形数目总共 = 6 + 2 + 3 + 1 + 1 = 13 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
 * 输出：24
 * 解释：
 * 有 8 个 1x1 的子矩形。
 * 有 5 个 1x2 的子矩形。
 * 有 2 个 1x3 的子矩形。
 * 有 4 个 2x1 的子矩形。
 * 有 2 个 2x2 的子矩形。
 * 有 2 个 3x1 的子矩形。
 * 有 1 个 3x2 的子矩形。
 * 矩形数目总共 = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24 。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 150
 * mat[i][j] 仅包含 0 或 1
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
    int numSubmat(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> row(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j == 0)
                {
                    row[i][j] = mat[i][j];
                }
                else if (mat[i][j])
                {
                    row[i][j] = row[i][j - 1] + 1;
                }
                else
                {
                    row[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int col = row[i][j];
                for (int k = i; k >= 0 && col; --k)
                {
                    col = min(col, row[k][j]);
                    ans += col;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,0,1],[1,1,0],[1,1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,1,0],[0,1,1,1],[1,1,1,0]]\n
// @lcpr case=end

 */
