// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 * @lcpr version=30113
 *
 * [1696] 跳跃游戏 VI
 *
 * https://leetcode.cn/problems/jump-game-vi/description/
 *
 * algorithms
 * Medium (40.64%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 34.5K
 * Testcase Example:  '[1,-1,-2,4,-7,3]\n2'
 *
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。
 *
 * 一开始你在下标 0 处。每一步，你最多可以往前跳 k 步，但你不能跳出数组的边界。也就是说，你可以从下标 i 跳到 [i + 1， min(n - 1,
 * i + k)] 包含 两个端点的任意位置。
 *
 * 你的目标是到达数组最后一个位置（下标为 n - 1 ），你的 得分 为经过的所有数字之和。
 *
 * 请你返回你能得到的 最大得分 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,-1,-2,4,-7,3], k = 2
 * 输出：7
 * 解释：你可以选择子序列 [1,-1,4,3] （上面加粗的数字），和为 7 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [10,-5,-2,4,0,3], k = 3
 * 输出：17
 * 解释：你可以选择子序列 [10,4,3] （上面加粗数字），和为 17 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length, k <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
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
            val = -1099999999;
            sum = 0;
            min_val = 0;
            max_val = -1099999999;
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

    long long query_max(int l, int r)
    {
        return query_max(root, all_left, all_right, l, r);
    }
};
class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int a = -1099999999;
        int n = nums.size();
        vector<int> temp_result = vector<int>(n, a);

        segmentTree *st = new segmentTree(0, 100001);

        // 初始化 0 到 k
        for (int j = 0; j <= 0; j++)
        {
            st->modify(j, j, -a);
            st->modify(j, j, nums[j]);
            temp_result[j] = nums[j];
        }

        for (int i = 1; i < n; i++)
        {
            // 到当前位置的最大值 = 前面 i - k 的最大值 + 自己
            int cur_v = nums[i];
            long long c_max = st->query_max(max(0, i - k), i - 1);
            if (c_max == a)
            {
                c_max = 0;
            }
            int jj = c_max + cur_v;
            temp_result[i] = max(temp_result[i], jj);
            int cur_i = st->query_max(i, i);
            if (temp_result[i] > cur_i)
            {
                if (cur_i == a)
                {
                    st->modify(i, i, -a);
                    st->modify(i, i, (temp_result[i]));
                }
                else
                {
                    st->modify(i, i, (temp_result[i] - cur_i));
                }
            }
        }
        return temp_result[n - 1];
    }
};
// @lc code=end
// @lcpr-div-debug-arg-start
// funName=maxResult
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,-1,-2,4,-7,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [10,-5,-2,4,0,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,-5,-20,4,-1,3,-6,-3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [-1,-2,-3,-4,-5,-6,-7]\n2\n
// @lcpr case=end

 */
