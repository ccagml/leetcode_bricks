/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 *
 * [2398] 预算内的最多机器人数目
 *
 * https://leetcode.cn/problems/maximum-number-of-robots-within-budget/description/
 *
 * algorithms
 * Hard (32.52%)
 * Likes:    11
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 9.8K
 * Testcase Example:  '[3,6,1,3,4]\n[2,1,3,4,5]\n25'
 *
 * 你有 n 个机器人，给你两个下标从 0 开始的整数数组 chargeTimes 和 runningCosts ，两者长度都为 n 。第 i
 * 个机器人充电时间为 chargeTimes[i] 单位时间，花费 runningCosts[i] 单位时间运行。再给你一个整数 budget 。
 *
 * 运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，其中
 * max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。
 *
 * 请你返回在 不超过 budget 的前提下，你 最多 可以 连续 运行的机器人数目为多少。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
 * 输出：3
 * 解释：
 * 可以在 budget 以内运行所有单个机器人或者连续运行 2 个机器人。
 * 选择前 3 个机器人，可以得到答案最大值 3 。总开销是 max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24
 * ，小于 25 。
 * 可以看出无法在 budget 以内连续运行超过 3 个机器人，所以我们返回 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
 * 输出：0
 * 解释：即使运行任何一个单个机器人，还是会超出 budget，所以我们返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * chargeTimes.length == runningCosts.length == n
 * 1 <= n <= 5 * 10^4
 * 1 <= chargeTimes[i], runningCosts[i] <= 10^5
 * 1 <= budget <= 10^15
 *
 *
 */

// @lc code=start
// 思考1
// 前缀和 runningCosts
// 区间查找最大值 chargeTimes
// 滑动窗口
// ======================
// -> 思考2
// 滑动窗口可能不需要前缀和
// 区间查找 可能用一个栈 存最大值就行(单调栈)?  优先级队列?
// 思路对,类型要long long
class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::less<std::pair<long long, long long>>> coll;
        long long left = 0;
        long long right = 0;
        long long all_n = chargeTimes.size();
        long long cur_sum = 0;
        long long result = 0;
        while (right < all_n)
        {
            coll.push({chargeTimes[right], right});
            cur_sum += runningCosts[right];
            right++;
            while (coll.size() > 0 && coll.top().second < left)
            {
                coll.pop();
            }
            while (coll.size() > 0 && (coll.top().first + (right - left) * cur_sum) > budget)
            {
                cur_sum -= runningCosts[left];
                left++;
                while (coll.size() > 0 && coll.top().second < left)
                {
                    coll.pop();
                }
            }
            result = max(result, (right - left));
        }

        return result;
    }
};
// @lc code=end
