/*
 * @lc app=leetcode.cn id=2873 lang=cpp
 * @lcpr version=30102
 *
 * [2873] 有序三元组中的最大值 I
 *
 * https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/description/
 *
 * algorithms
 * Easy (53.92%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 8.7K
 * Testcase Example:  '[12,6,1,2,7]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 *
 * 请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0
 * 。
 *
 * 下标三元组 (i, j, k) 的值等于 (nums[i] - nums[j]) * nums[k] 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [12,6,1,2,7]
 * 输出：77
 * 解释：下标三元组 (0, 2, 4) 的值是 (nums[0] - nums[2]) * nums[4] = 77 。
 * 可以证明不存在值大于 77 的有序下标三元组。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,10,3,4,19]
 * 输出：133
 * 解释：下标三元组 (1, 2, 4) 的值是 (nums[1] - nums[2]) * nums[4] = 133 。
 * 可以证明不存在值大于 133 的有序下标三元组。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3]
 * 输出：0
 * 解释：唯一的下标三元组 (0, 1, 2) 的值是一个负数，(nums[0] - nums[1]) * nums[2] = -3 。因此，答案是 0
 * 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 100
 * 1 <= nums[i] <= 10^6
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long temp = nums[i];
                    temp -= nums[j];
                    temp *= nums[k];
                    result = max(result, temp);
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [12,6,1,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,3,4,19]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
