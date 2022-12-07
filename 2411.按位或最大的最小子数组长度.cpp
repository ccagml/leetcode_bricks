/*
 * @lc app=leetcode.cn id=2411 lang=cpp
 * @lcpr version=20703
 *
 * [2411] 按位或最大的最小子数组长度
 *
 * https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or/description/
 *
 * algorithms
 * Medium (41.01%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 9.7K
 * Testcase Example:  '[1,0,2,1,3]'
 *
 * 给你一个长度为 n 下标从 0 开始的数组 nums ，数组中所有数字均为非负整数。对于 0 到 n - 1 之间的每一个下标 i ，你需要找出
 * nums 中一个 最小 非空子数组，它的起始位置为 i （包含这个位置），同时有 最大 的 按位或运算值 。
 *
 *
 * 换言之，令 Bij 表示子数组 nums[i...j] 的按位或运算的结果，你需要找到一个起始位置为 i 的最小子数组，这个子数组的按位或运算的结果等于
 * max(Bik) ，其中 i <= k <= n - 1 。
 *
 *
 * 一个数组的按位或运算值是这个数组里所有数字按位或运算的结果。
 *
 * 请你返回一个大小为 n 的整数数组 answer，其中 answer[i]是开始位置为 i ，按位或运算结果最大，且 最短 子数组的长度。
 *
 * 子数组 是数组里一段连续非空元素组成的序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,0,2,1,3]
 * 输出：[3,3,2,2,1]
 * 解释：
 * 任何位置开始，最大按位或运算的结果都是 3 。
 * - 下标 0 处，能得到结果 3 的最短子数组是 [1,0,2] 。
 * - 下标 1 处，能得到结果 3 的最短子数组是 [0,2,1] 。
 * - 下标 2 处，能得到结果 3 的最短子数组是 [2,1] 。
 * - 下标 3 处，能得到结果 3 的最短子数组是 [1,3] 。
 * - 下标 4 处，能得到结果 3 的最短子数组是 [3] 。
 * 所以我们返回 [3,3,2,2,1] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2]
 * 输出：[2,1]
 * 解释：
 * 下标 0 处，能得到最大按位或运算值的最短子数组长度为 2 。
 * 下标 1 处，能得到最大按位或运算值的最短子数组长度为 1 。
 * 所以我们返回 [2,1] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 0 <= nums[i] <= 10^9
 *
 *
 */

// [1,1,1,1,0,1]
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

bool is_bit_1(int x, int index)
{
    return ((1 << index) & (x));
}

class Solution
{
public:
    vector<int> smallestSubarrays(vector<int> &nums)
    {
        vector<int> result(nums.size());
        vector<int> v32(32, -1);
        for (int end = nums.size() - 1; end >= 0; end--)
        {
            int cur_value = nums[end];
            int end_max = 0;
            for (int i = 0; i < 32; i++)
            {
                if (is_bit_1(cur_value, i))
                {
                    v32[i] = end;
                }
                if (v32[i] >= 0)
                {
                    end_max = max(end_max, v32[i]);
                }
            }
            result[end] = (end_max - end + 1);
        }
        for (int end = nums.size() - 1; end >= 0; end--)
        {
            int cur_value = nums[end];
            if (cur_value > 0)
            {
                break;
            }
            result[end] = 1;
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
