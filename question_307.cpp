/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode.cn/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (51.45%)
 * Likes:    549
 * Dislikes: 0
 * Total Accepted:    58.7K
 * Total Submissions: 114.2K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询。
 *
 *
 * 其中一类查询要求 更新 数组 nums 下标对应的值
 * 另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
 *
 *
 * 实现 NumArray 类：
 *
 *
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值 更新 为 val
 * int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含
 * ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 *
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * 调用 update 和 sumRange 方法次数不大于 3 * 10^4 
 *
 *
 */

// @lc code=start
class NumArray
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
    int L = 0;
    int R = 0;
    Node *root;
    NumArray(vector<int> &nums)
    {
        R = nums.size();
        root = new Node();
        for (int i = 0; i < R; i++)
        {
            myupdate(root, 0, R, i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        int temp = myquery(root, 0, R, index, index);
        myupdate(root, 0, R, index, val - temp);
    }

    int sumRange(int left, int right)
    {
        return myquery(root, 0, R, left, right);
    }
};

//["NumArray","sumRange","sumRange","sumRange"]\n[[[1,3,5]],[0,0],[0,1],[0,2]]

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
