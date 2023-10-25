// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 * @lcpr version=30102
 *
 * [2698] 求一个整数的惩罚数
 *
 * https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/description/
 *
 * algorithms
 * Medium (68.80%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 20.3K
 * Testcase Example:  '10'
 *
 * 给你一个正整数 n ，请你返回 n 的 惩罚数 。
 *
 * n 的 惩罚数 定义为所有满足以下条件 i 的数的平方和：
 *
 *
 * 1 <= i <= n
 * i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i 。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 10
 * 输出：182
 * 解释：总共有 3 个整数 i 满足要求：
 * - 1 ，因为 1 * 1 = 1
 * - 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
 * - 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
 * 因此，10 的惩罚数为 1 + 81 + 100 = 182
 *
 *
 * 示例 2：
 *
 * 输入：n = 37
 * 输出：1478
 * 解释：总共有 4 个整数 i 满足要求：
 * - 1 ，因为 1 * 1 = 1
 * - 9 ，因为 9 * 9 = 81 ，且 81 可以分割成 8 + 1 。
 * - 10 ，因为 10 * 10 = 100 ，且 100 可以分割成 10 + 0 。
 * - 36 ，因为 36 * 36 = 1296 ，且 1296 可以分割成 1 + 29 + 6 。
 * 因此，37 的惩罚数为 1 + 81 + 100 + 1296 = 1478
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
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
    bool check(string s, int need)
    {
        for (int i = 1; i <= s.size(); i++)
        {
            std::string left = s.substr(0, i); // hello
            std::string right = s.substr(i);
            int end_i = 0;
            int int_str = std::stoi(left);
            if (right.size() > 0)
            {
                end_i = std::stoi(right);
            }
            if (int_str > need)
            {
                return false;
            }
            else if (int_str == need)
            {
                if (end_i == 0)
                {
                    return true;
                }
                return false;
            }
            else
            {
                bool t = check(right, need - int_str);
                if (t)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int punishmentNumber(int n)
    {
        int reuslt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (check(std::to_string(i * i), i))
            {
                reuslt += i * i;
            }
        }
        return reuslt;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=punishmentNumber
// paramTypes= ["number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 37\n
// @lcpr case=end

 */
