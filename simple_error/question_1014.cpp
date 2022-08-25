/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 *
 * https://leetcode.cn/problems/best-sightseeing-pair/description/
 *
 * algorithms
 * Medium (56.66%)
 * Likes:    326
 * Dislikes: 0
 * Total Accepted:    55.4K
 * Total Submissions: 97.7K
 * Testcase Example:  '[8,1,5,2,6]'
 *
 * 给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。
 *
 * 一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去
 * 它们两者之间的距离。
 *
 * 返回一对观光景点能取得的最高分。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：values = [8,1,5,2,6]
 * 输出：11
 * 解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
 *
 *
 * 示例 2：
 *
 *
 * 输入：values = [1,2]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2
 * 1
 *
 *
 */

// @lc code=start

	
// 1730分
// 1.2层循环会超时
// 2. 一开始想的是 分两个vector<int> 分别存储 values[i] + i 和 values[i] - i;然后排序
// 3. 2中的问题是可能出现的 + 的i比 - 的 i 大,不符合规则
// 4. 没想到的点, 因为 values[i] + values[j] + i - j 中 values[i] + i 中的i一定比j小, 所以可以累计一个最大值来
class Solution
{
public:
    // 两层循环会超时
    // int maxScoreSightseeingPair(vector<int> &values)
    // {
    //     int n = values.size();
    //     int result = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             result = max(result, (values[i] + values[j] + i - j));
    //         }
    //     }
    //     return result;
    // }
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int result = 0;
        int temp_max = values[0];
        for (int i = 1; i < values.size(); i++)
        {
            result = max(result, temp_max + values[i] - i);
            // 排前面的
            temp_max = max(temp_max, values[i] + i);
        }

        return result;
    }
};
// @lc code=end
