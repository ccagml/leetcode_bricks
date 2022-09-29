/*
 * @lc app=leetcode.cn id=面试题 01.09 lang=cpp
 *
 * [面试题 01.09] 字符串轮转
 *
 * https://leetcode.cn/problems/string-rotation-lcci/description/
 *
 * LCCI
 * Easy (54.28%)
 * Likes:    155
 * Dislikes: 0
 * Total Accepted:    54.7K
 * Total Submissions: 100.2K
 * Testcase Example:  '"waterbottle"\n"erbottlewat"'
 *
 * 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
 *
 * 示例1:
 *
 * ⁠输入：s1 = "waterbottle", s2 = "erbottlewat"
 * ⁠输出：True
 *
 *
 * 示例2:
 *
 * ⁠输入：s1 = "aa", s2 = "aba"
 * ⁠输出：False
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 字符串长度在[0, 100000]范围内。
 *
 *
 * 说明:
 *
 *
 * 你能只调用一次检查子串的方法吗？
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string mys1;
    string mys2;
    unordered_map<char, unordered_set<int>> ucusi;

    bool isFlipedString(string s1, string s2)
    {
        if (s1.size() != s2.size())
        {
            return false;
        }
        if (s1.size() == 0)
        {
            return true;
        }
        mys1 = s1;
        mys2 = s2;
        for (int i = 0; i < s2.size(); i++)
        {
            ucusi[s2[i]].insert(i);
        }
        unordered_set<int> temp = ucusi[s1[0]];
        for (auto get : temp)
        {
            int index = 0;
            int need = get;
            while (index < s1.size())
            {
                if (s1[index] == s2[need])
                {
                    index++;
                    need++;
                    if (need >= s2.size())
                    {
                        need = 0;
                    }
                }
                else
                {
                    break;
                }
            }
            if (index == s1.size())
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
