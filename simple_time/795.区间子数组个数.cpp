/*
 * @lc app=leetcode.cn id=795 lang=cpp
 * @lcpr version=20204
 *
 * [795] 区间子数组个数
 *
 * https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (57.78%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 57.5K
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

// 双指针,可以在一个循环里,把右边更大的也算上
// 想不到的结果是 左边数量 * 右边数量

using namespace std;
#include "stack"
#include "vector"

// @lc code=start
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int n = nums.size();
        stack<int> sl;
        stack<int> sr;
        vector<int> vl(n, -1);
        vector<int> vr(n, n);
        for (int i = 0; i < nums.size(); i++)
        {
            while (sl.size() > 0 && nums[sl.top()] < nums[i])
            {
                sl.pop();
            }
            vl[i] = sl.empty() ? -1 : sl.top();
            sl.push(i);
            while (sr.size() > 0 && nums[sr.top()] < nums[i])
            {
                vr[sr.top()] = i;
                sr.pop();
            }
            // vr[i] = sr.empty() ? i : sr.top();
            sr.push(i);
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            // 5,1,2,3,2,1,5
            if (nums[i] >= left && nums[i] <= right)
            {
                int a_left = (i - vl[i]);
                int a_right = (vr[i] - i);
                // std::cout << i << ":" << vl[i] << ":" << vr[i] << ":" << a_left << ":" << a_right << std::endl;
                result += a_left * a_right;
            }
        }
        return result;
    }
};
// 1, 2, 1, 1, 1
// @lc code=end

/*
// @lcpr case=start
// [2,1,4,3]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,9,2,5,6]\n2\n8\n
// @lcpr case=end

 */
