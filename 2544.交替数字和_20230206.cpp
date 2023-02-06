// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 * @lcpr version=21502
 *
 * [2544] 交替数字和
 *
 * https://leetcode.cn/problems/alternating-digit-sum/description/
 *
 * algorithms
 * Easy (80.42%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 5.8K
 * Testcase Example:  '521'
 *
 * 给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：
 *
 *
 * 最高有效位 上的数字分配到 正 号。
 * 剩余每位上数字的符号都与其相邻数字相反。
 *
 *
 * 返回所有数字及其对应符号的和。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 521
 * 输出：4
 * 解释：(+5) + (-2) + (+1) = 4
 *
 * 示例 2：
 *
 * 输入：n = 111
 * 输出：1
 * 解释：(+1) + (-1) + (+1) = 1
 *
 *
 * 示例 3：
 *
 * 输入：n = 886996
 * 输出：0
 * 解释：(+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^9
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        return 2;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName= alternateDigitSum
// paramTypes= ["number"]
// returnType= number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 521\n
// @lcpr case=end

// @lcpr case=start
// 111\n
// @lcpr case=end

// @lcpr case=start
// 886996\n
// @lcpr case=end

 */
