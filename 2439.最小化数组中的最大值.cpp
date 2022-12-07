/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 * @lcpr version=20703
 *
 * [2439] 最小化数组中的最大值
 *
 * https://leetcode.cn/problems/minimize-maximum-of-array/description/
 *
 * algorithms
 * Medium (35.58%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 11.3K
 * Testcase Example:  '[3,7,1,6]'
 *
 * 给你一个下标从 0 开始的数组 nums ，它含有 n 个非负整数。
 *
 * 每一步操作中，你需要：
 *
 *
 * 选择一个满足 1 <= i < n 的整数 i ，且 nums[i] > 0 。
 * 将 nums[i] 减 1 。
 * 将 nums[i - 1] 加 1 。
 *
 *
 * 你可以对数组执行 任意 次上述操作，请你返回可以得到的 nums 数组中 最大值 最小 为多少。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,7,1,6]
 * 输出：5
 * 解释：
 * 一串最优操作是：
 * 1. 选择 i = 1 ，nums 变为 [4,6,1,6] 。
 * 2. 选择 i = 3 ，nums 变为 [4,6,2,5] 。
 * 3. 选择 i = 1 ，nums 变为 [5,5,2,5] 。
 * nums 中最大值为 5 。无法得到比 5 更小的最大值。
 * 所以我们返回 5 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [10,1]
 * 输出：10
 * 解释：
 * 最优解是不改动 nums ，10 是最大值，所以返回 10 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 2 <= n <= 10^5
 * 0 <= nums[i] <= 10^9
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
//? 优先级队列?
class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int n = nums.size();
        long sum = 0;
        int maxi = 0; // maxi = optimal max no. in array

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxi = max(maxi, (int)ceil((double)sum / (i + 1))); // maximum of optimal maximum for each subarray
        }
        return maxi;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,7,1,6]\n
// @lcpr case=end

// @lcpr case=start
// [10,1]\n
// @lcpr case=end

 */
