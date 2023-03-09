// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21801
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.43%)
 * Likes:    6233
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.6M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 *
 * 示例 2：
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
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
    string longestPalindrome(string s)
    {
        string result = "";
        result.push_back(s[0]);

        for (int i = 0; i < s.size(); i++)
        {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 && right < s.size())
            {
                if (s[left] == s[right])
                {

                    if ((right - left + 1) > result.size())
                    {
                        result = s.substr(left, right - left + 1);
                    }
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            int left = i - 1;
            int right = i + 2;
            if (i + 1 < s.size())
            {
                if (s[i] == s[i + 1])
                {

                    if (2 > result.size())
                    {
                        result = s.substr(i, 2);
                    }

                    while (left >= 0 && right < s.size())
                    {
                        if (s[left] == s[right])
                        {

                            if ((right - left + 1) > result.size())
                            {
                                result = s.substr(left, right - left + 1);
                            }
                            left--;
                            right++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=longestPalindrome
// paramTypes=["string"]
// returnType=string
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end
// @lcpr case=start
// "aacabdkacaa"\n
// @lcpr case=end

 */
