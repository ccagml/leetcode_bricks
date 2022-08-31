/*
 * @lc app=leetcode.cn id=2064 lang=cpp
 *
 * [2064] 分配给商店的最多商品的最小值
 *
 * https://leetcode.cn/problems/minimized-maximum-of-products-distributed-to-any-store/description/
 *
 * algorithms
 * Medium (43.76%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 11.1K
 * Testcase Example:  '6\n[11,6]'
 *
 * 给你一个整数 n ，表示有 n 间零售商店。总共有 m 种产品，每种产品的数目用一个下标从 0 开始的整数数组 quantities 表示，其中
 * quantities[i] 表示第 i 种商品的数目。
 *
 * 你需要将 所有商品 分配到零售商店，并遵守这些规则：
 *
 *
 * 一间商店 至多 只能有 一种商品 ，但一间商店拥有的商品数目可以为 任意 件。
 * 分配后，每间商店都会被分配一定数目的商品（可能为 0 件）。用 x 表示所有商店中分配商品数目的最大值，你希望 x 越小越好。也就是说，你想 最小化
 * 分配给任意商店商品数目的 最大值 。
 *
 *
 * 请你返回最小的可能的 x 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 6, quantities = [11,6]
 * 输出：3
 * 解释： 一种最优方案为：
 * - 11 件种类为 0 的商品被分配到前 4 间商店，分配数目分别为：2，3，3，3 。
 * - 6 件种类为 1 的商品被分配到另外 2 间商店，分配数目分别为：3，3 。
 * 分配给所有商店的最大商品数目为 max(2, 3, 3, 3, 3, 3) = 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 7, quantities = [15,10,10]
 * 输出：5
 * 解释：一种最优方案为：
 * - 15 件种类为 0 的商品被分配到前 3 间商店，分配数目为：5，5，5 。
 * - 10 件种类为 1 的商品被分配到接下来 2 间商店，数目为：5，5 。
 * - 10 件种类为 2 的商品被分配到最后 2 间商店，数目为：5，5 。
 * 分配给所有商店的最大商品数目为 max(5, 5, 5, 5, 5, 5, 5) = 5 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 1, quantities = [100000]
 * 输出：100000
 * 解释：唯一一种最优方案为：
 * - 所有 100000 件商品 0 都分配到唯一的商店中。
 * 分配给所有商店的最大商品数目为 max(100000) = 100000 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == quantities.length
 * 1 <= m <= n <= 10^5
 * 1 <= quantities[i] <= 10^5
 *
 *
 */

// @lc code=start
// class Solution {
// public:
//     int minimizedMaximum(int n, vector<int>& quantities) {
//         int m = quantities.size();
//         int temp = 0;
//         for(int i = 0; i < m; i++){
//             temp+= quantities[i];
//         }
//         int ave = (temp % n == 0) ? temp / n : (temp / n) + 1;
//         vector<int> qi(m);
//         std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::less<pair<int, int>>> q2;
//         unordered_map<int, int> uii;
//         for(int i = 0; i < m; i++){
//             uii[i] = 1;
//             quantities[i] -= ave;
//             if(quantities[i] > 0){
//                 q2.push({quantities[i], i});
//             }
//         }
//         int free = n - m;
//         while(free > 0 && q2.size() > 0){
//             pair<int, int> temp = q2.top();
//             q2.pop();
//             uii[temp.second]++;
//             free--;
//             if(temp.first - ave > 0){
//                 q2.push({temp.first - ave, temp.second});
//             }
//         }
//         std::cout << "平均" << ave << std::endl;
//         int max_value = ave;
//         while(q2.size() > 0){
//             pair<int, int> temp = q2.top();
//             q2.pop();
//             int a = temp.first;
//             int i = temp.second;
//             int add = (a % uii[i] == 0)?(a / uii[i]) : (a / uii[i])+1;
//             std::cout << "添加:" << add << ":" << i << ":" << uii[i] << std::endl;
//             max_value = max(max_value, ave + add);
//         }
//         return max_value;

//     }
// };
// 应该是直接二分值看能不能分配
// 原本还以为要优先级队列分配,其实只要二分查找就好了
class Solution
{
public:
    bool check(int n, vector<int> &quantities, int ave_value)
    {
        if(ave_value < 1){
            return false;
        }
        int cur = 0;
        for (int i = 0; i < quantities.size(); i++)
        {
            int temp = (quantities[i] % ave_value == 0) ? quantities[i] / ave_value : (quantities[i] / ave_value) + 1;
            cur += temp;
            if (cur > n)
            {
                return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int m = quantities.size();
        // int temp = 0;
        int result_right = 0;
        for (int i = 0; i < m; i++)
        {
            // temp += quantities[i];
            result_right = max(result_right, quantities[i]);
        }
        // int ave = (temp % n == 0) ? temp / n : (temp / n) + 1;
        int result_left = 0;
        while (result_left < result_right)
        {
            int mid = result_left + (result_right - result_left) / 2;
            // std::cout << "测试mid:" << mid  << ":" << result_left << ":" << result_right << ":";
            if (check(n, quantities, mid))
            {
                result_right = mid;
            }
            else
            {
                result_left = mid + 1;
            }
        }
        return result_left;
    }
};
// @lc code=end
