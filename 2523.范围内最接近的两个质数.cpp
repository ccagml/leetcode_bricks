/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 * @lcpr version=21704
 *
 * [2523] 范围内最接近的两个质数
 *
 * https://leetcode.cn/problems/closest-prime-numbers-in-range/description/
 *
 * algorithms
 * Medium (41.25%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    5.8K
 * Total Submissions: 14K
 * Testcase Example:  '10\n19'
 *
 * 给你两个正整数 left 和 right ，请你找到两个整数 num1 和 num2 ，它们满足：
 *
 *
 * left <= nums1 < nums2 <= right  。
 * nums1 和 nums2 都是 质数 。
 * nums2 - nums1 是满足上述条件的质数对中的 最小值 。
 *
 *
 * 请你返回正整数数组 ans = [nums1, nums2] 。如果有多个整数对满足上述条件，请你返回 nums1
 * 最小的质数对。如果不存在符合题意的质数对，请你返回 [-1, -1] 。
 *
 * 如果一个整数大于 1 ，且只能被 1 和它自己整除，那么它是一个质数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：left = 10, right = 19
 * 输出：[11,13]
 * 解释：10 到 19 之间的质数为 11 ，13 ，17 和 19 。
 * 质数对的最小差值是 2 ，[11,13] 和 [17,19] 都可以得到最小差值。
 * 由于 11 比 17 小，我们返回第一个质数对。
 *
 *
 * 示例 2：
 *
 * 输入：left = 4, right = 6
 * 输出：[-1,-1]
 * 解释：给定范围内只有一个质数，所以题目条件无法被满足。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= left <= right <= 10^6
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start
class Solution
{
public:
    vector<int> ola(int n)
    {
        vector<int> vis(n + 1);
        vector<int> prime;
        for (int i = 2; i <= n; ++i)
        {
            if (!vis[i])
            {
                prime.push_back(i);
            }
            for (int j = 0; j < prime.size(); ++j)
            {
                if (1ll * i * prime[j] > n)
                    break;
                vis[i * prime[j]] = true;
                if (i % prime[j] == 0)
                {
                    // i % pri[j] == 0
                    // 换言之，i 之前被 pri[j] 筛过了
                    // 由于 pri 里面质数是从小到大的，所以 i乘上其他的质数的结果一定会被
                    // pri[j]的倍数筛掉，就不需要在这里先筛一次，所以这里直接 break
                    // 掉就好了
                    break;
                }
            }
        }
        return prime;
    }
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> temp = ola(right);
        if (temp.size() < 2)
        {
            return {-1, -1};
        }
        // 第一个大于等于 i 的位置
        int diff = 9999999;
        int a = -1;
        int b = -1;
        auto lower = std::lower_bound(temp.begin(), temp.end(), left);
        if (lower != temp.end())
        {
            int start = std::distance(temp.begin(), lower);
            for (int j = start; j < temp.size() - 1; j++)
            {
                if (temp[j + 1] - temp[j] < diff)
                {
                    diff = temp[j + 1] - temp[j];
                    a = temp[j];
                    b = temp[j + 1];
                }
            }
        }

        return {a, b};
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 10\n19\n
// @lcpr case=end

// @lcpr case=start
// 4\n6\n
// @lcpr case=end

 */
