/*
 * @lc app=leetcode.cn id=2448 lang=cpp
 * @lcpr version=20703
 *
 * [2448] 使数组相等的最小开销
 *
 * https://leetcode.cn/problems/minimum-cost-to-make-array-equal/description/
 *
 * algorithms
 * Hard (35.08%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 13.7K
 * Testcase Example:  '[1,3,5,2]\n[2,3,1,14]'
 *
 * 给你两个下标从 0 开始的数组 nums 和 cost ，分别包含 n 个 正 整数。
 *
 * 你可以执行下面操作 任意 次：
 *
 *
 * 将 nums 中 任意 元素增加或者减小 1 。
 *
 *
 * 对第 i 个元素执行一次操作的开销是 cost[i] 。
 *
 * 请你返回使 nums 中所有元素 相等 的 最少 总开销。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,5,2], cost = [2,3,1,14]
 * 输出：8
 * 解释：我们可以执行以下操作使所有元素变为 2 ：
 * - 增加第 0 个元素 1 次，开销为 2 。
 * - 减小第 1 个元素 1 次，开销为 3 。
 * - 减小第 2 个元素 3 次，开销为 1 + 1 + 1 = 3 。
 * 总开销为 2 + 3 + 3 = 8 。
 * 这是最小开销。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,2,2,2], cost = [4,2,8,1,3]
 * 输出：0
 * 解释：数组中所有元素已经全部相等，不需要执行额外的操作。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length == cost.length
 * 1 <= n <= 10^5
 * 1 <= nums[i], cost[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,2]\n[2,3,1,14]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n[4,2,8,1,3]\n
// @lcpr case=end

 */
