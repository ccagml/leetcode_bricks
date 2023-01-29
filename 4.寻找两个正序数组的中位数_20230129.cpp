/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=21301
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.64%)
 * Likes:    6217
 * Dislikes: 0
 * Total Accepted:    875.6K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        // sort(nums1.begin(), nums1.end());
        // if (nums1.size() % 2 == 0)
        // {
        //     int mid = nums1.size() / 2;
        //     double result = double(nums1[mid] + nums1[mid - 1]) / 2;
        //     return result;
        // }
        // else
        // {
        //     int mid = nums1.size() / 2;
        //     double result = double(nums1[mid]);
        //     return result;
        // }
        int n = nums1.size() + nums2.size();
        int need_cut = n / 2;
        int left = 0;
        int right = 0;
        while (need_cut > 0)
        {
            int mid1v = (nums1.size() + left) / 2;
            int mid2v = (nums2.size() + right) / 2;
            if (mid1v < nums1.size() && mid2v < nums2.size())
            {
                int midl = nums1[mid1v];
                int mid2 = nums1[mid2v];
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */
