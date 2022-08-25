/*
 * @lc app=leetcode.cn id=2370 lang=cpp
 *
 * [2370] 最长理想子序列
 *
 * https://leetcode.cn/problems/longest-ideal-subsequence/description/
 *
 * algorithms
 * Medium (40.17%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 13.7K
 * Testcase Example:  '"acfgbd"\n2'
 *
 * 给你一个由小写字母组成的字符串 s ，和一个整数 k 。如果满足下述条件，则可以将字符串 t 视作是 理想字符串 ：
 *
 *
 * t 是字符串 s 的一个子序列。
 * t 中每两个 相邻 字母在字母表中位次的绝对差值小于或等于 k 。
 *
 *
 * 返回 最长 理想字符串的长度。
 *
 * 字符串的子序列同样是一个字符串，并且子序列还满足：可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。
 *
 * 注意：字母表顺序不会循环。例如，'a' 和 'z' 在字母表中位次的绝对差值是 25 ，而不是 1 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "acfgbd", k = 2
 * 输出：4
 * 解释：最长理想字符串是 "acbd" 。该字符串长度为 4 ，所以返回 4 。
 * 注意 "acfgbd" 不是理想字符串，因为 'c' 和 'f' 的字母表位次差值为 3 。
 *
 * 示例 2：
 *
 *
 * 输入：s = "abcd", k = 3
 * 输出：4
 * 解释：最长理想字符串是 "abcd" ，该字符串长度为 4 ，所以返回 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * 0 <= k <= 25
 * s 由小写英文字母组成
 *
 *
 */
// 	1834分
// @lc code=start
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        vector<int> vvi(26);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int cur_index = s[i] - 'a';
            if (i == 0)
            {
                vvi[cur_index] = 1;
            }
            else
            {
                // std::cout << i << ":";
                int cur_last_max = 0;
                for (int cur_temp = (cur_index - k > 0 ? cur_index - k : 0); cur_temp < (cur_index + k + 1 < 26 ? cur_index + k + 1 : 26); cur_temp++)
                {
                    cur_last_max = (cur_last_max > vvi[cur_temp]) ? cur_last_max : vvi[cur_temp];
                }
                vvi[cur_index] = cur_last_max + 1;
                // std::cout << std::endl;
            }
            result = (result > vvi[cur_index] ? result : vvi[cur_index]);
        }
        return result;
    }
};
// @lc code=end
