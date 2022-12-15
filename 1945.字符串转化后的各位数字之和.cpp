/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 * @lcpr version=21101
 *
 * [1945] 字符串转化后的各位数字之和
 *
 * https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/description/
 *
 * algorithms
 * Easy (64.95%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 20.3K
 * Testcase Example:  '"iiii"\n1'
 *
 * 给你一个由小写字母组成的字符串 s ，以及一个整数 k 。
 *
 * 首先，用字母在字母表中的位置替换该字母，将 s 转化 为一个整数（也就是，'a' 用 1 替换，'b' 用 2 替换，... 'z' 用 26
 * 替换）。接着，将整数 转换 为其 各位数字之和 。共重复 转换 操作 k 次 。
 *
 * 例如，如果 s = "zbax" 且 k = 2 ，那么执行下述步骤后得到的结果是整数 8 ：
 *
 *
 * 转化："zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
 * 转换 #1：262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
 * 转换 #2：17 ➝ 1 + 7 ➝ 8
 *
 *
 * 返回执行上述操作后得到的结果整数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "iiii", k = 1
 * 输出：36
 * 解释：操作如下：
 * - 转化："iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
 * - 转换 #1：9999 ➝ 9 + 9 + 9 + 9 ➝ 36
 * 因此，结果整数为 36 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "leetcode", k = 2
 * 输出：6
 * 解释：操作如下：
 * - 转化："leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝
 * 12552031545
 * - 转换 #1：12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
 * - 转换 #2：33 ➝ 3 + 3 ➝ 6
 * 因此，结果整数为 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 100
 * 1 <= k <= 10
 * s 由小写英文字母组成
 *
 *
 */
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
// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        string temp = "";
        for (char c : s)
        {
            int a = c - 'a' + 1;
            temp += std::to_string(a);
        }
        int result = 0;
        for (int i = 0; i < k; i++)
        {
            int a = 0;
            for (char c : temp)
            {
                a += (c - '0');
            }
            result = a;
            temp = std::to_string(a);
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "iiii"\n1\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n2\n
// @lcpr case=end

 */
