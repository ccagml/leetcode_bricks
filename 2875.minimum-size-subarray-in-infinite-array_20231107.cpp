// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2875 lang=cpp
 * @lcpr version=30106
 *
 * [2875] 无限数组的最短子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array/description/
 *
 * algorithms
 * Medium (33.95%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 11.4K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * 给你一个下标从 0 开始的数组 nums 和一个整数 target 。
 *
 * 下标从 0 开始的数组 infinite_nums 是通过无限地将 nums 的元素追加到自己之后生成的。
 *
 * 请你从 infinite_nums 中找出满足 元素和 等于 target 的 最短 子数组，并返回该子数组的长度。如果不存在满足条件的子数组，返回
 * -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3], target = 5
 * 输出：2
 * 解释：在这个例子中 infinite_nums = [1,2,3,1,2,3,1,2,...] 。
 * 区间 [1,2] 内的子数组的元素和等于 target = 5 ，且长度 length = 2 。
 * 可以证明，当元素和等于目标值 target = 5 时，2 是子数组的最短长度。
 *
 * 示例 2：
 *
 * 输入：nums = [1,1,1,2,3], target = 4
 * 输出：2
 * 解释：在这个例子中 infinite_nums = [1,1,1,2,3,1,1,1,2,3,1,1,...].
 * 区间 [4,5] 内的子数组的元素和等于 target = 4 ，且长度 length = 2 。
 * 可以证明，当元素和等于目标值 target = 4 时，2 是子数组的最短长度。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [2,4,6,8], target = 3
 * 输出：-1
 * 解释：在这个例子中 infinite_nums = [2,4,6,8,2,4,6,8,...] 。
 * 可以证明，不存在元素和等于目标值 target = 3 的子数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= target <= 10^9
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
    // 在两个循环nums内找到目标值
    int check_len(vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return 0;
        }
        int end_index = nums.size() * 2;

        long long cur = 0;
        int min_result = 999999;
        queue<int> qi;
        int index = 0;
        while (index <= end_index)
        {
            if (cur < target)
            {
                qi.push(nums[index % nums.size()]);
                cur += nums[index % nums.size()];
                index++;
            }
            else if (cur == target)
            {
                int len = qi.size();
                min_result = min(min_result, len);
                cur -= qi.front();
                qi.pop();
            }
            else if (cur > target)
            {
                cur -= qi.front();
                qi.pop();
            }
        }
        return min_result;
    }
    int minSizeSubarray(vector<int> &nums, int target)
    {
        long long sum_all = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum_all += nums[i];
        }

        int new_target = target % sum_all;

        int min_len = check_len(nums, new_target);
        if (min_len == 999999)
        {
            return -1;
        }
        int result = min_len + (target / sum_all) * nums.size();
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minSizeSubarray
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,8]\n3\n
// @lcpr case=end

 */
