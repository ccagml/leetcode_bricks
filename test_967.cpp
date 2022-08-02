/*
 * @lc app=leetcode.cn id=967 lang=cpp
 *
 * [967] 连续差相同的数字
 *
 * https://leetcode.cn/problems/numbers-with-same-consecutive-differences/description/
 *
 * algorithms
 * Medium (49.19%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    10.2K
 * Total Submissions: 20.7K
 * Testcase Example:  '3\n7'
 *
 * 返回所有长度为 n 且满足其每两个连续位上的数字之间的差的绝对值为 k 的 非负整数 。
 *
 * 请注意，除了 数字 0 本身之外，答案中的每个数字都 不能 有前导零。例如，01 有一个前导零，所以是无效的；但 0 是有效的。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, k = 7
 * 输出：[181,292,707,818,929]
 * 解释：注意，070 不是一个有效的数字，因为它有前导零。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2, k = 1
 * 输出：[10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 *
 * 示例 3：
 *
 *
 * 输入：n = 2, k = 0
 * 输出：[11,22,33,44,55,66,77,88,99]
 *
 *
 * 示例 4：
 *
 *
 * 输入：n = 2, k = 2
 * 输出：[13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 9
 * 0 <= k <= 9
 *
 *
 */

// @lc code=start

// 常规模拟
class Solution
{
public:
    vector<int> result;
    int nn;
    int kk;
    void dfs(int last_n, int cur_index, int cur_value)
    {
        if (cur_index >= nn)
        {
            result.push_back(cur_value);
            return;
        }
        int last_n_add = last_n + kk;
        int last_n_cost = last_n - kk;
        if ((last_n + kk) >= 0 && (last_n + kk) <= 9)
        {
            dfs((last_n + kk), cur_index + 1, cur_value * 10 + (last_n + kk));
        }
        if (last_n_cost >= 0 && last_n_cost <= 9 && (last_n + kk) != last_n_cost)
        {
            dfs(last_n_cost, cur_index + 1, cur_value * 10 + last_n_cost);
        }
    };

    vector<int> numsSameConsecDiff(int n, int k)
    {
        nn = n;
        kk = k;
        // 第一位只会是 1 - 9
        for (int s = 1; s <= 9; s++)
        {
            dfs(s, 1, s);
        }
        return result;
    }
};
// @lc code=end
