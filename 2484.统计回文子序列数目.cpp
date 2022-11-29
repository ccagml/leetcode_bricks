/*
 * @lc app=leetcode.cn id=2484 lang=cpp
 * @lcpr version=20401
 *
 * [2484] 统计回文子序列数目
 *
 * https://leetcode.cn/problems/count-palindromic-subsequences/description/
 *
 * algorithms
 * Hard (43.52%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 3.9K
 * Testcase Example:  '"103301"'
 *
 * 给你数字字符串 s ，请你返回 s 中长度为 5 的 回文子序列 数目。由于答案可能很大，请你将答案对 10^9 + 7 取余 后返回。
 *
 * 提示：
 *
 *
 * 如果一个字符串从前往后和从后往前读相同，那么它是 回文字符串 。
 * 子序列是一个字符串中删除若干个字符后，不改变字符顺序，剩余字符构成的字符串。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "103301"
 * 输出：2
 * 解释：
 * 总共有 6 长度为 5 的子序列："10330" ，"10331" ，"10301" ，"10301" ，"13301" ，"03301" 。
 * 它们中有两个（都是 "10301"）是回文的。
 *
 *
 * 示例 2：
 *
 * 输入：s = "0000000"
 * 输出：21
 * 解释：所有 21 个长度为 5 的子序列都是 "00000" ，都是回文的。
 *
 *
 * 示例 3：
 *
 * 输入：s = "9999900000"
 * 输出：2
 * 解释：仅有的两个回文子序列是 "99999" 和 "00000" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 只包含数字字符。
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
    // unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> uuuuu;

    int uuuuu[10001][6][10][10];
    // vector<vector<vector<vector<int>>>> uuuuu;
    string new_s;
    int MOD = 1e9 + 7;
    long long dp(int cur, int len, int a, int b)
    {
        if (len == 5)
        {
            return 1;
        }

        if (5 - len > new_s.size() - cur)
        {
            return 0;
        }
        if (uuuuu[cur][len][a][b] != -1)
        {
            return uuuuu[cur][len][a][b];
        }

        int result = 0;
        if (len == 0)
        {
            result = (result + dp(cur + 1, len + 1, new_s[cur] - '0', b)) % MOD;
        }
        else if (len == 1)
        {
            result = (result + dp(cur + 1, len + 1, a, new_s[cur] - '0')) % MOD;
        }
        else if (len == 2)
        {
            result = (result + dp(cur + 1, len + 1, a, b)) % MOD;
        }
        else if (len == 3)
        {
            if (new_s[cur] - '0' == b)
            {
                result = (result + dp(cur + 1, len + 1, a, b)) % MOD;
            }
        }
        else if (len == 4)
        {
            if (new_s[cur] - '0' == a)
            {
                result = (result + dp(cur + 1, len + 1, a, b)) % MOD;
            }
        }
        result = (result + dp(cur + 1, len, a, b)) % MOD;
        uuuuu[cur][len][a][b] = result;
        return uuuuu[cur][len][a][b];
    }

    int countPalindromes(string s)
    {
        // vector<vector<vector<vector<int>>>> a(10001, vector<vector<vector<int>>>(6, vector<vector<int>>(10, vector<int>(10, -1))));
        // uuuuu = a;
        memset(uuuuu, -1, sizeof(uuuuu));
        new_s = s;
        return dp(0, 0, 0, 0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "103301"\n
// @lcpr case=end

// @lcpr case=start
// "0000000"\n
// @lcpr case=end

// @lcpr case=start
// "9999900000"\n
// @lcpr case=end

 */
