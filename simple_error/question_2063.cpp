/*
 * @lc app=leetcode.cn id=2063 lang=cpp
 *
 * [2063] 所有子字符串中的元音
 *
 * https://leetcode.cn/problems/vowels-of-all-substrings/description/
 *
 * algorithms
 * Medium (50.90%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 11.2K
 * Testcase Example:  '"aba"'
 *
 * 给你一个字符串 word ，返回 word 的所有子字符串中 元音的总数 ，元音是指 'a'、'e'、'i'、'o' 和 'u' 。
 *
 * 子字符串 是字符串中一个连续（非空）的字符序列。
 *
 * 注意：由于对 word 长度的限制比较宽松，答案可能超过有符号 32 位整数的范围。计算时需当心。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：word = "aba"
 * 输出：6
 * 解释：
 * 所有子字符串是："a"、"ab"、"aba"、"b"、"ba" 和 "a" 。
 * - "b" 中有 0 个元音
 * - "a"、"ab"、"ba" 和 "a" 每个都有 1 个元音
 * - "aba" 中有 2 个元音
 * 因此，元音总数 = 0 + 1 + 1 + 1 + 1 + 2 = 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：word = "abc"
 * 输出：3
 * 解释：
 * 所有子字符串是："a"、"ab"、"abc"、"b"、"bc" 和 "c" 。
 * - "a"、"ab" 和 "abc" 每个都有 1 个元音
 * - "b"、"bc" 和 "c" 每个都有 0 个元音
 * 因此，元音总数 = 1 + 1 + 1 + 0 + 0 + 0 = 3 。
 *
 * 示例 3：
 *
 *
 * 输入：word = "ltcd"
 * 输出：0
 * 解释："ltcd" 的子字符串均不含元音。
 *
 * 示例 4：
 *
 *
 * 输入：word = "noosabasboosa"
 * 输出：237
 * 解释：所有子字符串中共有 237 个元音。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= word.length <= 10^5
 * word 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    long long countVowels(string word)
    {
        int n = word.size();
        long long result = 0;
        int cnt = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            {
                // abcde
                long long start_i = i - 0; // 以i结尾
                long long end_i = n - i - 1; // 以i开头
                long long mid_i = start_i * end_i; // i 在中间的情况
                result += (start_i + 1 + end_i + mid_i);
                // std::cout << i << ":" << start_i  << "|" << 1  << "|" << end_i << std::endl;
            }
        }
        return result;
    }
};
/*
0:0|1|2
1:1|1|1
2:2|1|0

"a"、"ab"、"abc"、
"b"、"bc" 
"c" 。

*/
// @lc code=end
