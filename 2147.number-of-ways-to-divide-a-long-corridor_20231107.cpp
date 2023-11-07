// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2147 lang=cpp
 * @lcpr version=30106
 *
 * [2147] 分隔长廊的方案数
 *
 * https://leetcode.cn/problems/number-of-ways-to-divide-a-long-corridor/description/
 *
 * algorithms
 * Hard (41.98%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 10K
 * Testcase Example:  '"SSPPSPS"'
 *
 * 在一个图书馆的长廊里，有一些座位和装饰植物排成一列。给你一个下标从 0 开始，长度为 n 的字符串 corridor ，它包含字母 'S' 和 'P'
 * ，其中每个 'S' 表示一个座位，每个 'P' 表示一株植物。
 *
 * 在下标 0 的左边和下标 n - 1 的右边 已经 分别各放了一个屏风。你还需要额外放置一些屏风。每一个位置 i - 1 和 i 之间（1 <= i
 * <= n - 1），至多能放一个屏风。
 *
 * 请你将走廊用屏风划分为若干段，且每一段内都 恰好有两个座位
 * ，而每一段内植物的数目没有要求。可能有多种划分方案，如果两个方案中有任何一个屏风的位置不同，那么它们被视为 不同 方案。
 *
 * 请你返回划分走廊的方案数。由于答案可能很大，请你返回它对 10^9 + 7 取余 的结果。如果没有任何方案，请返回 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：corridor = "SSPPSPS"
 * 输出：3
 * 解释：总共有 3 种不同分隔走廊的方案。
 * 上图中黑色的竖线表示已经放置好的屏风。
 * 上图每种方案中，每一段都恰好有 两个 座位。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：corridor = "PPSPSP"
 * 输出：1
 * 解释：只有 1 种分隔走廊的方案，就是不放置任何屏风。
 * 放置任何的屏风都会导致有一段无法恰好有 2 个座位。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：corridor = "S"
 * 输出：0
 * 解释：没有任何方案，因为总是有一段无法恰好有 2 个座位。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == corridor.length
 * 1 <= n <= 10^5
 * corridor[i] 要么是 'S' ，要么是 'P' 。
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
    int numberOfWays(string corridor)
    {
        int all_s = 0;
        for (int i = 0; i < corridor.size(); i++)
        {
            if (corridor[i] == 'S')
            {
                all_s++;
            }
        }
        if (all_s < 2)
        {
            return 0;
        }
        if (all_s % 2 == 1)
        {
            return 0;
        }
        // 把 2 个 S 合起来
        int wait_s = 0;
        int p_cnt = 0;
        vector<int> p_l;
        for (int i = 0; i < corridor.size(); i++)
        {
            if (wait_s == 0)
            {
                if (corridor[i] == 'P')
                {
                    continue;
                }
                wait_s = 1;
            }
            else if (wait_s == 1)
            {
                if (corridor[i] == 'P')
                {
                    continue;
                }
                wait_s = 2;
            }
            else if (wait_s == 2)
            {
                // 多余的 P
                if (corridor[i] == 'P')
                {
                    p_cnt++;
                    continue;
                }
                if (p_cnt > 0)
                {
                    p_l.push_back(p_cnt);
                }
                wait_s = 1;
                p_cnt = 0;
            }
            // SSPSSPPP
        }
        long long result = 1;
        for (int i = 0; i < p_l.size(); i++)
        {
            result *= (p_l[i] + 1);
            int e97 = 1000000007;
            result %= e97;
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=numberOfWays
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "SSPPSPS"\n
// @lcpr case=end

// @lcpr case=start
// "PPSPSP"\n
// @lcpr case=end

// @lcpr case=start
// "S"\n
// @lcpr case=end

 */
