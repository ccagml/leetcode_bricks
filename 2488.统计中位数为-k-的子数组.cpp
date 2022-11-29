/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 * @lcpr version=20401
 *
 * [2488] 统计中位数为 K 的子数组
 *
 * https://leetcode.cn/problems/count-subarrays-with-median-k/description/
 *
 * algorithms
 * Hard (37.69%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 8.6K
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
        unordered_map<int, int> umii;

        int da = 0;
        int xiao = 0;
        for (int i = k_index; i >= 0; i--)
        {
            (nums[i] > k) ? da++ : xiao++;
            int jd = da - xiao;
            umii[jd]++;
        }
        int result = 0;
        da = 0;
        xiao = 0;
        for (int i = k_index; i < nums.size(); i++)
        {
            (nums[i] >= k) ? da++ : xiao++;
            int jd = da - xiao;
            result += (umii[-jd] + umii[-jd + 1]);
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,1,4,5]\n4\n
// @lcpr case=end

// @lcpr case=start
// [2,5,1,4,3,6]\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,3,1]\n3\n
// @lcpr case=end

 */
