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











class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> result(n, -1);
        unordered_map<int, unordered_map<int, int>> all;
        for(int i = 0; i < red_edges.size(); i++){
            all[red_edges[i][0]][red_edges[i][1]] += 1;
        }
        for(int i = 0; i < blue_edges.size(); i++){
            all[blue_edges[i][0]][blue_edges[i][1]] += 2;
        }

        queue<vector<int>> q;
        q.push({0, 0, 0});
        unordered_map<int, unordered_set<int>> vis;
        while (q.size() > 0)
        {
            vector<int> cur = q.front();
            q.pop();

            if(result[cur[0]] == -1){
                result[cur[0]] = cur[1];
            }
            if(cur[2] > 0){
                vis[cur[2]].insert(cur[0]);
            }

            for( auto x :all[cur[0]]){
                // std::cout << "当前:遍历标记" << vis[3 - cur[2]].count(x.first) << ":"<< cur[0] << ":" << x.first << ":type:" << x.second << std::endl;
                if(vis[3 - cur[2]].count(x.first) < 1 && (x.second != cur[2] || x.second == 3)){
                    if(x.second == 3){
                        all[cur[0]][x.first] = cur[2];
                        x.second = 3 - cur[2];
                        // std::cout << "原本是3调整后" << cur[0] <<"," <<x.first << ":" << all[cur[0]][x.first] << std::endl;
                    }
                    // std::cout << "进入当前:" << cur[0] << ":" << x.first << ":type:" << x.second << std::endl;
                    q.push({x.first, cur[1] + 1, x.second});
                }
            }
        }
        return result;
    }
};



// @lc code=end

