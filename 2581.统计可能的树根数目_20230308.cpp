// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 * @lcpr version=21801
 *
 * [2581] 统计可能的树根数目
 *
 * https://leetcode.cn/problems/count-number-of-possible-root-nodes/description/
 *
 * algorithms
 * Hard (54.29%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 3.1K
 * Testcase Example:  '[[0,1],[1,2],[1,3],[4,2]]\n[[1,3],[0,1],[1,0],[2,4]]\n3'
 *
 * Alice 有一棵 n 个节点的树，节点编号为 0 到 n - 1 。树用一个长度为 n - 1 的二维整数数组 edges 表示，其中
 * edges[i] = [ai, bi] ，表示树中节点 ai 和 bi 之间有一条边。
 *
 * Alice 想要 Bob 找到这棵树的根。她允许 Bob 对这棵树进行若干次 猜测 。每一次猜测，Bob 做如下事情：
 *
 *
 * 选择两个 不相等 的整数 u 和 v ，且树中必须存在边 [u, v] 。
 * Bob 猜测树中 u 是 v 的 父节点 。
 *
 *
 * Bob 的猜测用二维整数数组 guesses 表示，其中 guesses[j] = [uj, vj] 表示 Bob 猜 uj 是 vj 的父节点。
 *
 * Alice 非常懒，她不想逐个回答 Bob 的猜测，只告诉 Bob 这些猜测里面 至少 有 k 个猜测的结果为 true 。
 *
 * 给你二维整数数组 edges ，Bob 的所有猜测和整数 k ，请你返回可能成为树根的 节点数目 。如果没有这样的树，则返回 0。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：edges = [[0,1],[1,2],[1,3],[4,2]], guesses = [[1,3],[0,1],[1,0],[2,4]], k
 * = 3
 * 输出：3
 * 解释：
 * 根为节点 0 ，正确的猜测为 [1,3], [0,1], [2,4]
 * 根为节点 1 ，正确的猜测为 [1,3], [1,0], [2,4]
 * 根为节点 2 ，正确的猜测为 [1,3], [1,0], [2,4]
 * 根为节点 3 ，正确的猜测为 [1,0], [2,4]
 * 根为节点 4 ，正确的猜测为 [1,3], [1,0]
 * 节点 0 ，1 或 2 为根时，可以得到 3 个正确的猜测。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：edges = [[0,1],[1,2],[2,3],[3,4]], guesses = [[1,0],[3,4],[2,1],[3,2]], k
 * = 1
 * 输出：5
 * 解释：
 * 根为节点 0 ，正确的猜测为 [3,4]
 * 根为节点 1 ，正确的猜测为 [1,0], [3,4]
 * 根为节点 2 ，正确的猜测为 [1,0], [2,1], [3,4]
 * 根为节点 3 ，正确的猜测为 [1,0], [2,1], [3,2], [3,4]
 * 根为节点 4 ，正确的猜测为 [1,0], [2,1], [3,2]
 * 任何节点为根，都至少有 1 个正确的猜测。
 *
 *
 *
 *
 * 提示：
 *
 *
 * edges.length == n - 1
 * 2 <= n <= 10^5
 * 1 <= guesses.length <= 10^5
 * 0 <= ai, bi, uj, vj <= n - 1
 * ai != bi
 * uj != vj
 * edges 表示一棵有效的树。
 * guesses[j] 是树中的一条边。
 * guesses 是唯一的。
 * 0 <= k <= guesses.length
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
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    int zero_true = 0;
    unordered_set<string> usll;

    unordered_map<int, vector<int>> uivi;
    int kkk = 0;

    int result = 0;
    void dfs(int cur, int fa)
    {

        zero_true += usll.count(create_v(fa, cur));

        for (int son : uivi[cur])
        {
            if (son != fa)
            {
                dfs(son, cur);
            }
        }
    }

    string create_v(int a, int b)
    {
        return std::to_string(a) + "|" + std::to_string(b);
    }

    void reroot(int cur, int fa, int cnt)
    {

        result += (cnt >= kkk);
        for (int son : uivi[cur])
        {
            if (son != fa)
            {
                reroot(son, cur, cnt - usll.count(create_v(cur, son)) + usll.count(create_v(son, cur)));
            }
        }
    }
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        kkk = k;
        // 建立
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            uivi[a].push_back(b);
            uivi[b].push_back(a);
        }

        // 合并猜测
        for (int i = 0; i < guesses.size(); i++)
        {
            int a = guesses[i][0];
            int b = guesses[i][1];
            usll.insert(create_v(a, b));
        }

        // 计算以0为根正确的数量
        dfs(0, -1);

        // 换根

        reroot(0, -1, zero_true);

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=rootCount
// paramTypes=["number[][]","number[][]","number"]
// returnType=number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[0,1],[1,2],[1,3],[4,2]]\n[[1,3],[0,1],[1,0],[2,4]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[1,2],[2,3],[3,4]]\n[[1,0],[3,4],[2,1],[3,2]]\n1\n
// @lcpr case=end

 */
