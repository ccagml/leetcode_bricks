// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=754 lang=cpp
 * @lcpr version=30122
 *
 * [754] 到达终点数字
 *
 * https://leetcode.cn/problems/reach-a-number/description/
 *
 * algorithms
 * Medium (51.55%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 74.1K
 * Testcase Example:  '2'
 *
 * 在一根无限长的数轴上，你站在0的位置。终点在target的位置。
 *
 * 你可以做一些数量的移动 numMoves :
 *
 *
 * 每次你可以选择向左或向右移动。
 * 第 i 次移动（从  i == 1 开始，到 i == numMoves ），在选择的方向上走 i 步。
 *
 *
 * 给定整数 target ，返回 到达目标所需的 最小 移动次数(即最小 numMoves ) 。
 *
 *
 *
 * 示例 1:
 *
 * 输入: target = 2
 * 输出: 3
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 -1 。
 * 第三次移动，从 -1 到 2 。
 *
 *
 * 示例 2:
 *
 * 输入: target = 3
 * 输出: 2
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 3 。
 *
 *
 *
 *
 * 提示:
 *
 *
 * -10^9 <= target <= 10^9
 * target != 0
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool find(int result, int all_zheng)
    {
        // 从 1 到 result 能不能找到和为all_zheng
        vector<int> vi(all_zheng + 1, 0);
        vi[0] = 1;
        for (int coin = 1; coin <= result; coin++)
        {
            if (coin <= all_zheng)
            {
                for (int target = all_zheng; target >= coin; target--)
                {
                    if (vi[target - coin] > 0)
                    {
                        vi[target] = 1;
                    }
                }
                if (vi[all_zheng] > 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int reachNumber(int target)
    {
        target = abs(target);
        // all_zheng + all_fu = target
        // all_zheng - all_fu = all_sum
        // 2all_zheng = target + all_sum
        // all_zheng = (target + all_sum)/2
        // all_sum = (n * n + 1)/2
        for (int result = 1; result <= 999999; result++)
        {
            int all_sum = (result * (result + 1)) / 2;
            if ((target + all_sum) % 2 == 0)
            {
                int all_zheng = (target + all_sum) / 2;
                if (all_zheng <= all_sum)
                {
                    return result;
                    // if (find(result, all_zheng))
                    // {
                    //     return result;
                    // }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end
// @lcpr case=start
// -1\n
// @lcpr case=end
// @lcpr case=start
// 5\n
// @lcpr case=end
// @lcpr case=start
// 1000000000\n
// @lcpr case=end

 */
