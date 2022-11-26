/*
 * @lc app=leetcode.cn id=882 lang=cpp
 * @lcpr version=20204
 *
 * [882] 细分图中的可到达节点
 *
 * https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/description/
 *
 * algorithms
 * Hard (57.80%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 9.1K
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

// 1.只想到遍历
// 2.写了很久
// 3.超时,优化, 优先级队列 让剩余步数多的先走
using namespace std;
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution
{
public:
    void print_u(unordered_map<int, unordered_map<int, int>> &uiuii)
    {
        for (pair<int, unordered_map<int, int>> pu : uiuii)
        {
            std::cout << pu.first << "到:";
            for (pair<int, int> puu : pu.second)
            {
                std::cout << "(" << puu.first << "," << puu.second << ")";
            }
            std::cout << std::endl;
        }
    }

    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
    {
        int result = 1;
        unordered_map<int, unordered_map<int, int>> uiuii;
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> vi = edges[i];
            int a0 = vi[0];
            int a1 = vi[1];
            int a2 = vi[2];
            uiuii[a0][a1] = a2;
            uiuii[a1][a0] = a2;
        }

        // print_u(uiuii);
        // queue<pair<int, int>> qpii;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>> qpii;
        unordered_set<int> inqpii;
        qpii.push({maxMoves, 0});
        inqpii.insert(0);
        unordered_map<int, unordered_map<int, int>> a_to_b_n;
        unordered_map<int, int> p_max;

        while (qpii.size() > 0)
        {
            pair<int, int> a = qpii.top();
            qpii.pop();
            int a_node = a.second;
            int a_can_move = a.first;
            // 可走的方向
            for (pair<int, int> b_n : uiuii[a_node])
            {
                int b_node = b_n.first;
                int mid_b = b_n.second;
                // 获取 b 到当前走了几个点
                int b_to_a = a_to_b_n[b_node][a_node];
                int a_to_b = a_to_b_n[a_node][b_node];
                int can_add_min = mid_b - b_to_a - a_to_b;
                int result_add = min(can_add_min, (a_can_move - a_to_b));
                a_to_b_n[a_node][b_node] = max(a_to_b, min(a_can_move, mid_b));
                if (result_add > 0)
                {
                    // std::cout << a_node << ":to:" << b_node << ":add:" << result_add << std::endl;
                    result += result_add;
                }
                // 可以到达b
                if (a_can_move - mid_b > 0)
                {
                    // 第一次到
                    if (inqpii.count(b_node) < 1)
                    {
                        result++;
                        // std::cout << a_node << ":to:" << b_node << ":第一次到达:" << std::endl;
                    }
                    inqpii.insert(b_node);
                    // 是否可以进去
                    int next_can = a_can_move - mid_b - 1;
                    if (next_can > 0)
                    {
                        // std::cout << b_node << "可以继续走:" << next_can << std::endl;
                        if (p_max[b_node] < next_can)
                        {
                            p_max[b_node] = next_can;
                            qpii.push({next_can, b_node});
                        }
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


// @lcpr case=start
// [[1,3,23],[3,5,19],[3,6,17],[1,5,14],[6,7,20],[1,4,10],[1,6,0],[3,4,20],[1,7,4],[0,4,10],[0,7,9],[2,3,3],[3,7,9],[5,7,4],[4,5,16],[0,1,16],[2,6,0],[4,7,11],[2,5,14],[5,6,22],[4,6,12],[0,6,2],[0,2,1],[2,4,22],[2,7,20]]\n19\n8
// @lcpr case=end

// @lcpr case=start
// [[1,2,1],[1,3,1],[2,3,1],[1,4,1],[1,5,1],[1,6,1],[1,7,1],[1,8,1],[0,1,1]]\n10000\n9
// @lcpr case=end

 */
