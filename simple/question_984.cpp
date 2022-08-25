/*
 * @lc app=leetcode.cn id=984 lang=cpp
 *
 * [984] 不含 AAA 或 BBB 的字符串
 *
 * https://leetcode.cn/problems/string-without-aaa-or-bbb/description/
 *
 * algorithms
 * Medium (42.69%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    11.2K
 * Total Submissions: 26.3K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数 a 和 b ，返回 任意 字符串 s ，要求满足：
 *
 *
 * s 的长度为 a + b，且正好包含a 个 'a' 字母与 b 个 'b' 字母；
 * 子串 'aaa' 没有出现在 s 中；
 * 子串 'bbb' 没有出现在 s 中。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：a = 1, b = 2
 * 输出："abb"
 * 解释："abb", "bab" 和 "bba" 都是正确答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：a = 4, b = 1
 * 输出："aabaa"
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= a, b <= 100
 * 对于给定的 a 和 b，保证存在满足要求的 s 
 *
 * ​​​
 */

// @lc code=start
class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        string result = "";
        int a_cnt = 0;
        int b_cnt = 0;
        while (a > 0 || b > 0)
        {
            if (a_cnt == 2)
            {
                result.push_back('b');
            }
            else if (b_cnt == 2)
            {
                result.push_back('a');
            }
            else
            {
                if (a > b)
                {
                    result.push_back('a');
                }
                else
                {
                    result.push_back('b');
                }
            }
            if (result[result.size() - 1] == 'a')
            {
                a--;
                a_cnt++;
                b_cnt = 0;
            }
            else if (result[result.size() - 1] == 'b')
            {
                b--;
                a_cnt = 0;
                b_cnt++;
            }
        }
        return result;
    }
};
// @lc code=end
