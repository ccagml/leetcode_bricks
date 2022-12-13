/*
 * @lc app=leetcode.cn id=416 lang=cpp
 * @lcpr version=20602
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.16%)
 * Likes:    1568
 * Dislikes: 0
 * Total Accepted:    352.6K
 * Total Submissions: 676K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
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

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int target = 0;
        for (int j : nums)
        {
            target += j;
        }
        if (target % 2 == 1)
        {
            return false;
        }
        int need = target / 2;

        vector<bool> vb(need + 1);
        vb[0] = true;
        for (int j : nums)
        {
            for (int i = need; i >= j; i--)
            {
                vb[i] = vb[i] || vb[i - j];
            }
        }
        return vb[need];
    }
};
// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         int sum = 0;
//         for (int num : nums)
//         {
//             sum += num;
//         }
//         if (sum % 2 == 1)
//         {
//             return false;
//         }
//         int target = sum / 2;
//         vector<bool> vi(target + 1);
//         vi[0] = true;
//         for (int num : nums)
//         {
//             for (int j = target; j >= num; j--)
//             {
//                 vi[j] = vi[j - num] || vi[j];
//             }
//         }
//         return vi[target];
//     }
// };
// @lc code=end

/*
// @lcpr case=start
// [1,2,5]\n
// @lcpr case=end
// @lcpr case=start
// [1,5,11,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5]\n
// @lcpr case=end

 */
