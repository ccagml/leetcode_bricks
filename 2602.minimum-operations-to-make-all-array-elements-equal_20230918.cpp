/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 * @lcpr version=21914
 *
 * [2602] 使数组元素全部相等的最少操作次数
 *
 * https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/description/
 *
 * algorithms
 * Medium (33.80%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 20.9K
 * Testcase Example:  '[3,1,6,8]\n[1,5]'
 *
 * 给你一个正整数数组 nums 。
 *
 * 同时给你一个长度为 m 的整数数组 queries 。第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。你可以执行以下操作
 * 任意 次：
 *
 *
 * 将数组里一个元素 增大 或者 减小 1 。
 *
 *
 * 请你返回一个长度为 m 的数组 answer ，其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。
 *
 * 注意，每次查询后，数组变回最开始的值。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,1,6,8], queries = [1,5]
 * 输出：[14,10]
 * 解释：第一个查询，我们可以执行以下操作：
 * - 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
 * - 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
 * - 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
 * 第一个查询的总操作次数为 2 + 5 + 7 = 14 。
 * 第二个查询，我们可以执行以下操作：
 * - 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
 * - 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
 * - 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
 * - 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
 * 第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,9,6,3], queries = [10]
 * 输出：[20]
 * 解释：我们可以将数组中所有元素都增大到 10 ，总操作次数为 8 + 1 + 4 + 7 = 20 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * m == queries.length
 * 1 <= n, m <= 10^5
 * 1 <= nums[i], queries[i] <= 10^9
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
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
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin().nums.end());
        unordered_map<int, int> umii;
        for (int j : queries)
        {
            umii[j]++;
        }
        vector<int> q;
        for (pair<int, int> pii : umii)
        {
            q.push_back(pii.first);
        }
        sort(q.begin(), q.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,1,6,8]\n[1,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,9,6,3]\n[10]\n
// @lcpr case=end

 */
