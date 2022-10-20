/*
 * @lc app=leetcode id=2435 lang=cpp
 *
 * [2435] 矩阵中和能被 K 整除的路径
 *
 * https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/
 *
 * algorithms
 * Hard (49.87%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 9.7K
 * Testcase Example:  '[[5,2,4],[3,0,5],[0,7,2]]\n3'
 *
 * 给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。你从起点 (0, 0) 出发，每一步只能往 下 或者往 右
 * ，你想要到达终点 (m - 1, n - 1) 。
 *
 * 请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 10^9 + 7 取余 的结果。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
 * 输出：2
 * 解释：有两条路径满足路径上元素的和能被 k 整除。
 * 第一条路径为上图中用红色标注的路径，和为 5 + 2 + 4 + 5 + 2 = 18 ，能被 3 整除。
 * 第二条路径为上图中用蓝色标注的路径，和为 5 + 3 + 0 + 5 + 2 = 15 ，能被 3 整除。
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[0,0]], k = 5
 * 输出：1
 * 解释：红色标注的路径和为 0 + 0 = 0 ，能被 5 整除。
 *
 *
 * 示例 3：
 *
 * 输入：grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
 * 输出：10
 * 解释：每个数字都能被 1 整除，所以每一条路径的和都能被 k 整除。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 5 * 10^4
 * 1 <= m * n <= 5 * 10^4
 * 0 <= grid[i][j] <= 100
 * 1 <= k <= 50
 *
 *
 */

// @lc code=start
// 思考1: 可能是每个格子需要一个长度k的vector存余数数据的数量
class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int yy = grid.size();
        int xx = grid[0].size();
        vector<vector<vector<int>>> temp(yy, vector<vector<int>>(xx, vector<int>(k)));
        int dd = 1e9 + 7;
        for (int y = 0; y < yy; y++)
        {
            for (int x = 0; x < xx; x++)
            {
                int cur = grid[y][x];
                int cur_b = cur % k;
                if (x == 0 || y == 0)
                {
                    if (x == 0 && y == 0)
                    {
                        temp[y][x][cur_b]++;
                    }
                    else if (x == 0)
                    {
                        for (int start_k = 0; start_k < k; start_k++)
                        {
                            temp[y][x][(start_k + cur) % k] += temp[y - 1][x][start_k];
                            temp[y][x][(start_k + cur) % k] %= (dd);
                        }
                    }
                    else if (y == 0)
                    {
                        for (int start_k = 0; start_k < k; start_k++)
                        {
                            temp[y][x][(start_k + cur) % k] += temp[y][x - 1][start_k];
                            temp[y][x][(start_k + cur) % k]  %= (dd);
                        }
                    }
                }
                else
                {
                    for (int start_k = 0; start_k < k; start_k++)
                    {
                        temp[y][x][(start_k + cur) % k] += temp[y][x - 1][start_k];
                        temp[y][x][(start_k + cur) % k]  %= (dd);
                        temp[y][x][(start_k + cur) % k] += temp[y - 1][x][start_k];
                        temp[y][x][(start_k + cur) % k]  %= (dd);
                    }
                }
            }
        }

        int aa = yy - 1;
        int bb = xx - 1;
        int ff = temp[aa][bb][0] % (dd);

        return ff;
    }
};
// @lc code=end
