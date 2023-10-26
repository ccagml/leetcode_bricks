/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 * @lcpr version=30102
 *
 * [2520] 统计能整除数字的位数
 *
 * https://leetcode.cn/problems/count-the-digits-that-divide-a-number/description/
 *
 * algorithms
 * Easy (85.00%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 20.5K
 * Testcase Example:  '7'
 *
 * 给你一个整数 num ，返回 num 中能整除 num 的数位的数目。
 *
 * 如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：num = 7
 * 输出：1
 * 解释：7 被自己整除，因此答案是 1 。
 *
 *
 * 示例 2：
 *
 * 输入：num = 121
 * 输出：2
 * 解释：121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
 *
 *
 * 示例 3：
 *
 * 输入：num = 1248
 * 输出：4
 * 解释：1248 可以被它每一位上的数字整除，因此答案是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num <= 10^9
 * num 的数位中不含 0
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
    int countDigits(int num)
    {
        int result = 0;
        string ns = std::to_string(num);
        for (int i = 0; i < ns.size(); i++)
        {
            if ((num % (ns[i] - '0')) == 0)
            {
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// 1248\n
// @lcpr case=end

 */
