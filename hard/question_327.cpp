/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 *
 * https://leetcode.cn/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (41.21%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    34.1K
 * Total Submissions: 82.7K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * 给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和
 * upper）之内的 区间和的个数 。
 *
 * 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,5,-1], lower = -2, upper = 2
 * 输出：3
 * 解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0], lower = 0, upper = 0
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -2^31
 * -10^5
 * 题目数据保证答案是一个 32 位 的整数
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

    long long count_u = 0;
    void update(Node *node, long lc, long rc, long x, int v)
    {
        node->val += v;
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
        return query(node->ls, lc, mid, l, r) + query(node->rs, mid + 1, rc, l, r);
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long long L = 0, R = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            s += nums[i];
            L = min(min(L, s), min(s - lower, s - upper));
            R = max(max(R, s), max(s - lower, s - upper));
        }
        int result = 0;
        s = 0;
        Node *root = new Node();
        update(root, L, R, 0, 1);
        for (int i : nums)
        {
            s += i;
            long long a = s - upper;
            long long b = s - lower;
            result += query(root, L, R, a, b);
            update(root, L, R, s, 1);
        }
        return result;
    }
};
// @lc code=end
