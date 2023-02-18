/*
 * @lc app=leetcode.cn id=204 lang=cpp
 * @lcpr version=21704
 *
 * [204] 计数质数
 *
 * https://leetcode.cn/problems/count-primes/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    1020
 * Dislikes: 0
 * Total Accepted:    239.9K
 * Total Submissions: 640.1K
 * Testcase Example:  '10'
 *
 * 给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 10
 * 输出：4
 * 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 0
 * 输出：0
 *
 *
 * 示例 3：
 *
 * 输入：n = 1
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 5 * 10^6
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
    int countPrimes(int n)
    {
        n = n - 1;
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
        return prime.size();
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
// 10\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
