/*
 * @lc app=leetcode.cn id=1129 lang=cpp
 *
 * [1129] 颜色交替的最短路径
 *
 * https://leetcode-cn.com/problems/shortest-path-with-alternating-colors/description/
 *
 * algorithms
 * Medium (38.09%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 16.7K
 * Testcase Example:  '3\n[[0,1],[1,2]]\n[]'
 *
 * 在一个有向图中，节点分别标记为 0, 1, ..., n-1。这个图中的每条边不是红色就是蓝色，且存在自环或平行边。
 *
 * red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。类似地，blue_edges 中的每一个 [i, j]
 * 对表示从节点 i 到节点 j 的蓝色有向边。
 *
 * 返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X
 * 的红色边和蓝色边交替出现的最短路径的长度。如果不存在这样的路径，那么 answer[x] = -1。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
 * 输出：[0,1,-1]
 *
 *
 * 示例 2：
 *
 * 输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
 * 输出：[0,1,-1]
 *
 *
 * 示例 3：
 *
 * 输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
 * 输出：[0,-1,-1]
 *
 *
 * 示例 4：
 *
 * 输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
 * 输出：[0,1,2]
 *
 *
 * 示例 5：
 *
 * 输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
 * 输出：[0,1,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 100
 * red_edges.length <= 400
 * blue_edges.length <= 400
 * red_edges[i].length == blue_edges[i].length == 2
 * 0 <= red_edges[i][j], blue_edges[i][j] < n
 *
 *
 */

// @lc code=start

class Solution
{

    // 广度搜索 模拟
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        struct red_blue
        {
            bool red;
            bool blue;
        };

        vector<int> result(n, -1);
        unordered_map<int, unordered_map<int, red_blue>> all;
        for (int i = 0; i < red_edges.size(); i++)
        {
            all[red_edges[i][0]][red_edges[i][1]].red = true;
        }
        for (int i = 0; i < blue_edges.size(); i++)
        {
            all[blue_edges[i][0]][blue_edges[i][1]].blue = true;
        }
        struct queue_status
        {
            int from;
            int cnt;
            red_blue rb;
        };

        queue<queue_status> q;
        queue_status s = {0, 0, {true, true}};
        q.push(s);
        unordered_map<int, red_blue> vis;
        while (q.size() > 0)
        {
            queue_status cur = q.front();
            q.pop();

            if (result[cur.from] == -1)
            {
                result[cur.from] = cur.cnt;
            }
            if (cur.rb.blue)
            {
                vis[cur.from].blue = true;
            }
            if (cur.rb.red)
            {
                vis[cur.from].red = true;
            }

            for (auto next_node : all[cur.from])
            {
                // std::cout << "当前:" << cur.from << "->"  << "next_node.first" << std::endl;
                if (cur.rb.blue && next_node.second.red && (!vis[next_node.first].red))
                {
                    // std::cout << "蓝:" << cur.from << "->红:"  << next_node.first << std::endl;
                    queue_status s = {next_node.first, cur.cnt + 1, {true, false}};
                    q.push(s);
                }
                if (cur.rb.red && next_node.second.blue && (!vis[next_node.first].blue))
                {
                    // std::cout << "红:" << cur.from << "->蓝:"  << next_node.first << std::endl;
                    queue_status s = {next_node.first, cur.cnt + 1, {false, true}};
                    q.push(s);
                }
            }
        }
        return result;
    }
};

// @lc code=end
