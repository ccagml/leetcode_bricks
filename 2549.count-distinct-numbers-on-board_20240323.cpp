/*
 * @lc app=leetcode.cn id=2549 lang=cpp
 * @lcpr version=30120
 *
 * [2549] 统计桌面上的不同数字
 *
 * https://leetcode.cn/problems/count-distinct-numbers-on-board/description/
 *
 * algorithms
 * Easy (67.16%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 26.5K
 * Testcase Example:  '5'
 *
 * 给你一个正整数 n ，开始时，它放在桌面上。在 10^9 天内，每天都要执行下述步骤：
 *
 *
 * 对于出现在桌面上的每个数字 x ，找出符合 1 <= i <= n 且满足 x % i == 1 的所有数字 i 。
 * 然后，将这些数字放在桌面上。
 *
 *
 * 返回在 10^9 天之后，出现在桌面上的 不同 整数的数目。
 *
 * 注意：
 *
 *
 * 一旦数字放在桌面上，则会一直保留直到结束。
 * % 表示取余运算。例如，14 % 3 等于 2 。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 5
 * 输出：4
 * 解释：最开始，5 在桌面上。
 * 第二天，2 和 4 也出现在桌面上，因为 5 % 2 == 1 且 5 % 4 == 1 。
 * 再过一天 3 也出现在桌面上，因为 4 % 3 == 1 。
 * 在十亿天结束时，桌面上的不同数字有 2 、3 、4 、5 。
 *
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：2
 * 解释：
 * 因为 3 % 2 == 1 ，2 也出现在桌面上。
 * 在十亿天结束时，桌面上的不同数字只有两个：2 和 3 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 100
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
    int distinctIntegers(int n)
    {
        vector<int> vi;
        unordered_set<int> result;
        result.insert(n);
        unordered_set<int> temp;
        temp.insert(n);
        while (true)
        {
            unordered_set<int> new_temp;
            for (int x : temp)
            {
                for (int j = 1; j < x; j++)
                {
                    if (x % j == 1 && result.count(j) == 0)
                    {
                        result.insert(j);
                        new_temp.insert(j);
                    }
                }
            }
            if (new_temp.size() > 0)
            {
                temp = new_temp;
            }
            else
            {
                break;
            }
        }
        return result.size();
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
