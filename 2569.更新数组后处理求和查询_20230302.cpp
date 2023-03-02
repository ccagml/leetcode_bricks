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
    class segmentTreeNode
    {
    public:
        segmentTreeNode(int l, int r)
        {
            left = l;
            right = r;
            val = 0;
            temp_add = 0;
            sum = 0;
            left_son = nullptr;
            right_son = nullptr;
            push_down_flag = true;
        }
        int id;
        int left;
        int right;
        int sum = 0;
        bool push_down_flag;
        long long val;
        long long temp_add;
        segmentTreeNode *left_son;
        segmentTreeNode *right_son;
    };

    int all_left, all_right;

    void pushup(segmentTreeNode *cur_node)
    {
        cur_node->sum = (cur_node->left_son->sum + cur_node->right_son->sum);
    }

    void wait_pushdown(segmentTreeNode *cur_node, long long add)
    {
        // 到底了
        if (cur_node->left == cur_node->right)
        {
            cur_node->val = ((cur_node->val + add) % 2);
            cur_node->sum = cur_node->val;
        }
        else
        {
            cur_node->temp_add += add;
        }
    }

    // 真正递推
    void pushdown(segmentTreeNode *cur_node, long long add)
    {
        // 需要递推
        // 继续下推
        int mid = (cur_node->left + cur_node->right) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_node->left, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_node->right);
        }

        // 到底了
        if (cur_node->left == cur_node->right)
        {
            cur_node->val = ((cur_node->val + add) % 2);
            cur_node->sum = cur_node->val;
            return;
        }
        long long next_add = add + cur_node->temp_add;
        if (cur_node->push_down_flag || next_add > 0)
        {
            pushdown(cur_node->left_son, next_add);
            pushdown(cur_node->right_son, next_add);
            pushup(cur_node);
            cur_node->push_down_flag = false;
            cur_node->temp_add = 0;
        }
    }

    void modify(segmentTreeNode *cur_node, int cur_l, int cur_r, int need_L, int need_R, long long add)
    {
        cur_node->push_down_flag = true;
        //  cur_l   need_L  need_R  cur_r
        //  范围外
        if (cur_l > need_R || cur_r < need_L)
        {
            return;
        }

        // 全包含了,不往下递推
        if (need_L <= cur_l && cur_r <= need_R)
        {
            wait_pushdown(cur_node, add);
            return;
        }

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
        modify(cur_node->left_son, cur_l, mid, need_L, need_R, add);
        modify(cur_node->right_son, mid + 1, cur_r, need_L, need_R, add);
        // pushup(cur_node);
    }

    segmentTreeNode *root;
    long long query_sum(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
    {
        pushdown(cur_node, 0);
        if (cur_l > NEED_R || cur_r < NEED_L)
            return 0;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->sum;
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        return query_sum(cur_node->left_son, cur_l, mid, NEED_L, NEED_R) + query_sum(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R);
    }

public:
    segmentTree(int left, int right)
    {

        root = new segmentTreeNode(left, right);
        all_left = left;
        all_right = right;
        // build(root, all_left, all_right, _initValue);
    }

    void modify(int l, int r, long long add)
    {
        modify(root, all_left, all_right, l, r, add);
    }

    long long query_sum(int l, int r)
    {
        return query_sum(root, all_left, all_right, l, r);
    }
    void print_tree()
    {
        std::cout << "[";
        for (int j = all_left; j <= all_right; j++)
        {
            std::cout << query_sum(j, j) << ",";
        }
        std::cout << "]" << std::endl;
        ;
    }
};

class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {

        segmentTree *st = new segmentTree(0, nums1.size());
        vector<int> flag_1(nums1.size() + 10);
        long long cur_sum = 0;
        for (int j : nums2)
        {
            cur_sum += j;
        }

        // std::cout << "[";
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == 1)
            {
                st->modify(i, i, 1);
            }

            // std::cout << nums1[i] << ",";
        }

        // std::cout << "]" << std::endl;

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
                // int jj = 0;
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

 */
