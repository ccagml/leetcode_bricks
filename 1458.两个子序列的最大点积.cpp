/*
 * @lc app=leetcode.cn id=1458 lang=cpp
 * @lcpr version=21113
 *
 * [1458] 两个子序列的最大点积
 *
 * https://leetcode.cn/problems/max-dot-product-of-two-subsequences/description/
 *
 * algorithms
 * Hard (45.96%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 15.4K
 * Testcase Example:  '[2,1,-2,5]\r\n[3,0,-6]\r'
 *
 * 给你两个数组 nums1 和 nums2 。
 *
 * 请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。
 *
 * 数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，[2,3,5] 是
 * [1,2,3,4,5] 的一个子序列而 [1,5,3] 不是。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [2,1,-2,5], nums2 = [3,0,-6]
 * 输出：18
 * 解释：从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
 * 它们的点积为 (2*3 + (-2)*(-6)) = 18 。
 *
 * 示例 2：
 *
 * 输入：nums1 = [3,-2], nums2 = [2,-6,7]
 * 输出：21
 * 解释：从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
 * 它们的点积为 (3*7) = 21 。
 *
 * 示例 3：
 *
 * 输入：nums1 = [-1,-1], nums2 = [1,1]
 * 输出：-1
 * 解释：从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
 * 它们的点积为 -1 。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 500
 * -1000 <= nums1[i], nums2[i] <= 100
 *
 *
 *
 *
 * 点积：
 *
 * 定义 a = [a1, a2,…, an] 和 b = [b1, b2,…, bn] 的点积为：
 *
 *
 *
 * 这里的 Σ 指示总和符号。
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
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<vector<int>> vvi(s1, vector<int>(s2));

        for (int i = 0; i < s1; i++)
        {
            for (int j = 0; j < s2; j++)
            {
                int ixj = nums1[i] * nums2[j];
                vvi[i][j] = ixj;
                if (i > 0)
                {
                    vvi[i][j] = max(vvi[i][j], vvi[i - 1][j]);
                }

                if (j > 0)
                {
                    vvi[i][j] = max(vvi[i][j], vvi[i][j - 1]);
                }

                if (j > 0 && i > 0)
                {
                    vvi[i][j] = max(vvi[i][j], vvi[i - 1][j - 1] + ixj);
                }
            }
        }
        return vvi[s1 - 1][s2 - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,-2,5]\n[3,0,-6]\n
// @lcpr case=end

// @lcpr case=start
// [3,-2]\n[2,-6,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1]\n[1,1]\n
// @lcpr case=end

 */
