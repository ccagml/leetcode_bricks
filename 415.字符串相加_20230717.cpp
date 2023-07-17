// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=415 lang=cpp
 * @lcpr version=21910
 *
 * [415] 字符串相加
 *
 * https://leetcode.cn/problems/add-strings/description/
 *
 * algorithms
 * Easy (54.60%)
 * Likes:    750
 * Dislikes: 0
 * Total Accepted:    280.1K
 * Total Submissions: 511.1K
 * Testcase Example:  '"11"\n"123"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
 *
 * 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
 *
 *
 *
 * 示例 1：
 *
 * 输入：num1 = "11", num2 = "123"
 * 输出："134"
 *
 *
 * 示例 2：
 *
 * 输入：num1 = "456", num2 = "77"
 * 输出："533"
 *
 *
 * 示例 3：
 *
 * 输入：num1 = "0", num2 = "0"
 * 输出："0"
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num1.length, num2.length <= 10^4
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
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
    string addStrings(string num1, string num2)
    {
        string reuslt = "";
        int m_len = max(num1.size(), num2.size());
        int temp = 0;
        for (int j = 0; j < m_len; j++)
        {
            int n1_index = num1.size() - (j + 1);
            int n2_index = num2.size() - (j + 1);
            if (n1_index >= 0)
            {
                temp += (num1[n1_index] - '0');
            }
            if (n2_index >= 0)
            {
                temp += (num2[n2_index] - '0');
            }
            int add = temp % 10;
            temp /= 10;
            reuslt = std::to_string(add) + reuslt;
        }
        if (temp > 0)
        {
            reuslt = std::to_string(1) + reuslt;
        }
        return reuslt;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "11"\n"123"\n
// @lcpr case=end

// @lcpr case=start
// "456"\n"77"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n"0"\n
// @lcpr case=end

// @lcpr case=start
// "99999999"\n"1"\n
// @lcpr case=end

 */
