/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=21401
 *
 * [32] 最长有效括号
 *
 * https://leetcode.cn/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (37.07%)
 * Likes:    2134
 * Dislikes: 0
 * Total Accepted:    342.3K
 * Total Submissions: 923.5K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 *
 *
 * 示例 2：
 *
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 *
 *
 * 示例 3：
 *
 * 输入：s = ""
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] 为 '(' 或 ')'
 *
 *
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
    int result;
    int max_left = -1;
    int max_right = -1;
    unordered_map<int, int> left_right;
    unordered_map<int, int> right_left;
    string sss;
    int longestValidParentheses(string s)
    {
        sss = s;
        int n = s.size();
        vector<vector<bool>> vvb(n, vector<bool>(n));
        // x y 是否合法
        // 合法 + 合法 = 合法
        // (合法) = 合法

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '(' && s[i + 1] == ')')
            {
                vvb[i][i + 1] = true;
                left_right[i] = i + 1;
                right_left[i + 1] = i;
                result = 2;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (vvb[i][i + 1] && (i < max_left || i > max_right))
            {
                check(i, i + 1);
            }
        }
        return result;
    }
    void check(int left, int right)
    {
        bool update = false;
        while (left_right.count(right + 1))
        {
            //连接左右
            right = left_right[right + 1];
            update = true;
        }
        while (right_left.count(left - 1))
        {
            left = right_left[left - 1];
            update = true;
        }
        // 尽可能扩大
        while (left > 0 && right < sss.size() - 1)
        {
            if (sss[left - 1] == '(' && sss[right + 1] == ')')
            {
                left--;
                right++;
                update = true;
            }
            else
            {
                break;
            }
        }
        if (right - left + 1 > result)
        {
            max_left = left;
            max_right = right;
            result = right - left + 1;
        }
        // result = max(result, right - left + 1);
        if (update)
        {
            left_right[left] = right;
            right_left[right] = left;
            // result = max(result, right - left + 1);
            check(left, right);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
