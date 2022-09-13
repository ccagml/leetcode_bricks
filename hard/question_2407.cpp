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
class Solution
{
public:
    class Node
    {
    public:
        Node *ls;
        Node *rs;
        long long val;
    };

    void update(Node *node, long lc, long rc, long x, long long v)
    {
        node->val = max(node->val, v);
        if (lc == rc)
            return;
        long mid = (lc + rc) >> 1;
        if (x <= mid)
        {
            if (node->ls == nullptr)
                node->ls = new Node();
            update(node->ls, lc, mid, x, v);
        }
        else
        {
            if (node->rs == nullptr)
                node->rs = new Node();
            update(node->rs, mid + 1, rc, x, v);
        }
    }

    long long query(Node *node, long lc, long rc, long l, long r)
    {
        if (node == nullptr)
            return 0;
        if (r < lc || l > rc)
            return 0;
        if (l <= lc && rc <= r)
            return node->val;
        long mid = (lc + rc) >> 1;
        return max(query(node->ls, lc, mid, l, r), query(node->rs, mid + 1, rc, l, r));
    }

    int lengthOfLIS(vector<int> &nums, int k)
    {
        int result = 0;
        Node *root = new Node();
        update(root, 0, 100001, 0, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int temp_max = query(root, 0, 100001, nums[i] - k, nums[i] - 1);
            update(root, 0, 100001, nums[i], temp_max + 1);
            result = max(result, temp_max + 1);
        }
        return result;
    }
};
// @lc code=end
