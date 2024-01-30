// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 * @lcpr version=30114
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 *
 * https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array/description/
 *
 * algorithms
 * Medium (36.30%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 10.6K
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int minimumSeconds(vector<int> &nums)
    {
        int result = nums.size();
        unordered_map<int, vector<int>> umii;
        for (int i = 0; i < nums.size(); i++)
        {
            umii[nums[i]].push_back(i);
        }

        for (pair<int, vector<int>> pivi : umii)
        {
            // 全部变成 pivi.first 需要
            vector<int> pivis = pivi.second;
            if (pivis.size() == 1)
            {
                pivis.push_back(pivis[0]);
            }
            if (pivis.size() > 1)
            {
                int min_c = 0;
                // 变化最长
                for (int j = 0; j < pivis.size() - 1; j++)
                {
                    int cur_j_index = pivis[j];
                    int next_j_index = pivis[j + 1];
                    // 相距
                    int diff_len = next_j_index - cur_j_index - 1;
                    if (diff_len > 0)
                    {
                        int need_diff = (diff_len % 2 == 0) ? (diff_len / 2) : (diff_len / 2 + 1);
                        min_c = max(min_c, need_diff);
                    }
                }
                // 头跟尾巴
                int cur_left = pivis[0] - 0;
                int cur_right = (nums.size() - 1) - pivis[pivis.size() - 1];
                int diff_len = cur_left + cur_right;
                if (diff_len > 0)
                {
                    int need_diff = (diff_len % 2 == 0) ? (diff_len / 2) : (diff_len / 2 + 1);
                    min_c = max(min_c, need_diff);
                }
                result = min(result, min_c);
                // 0 1 1 3 4 5
            }
        }
        return result;
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
// [4,18]\n
// @lcpr case=end

// @lcpr case=start
// [11,4,10]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [19,20,7,7,20]\n
// @lcpr case=end

 */
