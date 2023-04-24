// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=21907
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.66%)
 * Likes:    6484
 * Dislikes: 0
 * Total Accepted:    938.5K
 * Total Submissions: 2.3M
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
        int all = nums1.size() + nums2.size();
        int cost = all / 2;
        if (all % 2 == 0)
        {
            cost--;
        }

        int left = 0;
        int right = 0;
        while (cost > 0)
        {
            if (left < nums1.size() && right < nums2.size())
            {
                if (nums1[left] < nums2[right])
                {
                    left++;
                    cost--;
                }
                else
                {
                    right++;
                    cost--;
                }
            }
            else if (left < nums1.size())
            {
                left++;
                cost--;
            }
            else if (right < nums2.size())
            {
                right++;
                cost--;
            }
        }

        vector<double> vi;
        if (left < nums1.size())
        {
            vi.push_back(nums1[left]);
            left++;
        }
        if (right < nums2.size())
        {
            vi.push_back(nums2[right]);
            right++;
        }

        if (left < nums1.size())
        {
            vi.push_back(nums1[left]);
            left++;
        }
        if (right < nums2.size())
        {
            vi.push_back(nums2[right]);
            right++;
        }
        sort(vi.begin(), vi.end());
        if (all % 2 == 0)
        {
            return (vi[0] + vi[1]) / 2;
        }
        else
        {
            return vi[0];
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
