/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=20204
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (62.22%)
 * Likes:    3946
 * Dislikes: 0
 * Total Accepted:    606.8K
 * Total Submissions: 975.1K
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

// 思考,  左边最高, 右边最高的最小值

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        stack<int> s_left;
        stack<int> s_right;
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        for (int i = 0; i < height.size(); i++)
        {
            if (s_left.empty())
            {
                s_left.push(i);
            }
            else if (height[s_left.top()] < height[i])
            {
                s_left.push(i);
            }
            left[i] = s_left.top();
            // std::cout << "left " << i << ":" << height[i] << "最大" << s_left.top() << ":" << height[s_left.top()] << std::endl;
        }

        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (s_right.empty())
            {
                s_right.push(i);
            }
            else if (height[s_right.top()] < height[i])
            {
                s_right.push(i);
            }
            right[i] = s_right.top();
            // std::cout << "right " << i << ":" << height[i] << "最大" << s_left.top() << ":" << height[s_right.top()] << std::endl;
        }
        int result = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int h_l = min(height[right[i]], height[left[i]]);
            // std::cout << i << "当前" << height[i] << ":left:" << height[left[i]] << ":right:" << height[right[i]] << ":add:" << height[i] - h_l << std::endl;
            if (h_l - height[i] > 0)
            {
                result += (h_l - height[i]);
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
