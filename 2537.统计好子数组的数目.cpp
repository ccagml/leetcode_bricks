/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 * @lcpr version=21113
 *
 * [2537] 统计好子数组的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-good-subarrays/description/
 *
 * algorithms
 * Medium (46.55%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 8.3K
 * Testcase Example:  '[1,1,1,1,1]\n10'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。
 *
 * 一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。
 *
 * 子数组 是原数组中一段连续 非空 的元素序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,1,1,1], k = 10
 * 输出：1
 * 解释：唯一的好子数组是这个数组本身。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [3,1,4,3,2,2,4], k = 2
 * 输出：4
 * 解释：总共有 4 个不同的好子数组：
 * - [3,1,4,3,2,2] 有 2 对。
 * - [3,1,4,3,2,2,4] 有 3 对。
 * - [1,4,3,2,2,4] 有 2 对。
 * - [4,3,2,2,4] 有 2 对。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^9
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
    long long countGood(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        if (nums.size() == 2)
        {
            return nums[0] == nums[1] ? 1 : 0;
        }
        long long result = 0;
        unordered_map<int, int> umii;
        // v[x][k] = x; 从x开始 有k对的位置
        // 如果当前 x 没有,那么就结束了
        // 双指针?
        int left = 0;
        int right = 0;
        long long cur_good = 0;
        while (right < nums.size() && left < nums.size())
        {
            int old_right = umii[nums[right]];
            umii[nums[right]]++;
            if (umii[nums[right]] >= 2)
            {
                long long last = (old_right * (old_right - 1)) / 2;
                long long cur = (old_right + 1) * old_right / 2;
                cur_good += (cur - last);
            }
            right++;
            while (cur_good >= k)
            {
                result += (nums.size() - (right - 1));
                int old_left_value = umii[nums[left]];
                umii[nums[left]]--;
                int new_left_value = old_left_value - 1;
                long long last = (old_left_value * (old_left_value - 1)) / 2;
                long long cur = (new_left_value * (new_left_value - 1)) / 2;
                cur_good += (cur - last);
                left++;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,1,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,3,2,2,4]\n2\n
// @lcpr case=end

 */
