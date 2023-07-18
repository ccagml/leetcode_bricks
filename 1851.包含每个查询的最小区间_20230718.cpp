// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1851 lang=cpp
 * @lcpr version=21910
 *
 * [1851] 包含每个查询的最小区间
 *
 * https://leetcode.cn/problems/minimum-interval-to-include-each-query/description/
 *
 * algorithms
 * Hard (44.23%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 10K
 * Testcase Example:  '[[1,4],[2,4],[3,6],[4,4]]\n[2,3,4,5]'
 *
 * 给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti
 * 、结束于 righti（包含两侧取值，闭区间）。区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。
 *
 * 再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i
 * 的长度 。如果不存在这样的区间，那么答案是 -1 。
 *
 * 以数组形式返回对应查询的所有答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
 * 输出：[3,3,1,4]
 * 解释：查询处理如下：
 * - Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
 * - Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
 * - Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
 * - Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。
 *
 *
 * 示例 2：
 *
 * 输入：intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
 * 输出：[2,-1,4,6]
 * 解释：查询处理如下：
 * - Query = 2 ：区间 [2,3] 是包含 2 的最小区间，答案为 3 - 2 + 1 = 2 。
 * - Query = 19：不存在包含 19 的区间，答案为 -1 。
 * - Query = 5 ：区间 [2,5] 是包含 5 的最小区间，答案为 5 - 2 + 1 = 4 。
 * - Query = 22：区间 [20,25] 是包含 22 的最小区间，答案为 25 - 20 + 1 = 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 1 <= lefti <= righti <= 10^7
 * 1 <= queries[j] <= 10^7
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
int temp_max = 99999999;

class segmentTree
{
private:
    class segmentTreeNode
    {
    public:
        segmentTreeNode(int l, int r)
        {
            left = l;
            right = r;
            val = 0;
            temp_add = 0;
            min_v = temp_max;
            left_son = nullptr;
            right_son = nullptr;
            push_down_flag = true;
        }
        int id;
        int left;
        int right;
        long long min_v = 0;
        bool push_down_flag;
        long long val;
        long long temp_add;
        segmentTreeNode *left_son;
        segmentTreeNode *right_son;
    };

    int all_left, all_right;

    void modify(segmentTreeNode *cur_node, int cur_l, int cur_r, int need_L, int need_R, long long new_v)
    {
        cur_node->push_down_flag = true;
        //  cur_l   need_L  need_R  cur_r
        //  范围外
        if (cur_l > need_R || cur_r < need_L)
        {
            return;
        }

        // 全包含了,不往下递推
        if (need_L <= cur_l && cur_r <= need_R && cur_node->left_son == nullptr && cur_node->right_son == nullptr)
        {
            cur_node->min_v = min(new_v, cur_node->min_v);

            // 2 3-6 10  /  3  -  6 == 5
            return;
        }
        int old_min_v = cur_node->min_v;
        cur_node->min_v = temp_max;
        // 继续下推
        int mid = (cur_l + cur_r) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        if (old_min_v != temp_max)
        {
            modify(cur_node->left_son, cur_l, mid, cur_l, cur_r, old_min_v);
            modify(cur_node->right_son, mid + 1, cur_r, cur_l, cur_r, old_min_v);
        }
        modify(cur_node->left_son, cur_l, mid, need_L, need_R, new_v);
        modify(cur_node->right_son, mid + 1, cur_r, need_L, need_R, new_v);
    }

    segmentTreeNode *root;
    long long query_min(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
    {
        if (cur_node == nullptr)
        {
            return temp_max;
        }
        if (cur_l > NEED_R || cur_r < NEED_L)
        {
            return temp_max;
        }

        if (cur_node->left_son == nullptr && cur_node->right_son == nullptr && cur_l <= NEED_L && NEED_R <= cur_r)
        {
            return cur_node->min_v;
        }
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->min_v;
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        return min(query_min(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_min(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
    }

public:
    segmentTree(int left, int right)
    {

        root = new segmentTreeNode(left, right);
        all_left = left;
        all_right = right;
    }

    void modify(int l, int r, long long new_v)
    {
        modify(root, all_left, all_right, l, r, new_v);
    }
    int query(int l, int r)
    {
        return query_min(root, all_left, all_right, l, r);
    }
};

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        segmentTree *st = new segmentTree(1, 10000002);
        for (int i = 0; i < intervals.size(); i++)
        {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = b - a + 1;
            st->modify(a, b, c);
        }
        vector<int> result;
        for (int q : queries)
        {
            int temp_q = st->query(q, q);
            result.push_back(((temp_q == temp_max) ? -1 : temp_q));
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minInterval
// paramTypes= ["number[][]","number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,4],[2,4],[3,6],[4,4]]\n[2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[2,5],[1,8],[20,25]]\n[2,19,5,22]\n
// @lcpr case=end

// @lcpr case=start
// [[4,5],[5,8],[1,9],[8,10],[1,6]]\n[7,9,3,9,3]\n
// @lcpr case=end
//[4,3,6,3,6]

 */
