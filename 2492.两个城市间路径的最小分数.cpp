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
// 思路1:路径最小 , 环最小
// 思路2:并查集思路

class unionFind
{
public:
    unordered_map<int, int> quan;
    unordered_map<int, int> fa;
    unionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            quan[i] = 1e9;
            fa[i] = i;
        }
    }
    int get_fa_quan(int i)
    {
        return quan[get(i)];
    }
    void set_fa_quan(int i, int v)
    {
        quan[get(i)] = min(quan[get(i)], v);
    }
    int get(int i)
    {
        if (fa[i] == i)
        {
            return i;
        }
        fa[i] = get(fa[i]);
        return fa[i];
    }
    void set(int a, int b)
    {
        int fa_id = get(a);
        int fb_id = get(b);
        int fa_quan_a = get_fa_quan(a);
        int fa_quan_b = get_fa_quan(b);
        if (fa_quan_a > fa_quan_b)
        {
            fa[fa_id] = fb_id;
        }
        else if (fa_quan_a == fa_quan_b && fa_id > fb_id)
        {
            fa[fa_id] = fb_id;
        }
        else
        {
            fa[fb_id] = fa_id;
        }
    }
};

class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> a_to_b;
    int minScore(int n, vector<vector<int>> &roads)
    {
        unionFind *uf = new unionFind(n + 1);
        for (vector<int> &r : roads)
        {
            a_to_b[r[0]][r[1]] = r[2];
            a_to_b[r[1]][r[0]] = r[2];
            uf->set_fa_quan(r[0], r[2]);
            uf->set_fa_quan(r[1], r[2]);
            uf->set(r[0], r[1]);
        }
        return uf->get_fa_quan(1);
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
