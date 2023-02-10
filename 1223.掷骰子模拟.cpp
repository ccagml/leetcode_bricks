/*
 * @lc app=leetcode.cn id=1223 lang=cpp
 * @lcpr version=21504
 *
 * [1223] 掷骰子模拟
 *
 * https://leetcode.cn/problems/dice-roll-simulation/description/
 *
 * algorithms
 * Hard (58.11%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 14.5K
 * Testcase Example:  '2\n[1,1,2,2,2,3]'
 *
 * 有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。
 *
 * 不过我们在使用它时有个约束，就是使得投掷骰子时，连续 掷出数字 i 的次数不能超过 rollMax[i]（i 从 1 开始编号）。
 *
 * 现在，给你一个整数数组 rollMax 和一个整数 n，请你来计算掷 n 次骰子可得到的不同点数序列的数量。
 *
 * 假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 模 10^9 + 7 之后的结果。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2, rollMax = [1,1,2,2,2,3]
 * 输出：34
 * 解释：我们掷 2 次骰子，如果没有约束的话，共有 6 * 6 = 36 种可能的组合。但是根据 rollMax 数组，数字 1 和 2
 * 最多连续出现一次，所以不会出现序列 (1,1) 和 (2,2)。因此，最终答案是 36-2 = 34。
 *
 *
 * 示例 2：
 *
 * 输入：n = 2, rollMax = [1,1,1,1,1,1]
 * 输出：30
 *
 *
 * 示例 3：
 *
 * 输入：n = 3, rollMax = [1,1,1,2,2,3]
 * 输出：181
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 5000
 * rollMax.length == 6
 * 1 <= rollMax[i] <= 15
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
    int dieSimulator(int n, vector<int> &rollMax)
    {
        int mod = 1e9 + 7;
        // temp[n轮][本轮以x结尾][已经连续个x了] = 数量
        vector<vector<vector<long long>>> temp(n, vector<vector<long long>>(6, vector<long long>(16, 0)));
        // temp1[n轮][以x结尾] = 数量
        vector<vector<long long>> temp1(n, vector<long long>(6, 0));

        for (int nn = 0; nn < n; nn++)
        {
            if (nn == 0)
            {
                temp[0][0][1] = 1;
                temp[0][1][1] = 1;
                temp[0][2][1] = 1;
                temp[0][3][1] = 1;
                temp[0][4][1] = 1;
                temp[0][5][1] = 1;
                temp1[0][0] = 1;
                temp1[0][1] = 1;
                temp1[0][2] = 1;
                temp1[0][3] = 1;
                temp1[0][4] = 1;
                temp1[0][5] = 1;
            }
            else
            {
                for (int cur = 0; cur < 6; cur++)
                {
                    int cur_rool_max = rollMax[cur];
                    for (int i = 1; i <= cur_rool_max; i++)
                    {
                        if (i == 1)
                        {
                            for (int last_cur = 0; last_cur < 6; last_cur++)
                            {
                                if (last_cur != cur)
                                {
                                    temp[nn][cur][i] += temp1[nn - 1][last_cur];
                                    temp1[nn][cur] += temp1[nn - 1][last_cur];

                                    temp[nn][cur][i] %= mod;
                                    temp1[nn][cur] %= mod;
                                }
                            }
                        }
                        else
                        {
                            temp[nn][cur][i] += temp[nn - 1][cur][i - 1];
                            temp1[nn][cur] += temp[nn - 1][cur][i - 1];
                            temp[nn][cur][i] %= mod;
                            temp1[nn][cur] %= mod;
                        }
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 6; i++)
        {
            result += temp1[n - 1][i];
            result %= mod;
        }
        return result;
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
// 2\n[1,1,2,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[1,1,1,1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// 100\n[7,5,15,5,1,7]
// @lcpr case=end

 */
