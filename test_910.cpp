/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 *
 * https://leetcode.cn/problems/smallest-range-ii/description/
 *
 * algorithms
 * Medium (34.23%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 27.5K
 * Testcase Example:  '[1]\n0'
 *
 * 给你一个整数数组 nums，和一个整数 k 。
 *
 * 对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成  nums[i] + k 或 nums[i] - k 。
 *
 * nums 的 分数 是 nums 中最大元素和最小元素的差值。
 *
 * 在更改每个下标对应的值之后，返回 nums 的最小 分数 。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1], k = 0
 * 输出：0
 * 解释：分数 = max(nums) - min(nums) = 1 - 1 = 0 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,10], k = 2
 * 输出：6
 * 解释：将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,3,6], k = 3
 * 输出：3
 * 解释：将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^4
 * 0 <= k <= 10^4
 *
 *
 */

// @lc code=start

// 当前值得+k -k 与 前后值得+k -k相比较

class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int result = nums[nums.size() - 1] - nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = max(nums[i - 1] + k, nums.back() - k) - min(nums[i] - k, nums.front() + k);
            result = min(result, temp);
        }
        return result;
    }
};
// @lc code=end
