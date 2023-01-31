/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=21401
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.37%)
 * Likes:    3707
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.1M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 *
 * 示例 3：
 *
 * 输入：s = "(]"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
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
    bool isValid(string s)
    {
        stack<char> stc;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stc.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (stc.size() == 0 || stc.top() != '(')
                {
                    return false;
                }
                stc.pop();
            }
            else if (s[i] == ']')
            {
                if (stc.size() == 0 || stc.top() != '[')
                {
                    return false;
                }
                stc.pop();
            }
            else if (s[i] == '}')
            {
                if (stc.size() == 0 || stc.top() != '{')
                {
                    return false;
                }
                stc.pop();
            }
        }
        return stc.size() == 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
