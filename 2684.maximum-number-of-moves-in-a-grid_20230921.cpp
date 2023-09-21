// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2684 lang=cpp
 * @lcpr version=21917
 *
 * [2684] 矩阵中移动的最大次数
 *
 * https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/description/
 *
 * algorithms
 * Medium (41.17%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 15.5K
 * Testcase Example:  '[[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]'
 *
 * 给你一个下标从 0 开始、大小为 m x n 的矩阵 grid ，矩阵由若干 正 整数组成。
 *
 * 你可以从矩阵第一列中的 任一 单元格出发，按以下方式遍历 grid ：
 *
 *
 * 从单元格 (row, col) 可以移动到 (row - 1, col + 1)、(row, col + 1) 和 (row + 1, col + 1)
 * 三个单元格中任一满足值 严格 大于当前单元格的单元格。
 *
 *
 * 返回你在矩阵中能够 移动 的 最大 次数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid = [[2,4,3,5],
 *              [5,4,9,3],
 *              [3,4,2,11],
 *              [10,9,13,15]]
 * 输出：3
 * 解释：可以从单元格 (0, 0) 开始并且按下面的路径移动：
 * - (0, 0) -> (0, 1).
 * - (0, 1) -> (1, 2).
 * - (1, 2) -> (2, 3).
 * 可以证明这是能够移动的最大次数。
 *
 * 示例 2：
 *
 *
 * 输入：grid = [[3,2,4],
 *              [2,1,9],
 *              [1,1,7]]
 * 输出：0
 * 解释：从第一列的任一单元格开始都无法移动。
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
 * 1 <= grid[i][j] <= 10^6
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
    int maxMoves(vector<vector<int>> &grid)
    {
        int y = grid.size();
        int x = grid[0].size();
        vector<vector<int>> tt(y, vector<int>(x));
        int max_result = 0;
        for (int xx = 0; xx < x; xx++)
        {
            for (int yy = 0; yy < y; yy++)
            {
                if (xx == 0 || (xx > 0 && tt[yy][xx] > 0))
                {
                    // 检查往右边
                    // 右上
                    if (xx + 1 < x && yy - 1 >= 0 && grid[yy - 1][xx + 1] > grid[yy][xx])
                    {
                        tt[yy - 1][xx + 1] = max(tt[yy - 1][xx + 1], tt[yy][xx] + 1);
                        max_result = max(max_result, tt[yy - 1][xx + 1]);
                    }
                    // 右
                    if (xx + 1 < x && grid[yy][xx + 1] > grid[yy][xx])
                    {
                        tt[yy][xx + 1] = max(tt[yy][xx + 1], tt[yy][xx] + 1);
                        max_result = max(max_result, tt[yy][xx + 1]);
                    }
                    // 右下
                    if (xx + 1 < x && yy + 1 < y && grid[yy + 1][xx + 1] > grid[yy][xx])
                    {
                        tt[yy + 1][xx + 1] = max(tt[yy + 1][xx + 1], tt[yy][xx] + 1);
                        max_result = max(max_result, tt[yy + 1][xx + 1]);
                    }
                }
            }
        }

        return max_result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxMoves
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,2,4],[2,1,9],[1,1,7]]\n
// @lcpr case=end

 */
