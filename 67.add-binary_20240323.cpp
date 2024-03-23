// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30120
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.00%)
 * Likes:    1179
 * Dislikes: 0
 * Total Accepted:    383.8K
 * Total Submissions: 724.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 *
 *
 *
 * 示例 1：
 *
 * 输入:a = "11", b = "1"
 * 输出："100"
 *
 * 示例 2：
 *
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
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
    string addBinary(string a, string b)
    {
        vector<int> vi;
        int a_len = a.size();
        int b_len = b.size();
        int temp_add = 0;
        for (int i = 1; i <= max(a_len, b_len); i++)
        {
            int ai = 0;
            int bi = 0;
            if (a_len >= i)
            {
                ai = a[a_len - i] - '0';
            }
            if (b_len >= i)
            {
                bi = b[b_len - i] - '0';
            }

            int c = ai + bi + temp_add;
            if (c >= 2)
            {
                temp_add = 1;
            }
            else
            {
                temp_add = 0;
            }
            c %= 2;
            vi.push_back(c);
        }
        if (temp_add > 0)
        {
            vi.push_back(temp_add);
        }
        string result = "";
        for (int j = vi.size() - 1; j >= 0; j--)
        {
            result.push_back(vi[j] + '0');
        }
        return result.size() == 0 ? "0" : result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */
