/*
 * @lc app=leetcode.cn id=LCP 06 lang=cpp
 * @lcpr version=21914
 *
 * [LCP 06] 拿硬币
 *
 * https://leetcode.cn/problems/na-ying-bi/description/
 *
 * algorithms
 * Easy (83.84%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    79.5K
 * Total Submissions: 93K
 * Testcase Example:  '[4,2,1]'
 *
 * 桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。
 *
 * 示例 1：
 *
 *
 * 输入：[4,2,1]
 *
 * 输出：4
 *
 * 解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。
 *
 *
 * 示例 2：
 *
 *
 * 输入：[2,3,10]
 *
 * 输出：8
 *
 *
 * 限制：
 *
 *
 * 1 <= n <= 4
 * 1 <= coins[i] <= 10
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
    int minCount(vector<int> &coins)
    {
        int result = 0;
        for (int i : coins)
        {
            (i % 2 == 0) ? (result += i / 2) : (result += ((i / 2) + 1));
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,10]\n
// @lcpr case=end

 */
