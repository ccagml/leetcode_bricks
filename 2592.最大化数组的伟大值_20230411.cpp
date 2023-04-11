/*
 * @lc app=leetcode.cn id=2592 lang=cpp
 * @lcpr version=21905
 *
 * [2592] 最大化数组的伟大值
 *
 * https://leetcode.cn/problems/maximize-greatness-of-an-array/description/
 *
 * algorithms
 * Medium (58.33%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 7.5K
 * Testcase Example:  '[1,3,5,2,1,3,1]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。你需要将 nums 重新排列成一个新的数组 perm 。
 *
 * 定义 nums 的 伟大值 为满足 0 <= i < nums.length 且 perm[i] > nums[i] 的下标数目。
 *
 * 请你返回重新排列 nums 后的 最大 伟大值。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,5,2,1,3,1]
 * 输出：4
 * 解释：一个最优安排方案为 perm = [2,5,1,3,3,1,1] 。
 * 在下标为 0, 1, 3 和 4 处，都有 perm[i] > nums[i] 。因此我们返回 4 。
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4]
 * 输出：3
 * 解释：最优排列为 [2,3,4,1] 。
 * 在下标为 0, 1 和 2 处，都有 perm[i] > nums[i] 。因此我们返回 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
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
    int result;
    unordered_map<int, int> umii;

    bool can_add(vector<int> &nums, int cur)
    {
        while (true)
        {
            // //第一个大于 i
            auto upper = std::upper_bound(nums.begin(), nums.end(), cur);
            if (upper != nums.end())
            {
                int next_value = *upper;
                if (umii[next_value] > 0)
                {
                    umii[next_value]--;
                    return true;
                }
                else
                {
                    cur = next_value;
                }
            }
            else
            {
                return false;
            }
        }
        return false;
    }
    int maximizeGreatness(vector<int> &nums)
    {
        result = 0;

        sort(nums.begin(), nums.end());
        for (int i : nums)
        {
            umii[i]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (can_add(nums, nums[i]))
            {
                result++;
            }
            else
            {
                return result;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,2,1,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */
