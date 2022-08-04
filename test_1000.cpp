/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 *
 * https://leetcode.cn/problems/minimum-cost-to-merge-stones/description/
 *
 * algorithms
 * Hard (44.09%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 11.9K
 * Testcase Example:  '[3,2,4,1]\n2'
 *
 * 有 N 堆石头排成一排，第 i 堆中有 stones[i] 块石头。
 *
 * 每次移动（move）需要将连续的 K 堆石头合并为一堆，而这个移动的成本为这 K 堆石头的总数。
 *
 * 找出把所有石头合并成一堆的最低成本。如果不可能，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：stones = [3,2,4,1], K = 2
 * 输出：20
 * 解释：
 * 从 [3, 2, 4, 1] 开始。
 * 合并 [3, 2]，成本为 5，剩下 [5, 4, 1]。
 * 合并 [4, 1]，成本为 5，剩下 [5, 5]。
 * 合并 [5, 5]，成本为 10，剩下 [10]。
 * 总成本 20，这是可能的最小值。
 *
 *
 * 示例 2：
 *
 * 输入：stones = [3,2,4,1], K = 3
 * 输出：-1
 * 解释：任何合并操作后，都会剩下 2 堆，我们无法再进行合并。所以这项任务是不可能完成的。.
 *
 *
 * 示例 3：
 *
 * 输入：stones = [3,5,1,2,6], K = 3
 * 输出：25
 * 解释：
 * 从 [3, 5, 1, 2, 6] 开始。
 * 合并 [5, 1, 2]，成本为 8，剩下 [3, 8, 6]。
 * 合并 [3, 8, 6]，成本为 17，剩下 [17]。
 * 总成本 25，这是可能的最小值。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= stones.length <= 30
 * 2 <= K <= 30
 * 1 <= stones[i] <= 100
 *
 *
 */

// @lc code=start
class Solution
{
    // 区间dp
    // [3,2,4,1]\n2\n[3,2,4,1]\n3\n[3,5,1,2,6]\n3\n
public:
    int mergeStones(vector<int> &stones, int k)
    {

        int n = stones.size();

        if ((n - 1) % (k - 1) != 0)
        {
            return -1;
        }

        // 可能需要一个前缀和
        vector<int> qian(n + 1);
        for (int i = 1; i <= n; i++)
        {
            qian[i] = ((qian[i - 1] + stones[i - 1]));
            // std::cout << qian[i] << ",";
        }
        // std::cout << std::endl;

        vector<vector<int>> vvi(n, vector<int>(n, 1000000));
        for (int i = 0; i < n; i++)
        {
            vvi[i][i] = 0;
        }
        for (int start = k; start <= n; start++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + start - 1;
                if (j >= n)
                {
                    break;
                }
                // vvi[i][j] = 10   i - j 合成一堆的最小代价
                for (int temp = i; temp < j; temp += (k - 1))
                {
                    vvi[i][j] = min(vvi[i][j], vvi[i][temp] + vvi[temp + 1][j]);
                }

                if ((start - 1) % (k - 1) == 0)
                {
                    vvi[i][j] += (qian[j + 1] - qian[i]);
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << "" << std::endl;
        //     for (int j = 0; j < n; j++)
        //     {
        //         std::cout << vvi[i][j] << "|";
        //     }
        //     std::cout << "," << std::endl;
        // }

        return vvi[0][n - 1];
    }
};
// @lc code=end
