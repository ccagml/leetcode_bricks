/*
 * @lc app=leetcode.cn id=2426 lang=cpp
 * @lcpr version=20703
 *
 * [2426] 满足不等式的数对数目
 *
 * https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/description/
 *
 * algorithms
 * Hard (44.88%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 7.6K
 * Testcase Example:  '[3,2,5]\n[2,2,1]\n1'
 *
 * 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两个数组的大小都为 n ，同时给你一个整数 diff ，统计满足以下条件的 数对
 * (i, j) ：
 *
 *
 * 0 <= i < j <= n - 1 且
 * nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
 *
 *
 * 请你返回满足条件的 数对数目 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
 * 输出：3
 * 解释：
 * 总共有 3 个满足条件的数对：
 * 1. i = 0, j = 1：3 - 2 <= 2 - 2 + 1 。因为 i < j 且 1 <= 1 ，这个数对满足条件。
 * 2. i = 0, j = 2：3 - 5 <= 2 - 1 + 1 。因为 i < j 且 -2 <= 2 ，这个数对满足条件。
 * 3. i = 1, j = 2：2 - 5 <= 2 - 1 + 1 。因为 i < j 且 -3 <= 2 ，这个数对满足条件。
 * 所以，我们返回 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [3,-1], nums2 = [-2,2], diff = -1
 * 输出：0
 * 解释：
 * 没有满足条件的任何数对，所以我们返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums1.length == nums2.length
 * 2 <= n <= 10^5
 * -10^4 <= nums1[i], nums2[i] <= 10^4
 * -10^4 <= diff <= 10^4
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
            sum = 0;
            min_val = 0;
            max_val = 0;
            left_son = nullptr;
            right_son = nullptr;
        }
        int id;
        int left;
        int right;
        long long val;
        long long sum;
        long long min_val;
        long long max_val;
        segmentTreeNode *left_son;
        segmentTreeNode *right_son;
    };

    int all_left, all_right;

    void pushup(segmentTreeNode *cur_node)
    {
        cur_node->sum = (cur_node->left_son->sum + cur_node->right_son->sum);
        cur_node->min_val = std::min(cur_node->left_son->min_val, cur_node->right_son->min_val);
        cur_node->max_val = std::max(cur_node->left_son->max_val, cur_node->right_son->max_val);
    }

    void pushdown(segmentTreeNode *cur_node, long long add)
    {
        update(cur_node->left_son, add);
        update(cur_node->right_son, add);
    }
    void modify(segmentTreeNode *cur_node, int cur_l, int cur_r, int need_L, int need_R, long long add)
    {
        //  cur_r needl  needr cur_l
        if (cur_l > need_R || cur_r < need_L)
        {
            return;
        }
        //   need_l  cur_l  cur_r  need_r
        // std::cout << (cur_node == nullptr) << ":" << cur_l << ":" << cur_r << ":" << need_L << ":" << need_R << ":" << add << std::endl;
        if (need_L <= cur_l && cur_r <= need_R)
        {
            update(cur_node, (add * (cur_r - cur_l + 1)));
        }
        // 到底了
        if (cur_l == cur_r)
        {
            return;
        }

        // pushdown(node_index, add);
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
        pushup(cur_node);
    }

    long long query_min(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
    {
        if (cur_node == nullptr)
            return LLONG_MAX;
        if (cur_l > NEED_R || cur_r < NEED_L)
            return LLONG_MAX;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->min_val;
        long mid = (cur_l + cur_r) >> 1;
        // pushdown(cur_node, 0);
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        return std::min(query_min(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_min(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
    }
    long long query_max(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
    {
        // std::cout << cur_l << ":" << cur_r << ":" << NEED_L << ":" << NEED_R << ":" << std::endl;
        if (cur_node == nullptr)
            return LLONG_MIN;
        if (cur_l > NEED_R || cur_r < NEED_L)
            return LLONG_MIN;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->max_val;
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        return std::max(query_max(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_max(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
    }
    long long query_sum(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
    {
        if (cur_l > NEED_R || cur_r < NEED_L)
            return 0;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->sum;
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        return query_sum(cur_node->left_son, cur_l, mid, NEED_L, NEED_R) + query_sum(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R);
    }
    // 更新某个点?
    void update(segmentTreeNode *node, long long add)
    {
        node->val += add;
        node->sum = node->val;
        node->min_val = node->val;
        node->max_val = node->val;
    }
    segmentTreeNode *root;

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

    long long query_min(int l, int r)
    {
        return query_min(root, all_left, all_right, l, r);
    }
    long long query_max(int l, int r)
    {
        return query_max(root, all_left, all_right, l, r);
    }
    long long query_sum(int l, int r)
    {
        return query_sum(root, all_left, all_right, l, r);
    }
};

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int d)
    {
        // 超时思路
        // long long result = 0;
        // for (int i = 0; i < nums1.size(); i++)
        // {
        //     for (int j = i + 1; j < nums2.size(); j++)
        //     {
        //         if (nums1[i] - nums1[j] - nums2[i] + nums2[j] <= d)
        //         {
        //             result++;
        //         }
        //     }
        // }
        // return result;
        //(nums1[i] - nums2[i]) - (nums[j] - nums2[j]) <= d;
        // -2000 , 2000
        // 从尾巴来
        // ?动态维护前缀和?
        unordered_map<int, int> umii;
        long long reuslt = 0;
        bool debug = false;
        // if (nums1.size() > 10)
        // {
        //     vector<int> temp_vi = {3858,
        //                            -7670,
        //                            -7640,
        //                            6453,
        //                            -2155};
        //     debug = true;
        //     for (int j = 0; j < temp_vi.size(); j++)
        //     {
        //         if (nums1[j] != temp_vi[j])
        //         {
        //             debug = false;
        //             break;
        //         }
        //     }
        // }

        segmentTree *root = new segmentTree(0, 50000);
        long long debug_reuslt = 0;
        for (int j = nums1.size() - 1; j >= 0; j--)
        {
            int cur = nums1[j] - nums2[j];

            cur += 25000;
            int temp = root->query_sum(cur - d, 50000);
            reuslt += temp;
            root->modify(cur, cur, 1);
            if (debug)
            {
                long long temp_debug_add = 0;
                for (pair<int, int> pii : umii)
                {
                    if (cur - d <= pii.first)
                    {
                        temp_debug_add += pii.second;
                    }
                }
                debug_reuslt += temp_debug_add;
                std::cout << cur << ":" << temp << ":" << temp_debug_add << ")";
                umii[cur]++;
            }
        }
        if (debug)
        {
            std::cout << reuslt << ":debug:" << debug_reuslt << std::endl;
        }
        return reuslt;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,5]\n[2,2,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,-1]\n[-2,2]\n-1\n
// @lcpr case=end

 */
