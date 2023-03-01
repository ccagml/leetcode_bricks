// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 * @lcpr version=21707
 *
 * [2373] 矩阵中的局部最大值
 *
 * https://leetcode.cn/problems/largest-local-values-in-a-matrix/description/
 *
 * algorithms
 * Easy (86.42%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 24.2K
 * Testcase Example:  '[[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]'
 *
 * 给你一个大小为 n x n 的整数矩阵 grid 。
 *
 * 生成一个大小为 (n - 2) x (n - 2) 的整数矩阵  maxLocal ，并满足：
 *
 *
 * maxLocal[i][j] 等于 grid 中以 i + 1 行和 j + 1 列为中心的 3 x 3 矩阵中的 最大值 。
 *
 *
 * 换句话说，我们希望找出 grid 中每个 3 x 3 矩阵中的最大值。
 *
 * 返回生成的矩阵。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
 * 输出：[[9,9],[8,6]]
 * 解释：原矩阵和生成的矩阵如上图所示。
 * 注意，生成的矩阵中，每个值都对应 grid 中一个相接的 3 x 3 矩阵的最大值。
 *
 * 示例 2：
 *
 *
 *
 * 输入：grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
 * 输出：[[2,2,2],[2,2,2],[2,2,2]]
 * 解释：注意，2 包含在 grid 中每个 3 x 3 的矩阵中。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length == grid[i].length
 * 3 <= n <= 100
 * 1 <= grid[i][j] <= 100
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
    int get(vector<vector<int>> &grid, int x, int y)
    {
        int temp = 0;
        for (int xx = x - 1; xx <= x + 1; xx++)
        {
            for (int yy = y - 1; yy <= y + 1; yy++)
            {
                temp = max(temp, grid[yy][xx]);
            }
        }
        return temp;
    }

    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int y = grid.size() - 2;
        int x = grid[0].size() - 2;
        vector<vector<int>> result(y, vector<int>(x));
        for (int yy = 0; yy < y; yy++)
        {
            for (int xx = 0; xx < x; xx++)
            {
                result[yy][xx] = get(grid, xx + 1, yy + 1);
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=largestLocal
// paramTypes=["number[][]"]
// returnType=number[][]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]\n
// @lcpr case=end

 */
