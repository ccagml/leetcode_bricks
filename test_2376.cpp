/*
 * @lc app=leetcode.cn id=2376 lang=cpp
 *
 * [2376] 统计特殊整数
 *
 * https://leetcode.cn/problems/count-special-integers/description/
 *
 * algorithms
 * Hard (45.07%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 10.9K
 * Testcase Example:  '20'
 *
 * 如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。
 *
 * 给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 20
 * 输出：19
 * 解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 5
 * 输出：5
 * 解释：1 到 5 所有整数都是特殊整数。
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 135
 * 输出：110
 * 解释：从 1 到 135 总共有 110 个整数是特殊整数。
 * 不特殊的部分数字为：22 ，114 和 131 。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2 * 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        string str_n = std::to_string(n);
        int n_size = str_n.size();
        int result = 0;
        // 整数的首位不能是0
        int cur = str_n[0] - '0';
        int temp_answer = cur;
        int temp_start = 9;
        for (int ii = 1; ii < n_size; ii++)
        {
            temp_answer *= temp_start;
            temp_start--;
        }
        result += temp_answer;

        for (int i = 1; i < n_size; i++)
        {
            int cur = str_n[i] - '0';
            if (cur > 0)
            {
                temp_answer = cur;
                temp_start = 9;
                for (int ii = i + 1; ii < n_size; ii++)
                {
                    temp_answer *= temp_start;
                    temp_start--;
                }
                result += temp_answer;
            }
        }

        return result;
    }
};
// @lc code=end
