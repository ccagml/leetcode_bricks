/*
 * @lc app=leetcode.cn id=761 lang=cpp
 *
 * [761] 特殊的二进制序列
 *
 * https://leetcode.cn/problems/special-binary-string/description/
 *
 * algorithms
 * Hard (58.92%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 7.5K
 * Testcase Example:  '"11010100"'
 *
 * 特殊的二进制序列是具有以下两个性质的二进制序列：
 *
 *
 * 0 的数量与 1 的数量相等。
 * 二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。
 *
 *
 * 给定一个特殊的二进制序列 S，以字符串形式表示。定义一个操作 为首先选择 S
 * 的两个连续且非空的特殊的子串，然后将它们交换。（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)
 *
 * 在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？
 *
 * 示例 1:
 *
 *
 * 输入: S = "11011000"
 * 输出: "11100100"
 * 解释:
 * 将子串 "10" （在S[1]出现） 和 "1100" （在S[3]出现）进行交换。
 * 这是在进行若干次操作后按字典序排列最大的结果。
 *
 *
 * 说明:
 *
 *
 * S 的长度不超过 50。
 * S 保证为一个满足上述定义的特殊 的二进制序列。
 *
 *
 */

// @lc code=start

// 1.看题目觉得可能是动态规划, 看着交换规则看不出递推式
// 2.按照题目的规则, 每个部分一定是 1开头 0结尾
// 3.从题目看不出是要分治,然后每个小部分可以交换(题目的规则是前后相等才能交换)
// 4. 从3看 如果 首位的1可以交换来, 那么 就是 0xxxy1 1yyyy0交换的情况, 那么他们本身就可以拆分成2个子结构
// 5. 因为我们的每一个子串都是 1开头 0结尾,  （两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)
// 6. 所以可以直接排序
class Solution
{
public:
    string makeLargestSpecial(string s)
    {
        int n = s.size();
        if (n <= 2)
        {
            return s;
        }

        int cnt = 0;
        int start = 0;
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    string cut = s.substr(start + 1, i - start - 1);
                    // std::cout << "裁剪:" << s <<":" << start << ":" << i << ":" << cut << std::endl;
                    if((i - start) > 2 ){
                        temp.push_back("1" + makeLargestSpecial(cut) + "0");
                    }else{
                        temp.push_back("10");
                    }
                    start = i + 1;
                }
            }
        }

        sort(temp.begin(), temp.end(), greater<string>());
        std::string result;
        for (const auto &piece : temp)
            result += piece;
        // std::cout << n << ":" << s << ", result:" << result << std::endl;
        return result;
    }
};
// @lc code=end
