/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 * @lcpr version=20703
 *
 * [1775] 通过最少操作次数使数组的和相等
 *
 * https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/description/
 *
 * algorithms
 * Medium (49.03%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 20.2K
 * Testcase Example:  '[1,2,3,4,5,6]\n[1,1,2,2,2,2]'
 *
 * 给你两个长度可能不等的整数数组 nums1 和 nums2 。两个数组中的所有值都在 1 到 6 之间（包含 1 和 6）。
 *
 * 每次操作中，你可以选择 任意 数组中的任意一个整数，将它变成 1 到 6 之间 任意 的值（包含 1 和 6）。
 *
 * 请你返回使 nums1 中所有数的和与 nums2 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
 * 输出：3
 * 解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
 * - 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
 * - 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
 * - 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
 * 输出：-1
 * 解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
 *
 *
 * 示例 3：
 *
 * 输入：nums1 = [6,6], nums2 = [1]
 * 输出：3
 * 解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
 * - 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
 * - 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
 * - 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 10^5
 * 1 <= nums1[i], nums2[i] <= 6
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
// 贪心?
// 两个优先级队列?
class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if ((n1 > n2 && n1 > 6 * n2) || (n1 < n2 && n1 * 6 < n2))
        {
            return -1;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> small_pri;
        std::priority_queue<int, std::vector<int>, std::less<int>> big_pri;
        int sum1 = 0;
        for (int num1 : nums1)
        {
            sum1 += num1;
        }
        int sum2 = 0;
        for (int num2 : nums2)
        {
            sum2 += num2;
        }

        int big_sum = 0;
        int small_sum = 0;

        if (sum1 == sum2)
        {
            return 0;
        }
        else if (sum1 > sum2)
        {
            big_sum = sum1;
            small_sum = sum2;
            for (int num1 : nums1)
            {
                big_pri.push(num1);
            }

            for (int num2 : nums2)
            {
                small_pri.push(num2);
            }
        }
        else if (sum2 > sum1)
        {
            big_sum = sum2;
            small_sum = sum1;

            for (int num1 : nums1)
            {
                small_pri.push(num1);
            }

            for (int num2 : nums2)
            {
                big_pri.push(num2);
            }
        }
        int result = 0;
        while (big_sum > small_sum)
        {
            int big_front = big_pri.top();
            int small_front = small_pri.top();
            int big_diff = big_front - 1;
            int small_diff = 6 - small_front;
            if (big_diff > small_diff)
            {
                big_pri.pop();
                big_sum -= big_diff;
            }
            else
            {
                small_pri.pop();
                small_sum += small_diff;
            }
            result++;
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6]\n[1,1,2,2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,1,1,1]\n[6]\n
// @lcpr case=end

// @lcpr case=start
// [6,6]\n[1]\n
// @lcpr case=end

 */
