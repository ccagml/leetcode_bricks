// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2598 lang=cpp
 * @lcpr version=21914
 *
 * [2598] 执行操作后的最大 MEX
 *
 * https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/description/
 *
 * algorithms
 * Medium (39.29%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 13.7K
 * Testcase Example:  '[1,-10,7,13,6,8]\n5'
 *
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 value 。
 *
 * 在一步操作中，你可以对 nums 中的任一元素加上或减去 value 。
 *
 *
 * 例如，如果 nums = [1,2,3] 且 value = 2 ，你可以选择 nums[0] 减去 value ，得到 nums = [-1,2,3]
 * 。
 *
 *
 * 数组的 MEX (minimum excluded) 是指其中数组中缺失的最小非负整数。
 *
 *
 * 例如，[-1,2,3] 的 MEX 是 0 ，而 [1,0,3] 的 MEX 是 2 。
 *
 *
 * 返回在执行上述操作 任意次 后，nums 的最大 MEX 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,-10,7,13,6,8], value = 5
 * 输出：4
 * 解释：执行下述操作可以得到这一结果：
 * - nums[1] 加上 value 两次，nums = [1,0,7,13,6,8]
 * - nums[2] 减去 value 一次，nums = [1,0,2,13,6,8]
 * - nums[3] 减去 value 两次，nums = [1,0,2,3,6,8]
 * nums 的 MEX 是 4 。可以证明 4 是可以取到的最大 MEX 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,-10,7,13,6,8], value = 7
 * 输出：2
 * 解释：执行下述操作可以得到这一结果：
 * - nums[2] 减去 value 一次，nums = [1,-10,0,13,6,8]
 * nums 的 MEX 是 2 。可以证明 2 是可以取到的最大 MEX 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length, value <= 10^5
 * -10^9 <= nums[i] <= 10^9
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
    int findSmallestInteger(vector<int> &nums, int value)
    {
        // 计算余数
        vector<int> vt(value);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                int j = nums[i] % value;
                vt[j]++;
            }
            else
            {
                int dividend = abs(nums[i]);
                int divisor = value;
                int result = (dividend % divisor == 0) ? (dividend / divisor) : (dividend / divisor + 1);
                int j = ((result * value) - dividend) % value;
                vt[j]++;
            }
        }
        int min_j = 999999999;
        int need_j = 0;
        for (int i = 0; i < vt.size(); i++)
        {
            if (vt[i] < min_j)
            {
                min_j = vt[i];
                need_j = i;
            }
        }
        return (min_j * value) + need_j;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findSmallestInteger
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,-10,7,13,6,8]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,-10,7,13,6,8]\n7\n
// @lcpr case=end

// @lcpr case=start
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -4]\n7\n
// @lcpr case=end

 */
