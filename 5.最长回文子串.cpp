/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=21104
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.33%)
 * Likes:    6017
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
    unsigned long long get_h(vector<unsigned long long> f, vector<unsigned long long> p, int left, int right)
    {
        if (left == 0)
        {
            return f[right];
        }
        return f[right] - f[left - 1] * p[right - left + 1];
    }
    unsigned long long get_h1(vector<unsigned long long> f1, vector<unsigned long long> p1, int left, int right)
    {
        int need_left = n - 1 - right;
        int need_right = n - 1 - left;
        return get_h(f1, p1, need_left, need_right);
    }
    int n;
    string longestPalindrome(string s)
    {
        n = s.size();
        int p_131 = 131;
        vector<unsigned long long> f(1001);
        vector<unsigned long long> p(1001);
        p[0] = 1;
        f[0] = (s[0] - 'a' + 1);
        for (int i = 1; i < s.size(); i++)
        {
            f[i] = f[i - 1] * p_131 + (s[i] - 'a' + 1);
            p[i] = p[i - 1] * 131;
        }

        vector<unsigned long long> f1(1001);
        vector<unsigned long long> p1(1001);

        string s1(s);
        reverse(s1.begin(), s1.end());
        p1[0] = 1;
        f1[0] = (s1[0] - 'a' + 1);
        for (int i = 1; i < s.size(); i++)
        {
            f1[i] = f1[i - 1] * p_131 + (s1[i] - 'a' + 1);
            p1[i] = p1[i - 1] * 131;
        }

        string result = "";
        result.push_back(s[0]);
        // 以 i 为中心
        for (int i = 0; i < s.size(); i++)
        {
            int need_len = result.size() / 2;
            for (int len = max(1, need_len); len < s.size(); len++)
            {
                int left = i - len;
                int right = i - 1;

                int left1 = i + 1;
                int right1 = i + len;
                if (left < 0 || right1 >= s.size())
                {
                    break;
                }

                unsigned long long left_flag = get_h(f, p, left, right);
                unsigned long long right_flag = get_h1(f1, p1, left1, right1);
                // std::cout << "(前:" << left << ":" << right << "=" << left_flag;
                // std::cout << "(后:" << left1 << ":" << right1 << "=" << right_flag;
                if (left_flag == right_flag)
                {
                    // std::cout << "前后相等";
                    int cur_n = result.size();
                    if (len * 2 + 1 > cur_n)
                    {
                        result = s.substr(left, (len * 2 + 1));
                    }
                }
                else
                {
                    break;
                }
                // std::cout << std::endl;
            }
        }

        for (int i = 0; i < s.size() - 1; i++)
        {
            int need_len = result.size() / 2;
            for (int len = max(0, need_len); len < s.size(); len++)
            {
                int left = i - len;
                int right = i;

                int left1 = i + 1;
                int right1 = i + len + 1;
                if (left < 0 || right1 >= s.size())
                {
                    break;
                }

                unsigned long long left_flag = get_h(f, p, left, right);
                unsigned long long right_flag = get_h1(f1, p1, left1, right1);
                // std::cout << "(前:" << left << ":" << right << "=" << left_flag;
                // std::cout << "(后:" << left1 << ":" << right1 << "=" << right_flag;
                if (left_flag == right_flag)
                {
                    // std::cout << "前后相等";
                    int cur_n = result.size();
                    if (len * 2 + 2 > cur_n)
                    {
                        result = s.substr(left, (len * 2 + 2));
                    }
                }
                else
                {
                    break;
                }
                // std::cout << std::endl;
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
