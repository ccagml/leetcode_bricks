/*
 * @lc app=leetcode.cn id=6248 lang=cpp
 * @lcpr version=20301
 *
 * [6248] 统计中位数为 K 的子数组
 *
 * https://leetcode.cn/problems/count-subarrays-with-median-k/description/
 *
 * algorithms
 * Hard (35.90%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 8K
 * Testcase Example:  '[3,2,1,4,5]\n4'
 *
 * 给你一个长度为 n 的数组 nums ，该数组由从 1 到 n 的 不同 整数组成。另给你一个正整数 k 。
 *
 * 统计并返回 num 中的 中位数 等于 k 的非空子数组的数目。
 *
 * 注意：
 *
 *
 * 数组的中位数是按 递增 顺序排列后位于 中间 的那个元素，如果数组长度为偶数，则中位数是位于中间靠 左 的那个元素。
 *
 *
 * 例如，[2,3,1,4] 的中位数是 2 ，[8,4,3,5,1] 的中位数是 4 。
 *
 *
 * 子数组是数组中的一个连续部分。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,2,1,4,5], k = 4
 * 输出：3
 * 解释：中位数等于 4 的子数组有：[4]、[4,5] 和 [1,4,5] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,3,1], k = 3
 * 输出：1
 * 解释：[3] 是唯一一个中位数等于 3 的子数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 1 <= nums[i], k <= n
 * nums 中的整数互不相同
 *
 *
 */

using namespace std;
#include "unordered_map"
#include "vector"

// 想的是 计算左右合起来大于 k 的数量, 超时原因可能是一直重复计算
// 想不到 可以用map存下答案
// 40:0
// 先累计左边净多几个大的数量, 然后和右边合起来是0,或者净多1个的数量

// @lc code=start
class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        int k_index = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
            {
                k_index = i;
                break;
            }
        }

        unordered_map<int, int> jing_big;
        // 计算左边
        int left_big = 0;
        int left_small = 0;
        for (int i = k_index; i >= 0; i--)
        {
            (nums[i] > k) ? left_big++ : left_small++;
            int temp_jing_duo = left_big - left_small;
            jing_big[temp_jing_duo]++;
        }

        // 计算右边
        int right_big = 0;
        int right_small = 0;
        int result = 0;
        for (int i = k_index; i < nums.size(); i++)
        {
            (nums[i] >= k) ? right_big++ : right_small++;
            int temp_jing_duo = right_big - right_small;

            result += (jing_big[-temp_jing_duo] + jing_big[-temp_jing_duo + 1]);
        }
        return result;
        // unordered_map<int, int> mpl;
        // int l = 0, m = 0, ans = 0;

        // for (int i = k_index; i >= 0; i--)
        // {
        //     if (nums[i] <= k)
        //         l++;
        //     else
        //         m++;
        //     mpl[l - m]++;
        // }

        // l = -1;
        // m = 0;
        // for (int i = k_index; i < nums.size(); i++)
        // {
        //     if (nums[i] <= k)
        //         l++;
        //     else
        //         m++;
        //     ans += mpl[m - l + 1] + mpl[m - l];
        // }

        // return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,4,5]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1]\n3\n
// @lcpr case=end

 */
