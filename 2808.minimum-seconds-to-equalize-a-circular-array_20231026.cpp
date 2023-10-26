// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 * @lcpr version=30102
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 *
 * https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/description/
 *
 * algorithms
 * Medium (35.86%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 8.2K
 * Testcase Example:  '[1,2,1,2]'
 *
 * 给你一个下标从 0 开始长度为 n 的数组 nums 。
 *
 * 每一秒，你可以对数组执行以下操作：
 *
 *
 * 对于范围在 [0, n - 1] 内的每一个下标 i ，将 nums[i] 替换成 nums[i] ，nums[(i - 1 + n) % n] 或者
 * nums[(i + 1) % n] 三者之一。
 *
 *
 * 注意，所有元素会被同时替换。
 *
 * 请你返回将数组 nums 中所有元素变成相等元素所需要的 最少 秒数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,1,2]
 * 输出：1
 * 解释：我们可以在 1 秒内将数组变成相等元素：
 * - 第 1 秒，将每个位置的元素分别变为 [nums[3],nums[1],nums[3],nums[3]] 。变化后，nums = [2,2,2,2]
 * 。
 * 1 秒是将数组变成相等元素所需要的最少秒数。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,1,3,3,2]
 * 输出：2
 * 解释：我们可以在 2 秒内将数组变成相等元素：
 * - 第 1 秒，将每个位置的元素分别变为 [nums[0],nums[2],nums[2],nums[2],nums[3]] 。变化后，nums =
 * [2,3,3,3,3] 。
 * - 第 2 秒，将每个位置的元素分别变为 [nums[1],nums[1],nums[2],nums[3],nums[4]] 。变化后，nums =
 * [3,3,3,3,3] 。
 * 2 秒是将数组变成相等元素所需要的最少秒数。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [5,5,5,5]
 * 输出：0
 * 解释：不需要执行任何操作，因为一开始数组中的元素已经全部相等。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n == nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
    int minimumSeconds(vector<int> &nums)
    {
        unordered_map<int, vector<int>> mivi;
        for (int i = 0; i < nums.size(); i++)
        {
            mivi[nums[i]].push_back(i);
        }
        int ans = nums.size();

        for (pair<int, vector<int>> pivi : mivi)
        {
            int temp_need = 0;
            for (int j = 0; j < pivi.second.size(); j++)
            {
                if (j + 1 < pivi.second.size())
                {
                    int left_index = pivi.second[j];
                    int right_index = pivi.second[j + 1];
                    int have = right_index - left_index - 1;
                    // 0 - 0, 1- 1, 2-1, 3 -2, 4 -2

                    int need = (have % 2 == 0) ? (have / 2) : (have / 2 + 1);
                    temp_need = max(temp_need, need);
                }
                else
                {
                    int left_index = pivi.second[j];
                    int right_index = pivi.second[0];

                    // [ 0, 1, 2, 3, 4, 5 ];
                    int have = (nums.size() - left_index - 1) + (right_index);
                    int need = (have % 2 == 0) ? (have / 2) : (have / 2 + 1);
                    temp_need = max(temp_need, need);
                }
            }
            ans = min(ans, temp_need);
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minimumSeconds
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */
