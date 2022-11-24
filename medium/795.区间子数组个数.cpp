/*
 * @lc app=leetcode.cn id=795 lang=cpp
 * @lcpr version=20204
 *
 * [795] 区间子数组个数
 *
 * https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (55.49%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 31.3K
 * Testcase Example:  '[2,1,4,3]\n2\n3'
 *
 * 给你一个整数数组 nums 和两个整数：left 及 right 。找出 nums 中连续、非空且其中最大元素在范围 [left, right]
 * 内的子数组，并返回满足条件的子数组的个数。
 *
 * 生成的测试用例保证结果符合 32-bit 整数范围。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,1,4,3], left = 2, right = 3
 * 输出：3
 * 解释：满足条件的三个子数组：[2], [2, 1], [3]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,9,2,5,6], left = 2, right = 8
 * 输出：7
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= left <= right <= 10^9
 *
 *
 */

// 没想到 单调栈的思路
// 找出左边记录左边比我大的, 记录右边比我大的

// @lc code=start
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R)
    {
        int n = A.size();

        stack<int> leftBig, rightBig;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            while (!leftBig.empty() && A[leftBig.top()] < A[i])
                leftBig.pop();
            if (!leftBig.empty())
                left[i] = leftBig.top();
            leftBig.push(i);

            while (!rightBig.empty() && A[rightBig.top()] < A[i])
            {
                right[rightBig.top()] = i;
                rightBig.pop();
            }
            rightBig.push(i);
        }

        for (int i = 0; i < n; ++i)
        {
            if (A[i] >= L && A[i] <= R)
            {
                ans += (right[i] - i) * (i - left[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,4,3]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,9,2,5,6]\n2\n8\n
// @lcpr case=end

 */
