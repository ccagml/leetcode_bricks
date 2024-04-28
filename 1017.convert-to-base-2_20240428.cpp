// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 * @lcpr version=30125
 *
 * [1017] 负二进制转换
 *
 * https://leetcode.cn/problems/convert-to-base-2/description/
 *
 * algorithms
 * Medium (64.93%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 42K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。
 *
 * 注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出："110"
 * 解释：(-2)^2 + (-2)^1 = 2
 *
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出："111"
 * 解释：(-2)^2 + (-2)^1 + (-2)^0 = 3
 *
 *
 * 示例 3：
 *
 * 输入：n = 4
 * 输出："100"
 * 解释：(-2)^2 = 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 10^9
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
    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    string baseNeg2(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        vector<int> vi(40);
        for (int i = 0; i < 32; i++)
        {
            if (is_bit_1(n, i))
            {
                vi[i] = 1;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            if (i % 2 == 1 && vi[i] > 0)
            {
                vi[i + 1]++;
            }
        }
        for (int i = 0; i < vi.size(); i++)
        {
            while (vi[i] > 1)
            {

                // 110 = 6
                // 110 = 2
                //   -2 4 -8 16
                vi[i] -= 2;
                if (vi.size() > i + 1)
                {
                    vi[i + 1]++;
                }
                if (vi.size() > i + 2)
                {
                    vi[i + 2]++;
                }
            }
        }

        bool find = false;
        string result = "";
        for (int j = vi.size() - 1; j >= 0; j--)
        {
            if (vi[j] == 1)
            {
                find = true;
            }
            if (find)
            {
                result.push_back(vi[j] + '0');
            }
        }
        return result;
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
// 4\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 14\n
// @lcpr case=end

 */
