// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=201 lang=cpp
 * @lcpr version=30113
 *
 * [201] 数字范围按位与
 *
 * https://leetcode.cn/problems/bitwise-and-of-numbers-range/description/
 *
 * algorithms
 * Medium (54.33%)
 * Likes:    491
 * Dislikes: 0
 * Total Accepted:    83.3K
 * Total Submissions: 153.4K
 * Testcase Example:  '5\n7'
 *
 * 给你两个整数 left 和 right ，表示区间 [left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right
 * 端点）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：left = 5, right = 7
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：left = 0, right = 0
 * 输出：0
 *
 *
 * 示例 3：
 *
 * 输入：left = 1, right = 2147483647
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= left <= right <= 2^31 - 1
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
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }
    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    int rangeBitwiseAnd(int left, int right)
    {
        int result = 0;
        bool find_1 = false;
        for (int j = 31; j >= 0; j--)
        {

            if (!find_1 && is_bit_1(left, j))
            {
                find_1 = true;
            }
            if (!find_1 && is_bit_1(right, j))
            {
                find_1 = true;
            }
            if (is_bit_1(left, j) && is_bit_1(right, j))
            {
                result = set_bit_1(result, j);
            }
            else if (!is_bit_1(left, j) && !is_bit_1(right, j))
            {
            }
            else
            {
                if (find_1)
                {

                    break;
                }
            }
        }
        // 0101
        // 1010
        // 0111
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 10\n15\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n2147483647\n
// @lcpr case=end

 */
