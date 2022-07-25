/*
 * @lc app=leetcode.cn id=980 lang=cpp
 *
 * [980] 不同路径 III
 *
 * https://leetcode.cn/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (73.61%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 24.2K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * 在二维网格 grid 上，有 4 种类型的方格：
 *
 *
 * 1 表示起始方格。且只有一个起始方格。
 * 2 表示结束方格，且只有一个结束方格。
 * 0 表示我们可以走过的空方格。
 * -1 表示我们无法跨越的障碍。
 *
 *
 * 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。
 *
 * 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * 输出：2
 * 解释：我们有以下两条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 *
 * 示例 2：
 *
 * 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * 输出：4
 * 解释：我们有以下四条路径：
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 *
 * 示例 3：
 *
 * 输入：[[0,1],[2,0]]
 * 输出：0
 * 解释：
 * 没有一条路能完全穿过每一个空的方格一次。
 * 请注意，起始和结束方格可以位于网格中的任意位置。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length * grid[0].length <= 20
 *
 *
 */

// @lc code=start

// 看到困难题, 提示长度小于20, 还以为是状态压缩的动态规划
// 结果普通dfs也能过
// Accepted
// 39/39 cases passed (12 ms)
// Your runtime beats 17.22 % of cpp submissions
// Your memory usage beats 19.38 % of cpp submissions (8.3 MB)

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return p.first * 100 + p.second;  
    }
};

class Solution
{
public:
    int result;
    int x_len;
    int y_len;
    unordered_map<pair<int, int>, bool, pair_hash> umib;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &grid, pair<int, int> cur_pii)
    {
        int cur_x = cur_pii.first;
        int cur_y = cur_pii.second;
        umib.erase(cur_pii);
        for (int i = 0; i < dir.size(); i++)
        {
            int new_x = cur_x + dir[i][0];
            int new_y = cur_y + dir[i][1];
            if(new_x >= 0 && new_x < x_len && new_y >= 0 && new_y < y_len && grid[new_y][new_x] == 0){
                grid[new_y][new_x] = -2;
                pair<int, int> new_pii = make_pair(new_x, new_y);
                dfs(grid, new_pii);
                grid[new_y][new_x] = 0;
            }else if(new_x >= 0 && new_x < x_len && new_y >= 0 && new_y < y_len && grid[new_y][new_x] == 2 && umib.size() == 0 ){
                result++;
            }
        }
        umib[cur_pii] = true;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        umib = unordered_map<pair<int, int>, bool, pair_hash>();
        result = 0;
        x_len = grid[0].size();
        y_len = grid.size();
        pair<int, int> start_x_y;
        pair<int, int> end_x_y;
        for (int xx = 0; xx < x_len; xx++)
        {
            for (int yy = 0; yy < y_len; yy++)
            {
                pair<int, int> pii = make_pair(xx, yy);
                if (grid[yy][xx] == 0)
                {
                    umib[pii] = true;
                }
                else if (grid[yy][xx] == 1)
                {
                    start_x_y = pii;
                }
                else if (grid[yy][xx] == 2)
                {
                    end_x_y = pii;
                }
                else if (grid[yy][xx] == -1)
                {
                }
            }
        }

        dfs(grid, start_x_y);
        return result;
    }
};
// @lc code=end
