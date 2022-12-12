/*
 * @lc app=leetcode.cn id=2366 lang=cpp
 * @lcpr version=20801
 *
 * [2366] 将数组排序的最少替换次数
 *
 * https://leetcode.cn/problems/minimum-replacements-to-sort-the-array/description/
 *
 * algorithms
 * Hard (41.73%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 9K
 * Testcase Example:  '[3,9,3]'
 *
 * 给你一个下表从 0 开始的整数数组 nums 。每次操作中，你可以将数组中任何一个元素替换为 任意两个 和为该元素的数字。
 *
 *
 * 比方说，nums = [5,6,7] 。一次操作中，我们可以将 nums[1] 替换成 2 和 4 ，将 nums 转变成 [5,2,4,7] 。
 *
 *
 * 请你执行上述操作，将数组变成元素按 非递减 顺序排列的数组，并返回所需的最少操作次数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,9,3]
 * 输出：2
 * 解释：以下是将数组变成非递减顺序的步骤：
 * - [3,9,3] ，将9 变成 3 和 6 ，得到数组 [3,3,6,3]
 * - [3,3,6,3] ，将 6 变成 3 和 3 ，得到数组 [3,3,3,3,3]
 * 总共需要 2 步将数组变成非递减有序，所以我们返回 2 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4,5]
 * 输出：0
 * 解释：数组已经是非递减顺序，所以我们返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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

// 从屁股拆分, 直接求余数,答案不对
// 应该是要看怎么拆分使得最后一个进来大, 想不到
class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        int end_max = nums[nums.size() - 1];
        long long result = 0;
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            int cur_nums = nums[j];
            // std::cout << "(" << cur_nums << ":end_max:" << end_max << ")";
            if (cur_nums > end_max)
            {
                // long long add_result = (cur_nums / end_max) - 1;
                // result += add_result;
                // end_max = (cur_nums % end_max) == 0 ? end_max : (cur_nums % end_max);
                // 拆分后使得最后一个尽量大

                // std::cout << "(" << cur_nums << "," << add_result << ":" << end_max << ")";
            }
            else
            {
                end_max = cur_nums;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [12,9,7,6,17,19,21]n
// @lcpr case=end

// @lcpr case=start
// [19,7,2,24,11,16,1,11,23]\n
// @lcpr case=end

// @lcpr case=start
// [3,9,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */
