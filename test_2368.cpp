/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
 *
 * https://leetcode.cn/problems/reachable-nodes-with-restrictions/description/
 *
 * algorithms
 * Medium (42.91%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 16.5K
 * Testcase Example:  '7\n[[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]]\n[4,5]'
 *
 * 现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，共有 n - 1 条边。
 *
 * 给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi
 * 之间存在一条边。另给你一个整数数组 restricted 表示 受限 节点。
 *
 * 在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。
 *
 * 注意，节点 0 不 会标记为受限节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
 * 输出：4
 * 解释：上图所示正是这棵树。
 * 在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。
 *
 * 示例 2：
 *
 * 输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted =
 * [4,2,1]
 * 输出：3
 * 解释：上图所示正是这棵树。
 * 在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * edges 表示一棵有效的树
 * 1 <= restricted.length < n
 * 1 <= restricted[i] < n
 * restricted 中的所有值 互不相同
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        unordered_set<int> usi;
        for (int i = 0; i < restricted.size(); i++)
        {
            usi.insert(restricted[i]);
        }
        unordered_map<int, unordered_set<int>> uivi;
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            if (usi.count(a) == 0 && usi.count(b) == 0)
            {
                uivi[a].insert(b);
                uivi[b].insert(a);
            }
        }
        unordered_set<int> flag;
        queue<int> qi;
        qi.push(0);
        int result = 1;
        vector<int> qq;
        // qq.push_back(0);
        flag.insert(0);
        while (!qi.empty())
        {
            int cur = qi.front();
            qi.pop();

            for (const auto &no_i : uivi[cur])
            {
                if (flag.count(no_i) == 0)
                {
                    qi.push(no_i);
                    flag.insert(no_i);
                    result++;
                    // qq.push_back(no_i);
                }
            }
        }
        // for (int i = 0; i < qq.size(); i++)
        // {
        //     std::cout << qq[i] << ",";
        // }

        return result;
    }
};
// @lc code=end
