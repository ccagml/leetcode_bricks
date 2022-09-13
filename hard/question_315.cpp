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

    void myupdate(Node *node, long lc, long rc, long x, int v)
    {
        node->val += v;
        if (lc == rc)
            return;
        long mid = (lc + rc) >> 1;
        if (x <= mid)
        {
            if (node->ls == nullptr)
                node->ls = new Node();
            myupdate(node->ls, lc, mid, x, v);
        }
        else
        {
            if (node->rs == nullptr)
                node->rs = new Node();
            myupdate(node->rs, mid + 1, rc, x, v);
        }
    }
    int myquery(Node *node, long lc, long rc, long l, long r)
    {
        if (node == nullptr)
            return 0;
        if (r < lc || l > rc)
            return 0;
        if (l <= lc && rc <= r)
            return node->val;
        long mid = (lc + rc) >> 1;
        return myquery(node->ls, lc, mid, l, r) + myquery(node->rs, mid + 1, rc, l, r);
    }
    Node *root;
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n);
        root = new Node();
        myupdate(root, -10001, 10001, 0, 0);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            result[i] = myquery(root, -10001, 10001, -10001, nums[i] - 1);
            myupdate(root, -10001, 10001, nums[i], 1);
        }
        return result;
    }
};
// @lc code=end
