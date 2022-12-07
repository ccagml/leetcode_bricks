/*
 * @lc app=leetcode.cn id=2467 lang=cpp
 * @lcpr version=20702
 *
 * [2467] 树上最大得分和路径
 *
 * https://leetcode.cn/problems/most-profitable-path-in-a-tree/description/
 *
 * algorithms
 * Medium (48.01%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 4.6K
 * Testcase Example:  '[[0,1],[1,2],[1,3],[3,4]]\n3\n[-2,4,2,-4,6]'
 *
 * 一个 n 个节点的无向树，节点编号为 0 到 n - 1 ，树的根结点是 0 号节点。给你一个长度为 n - 1 的二维整数数组 edges ，其中
 * edges[i] = [ai, bi] ，表示节点 ai 和 bi 在树中有一条边。
 *
 * 在每一个节点 i 处有一扇门。同时给你一个都是偶数的数组 amount ，其中 amount[i] 表示：
 *
 *
 * 如果 amount[i] 的值是负数，那么它表示打开节点 i 处门扣除的分数。
 * 如果 amount[i] 的值是正数，那么它表示打开节点 i 处门加上的分数。
 *
 *
 * 游戏按照如下规则进行：
 *
 *
 * 一开始，Alice 在节点 0 处，Bob 在节点 bob 处。
 * 每一秒钟，Alice 和 Bob 分别 移动到相邻的节点。Alice 朝着某个 叶子结点 移动，Bob 朝着节点 0 移动。
 * 对于他们之间路径上的 每一个 节点，Alice 和 Bob 要么打开门并扣分，要么打开门并加分。注意：
 *
 * 如果门 已经打开 （被另一个人打开），不会有额外加分也不会扣分。
 * 如果 Alice 和 Bob 同时 到达一个节点，他们会共享这个节点的加分或者扣分。换言之，如果打开这扇门扣 c 分，那么 Alice 和 Bob
 * 分别扣 c / 2 分。如果这扇门的加分为 c ，那么他们分别加 c / 2 分。
 *
 *
 * 如果 Alice 到达了一个叶子结点，她会停止移动。类似的，如果 Bob 到达了节点 0 ，他也会停止移动。注意这些事件互相 独立
 * ，不会影响另一方移动。
 *
 *
 * 请你返回 Alice 朝最优叶子结点移动的 最大 净得分。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
 * 输出：6
 * 解释：
 * 上图展示了输入给出的一棵树。游戏进行如下：
 * - Alice 一开始在节点 0 处，Bob 在节点 3 处。他们分别打开所在节点的门。
 * ⁠ Alice 得分为 -2 。
 * - Alice 和 Bob 都移动到节点 1 。
 * 因为他们同时到达这个节点，他们一起打开门并平分得分。
 * Alice 的得分变为 -2 + (4 / 2) = 0 。
 * - Alice 移动到节点 3 。因为 Bob 已经打开了这扇门，Alice 得分不变。
 * Bob 移动到节点 0 ，并停止移动。
 * - Alice 移动到节点 4 并打开这个节点的门，她得分变为 0 + 6 = 6 。
 * 现在，Alice 和 Bob 都不能进行任何移动了，所以游戏结束。
 * Alice 无法得到更高分数。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：edges = [[0,1]], bob = 1, amount = [-7280,2350]
 * 输出：-7280
 * 解释：
 * Alice 按照路径 0->1 移动，同时 Bob 按照路径 1->0 移动。
 * 所以 Alice 只打开节点 0 处的门，她的得分为 -7280 。
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
 * edges 表示一棵有效的树。
 * 1 <= bob < n
 * amount.length == n
 * amount[i] 是范围 [-10^4, 10^4] 之间的一个 偶数 。
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

// 计算 bob到0中间的线路, 将一半设置成0;
// 遍历到所有节点的值取最大
class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> uiuii;
    unordered_map<int, int> uii;

    int get_father(int b)
    {
        if (b == 0)
        {
            return 0;
        }
        int b_ceng = uii[b];
        for (pair<int, int> pii : uiuii[b])
        {
            if (uii[pii.first] == b_ceng - 1)
            {
                return pii.first;
            }
        }
        return 0;
    }
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        for (vector<int> &ee : edges)
        {
            uiuii[ee[0]][ee[1]] = 1;
            uiuii[ee[1]][ee[0]] = 1;
        }
        // 计算层
        queue<int> qi;
        qi.push(0);
        int ceng = 0;
        uii[0] = 0;
        int max_ceng = 0;
        while (qi.size() > 0)
        {
            int n = qi.size();
            for (int i = 0; i < n; i++)
            {
                int cur = qi.front();
                uii[cur] = ceng;
                qi.pop();
                for (pair<int, int> pii : uiuii[cur])
                {
                    if (uii.count(pii.first) < 1)
                    {
                        qi.push(pii.first);
                    }
                }
            }
            max_ceng = ceng;
            ceng++;
        }
        vector<int> b_to_0;
        int cur_b = bob;
        while (cur_b != 0)
        {
            b_to_0.push_back(cur_b);
            cur_b = get_father(cur_b);
        }
        b_to_0.push_back(0);
        if (b_to_0.size() % 2 == 1)
        {
            int end = b_to_0.size() / 2;
            for (int i = 0; i < end; i++)
            {
                int b_node = b_to_0[i];
                amount[b_node] = 0;
            }
            amount[b_to_0[end]] /= 2;
        }
        else
        {
            int end = b_to_0.size() / 2;
            for (int i = 0; i < end; i++)
            {
                int b_node = b_to_0[i];
                amount[b_node] = 0;
            }
        }

        // std::cout << "路径:";
        // for (int j : b_to_0)
        // {
        //     std::cout << j << ",";
        // }
        // std::cout << "\namount:";
        // for (int j : amount)
        // {
        //     std::cout << j << ",";
        // }

        // 遍历到叶子节点的最大值?
        queue<pair<int, int>> qpii;
        qpii.push({0, amount[0]});
        int max_result = -999999999;

        while (qpii.size() > 0)
        {
            pair<int, int> cur = qpii.front();
            qpii.pop();
            int cur_node_id = cur.first;
            int cur_ceng = uii[cur_node_id];
            int cur_node_value = cur.second;
            for (pair<int, int> next : uiuii[cur_node_id])
            {
                int next_id = next.first;
                if (uii[next_id] == cur_ceng + 1)
                {
                    // std::cout << "(" << next_id << "," << cur_node_value + amount[next_id] << ")";
                    qpii.push({next_id, cur_node_value + amount[next_id]});
                }
            }
            if (cur_ceng == max_ceng)
            {
                max_result = max(max_result, cur_node_value);
            }
        }
        return max_result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[1,2],[1,3],[3,4]]\n3\n[-2,4,2,-4,6]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1]]\n1\n[-7280,2350]\n
// @lcpr case=end

 */
