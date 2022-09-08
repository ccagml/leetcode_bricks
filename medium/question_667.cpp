/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 *
 * https://leetcode.cn/problems/beautiful-arrangement-ii/description/
 *
 * algorithms
 * Medium (62.07%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 20.9K
 * Testcase Example:  '3\n1'
 *
 * 给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：
 *
 *
 * 假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|, |a3 -
 * a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
 *
 *
 * 返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, k = 1
 * 输出：[1, 2, 3]
 * 解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, k = 2
 * 输出：[1, 3, 2]
 * 解释：[1, 3, 2] 包含 3 个范围在 1-3 的不同整数，并且 [2, 1] 中有且仅有 2 个不同整数：1 和 2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 *
 *
 */

// 3\n1\n4\n2\n4\n1\n5\n3\n5\n2\n5\n1\n6\n4\n6\n3\n6\n2\n6\n1\n7\n5\n7\n4\n7\n3\n100\n20\n
// 构造的思路不一样, 都想到可能需要 一个前一个后来控制差值
// @lc code=start
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        int diff = n - k;
        int lo = 1;
        int hi = n;
        vector<int> result;
        int i = 0;
        while (i < diff)
        {
            result.push_back(lo);
            lo++;
            i++;
        }
        bool flag = true;
        for (int i = lo - 1; i < n; i++)
        {

            if (flag)
            {
                result.push_back(hi);
                hi--;
                flag = false;
            }
            else
            {
                result.push_back(lo);
                lo++;
                flag = true;
            }
        }
        return result;
    }
};
// @lc code=end
