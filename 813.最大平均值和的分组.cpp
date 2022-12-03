/*
 * @lc app=leetcode.cn id=813 lang=cpp
 * @lcpr version=20301
 *
 * [813] 最大平均值和的分组
 *
 * https://leetcode.cn/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (57.92%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 22.5K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * 给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个相邻的非空子数组 。 分数 由每个子数组内的平均值的总和构成。
 *
 * 注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数。
 *
 * 返回我们所能得到的最大 分数 是多少。答案误差在 10^-6 内被视为是正确的。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [9,1,2,3,9], k = 3
 * 输出: 20.00000
 * 解释:
 * nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
 * 我们也可以把 nums 分成[9, 1], [2], [3, 9].
 * 这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
 *
 *
 * 示例 2:
 *
 * 输入: nums = [1,2,3,4,5,6,7], k = 4
 * 输出: 20.50000
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// 1. 前缀和
// 2. 把前n个分成y组的最大和
// 1题做一天 1:55:8
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// @lc code=start
// class Solution
// {
// public:
//     vector<vector<double>> dp;
//     vector<int> start_sums;
//     vector<int> pre_sum;

//     double dfs(int cur_index, int cur_k)
//     {
//         double error = -9999999;
//         if (cur_k == 1)
//         {
//             double pre = get_sum(cur_index, pre_sum.size()) / (pre_sum.size() - (cur_index));

//             dp[cur_index][cur_k] = pre;
//         }
//         if (cur_k > 1 && ((start_sums.size() - (cur_index)) < cur_k))
//         {
//             // std::cout << "错误(" << cur_index << "分" << cur_k << "份)";
//             dp[cur_index][cur_k] = error;
//             return error;
//         }

//         if (dp[cur_index][cur_k] > 0)
//         {
//             return dp[cur_index][cur_k];
//         }

//         double temp_result = 0;

//         // std::cout << "从start" << cur_index << "开始分" << cur_k << "份=" << temp_result << std::endl;

//         for (int i = cur_index; i < start_sums.size(); i++)
//         {
//             double a = get_sum(cur_index, i) / (i - cur_index + 1);
//             double b = dfs(i + 1, cur_k - 1);
//             // std::cout << "a(" << cur_index << "到" << i << "分1份=" << a << ")";
//             // std::cout << "b(" << i + 1 << "到结束分" << cur_k - 1 << "份=" << b << ")";

//             temp_result = max(temp_result, a + b);
//         }

//         dp[cur_index][cur_k] = temp_result;
//         // std::cout << "从end" << cur_index << "开始分" << cur_k << "份=" << temp_result << std::endl;
//         return dp[cur_index][cur_k];
//     }

//     double get_sum(int i, int j)
//     {
//         int a = i > 0 ? pre_sum[i - 1] : 0;
//         int b = j < pre_sum.size() ? pre_sum[j] : pre_sum[pre_sum.size() - 1];

//         return b - a;
//     }
//     double largestSumOfAverages(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         vector<vector<double>> vvi1(111, vector<double>(111));
//         start_sums = nums;
//         dp = vvi1;
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             pre_sum.push_back(sum);
//         }
//         return dfs(0, k);
//     }
// };

// #include "unordered_map"
// class Solution
// {
// public:
//     vector<int> get_pre_sum(vector<int> &nums)
//     {
//         vector<int> result;
//         int n = nums.size();
//         int sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             result.push_back(sum);
//         }
//         return result;
//     }

//     double get_sum(vector<int> &pre_sum, int i, int j)
//     {
//         int a = i > 0 ? pre_sum[i - 1] : 0;
//         int b = j < pre_sum.size() ? pre_sum[j] : pre_sum[pre_sum.size() - 1];
//         return b - a;
//     }

//     double dfs(vector<int> &pre_sum, int cur_index, int cur_k, int need_k)
//     {
//         int n = pre_sum.size();
//         // 如果不够分是错误的
//         double have = n - cur_index;
//         int have_k = need_k - cur_k;
//         double result = -9999999;
//         if (have / have_k < 1)
//         {
//             return result;
//         }

//         if (have_k == 1)
//         {
//             return get_sum(pre_sum, cur_index, n) / have;
//         }

//         if (temp[cur_index].count(cur_k) > 0)
//         {
//             return temp[cur_index][cur_k];
//         }
//         result = 0;
//         for (int i = cur_index; i < n; i++)
//         {
//             double a = get_sum(pre_sum, cur_index, i);
//             double b = dfs(pre_sum, i + 1, cur_k + 1, need_k);
//             // std::cout << "(a:" << cur_index << "->" << i << "=" << a << "):(b:" << i + 1 << "->" << n << ":=" << b << ")";

//             result = max(result, get_sum(pre_sum, cur_index, i) / (i + 1 - cur_index) + dfs(pre_sum, i + 1, cur_k + 1, need_k));
//         }
//         // std::cout << "cur_index:" << cur_index << ":" << result << std::endl;
//         temp[cur_index][cur_k] = result;
//         return result;
//     }

//     vector<int> pre_sum;
//     unordered_map<int, unordered_map<int, double>> temp;
//     double largestSumOfAverages(vector<int> &nums, int k)
//     {
//         pre_sum = this->get_pre_sum(nums);
//         return dfs(pre_sum, 0, 0, k);
//     }
// };
class Solution
{
public:
    unordered_map<int, unordered_map<int, double>> cur_k_value;

    double get_sum(vector<int> &pre, int left, int right)
    {
        int left_value = (left > 0) ? pre[left - 1] : 0;
        int right_value = (right >= pre.size()) ? pre[pre.size() - 1] : pre[right];
        return right_value - left_value;
    }
    double dfs(vector<int> &pre, int cur, int k)
    {

        // 还有的数量
        double has = pre.size() - cur;
        if (k > has)
        {
            return 0;
        }
        if (k == 1)
        {
            double bbb = get_sum(pre, cur, pre.size()) / has;
            // std::cout << "bbb(" << cur << "->" << pre.size() << "=" << bbb << ")";
            return bbb;
        }
        // 从cur开始分k份最大值
        if (cur_k_value[cur].count(k) > 0)
        {
            return cur_k_value[cur][k];
        }

        double result = 0;
        for (int start = cur; start < pre.size(); start++)
        {
            double a = get_sum(pre, cur, start) / (start - cur + 1);
            // std::cout << "aaa(" << cur << "->" << start << "=" << a << ")";
            double b = dfs(pre, start + 1, k - 1);
            result = max(result, a + b);
        }
        // std::cout << "从" << cur << "分" << k << "=" << result << std::endl;
        cur_k_value[cur][k] = result;
        return result;
    }

    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> pre;
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
            pre.push_back(sum);
        }
        return dfs(pre, 0, k);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [9,1,2,3,9]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n4\n
// @lcpr case=end

// @lcpr case=start
// [4737,4611,1752,7231,4395,8569,1965,2591,2258,2874,1196,9770,1439,1694,7144,716,3764,1348,9831,6186]\n12
// @lcpr case=end

 */
