// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 * @lcpr version=30102
 *
 * [1155] 掷骰子等于目标和的方法数
 *
 * https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/description/
 *
 * algorithms
 * Medium (60.39%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 58.4K
 * Testcase Example:  '1\n6\n3'
 *
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。
 *
 * 给定三个整数 n ,  k 和 target ，返回可能的方式(从总共 k^n 种方式中)滚动骰子的数量，使正面朝上的数字之和等于 target 。
 *
 * 答案可能很大，你需要对 10^9 + 7 取模 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 1, k = 6, target = 3
 * 输出：1
 * 解释：你扔一个有 6 个面的骰子。
 * 得到 3 的和只有一种方法。
 *
 *
 * 示例 2：
 *
 * 输入：n = 2, k = 6, target = 7
 * 输出：6
 * 解释：你扔两个骰子，每个骰子有 6 个面。
 * 得到 7 的和有 6 种方法：1+6 2+5 3+4 4+3 5+2 6+1。
 *
 *
 * 示例 3：
 *
 * 输入：n = 30, k = 30, target = 500
 * 输出：222616187
 * 解释：返回的结果必须是对 10^9 + 7 取模。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n, k <= 30
 * 1 <= target <= 1000
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<long long> vi(target + 1);
        for (int i = 0; i < n; i++)
        {
            vector<long long> new_vi(target + 1);
            for (int j = 1; j <= k; j++)
            {
                if (i == 0)
                {
                    if (j < new_vi.size())
                    {
                        new_vi[j] = 1;
                    }
                }
                else
                {
                    for (int t = 0; t < new_vi.size(); t++)
                    {
                        if (t + j < new_vi.size())
                        {
                            new_vi[t + j] += vi[t];
                            new_vi[t + j] %= (1000000007);
                        }
                    }
                }
            }
            vi = new_vi;
        }
        return vi[target];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=numRollsToTarget
// paramTypes= ["number","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 1\n6\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n7\n
// @lcpr case=end

// @lcpr case=start
// 30\n30\n500\n
// @lcpr case=end

 */
