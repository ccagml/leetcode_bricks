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
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        // (a5 - a1)c1 + (a5 - a2)c2 + (a5 - a3)c3
        // (a5c1) + a5c2  - a1c1 - a2c2
        // a5(c1+cn) - all
        // 如果a5 小于 a1, 那么是反过来的 a1 - a5
        vector<pair<long long, long long>> vpii;
        for (int i = 0; i < nums.size(); i++)
        {
            vpii.push_back({nums[i], cost[i]});
        }
        sort(vpii.begin(), vpii.end());
        long long all = 0;
        long long c_all = 0;
        for (int i = 0; i < vpii.size(); i++)
        {
            all += vpii[i].first * vpii[i].second;
            c_all += vpii[i].second;
        }
        long long result = LONG_LONG_MAX;

        // 计算屁股
        vector<long long> end_v(vpii.size());
        long long end_c = 0;
        long long end_all = 0;
        for (int start = vpii.size() - 1; start >= 0; start--)
        {
            long long temp = -2 * vpii[start].first * end_c + 2 * end_all;
            end_v[start] = temp;
            end_all += vpii[start].first * vpii[start].second;
            end_c += vpii[start].second;
        }
        for (int i = 0; i < vpii.size(); i++)
        {
            long long temp_result = (vpii[i].first * c_all) - all;
            // 这里 大于 vpii[i].first 的值, 本来是 (vpii[i].first - b)cb 要变成 (b - vpii[i].first)cb
            // (vpii[i].first - b)cb + 2(b - vpii[i].first )cb =  (b - vpii[i].first)cb
            // 缺少 2倍的 值
            // - 2(vpii[i].first)c6..n + 2(a6c6 + a7c7)
            temp_result += end_v[i];
            result = min(result, temp_result);
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [735103,366367,132236,133334,808160,113001,49051,735598,686615,665317,999793,426087,587000,649989,509946,743518]\n[724182,447415,723725,902336,600863,287644,13836,665183,448859,917248,397790,898215,790754,320604,468575,825614]
// @lcpr case=end

// @lcpr case=start
// [1,3,5,2]\n[2,3,1,14]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n[4,2,8,1,3]\n
// @lcpr case=end

 */
