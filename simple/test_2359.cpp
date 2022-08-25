/*
 * @lc app=leetcode.cn id=2359 lang=cpp
 *
 * [2359] 找到离给定两个节点最近的节点
 *
 * https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/description/
 *
 * algorithms
 * Medium (28.63%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 22.7K
 * Testcase Example:  '[2,2,3,-1]\n0\n1'
 *
 * 给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，每个节点 至多 有一条出边。
 *
 * 有向图用大小为 n 下标从 0 开始的数组 edges 表示，表示节点 i 有一条有向边指向 edges[i] 。如果节点 i 没有出边，那么
 * edges[i] == -1 。
 *
 * 同时给你两个节点 node1 和 node2 。
 *
 * 请你返回一个从 node1 和 node2 都能到达节点的编号，使节点 node1 和节点 node2 到这个节点的距离
 * 较大值最小化。如果有多个答案，请返回 最小 的节点编号。如果答案不存在，返回 -1 。
 *
 * 注意 edges 可能包含环。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：edges = [2,2,3,-1], node1 = 0, node2 = 1
 * 输出：2
 * 解释：从节点 0 到节点 2 的距离为 1 ，从节点 1 到节点 2 的距离为 1 。
 * 两个距离的较大值为 1 。我们无法得到一个比 1 更小的较大值，所以我们返回节点 2 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：edges = [1,2,-1], node1 = 0, node2 = 2
 * 输出：2
 * 解释：节点 0 到节点 2 的距离为 2 ，节点 2 到它自己的距离为 0 。
 * 两个距离的较大值为 2 。我们无法得到一个比 2 更小的较大值，所以我们返回节点 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == edges.length
 * 2 <= n <= 10^5
 * -1 <= edges[i] < n
 * edges[i] != i
 * 0 <= node1, node2 < n
 *
 *
 */

// @lc code=start
// 1714分
class Solution
{
    // 题目没理解 是两个距离的较大值, 两个距离和的最小值
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        unordered_map<int, int> uii1;
        unordered_map<int, int> uii2;
        int len1 = 0;
        int start_1 = node1;
        uii1[start_1] = len1;
        while (edges[start_1] != -1)
        {
            if (uii1.count(edges[start_1]) > 0)
            {
                break;
            }
            // uii1[start_1] = len1;
            len1++;
            uii1[edges[start_1]] = len1;
            start_1 = edges[start_1];
            // std::cout << start_1 << ":";
        }
        // std::cout << std::endl;
        int len2 = 0;
        int start_2 = node2;
        uii2[start_2] = len2;
        while (edges[start_2] != -1)
        {
            if (uii2.count(edges[start_2]) > 0)
            {
                break;
            }
            // uii2[start_2] = len2;
            len2++;
            uii2[edges[start_2]] = len2;
            start_2 = edges[start_2];

            // std::cout << start_2 << ":";
        }
        // std::cout << std::endl;
        vector<pair<int, int>> vpii;
        int sum = 99999999;
        int node = -1;
        for (pair<int, int> p1 : uii1)
        {
            if (uii2.count(p1.first) > 0)
            {
                // std::cout << "到" << p1.first << "|" << p1.second << ":" << uii2[p1.first] << std::endl;
                int temp_sum = max(p1.second, uii2[p1.first]);
                if (temp_sum < sum)
                {
                    sum = temp_sum;
                    node = p1.first;
                }
                else if (temp_sum == sum && p1.first < node)
                {
                    node = p1.first;
                }
            }
        }
        return node;
    }
};
// @lc code=end
