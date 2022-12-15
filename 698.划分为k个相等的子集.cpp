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
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }
    int set_bit_0(int x, int index)
    {
        x &= ~(1 << index);
        return x;
    }

    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }
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
        int all_flag = 0;
        for (int i = 0; i < n; i++)
        {
            all_flag = set_bit_1(all_flag, i);
        }

        vector<bool> dp(all_flag + 1);
        dp[0] = true;
        vector<int> sum(all_flag + 1);
        for (int i = 0; i < all_flag; i++)
        {
            if (!dp[i])
            {
                continue;
            }
            // 如果可以累加
            for (int j_new = 0; j_new < n; j_new++)
            {
                if (sum[i] + nums[j_new] > per)
                {
                    break;
                }
                if (!is_bit_1(i, j_new))
                {
                    int next = set_bit_1(i, j_new);
                    dp[next] = true;
                    sum[next] = (sum[i] + nums[j_new]) % per;
                }
            }
        }
        return dp[all_flag];
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
