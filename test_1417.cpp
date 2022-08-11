/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 *
 * https://leetcode.cn/problems/reformat-the-string/description/
 *
 * algorithms
 * Easy (51.97%)
 * Likes:    52
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 48.8K
 * Testcase Example:  '"a0b1c2"'
 *
 * 给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。
 *
 * 请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。
 *
 * 请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "a0b1c2"
 * 输出："0a1b2c"
 * 解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
 *
 *
 * 示例 2：
 *
 * 输入：s = "leetcode"
 * 输出：""
 * 解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
 *
 *
 * 示例 3：
 *
 * 输入：s = "1229857369"
 * 输出：""
 * 解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
 *
 *
 * 示例 4：
 *
 * 输入：s = "covid2019"
 * 输出："c2o0v1i9d"
 *
 *
 * 示例 5：
 *
 * 输入：s = "ab123"
 * 输出："1a2b3"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 仅由小写英文字母和/或数字组成。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string reformat(string s)
    {
        int n = s.size();
        vector<char> vc1;
        vector<char> vc2;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                vc1.push_back(s[i]);
            }
            else
            {
                vc2.push_back(s[i]);
            }
        }
        int a = vc1.size() - vc2.size();
        if (abs(a) >= 2)
        {
            return "";
        }
        string result = "";
        int flag = 0;
        while (vc1.size() > 0 || vc2.size() > 0)
        {
            if (vc1.size() > vc2.size())
            {
                result.push_back(vc1[0]);
                vc1.erase(vc1.begin());
            }
            else if (vc1.size() == vc2.size())
            {
                if (result.size() == 0)
                {
                    result.push_back(vc1[0]);
                    vc1.erase(vc1.begin());
                }
                else if ('0' <= result[result.size() - 1] && result[result.size() - 1] <= '9')
                {
                    result.push_back(vc2[0]);
                    vc2.erase(vc2.begin());
                }
                else
                {
                    result.push_back(vc1[0]);
                    vc1.erase(vc1.begin());
                }
            }
            else
            {
                result.push_back(vc2[0]);
                vc2.erase(vc2.begin());
            }
        }
        return result;
    }
};
// @lc code=end
