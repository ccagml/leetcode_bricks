/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21301
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.37%)
 * Likes:    6081
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.5M
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
        int n = s.size();
        vector<vector<bool>> vvi(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            vvi[i][i] = true;
            if (i > 0 && s[i - 1] == s[i])
            {
                vvi[i - 1][i] = true;
            }
        }

        // std::cout << "11111";
        for (int i = 0; i < n; i++)
        {
            int left = i - 1;
            int right = i + 1;
            // std::cout << "|" << i << ",";
            while (left >= 0 && right < n && s[left] == s[right] && vvi[left + 1][right - 1])
            {
                vvi[left][right] = true;
                int cur_len = right - left + 1;
                if (cur_len > result.size())
                {
                    result = s.substr(left, cur_len);
                }
                left--;
                right++;
            }
            // std::cout << "[" << i << "]";
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right] && (right - left == 1 || vvi[left + 1][right - 1]))
            {

                vvi[left][right] = true;
                int cur_len = right - left + 1;
                if (cur_len > result.size())
                {
                    result = s.substr(left, cur_len);
                }
                left--;
                right++;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
