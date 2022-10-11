/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 *
 * https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal/description/
 *
 * algorithms
 * Easy (54.27%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 56.8K
 * Testcase Example:  '"bank"\n"kanb"'
 *
 * 给你长度相等的两个字符串 s1 和 s2 。一次 字符串交换 操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。
 *
 * 如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s1 = "bank", s2 = "kanb"
 * 输出：true
 * 解释：例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
 *
 *
 * 示例 2：
 *
 * 输入：s1 = "attack", s2 = "defend"
 * 输出：false
 * 解释：一次字符串交换无法使两个字符串相等
 *"bank"\n"kanb"\n"attack"\n"defend"\n"kelb"\n"kelb"\n"abcd"\n"dcba"
 *
 * 示例 3：
 *
 * 输入：s1 = "kelb", s2 = "kelb"
 * 输出：true
 * 解释：两个字符串已经相等，所以不需要进行字符串交换
 *
 *
 * 示例 4：
 *
 * 输入：s1 = "abcd", s2 = "dcba"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s1.length, s2.length <= 100
 * s1.length == s2.length
 * s1 和 s2 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        char ss = ' ';
        char ss2 = ' ';
        bool flag = false;
        for (int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i]){
                if(flag){
                    return false;
                }
                if(ss == ' '){
                    ss = s1[i];
                    ss2 = s2[i];
                }else{
                    if(ss == s2[i] && ss2 == s1[i]){
                        flag = true;
                    }else{
                        return false;
                    }
                }
            }
        }
        if(!flag && ss != ' '){
            return false;
        }
        return true;
    }
};
// @lc code=end
