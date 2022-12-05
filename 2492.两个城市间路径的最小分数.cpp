/*
 * @lc app=leetcode.cn id=2492 lang=cpp
 * @lcpr version=20701
 *
 * [2492] 两个城市间路径的最小分数
 *
 * https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/description/
 *
 * algorithms
 * Medium (37.94%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 11.7K
 * Testcase Example:  '4\n[[1,2,9],[2,3,6],[2,4,5],[1,4,7]]'
 *
 * 给你一个正整数 n ，表示总共有 n 个城市，城市从 1 到 n 编号。给你一个二维数组 roads ，其中 roads[i] = [ai, bi,
 * distancei] 表示城市 ai 和 bi 之间有一条 双向 道路，道路距离为 distancei 。城市构成的图不一定是连通的。
 *
 * 两个城市之间一条路径的 分数 定义为这条路径中道路的 最小 距离。
 *
 * 城市 1 和城市 n 之间的所有路径的 最小 分数。
 *
 * 注意：
 *
 *
 * 一条路径指的是两个城市之间的道路序列。
 * 一条路径可以 多次 包含同一条道路，你也可以沿着路径多次到达城市 1 和城市 n 。
 * 测试数据保证城市 1 和城市n 之间 至少 有一条路径。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
 * 输出：5
 * 解释：城市 1 到城市 4 的路径中，分数最小的一条为：1 -> 2 -> 4 。这条路径的分数是 min(9,5) = 5 。
 * 不存在分数更小的路径。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
 * 输出：2
 * 解释：城市 1 到城市 4 分数最小的路径是：1 -> 2 -> 1 -> 3 -> 4 。这条路径的分数是 min(2,2,4,7) = 2
 * 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^5
 * 1 <= roads.length <= 10^5
 * roads[i].length == 3
 * 1 <= ai, bi <= n
 * ai != bi
 * 1 <= distancei <= 10^4
 * 不会有重复的边。
 * 城市 1 和城市 n 之间至少有一条路径。
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
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// @lc code=start
// 路径最小 , 环最小
class Solution
{
public:
    int loop_min = 999999999;
    int path_min = 999999999;

    unordered_map<int, unordered_map<int, int>> uiuii;
    unordered_map<int, int> um_flag;
    void dfs(int cur, int fa, int cur_min)
    {
        um_flag[cur] = fa;
        for (pair<int, int> sun : uiuii[cur])
        {
            int next = sun.first;
            if (um_flag.count(next) > 0)
            {
                loop_min = min(loop_min, sun.second);
            }
            else
            {
                dfs(next, cur, min(cur_min, sun.second));
            }
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        for (int i = 0; i < roads.size(); i++)
        {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];
            uiuii[a][b] = c;
            uiuii[b][a] = c;
        }
        // std::cout << "1111111111111" << std::endl;
        dfs(1, 1, 99999999);

        queue<pair<int, int>> qi;
        unordered_map<int, int> in_min;
        for (pair<int, int> end : uiuii[n])
        {
            int nextb = end.first;
            int len = end.second;
            if (in_min.count(nextb) < 1 || in_min[nextb] > len)
            {
                in_min[nextb] = len;
                qi.push(end);
            }
        }

        // std::cout << "22222" << std::endl;
        while (qi.size() > 0)
        {
            pair<int, int> cur_top = qi.front();
            qi.pop();
            int cur_b = cur_top.first;
            int cur_b_min = cur_top.second;
            for (pair<int, int> next_ob : uiuii[cur_b])
            {
                int next_b = next_ob.first;
                int next_b_len = next_ob.second;
                if (next_b == 1)
                {
                    path_min = min(path_min, min(next_b_len, cur_b_min));
                }
                else if (in_min.count(next_b) < 1 || in_min[next_b] > min(next_b_len, cur_b_min))
                {
                    in_min[next_b] = min(next_b_len, cur_b_min);
                    // std::cout << cur_b << "->" << next_b << "=" << in_min[next_b] << "),";
                    qi.push({next_b, min(next_b_len, cur_b_min)});
                }
            }
        }
        return min(path_min, loop_min);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n[[1,2,9],[2,3,6],[2,4,5],[1,4,7]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2,2],[1,3,4],[3,4,7]]\n
// @lcpr case=end

 */
