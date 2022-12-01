/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=20602
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (62.25%)
 * Likes:    3958
 * Dislikes: 0
 * Total Accepted:    609.4K
 * Total Submissions: 978.9K
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
        stack<int> sl;
        stack<int> sr;
        vector<int> vl(n, -1);
        vector<int> vr(n, n);
        // for (int i = 0; i < n; i++)
        // {
        //     while (sl.size() > 0 && height[sl.top()] < height[i])
        //     {
        //         sl.pop();
        //     }
        //     vl[i] = sl.size() > 0 ? sl.top() : i;
        //     sl.push(i);
        //     while (sr.size() > 0 && height[sr.top()] < height[i])
        //     {
        //         vr[sr.top()] = i;
        //         sr.pop();
        //     }
        //     sr.push(i);
        // }

        // 统计左右最高的
        for (int i = 0; i < n; i++)
        {
            if (sl.size() == 0 || sl.size() > 0 && height[i] >= height[sl.top()])
            {
                sl.push(i);
            }
            vl[i] = sl.top();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (sr.size() == 0 || sr.size() > 0 && height[i] >= height[sr.top()])
            {
                sr.push(i);
            }
            vr[i] = sr.top();
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = height[i];
            int left = vl[i] >= 0 ? height[vl[i]] : 0;
            int right = vr[i] < n ? height[vr[i]] : 0;
            int add = max(0, min(left, right)) - cur;
            if (add > 0)
            {
                // std::cout << i << ":add:" << add << std::endl;
                result += add;
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
