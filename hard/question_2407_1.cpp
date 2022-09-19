/*
 * @lc app=leetcode.cn id=2407 lang=cpp
 *
 * [2407] 最长递增子序列 II
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence-ii/description/
 *
 * algorithms
 * Hard (22.32%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 11.5K
 * Testcase Example:  '[4,2,1,4,3,4,5,8,15]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k 。
 *
 * 找到 nums 中满足以下要求的最长子序列：
 *
 *
 * 子序列 严格递增
 * 子序列中相邻元素的差值 不超过 k 。
 *
 *
 * 请你返回满足上述要求的 最长子序列 的长度。
 *
 * 子序列 是从一个数组中删除部分元素后，剩余元素不改变顺序得到的数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,2,1,4,3,4,5,8,15], k = 3
 * 输出：5
 * 解释：
 * 满足要求的最长子序列是 [1,3,4,5,8] 。
 * 子序列长度为 5 ，所以我们返回 5 。
 * 注意子序列 [1,3,4,5,8,15] 不满足要求，因为 15 - 8 = 7 大于 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [7,4,5,1,8,12,4,7], k = 5
 * 输出：4
 * 解释：
 * 满足要求的最长子序列是 [4,5,8,12] 。
 * 子序列长度为 4 ，所以我们返回 4 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,5], k = 1
 * 输出：1
 * 解释：
 * 满足要求的最长子序列是 [1] 。
 * 子序列长度为 1 ，所以我们返回 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^5
 *
 *
 */

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

    // void build(segmentTreeNode *cur_node, int l, int r, long long initValue)
    // {
    //     // std::cout << (cur_node == nullptr) << ":" << l << ":" << r << ":" << initValue << std::endl;
    //     cur_node->left = l;
    //     cur_node->right = r;
    //     cur_node->sum = 0;
    //     cur_node->min_val = 0;
    //     cur_node->max_val = 0;

    //     if (l == r)
    //         cur_node->val = initValue;
    //     else
    //     {
    //         if (cur_node->left_son == nullptr)
    //         {
    //             cur_node->left_son = new segmentTreeNode();
    //         }
    //         if (cur_node->right_son == nullptr)
    //         {
    //             cur_node->right_son = new segmentTreeNode();
    //         }
    //         int mid = (l + r) >> 1;
    //         build(cur_node->left_son, l, mid, initValue);
    //         build(cur_node->right_son, mid + 1, r, initValue);
    //         pushup(cur_node);
    //     }
    // }
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
    segmentTree(int left, int right, long long _initValue)
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
    int lengthOfLIS(vector<int> &nums, int k)
    {
        int result = 0;
        segmentTree *root = new segmentTree(0, 100001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int temp_max = root->query_max(nums[i] - k, nums[i] - 1); // query(root, 0, 100001, nums[i] - k, nums[i] - 1);
            int q = root->query_max(nums[i], nums[i]);
            root->modify(nums[i], nums[i], ((temp_max + 1) - q));
            // update(root, 0, 100001, nums[i], temp_max + 1);
            result = max(result, temp_max + 1);
        }

        return result;
    }
};
// @lc code=end
