/*
 * @lc app=leetcode.cn id=2800 lang=cpp
 * @lcpr version=30102
 *
 * [2800] 包含三个字符串的最短字符串
 *
 * https://leetcode.cn/problems/shortest-string-that-contains-three-strings/description/
 *
 * algorithms
 * Medium (34.73%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    4.5K
 * Total Submissions: 12.8K
 * Testcase Example:  '"abc"\n"bca"\n"aaa"'
 *
 * 给你三个字符串 a ，b 和 c ， 你的任务是找到长度 最短 的字符串，且这三个字符串都是它的 子字符串 。
 * 如果有多个这样的字符串，请你返回 字典序最小 的一个。
 *
 * 请你返回满足题目要求的字符串。
 *
 * 注意：
 *
 *
 * 两个长度相同的字符串 a 和 b ，如果在第一个不相同的字符处，a 的字母在字母表中比 b 的字母 靠前 ，那么字符串 a 比字符串 b 字典序小
 * 。
 * 子字符串 是一个字符串中一段连续的字符序列。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：a = "abc", b = "bca", c = "aaa"
 * 输出："aaabca"
 * 解释：字符串 "aaabca" 包含所有三个字符串：a = ans[2...4] ，b = ans[3..5] ，c = ans[0..2]
 * 。结果字符串的长度至少为 6 ，且"aaabca" 是字典序最小的一个。
 *
 * 示例 2：
 *
 * 输入：a = "ab", b = "ba", c = "aba"
 * 输出："aba"
 * 解释：字符串 "aba" 包含所有三个字符串：a = ans[0..1] ，b = ans[1..2] ，c = ans[0..2] 。由于 c
 * 的长度为 3 ，结果字符串的长度至少为 3 。"aba" 是字典序最小的一个。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= a.length, b.length, c.length <= 100
 * a ，b ，c 只包含小写英文字母。
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    string join(string a, string b)
    {
        if (a.find(b) != -1)
            return a;
        if (b.find(a) != -1)
            return b;
        for (int i = min(a.size(), b.size()); i > 0; --i)
        {
            if (a.substr(a.size() - i) == b.substr(0, i))
            {
                return a + b.substr(i);
            }
        }
        return a + b;
    }

    string minimumString(string a, string b, string c)
    {
        vector<string> arr{a, b, c};
        sort(arr.begin(), arr.end());
        string ans = a + b + c;
        do
        {
            string str = join(join(arr[0], arr[1]), arr[2]);
            if (str.size() < ans.size() || (str.size() == ans.size() && str < ans))
            {
                ans = str;
            }
        } while (next_permutation(arr.begin(), arr.end()));
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bca"\n"aaa"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"ba"\n"aba"\n
// @lcpr case=end

 */
