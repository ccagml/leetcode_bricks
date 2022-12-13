/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=21004
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (62.26%)
 * Likes:    3983
 * Dislikes: 0
 * Total Accepted:    612.9K
 * Total Submissions: 984.4K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 *
 *
 * 示例 2：
 *
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
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
    int trap(vector<int> &height)
    {
        int n = height.size();
        stack<int> left;
        vector<int> left_v(n);
        stack<int> right;
        vector<int> right_v(n);
        for (int i = 0; i < height.size(); i++)
        {
            int cur = height[i];
            while (left.size() == 0 || height[left.top()] < cur)
            {
                left.push(i);
            }
            left_v[i] = left.top();
        }
        for (int i = height.size() - 1; i >= 0; i--)
        {
            int cur = height[i];
            while (right.size() == 0 || height[right.top()] < cur)
            {
                right.push(i);
            }
            right_v[i] = right.top();
        }
        int result = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int cur = height[i];
            int left_max = height[left_v[i]];
            int right_max = height[right_v[i]];
            if (min(left_max, right_max) - cur > 0)
            {
                result += min(left_max, right_max) - cur;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
