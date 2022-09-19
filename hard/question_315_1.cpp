/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.92%)
 * Likes:    878
 * Dislikes: 0
 * Total Accepted:    70.9K
 * Total Submissions: 165.2K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i]
 * 右侧小于 nums[i] 的元素的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,2,6,1]
 * 输出：[2,1,1,0]
 * 解释：
 * 5 的右侧有 2 个更小的元素 (2 和 1)
 * 2 的右侧仅有 1 个更小的元素 (1)
 * 6 的右侧有 1 个更小的元素 (1)
 * 1 的右侧有 0 个更小的元素
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [-1]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [-1,-1]
 * 输出：[0,0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
// 线段树
// 想不到的点 从右往左找结果

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
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        segmentTree *root = new segmentTree(-10001, 10001);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = root->query_sum(-10001, nums[i] - 1);
            root->modify(nums[i], nums[i], 1);
        }
        return result;
    }
};
// @lc code=end
