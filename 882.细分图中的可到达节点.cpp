/*
 * @lc app=leetcode.cn id=882 lang=cpp
 * @lcpr version=20401
 *
 * [882] 细分图中的可到达节点
 *
 * https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/description/
 *
 * algorithms
 * Hard (64.35%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 22.4K
 * Testcase Example:  '[[0,1,10],[0,2,1],[1,2,2]]\n6\n3'
 *
 * 给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1 。你决定将图中的每条边 细分 为一条节点链，每条边之间的新节点数各不相同。
 *
 * 图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti] 表示原始图中节点 ui 和 vi
 * 之间存在一条边，cnti 是将边 细分 后的新节点总数。注意，cnti == 0 表示边不可细分。
 *
 * 要 细分 边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti 个新节点。新节点为 x1, x2, ..., xcnti
 * ，新边为 [ui, x1], [x1, x2], [x2, x3], ..., [xcnti+1, xcnti], [xcnti, vi] 。
 *
 * 现在得到一个 新的细分图 ，请你计算从节点 0 出发，可以到达多少个节点？如果节点间距离是 maxMoves 或更少，则视为 可以到达 。
 *
 * 给你原始图和 maxMoves ，返回 新的细分图中从节点 0 出发 可到达的节点数 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
 * 输出：13
 * 解释：边的细分情况如上图所示。
 * 可以到达的节点已经用黄色标注出来。
 *
 *
 * 示例 2：
 *
 * 输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
 * 输出：23
 *
 *
 * 示例 3：
 *
 * 输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
 * 输出：1
 * 解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= edges.length <= min(n * (n - 1) / 2, 10^4)
 * edges[i].length == 3
 * 0 <= ui < vi < n
 * 图中 不存在平行边
 * 0 <= cnti <= 10^4
 * 0 <= maxMoves <= 10^9
 * 1 <= n <= 3000
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
// @lc code=start
class Solution
{
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        unordered_map<int, unordered_map<int, int>> umii;
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int c = edges[i][2];
            umii[a][b] = c;
            umii[b][a] = c;
        }
        //自定义比较函数pair//返回true使得第一个参数排后面
        auto cmp_pair = [](const std::pair<int, int> &t1, const std::pair<int, int> &t2)
        {
            // true使得t1排后面?
            if (t1.first < t2.first)
            {
                return true;
            }
            else if (t1.first == t2.first && t1.second < t2.second)
            {
                return true;
            }
            return false;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp_pair)> pair_pq(cmp_pair);

        pair_pq.push({maxMoves, 0});

        unordered_set<int> node_flag;
        node_flag.insert(0);

        int result = 1;

        unordered_map<int, unordered_map<int, int>> already_num;

        unordered_map<int, int> last_in;
        last_in[0] = maxMoves;

        while (pair_pq.size() > 0)
        {
            std::pair<int, int> cur = pair_pq.top();
            pair_pq.pop();
            int can_go = cur.first;
            int cur_node = cur.second;
            for (pair<int, int> next : umii[cur_node])
            {
                int next_node = next.first;
                int next_len = next.second;
                int a_to_b = already_num[cur_node][next_node];
                int b_to_a = already_num[next_node][cur_node];
                if (can_go > a_to_b)
                {
                    int shengyu = next_len - a_to_b - b_to_a;
                    int to_add_result = can_go - a_to_b;
                    int add_min = min(shengyu, to_add_result);
                    if (add_min > 0)
                    {
                        result += add_min;
                        // std::cout << cur_node << "->" << next_node << "结果+" << add_min << ":next_len:" << next_len << ":a_to_b:" << a_to_b << ":b_to_a:" << b_to_a << std::endl;
                        already_num[cur_node][next_node] += add_min;
                    }
                }
                if (can_go > next_len)
                {
                    if (node_flag.count(next_node) < 1)
                    {
                        result++;
                        // std::cout << "新到达" << next_node << "结果+1";
                    }
                    node_flag.insert(next_node);
                    int sheng = can_go - next_len - 1;
                    if (sheng > 0 && sheng > last_in[next_node])
                    {
                        last_in[next_node] = sheng;
                        // std::cout << "(" << next_node << "," << sheng << ")";
                        pair_pq.push({(can_go - next_len - 1), next_node});
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,10],[0,2,1],[1,2,2]]\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,4],[1,2,6],[0,2,8],[1,3,1]]\n10\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]]\n17\n5\n
// @lcpr case=end

 */
