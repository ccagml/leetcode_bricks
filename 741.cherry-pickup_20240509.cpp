// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=741 lang=cpp
 * @lcpr version=30201
 *
 * [741] 摘樱桃
 *
 * https://leetcode.cn/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (50.89%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    26.6K
 * Total Submissions: 50K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * 给你一个 n x n 的网格 grid ，代表一块樱桃地，每个格子由以下三种数字的一种来表示：
 *
 *
 * 0 表示这个格子是空的，所以你可以穿过它。
 * 1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
 * -1 表示这个格子里有荆棘，挡着你的路。
 *
 *
 * 请你统计并返回：在遵守下列规则的情况下，能摘到的最多樱桃数：
 *
 *
 * 从位置 (0, 0) 出发，最后到达 (n - 1, n - 1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为 0 或者 1
 * 的格子）；
 * 当到达 (n - 1, n - 1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
 * 当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为 0 ）；
 * 如果在 (0, 0) 和 (n - 1, n - 1) 之间不存在一条可经过的路径，则无法摘到任何一个樱桃。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：grid = [[0,1,-1],[1,0,-1],[1,1,1]]
 * 输出：5
 * 解释：玩家从 (0, 0) 出发：向下、向下、向右、向右移动至 (2, 2) 。
 * 在这一次行程中捡到 4 个樱桃，矩阵变成 [[0,1,-1],[0,0,-1],[0,0,0]] 。
 * 然后，玩家向左、向上、向上、向左返回起点，再捡到 1 个樱桃。
 * 总共捡到 5 个樱桃，这是最大可能值。
 *
 *
 * 示例 2：
 *
 * 输入：grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length
 * n == grid[i].length
 * 1 <= n <= 50
 * grid[i][j] 为 -1、0 或 1
 * grid[0][0] != -1
 * grid[n - 1][n - 1] != -1
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<vector<int>> gg;
    unordered_map<string, int> umsi;
    int dfs(int k, int a1, int a2)
    {
        // k 步 到达 (k - a1, a1), (k - a2, a2)
        int a_x = k - a1;
        int a_y = a1;
        int b_x = k - a2;
        int b_y = a2;

        string kaa = std::to_string(k) + "_" + std::to_string(a1) + "_" + std::to_string(a2);

        if (umsi.count(kaa) > 0)
        {
            return umsi[kaa];
        }

        // a1到达的最大值
        if (a_x < 0 || a_y < 0 || b_x < 0 || b_y < 0)
        {
            umsi[kaa] = -99999999;
            return -99999999;
        }

        if (a_x == 0 && a_y == 0 && b_x == 0 && b_y == 0)
        {
            umsi[kaa] = gg[0][0];
            return gg[0][0];
        }

        // 情况1 右右
        int d1 = dfs(k - 1, a1 - 1, a2 - 1);
        // 情况2 右下
        int d2 = dfs(k - 1, a1 - 1, a2);
        // 情况3 下右
        int d3 = dfs(k - 1, a1, a2 - 1);
        // 情况4 下下
        int d4 = dfs(k - 1, a1, a2);

        int add = 0;

        if (gg[a_y][a_x] > 0)
        {
            add += gg[a_y][a_x];
        }
        if (gg[b_y][b_x] > 0)
        {
            add += gg[b_y][b_x];
        }

        if (a1 == a2)
        {
            add -= gg[b_y][b_x];
        }
        if (gg[a_y][a_x] == -1)
        {
            umsi[kaa] = -99999999;
            return -99999999;
        }
        if (gg[b_y][b_x] == -1)
        {
            umsi[kaa] = -99999999;
            return -99999999;
        }

        int temp = max(d1, max(d2, max(d3, d4))) + add;
        umsi[kaa] = temp;

        return temp;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        gg = grid;
        //[1,2,3]
        //[4,5,6]
        //[7,8,9]
        // k 步 到达 (k - y, y)
        //
        int n = grid.size();
        int k = 2 * (n - 1);
        int result = dfs(k, n - 1, n - 1);
        return result > 0 ? result : 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,-1],[1,0,-1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1]]\n
// @lcpr case=end


// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,-1],[1,-1,1],[-1,1,1]]\n
// @lcpr case=end

 */
