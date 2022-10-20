/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] 网格图中递增路径的数目
 *
 * https://leetcode.cn/problems/number-of-increasing-paths-in-a-grid/description/
 *
 * algorithms
 * Hard (49.73%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 10.9K
 * Testcase Example:  '[[1,1],[3,4]]'
 *
 * 给你一个 m x n 的整数网格图 grid ，你可以从一个格子移动到 4 个方向相邻的任意一个格子。
 *
 * 请你返回在网格图中从 任意 格子出发，达到 任意 格子，且路径中的数字是 严格递增 的路径数目。由于答案可能会很大，请将结果对 10^9 + 7 取余
 * 后返回。
 *
 * 如果两条路径中访问过的格子不是完全相同的，那么它们视为两条不同的路径。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：grid = [[1,1],[3,4]]
 * 输出：8
 * 解释：严格递增路径包括：
 * - 长度为 1 的路径：[1]，[1]，[3]，[4] 。
 * - 长度为 2 的路径：[1 -> 3]，[1 -> 4]，[3 -> 4] 。
 * - 长度为 3 的路径：[1 -> 3 -> 4] 。
 * 路径数目为 4 + 3 + 1 = 8 。
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[1],[2]]
 * 输出：3
 * 解释：严格递增路径包括：
 * - 长度为 1 的路径：[1]，[2] 。
 * - 长度为 2 的路径：[1 -> 2] 。
 * 路径数目为 2 + 1 = 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 1000
 * 1 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^5
 *
 *
 */

// @lc code=start
// 思考1: 把每个格子的数值从小到大分类
// 思考2: 根据数值大小开始收集(这样能保证比我小的已经算完了)
class Solution
{
public:
    int countPaths(vector<vector<int>> &grid)
    {
        int yy = grid.size();
        int xx = grid[0].size();
        int mod = (1e9 + 7);
        vector<vector<int>> result(yy, vector<int>(xx, 1));
        map<int, vector<pair<int, int>>> miu;
        for (int y = 0; y < yy; y++)
        {
            for (int x = 0; x < xx; x++)
            {
                int cur = grid[y][x];
                if (miu.count(cur) == 0)
                {
                    vector<pair<int, int>> temp;
                    temp.push_back({x, y});
                    miu[cur] = temp;
                }
                else
                {
                    miu[cur].push_back({x, y});
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (const auto &n : miu)
        {
            // std::cout << "\"" << n.first << "\" = \"" << n.second << "\"\n";
            int cur = n.first;
            for (int jj = 0; jj < n.second.size(); jj++)
            {
                pair<int, int> get = n.second[jj];
                int x = get.first;
                int y = get.second;
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dir[i].first;
                    int ny = y + dir[i].second;
                    if (nx >= 0 && ny >= 0 && nx < xx && ny < yy)
                    {
                        if (grid[ny][nx] < cur)
                        {
                            result[y][x] += result[ny][nx];
                            result[y][x] %= mod;
                        }
                    }
                }
            }
        }
        int result_int = 0;
        for (int y = 0; y < yy; y++)
        {
            for (int x = 0; x < xx; x++)
            {
                result_int += result[y][x];
                // std::cout << "到达(" << x << "," << y << ")=" << result[y][x] << std::endl;
                result_int %= mod;
            }
        }
        return result_int;
    }
};
// @lc code=end
