// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2569 lang=cpp
 * @lcpr version=21708
 *
 * [2569] 更新数组后处理求和查询
 *
 * https://leetcode.cn/problems/handling-sum-queries-after-update/description/
 *
 * algorithms
 * Hard (37.34%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 5.4K
 * Testcase Example:  '[1,0,1]\n[0,0,0]\n[[1,1,1],[2,1,0],[3,0,0]]'
 *
 * 给你两个下标从 0 开始的数组 nums1 和 nums2 ，和一个二维数组 queries 表示一些操作。总共有 3 种类型的操作：
 *
 *
 * 操作类型 1 为 queries[i] = [1, l, r] 。你需要将 nums1 从下标 l 到下标 r 的所有 0 反转成 1 或将 1 反转成
 * 0 。l 和 r 下标都从 0 开始。
 * 操作类型 2 为 queries[i] = [2, p, 0] 。对于 0 <= i < n 中的所有下标，令 nums2[i] = nums2[i] + nums1[i] * p 。
 * 操作类型 3 为 queries[i] = [3, 0, 0] 。求 nums2 中所有元素的和。
 *
 *
 * 请你返回一个数组，包含所有第三种操作类型的答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,0,1], nums2 = [0,0,0], queries = [[1,1,1],[2,1,0],[3,0,0]]
 * 输出：[3]
 * 解释：第一个操作后 nums1 变为 [1,1,1] 。第二个操作后，nums2 变成 [1,1,1] ，所以第三个操作的答案为 3 。所以返回 [3]
 * 。
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [1], nums2 = [5], queries = [[2,0,0],[3,0,0]]
 * 输出：[5]
 * 解释：第一个操作后，nums2 保持不变为 [5] ，所以第二个操作的答案是 5 。所以返回 [5] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length,nums2.length <= 10^5
 * nums1.length = nums2.length
 * 1 <= queries.length <= 10^5
 * queries[i].length = 3
 * 0 <= l <= r <= nums1.length - 1
 * 0 <= p <= 10^6
 * 0 <= nums1[i] <= 1
 * 0 <= nums2[i] <= 10^9
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

class segmentTree
{
private:
    void pushup(int node_id)
    {
        node_sum[node_id] = node_sum[node_id * 2] + node_sum[node_id * 2 + 1];
    }

    void wait_pushdown(int node_id, long long add)
    {
        // 到底了
        int left = node_left[node_id];
        int right = node_right[node_id];

        if (left == right)
        {
            node_val[node_id] = ((node_val[node_id] + add) % 2);
            node_sum[node_id] = node_val[node_id];
        }
        else
        {
            node_temp_add[node_id] += add;
        }
    }

    // 真正递推
    void pushdown(int node_id, long long add)
    {

        // 需要递推
        // 继续下推
        int cur_l = node_left[node_id];
        int cur_r = node_right[node_id];

        // 到底了
        if (cur_l == cur_r)
        {
            node_val[node_id] = ((node_val[node_id] + add) % 2);
            node_sum[node_id] = node_val[node_id];
            return;
        }

        int mid = (cur_l + cur_r) >> 1;
        check_son(node_id * 2, cur_l, mid);
        check_son(node_id * 2 + 1, (mid + 1), cur_r);
        long long next_add = add + node_temp_add[node_id];
        if (node_push_down_flag[node_id] || next_add > 0)
        {
            pushdown(node_id * 2, next_add);
            pushdown(node_id * 2 + 1, next_add);
            pushup(node_id);
            node_push_down_flag[node_id] = false;
            node_temp_add[node_id] = 0;
        }
    }

    void modify(int node_id, int need_L, int need_R, long long add)
    {
        int cur_l = node_left[node_id];
        int cur_r = node_right[node_id];

        //  cur_l   need_L  need_R  cur_r
        //  范围外
        if (cur_l > need_R || cur_r < need_L)
        {
            return;
        }

        node_push_down_flag[node_id] = true;

        // 全包含了,不往下递推
        if (need_L <= cur_l && cur_r <= need_R)
        {
            wait_pushdown(node_id, add);
            return;
        }

        // 继续下推
        int mid = (cur_l + cur_r) >> 1;
        int left_node_id = node_id * 2;
        int right_node_id = node_id * 2 + 1;
        check_son(left_node_id, cur_l, mid);
        check_son(right_node_id, (mid + 1), cur_r);

        modify(left_node_id, need_L, need_R, add);
        modify(right_node_id, need_L, need_R, add);
    }

    long long query_sum(int node_id, int NEED_L, int NEED_R)
    {
        pushdown(node_id, 0);
        int cur_l = node_left[node_id];
        int cur_r = node_right[node_id];
        if (cur_l > NEED_R || cur_r < NEED_L)
            return 0;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return node_sum[node_id];
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        return query_sum(node_id * 2, NEED_L, NEED_R) + query_sum(node_id * 2 + 1, NEED_L, NEED_R);
    }

public:
    vector<int> node_left;
    vector<int> node_right;
    int default_left_right = -1;
    int first_id = 1;

    // 额外的数据
    vector<bool> node_push_down_flag;
    vector<long long> node_val;
    vector<long long> node_sum;
    vector<long long> node_temp_add;
    vector<int> leaf_node_; // 叶子节点对应的node_id
    int all_left;
    int all_right;
    segmentTree(int need_value, int left, int right)
    {
        all_left = left;
        all_right = right;
        // 整个数的节点大概是2倍的叶子节点
        int MX = 4 * need_value + 2;

        node_left.resize(MX, default_left_right);
        node_right.resize(MX, default_left_right);

        node_push_down_flag.resize(MX, false);
        node_val.resize(MX, 0);
        node_sum.resize(MX, 0);
        node_temp_add.resize(MX, 0);
        leaf_node_.resize(need_value + 1);

        build_tree(first_id, left, right);
    }

    // 初始化整个树
    void build_tree(int node_id, int cur_l, int cur_r)
    {

        if (node_id >= node_left.size())
        {
            return;
        }

        node_left[node_id] = cur_l;
        node_right[node_id] = cur_r;

        // 叶子节点
        if (cur_l == cur_r)
        {
            // cout << "(" << leaf_node_.size() << "," << cur_l << "," << node_id << ")";
            leaf_node_[cur_l] = node_id;
        }
        else
        {
            int mid = (cur_l + cur_r) >> 1;
            build_tree(node_id * 2, cur_l, mid);
            build_tree(node_id * 2 + 1, (mid + 1), cur_r);
        }
    }

    void init_leaf(vector<int> &nums1)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            int leaf_node_id = leaf_node_[i];
            node_val[leaf_node_id] = nums1[i];
            node_sum[leaf_node_id] = nums1[i];
        }
        init_sum(first_id);
    }

    void init_sum(int node_id)
    {
        if (node_id >= node_left.size())
        {
            return;
        }
        int cur_l = node_left[node_id];
        int cur_r = node_right[node_id];
        if (cur_l == cur_r)
        {
            return;
        }

        init_sum(node_id * 2);
        init_sum(node_id * 2 + 1);
        pushup(node_id);
    }

    // 检查初始化
    void check_son(int node_id, int left, int right)
    {
        if (node_left[node_id] == default_left_right)
        {
            node_left[node_id] = left;
            node_right[node_id] = right;
        }
    }

    void modify(int l, int r, long long add)
    {
        modify(first_id, l, r, add);
    }

    long long query_sum(int l, int r)
    {
        return query_sum(first_id, l, r);
    }
    void print_tree()
    {
        cout << "[";
        for (int i = all_left; i <= all_right; i++)
        {
            cout << query_sum(i, i) << ",";
        }
        cout << "]" << std::endl;
    }
};

class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {

        segmentTree *st = new segmentTree(nums1.size(), 0, nums1.size());
        long long cur_sum = 0;
        for (int j : nums2)
        {
            cur_sum += j;
        }

        st->init_leaf(nums1);
        // st->print_tree();
        vector<long long> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            int c = queries[i][2];

            if (a == 1)
            {
                st->modify(b, c, 1);
                // st->print_tree();
            }
            else if (a == 2)
            {
                long long add = st->query_sum(0, nums1.size());
                cur_sum += (add * b);
            }
            else if (a == 3)
            {
                result.push_back(cur_sum);
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=handleQuery
// paramTypes=["number[]","number[]","number[][]"]
// returnType=number[]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,0,1]\n[0,0,0]\n[[1,1,1],[2,1,0],[3,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[5]\n[[2,0,0],[3,0,0]]\n
// @lcpr case=end

// [277,331,331,395,395,395,515,515,615,615]	[277,331,331,445,445,445,625,625,775,775]
// @lcpr case=start
// [0,0,0,0,1,0,1,1,1]\n[35,29,21,34,8,48,22,43,37]\n[[1,4,7],[3,0,0],[2,27,0],[3,0,0],[1,0,3],[3,0,0],[2,6,0],[1,3,8],[2,13,0],[3,0,0],[3,0,0],[3,0,0],[2,2,0],[2,28,0],[3,0,0],[3,0,0],[2,25,0],[3,0,0],[3,0,0],[1,2,5]]\n
// @lcpr case=end


// [461,601,601]
// @lcpr case=start
//[0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,0]\n[0,13,26,9,34,32,14,29,42,14,43,6,31,22,13,35,4,24,37,33]\n[[3,0,0],[2,5,0],[2,9,0],[3,0,0],[3,0,0]]
// @lcpr case=end

 */
