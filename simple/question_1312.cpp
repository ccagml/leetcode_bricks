/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 *
 * https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (68.27%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 25.3K
 * Testcase Example:  '"zzazz"'
 *
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 *
 * 请你返回让 s 成为回文串的 最少操作次数 。
 *
 * 「回文串」是正读和反读都相同的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "zzazz"
 * 输出：0
 * 解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "mbadm"
 * 输出：2
 * 解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "leetcode"
 * 输出：5
 * 解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 500
 * s 中所有字符都是小写字母。
 *
 *
 */

// @lc code=start

// 还以为很难,结果只是一个简单的动态规划

class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<vector<int>> vvi(n, vector<int>(n, 1000));
        for (int i_len = 0; i_len <= n; i_len++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + i_len;
                if(j >= n){
                    break;
                }
                if(i_len == 0){
                    vvi[i][j] = 0;
                }
                else if (i_len == 1)
                {
                    vvi[i][j] = (s[i] == s[j])? 0 : 1;
                }else{
                    if(s[i] == s[j]){
                        vvi[i][j] = vvi[i + 1][j - 1];
                    }else{
                        int a = vvi[i + 1][j - 1] + 2;
                        int b = vvi[i][j - 1] + 1;
                        int c = vvi[i + 1][j ] + 1;
                        // std::cout << i << ":" << j <<":" << a <<":" << b <<":" << c << std::endl;
                        vvi[i][j] = min(a, min(b, c));
                    }
                }
            }
        }
        return vvi[0][n - 1];
    }
};
// @lc code=end
