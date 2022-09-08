/*
 * @lc app=leetcode.cn id=2311 lang=cpp
 *
 * [2311] 小于等于 K 的最长二进制子序列
 *
 * https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/
 *
 * algorithms
 * Medium (35.94%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 17.5K
 * Testcase Example:  '"1001010"\n5'
 *
 * 给你一个二进制字符串 s 和一个正整数 k 。
 *
 * 请你返回 s 的 最长 子序列，且该子序列对应的 二进制 数字小于等于 k 。
 *
 * 注意：
 *
 *
 * 子序列可以有 前导 0 。
 * 空字符串视为 0 。
 * 子序列 是指从一个字符串中删除零个或者多个字符后，不改变顺序得到的剩余字符序列。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "1001010", k = 5
 * 输出：5
 * 解释：s 中小于等于 5 的最长子序列是 "00010" ，对应的十进制数字是 2 。
 * 注意 "00100" 和 "00101" 也是可行的最长子序列，十进制分别对应 4 和 5 。
 * 最长子序列的长度为 5 ，所以返回 5 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "00101001", k = 1
 * 输出：6
 * 解释："000001" 是 s 中小于等于 1 的最长子序列，对应的十进制数字是 1 。
 * 最长子序列的长度为 6 ，所以返回 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 1000
 * s[i] 要么是 '0' ，要么是 '1' 。
 * 1 <= k <= 10^9
 *
 *
 */

// @lc code=start
// 最高位的1 前面可以加0
// 某一段序列的值小于k 加上前面的0


// 思路有点巧妙,
// 1.计算所有的0
// 2.从尾巴开始累计i的值,如果小于k就加入
class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        long long z = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            z += (s[i] == '0');
        }

        reverse(s.begin(), s.end());
        long long ans = z;
        for (long long i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (i > 31)
                {
                    return ans;
                }
                long long p = (long long)pow(2, i);
                if (p > k)
                {
                    return ans;
                }
                k -= p;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
