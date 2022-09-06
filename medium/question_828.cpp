/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 *
 * https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/
 *
 * algorithms
 * Hard (55.92%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    11.2K
 * Total Submissions: 17.9K
 * Testcase Example:  '"ABC"'
 *
 * 我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。
 *
 * 例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以
 * countUniqueChars(s) = 5 。
 *
 * 本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。输入用例保证返回值为 32
 * 位整数。
 *
 * 注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: s = "ABC"
 * 输出: 10
 * 解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
 * ⁠    其中，每一个子串都由独特字符构成。
 * ⁠    所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
 *
 *  a
 *  b ab
 *  b abb bb
 *  d abcb bcb cb
 *
 * 示例 2：
 *
 *
 * 输入: s = "ABA"
 * 输出: 8
 * 解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "LEETCODE"
 * 输出：92
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 只包含大写英文字符
 *
 *
 */

// 想到第一步 应该是需要 按 字符 的位置插入 不同的vector
// 想不到第二步, 每个字符对 子字符串的贡献 是 上一个 到本字符  跟 本字符到下一个的乘积
// @lc code=start

class Solution
{
public:
    int uniqueLetterString(string s)
    {
        unordered_map<char, vector<int>> index;
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i]].push_back(i);
        }
        int result = 0;
        for (pair<char, vector<int>> &&tt : index)
        {

            tt.second.insert(tt.second.begin(), -1);
            tt.second.push_back(s.size());

            for (int i = 1; i < tt.second.size() - 1; i++)
            {
                result += (tt.second[i] - tt.second[i - 1]) * (tt.second[i + 1] - tt.second[i]);
            }
        }
        return result;
    }
};
// @lc code=end
