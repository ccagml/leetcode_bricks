/*
 * @lc app=leetcode.cn id=698 lang=cpp
 * @lcpr version=20701
 *
 * [698] 划分为k个相等的子集
 *
 * https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (42.57%)
 * Likes:    868
 * Dislikes: 0
 * Total Accepted:    92K
 * Total Submissions: 216.2K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 *
 *
 *
 * 示例 1：
 *
 * 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 *
 * 示例 2:
 *
 * 输入: nums = [1,2,3,4], k = 3
 * 输出: false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= len(nums) <= 16
 * 0 < nums[i] < 10000
 * 每个元素的频率在 [1,4] 范围内
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
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int all = accumulate(nums.begin(), nums.end(), 0);
        if (all % k > 0)
        {
            return false;
        }
        int per = all / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > per)
        {
            return false;
        }
        int n = nums.size();
        vector<bool> dp(1 << n, false);
        vector<int> curSum(1 << n, 0);
        dp[0] = true;
        for (int i = 0; i < 1 << n; i++)
        {
            if (!dp[i])
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (curSum[i] + nums[j] > per)
                {
                    break;
                }
                if (((i >> j) & 1) == 0)
                {
                    int next = i | (1 << j);
                    if (!dp[next])
                    {
                        curSum[next] = (curSum[i] + nums[j]) % per;
                        dp[next] = true;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4, 3, 2, 3, 5, 2, 1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n3\n
// @lcpr case=end

 */
