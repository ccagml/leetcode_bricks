/*
 * @lc app=leetcode.cn id=279 lang=cpp
 * @lcpr version=20602
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (65.78%)
 * Likes:    1546
 * Dislikes: 0
 * Total Accepted:    355.8K
 * Total Submissions: 540.9K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 *
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> all;
        for (int i = 1; i < n; i++)
        {
            int a = i * i;
            all.push_back(a);
            if (a == n)
            {
                return 1;
            }
            if (a > n)
            {
                break;
            }
        }

        // 凑够n的最小数量 // vi[x] 凑够x的最小次数
        vector<int> vi(n + 1, 9999999);
        vi[0] = 0;
        vi[1] = 1;
        for (int has : all)
        {
            for (int i = has; i <= n; i++)
            {
                vi[i] = min(vi[i], vi[i - has] + 1);
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int has : all)
        //     {
        //         if (has <= i)
        //         {
        //             vi[i] = min(vi[i], vi[i - has] + 1);
        //         }
        //     }
        // }

        return vi[n];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 13\n
// @lcpr case=end

 */
