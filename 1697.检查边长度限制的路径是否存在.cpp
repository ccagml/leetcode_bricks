/*
 * @lc app=leetcode.cn id=1697 lang=cpp
 * @lcpr version=21005
 *
 * [1697] 检查边长度限制的路径是否存在
 *
 * https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/description/
 *
 * algorithms
 * Hard (55.39%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 8K
 * Testcase Example:  '3\n[[0,1,2],[1,2,4],[2,0,8],[1,0,16]]\n[[0,1,2],[0,2,5]]'
 *
 * 给你一个 n 个点组成的无向图边集 edgeList ，其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi
 * 之间有一条长度为 disi 的边。请注意，两个点之间可能有 超过一条边 。
 *
 * 给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj] ，你的任务是对于每个查询 queries[j]
 * ，判断是否存在从 pj 到 qj 的路径，且这条路径上的每一条边都 严格小于 limitj 。
 *
 * 请你返回一个 布尔数组 answer ，其中 answer.length == queries.length ，当 queries[j] 的查询结果为
 * true 时， answer 第 j 个值为 true ，否则为 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries =
 * [[0,1,2],[0,2,5]]
 * 输出：[false,true]
 * 解释：上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
 * 对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
 * 对于第二个查询，有一条路径（0 -> 1 -> 2）两条边都小于 5 ，所以这个查询我们返回 true 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries =
 * [[0,4,14],[1,4,13]]
 * 输出：[true,false]
 * 解释：上图为给定数据。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^5
 * 1 <= edgeList.length, queries.length <= 10^5
 * edgeList[i].length == 3
 * queries[j].length == 3
 * 0 <= ui, vi, pj, qj <= n - 1
 * ui != vi
 * pj != qj
 * 1 <= disi, limitj <= 10^9
 * 两个点之间可能有 多条 边。
 *
 *
 */
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
// @lc code=start

class unionFind
{
public:
    vector<int> v_father;
    unionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            v_father.push_back(i);
        }
    }
    int get(int i)
    {
        if (v_father[i] == i)
        {
            return i;
        }
        v_father[i] = get(v_father[i]);
        return v_father[i];
    }
    void set(int a, int b)
    {
        int fa = get(a);
        int fb = get(b);
        if (fa > fb)
        {
            v_father[fa] = fb;
        }
        else if (fb > fa)
        {
            v_father[fb] = fa;
        }
    }
};

class Solution
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        vector<pair<int, vector<int>>> vpivi;
        for (int i = 0; i < queries.size(); i++)
        {
            vpivi.push_back({i, queries[i]});
        }
        sort(vpivi.begin(), vpivi.end(), [](const pair<int, vector<int>> &left, const pair<int, vector<int>> &right)
             { return (left.second[2] < right.second[2]); });

        sort(edgeList.begin(), edgeList.end(), [](const vector<int> &left, const vector<int> &right)
             { return left[2] < right[2]; });
        unionFind *uf = new unionFind(n + 10);
        vector<bool> result(queries.size());
        int edge_index = 0;
        for (int i = 0; i < vpivi.size(); i++)
        {
            pair<int, vector<int>> temp = vpivi[i];
            int result_index = temp.first;
            int node_a = temp.second[0];
            int node_b = temp.second[1];
            int node_len = temp.second[2];
            while (edge_index < edgeList.size() && edgeList[edge_index][2] < node_len)
            {

                int edg_a = edgeList[edge_index][0];
                int edg_b = edgeList[edge_index][1];
                uf->set(edg_a, edg_b);
                edge_index++;
            }
            result[result_index] = (uf->get(node_a) == uf->get(node_b));
        }
        return result;
    }
};

// @lc code=end

/*
// @lcpr case=start
// 3\n[[0,1,2],[1,2,4],[2,0,8],[1,0,16]]\n[[0,1,2],[0,2,5]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,10],[1,2,5],[2,3,9],[3,4,13]]\n[[0,4,14],[1,4,13]]\n
// @lcpr case=end

 */
