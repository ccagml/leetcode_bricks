// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 * @lcpr version=21917
 *
 * [2698] 求一个整数的惩罚数
 *
 * https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/description/
 *
 * algorithms
 * Medium (68.14%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 9.6K
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
    bool dfs_check(string temp, int need)
    {
        // std::string str3 = "helloworld";
        // std::string str4 = str3.substr(0, 5); // hello
        // std::string str5 = str3.substr(6);    // world
        // std::string str6 = str3.substr(1, 3); // ell
        for (int cut_len = 1; cut_len <= temp.size(); cut_len++)
        {
            string left = temp.substr(0, cut_len);
            string right = "0";
            if (cut_len < temp.size())
            {
                right = temp.substr(cut_len);
            }
            int left_int = std::stoi(left);
            int right_int = std::stoi(right);
            // std::cout << "left" << left_int << "=" << right_int << std::endl;
            if (left_int > need)
            {
                return false;
            }
            if (left_int == need && right_int == 0)
            {
                return true;
            }

            if (cut_len == temp.size())
            {
                return false;
            }
            bool sun_result = dfs_check(right, need - left_int);
            if (sun_result)
            {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n)
    {
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dfs_check(std::to_string(i * i), i))
            {
                result += i * i;
            }
        }
        return result;
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
