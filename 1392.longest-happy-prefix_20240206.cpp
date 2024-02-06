// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1392 lang=cpp
 * @lcpr version=30116
 *
 * [1392] 最长快乐前缀
 *
 * https://leetcode.cn/problems/longest-happy-prefix/description/
 *
 * algorithms
 * Hard (44.97%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 34K
 * Testcase Example:  '"level"'
 *
 * 「快乐前缀」 是在原字符串中既是 非空 前缀也是后缀（不包括原字符串自身）的字符串。
 *
 * 给你一个字符串 s，请你返回它的 最长快乐前缀。如果不存在满足题意的前缀，则返回一个空字符串 "" 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "level"
 * 输出："l"
 * 解释：不包括 s 自己，一共有 4 个前缀（"l", "le", "lev", "leve"）和 4 个后缀（"l", "el", "vel",
 * "evel"）。最长的既是前缀也是后缀的字符串是 "l" 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "ababab"
 * 输出："abab"
 * 解释："abab" 是最长的既是前缀也是后缀的字符串。题目允许前后缀在原字符串中重叠。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 只含有小写英文字母
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    // 计算某部分的哈希
    unsigned long long get_h(vector<unsigned long long> &f, vector<unsigned long long> &p, int left, int right)
    {
        if (left == 0)
        {
            return f[right];
        }
        return f[right] - f[left - 1] * p[right - left + 1];
    }

    string longestPrefix(string s)
    {
        int p_131 = 131;
        int n = s.size();
        vector<unsigned long long> f(n + 1);
        vector<unsigned long long> p(n + 1);
        p[0] = 1;
        f[0] = (s[0] - 'a' + 1);
        for (int i = 1; i < s.size(); i++)
        {
            f[i] = f[i - 1] * p_131 + (s[i] - 'a' + 1);
            p[i] = p[i - 1] * 131;
        }

        string result = "";

        for (int i = s.size() - 1; i > 0; i--)
        {
            unsigned long long left = get_h(f, p, 0, i - 1);
            unsigned long long right = get_h(f, p, n - i, n - 1);
            if (left == right)
            {
                result = s.substr(0, i);
                return result;
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=longestPrefix
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "level"\n
// @lcpr case=end

// @lcpr case=start
// "ababab"\n
// @lcpr case=end

// @lcpr case=start
// "aaaaa"\n
// @lcpr case=end

// @lcpr case=start
// "ddjefgfiagebcgbgchgchhabdcadbbbjaibabgacidjhdhidfbfefbigigiaibjbdaijififhabaajihicchdeffabjbegieedjebgdbfbbbdcfbcfhiejjihbddibhffejcehfggabbhidhbdaebehjbeiggdchjejjfejjbgcheehahfaccicffgfiiagdgfiijghceihbfjdabchcfedigicehiaadijbedfcdhajbifjjgcaaggbadidacbhieijjddifffbfaegghjifcchdbdjgghiedddagacdfjbbbcjjfgbghibigchagfjaacgihdiggbcbeijjcgaihccgdgcccjcddgabajedjibbajhjeehbgcjefhajbdbebbfiaiabhijbefcjeaceffcbiehafaghgdjdeedjhfgajjbjaffafeeffbeghhgijjffehdaejgigihcbabeahdbghfgfbhgageajafgehhdbjddcghgeaicaccjhdiejjagjciegeiihjedhigifaahcfhdigbcacfabgcdbbceagddeejiidiigfaafbhiejahgfaccggdedgiichjgdhbhfcdgceecjhfjifieecjacfcfgajaichjdbhcibgffhajihggchjebbacccfciegjhhdjhfadacaiifgijeijegbeeijjccfhgeiccbjjafiabgjfjhccchefdegceahbadcjadhgdgbfijihbeajjhfejfijffbdiaicdjacgjcdiaefjdeeijegciggiahgdagafcaeibhdicaejgaficfdfgaefajiebgaihjjfacchhfdieajfihecdejgbeicjficcgafafajcfbgjafcdcgffcgjjbdicagaedeeggbgebijdggigaabcihdccbehfagijbejhhcjcefgdbijjfbajbdaiaifdegdgfgfejihbedbhiaagbdjhajgbfjachjjcccdifciigfdijhjdadehdebehhjihfjbjggcfeefgejgdiifdhghggfhadedjfjabhfdechghiahibaijfefjhcbffhieejedjabddhdfjageajcfchcjfadacfhabgfbhdhiffjjhahjdhjibideabhfgeiajccigcfjgfjeggchdhicdiciadgbfiaegcgdeggichdcjjegbiggcjjbhdedhjhgededjedgaaffhcjjihbfdegigefagjbjdidddjefgfiagebcgbgchgchhabdcadbbbjaibabgacidjhdhidfbfefbigigiaibjbdaijififhabaajihicchdeffabjbegieedjebgdbfbbbdcfbcfhiejjihbddibhffejcehfggabbhidhbdaebehjbeiggdchjejjfejjbgcheehahfacci"\n
// @lcpr case=end

 */
