// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2767 lang=cpp
 * @lcpr version=30102
 *
 * [2767] 将字符串分割为最少的美丽子字符串
 *
 * https://leetcode.cn/problems/partition-string-into-minimum-beautiful-substrings/description/
 *
 * algorithms
 * Medium (56.19%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    2.9K
 * Total Submissions: 5.2K
 * Testcase Example:  '"1011"'
 *
 * 给你一个二进制字符串 s ，你需要将字符串分割成一个或者多个 子字符串  ，使每个子字符串都是 美丽 的。
 *
 * 如果一个字符串满足以下条件，我们称它是 美丽 的：
 *
 *
 * 它不包含前导 0 。
 * 它是 5 的幂的 二进制 表示。
 *
 *
 * 请你返回分割后的子字符串的 最少 数目。如果无法将字符串 s 分割成美丽子字符串，请你返回 -1 。
 *
 * 子字符串是一个字符串中一段连续的字符序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "1011"
 * 输出：2
 * 解释：我们可以将输入字符串分成 ["101", "1"] 。
 * - 字符串 "101" 不包含前导 0 ，且它是整数 5^1 = 5 的二进制表示。
 * - 字符串 "1" 不包含前导 0 ，且它是整数 5^0 = 1 的二进制表示。
 * 最少可以将 s 分成 2 个美丽子字符串。
 *
 *
 * 示例 2：
 *
 * 输入：s = "111"
 * 输出：3
 * 解释：我们可以将输入字符串分成 ["1", "1", "1"] 。
 * - 字符串 "1" 不包含前导 0 ，且它是整数 5^0 = 1 的二进制表示。
 * 最少可以将 s 分成 3 个美丽子字符串。
 *
 *
 * 示例 3：
 *
 * 输入：s = "0"
 * 输出：-1
 * 解释：无法将给定字符串分成任何美丽子字符串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 15
 * s[i] 要么是 '0' 要么是 '1' 。
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
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
    std::string intToBinaryString(int number)
    {
        // 找到最高有效位
        int highestBit = 31; // 对于32位整数，最高位是31
        while (highestBit >= 0 && !(number & (1 << highestBit)))
        {
            highestBit--;
        }

        // 如果输入为0，直接返回 "0"
        if (highestBit < 0)
        {
            return "0";
        }

        // 使用std::bitset来处理二进制表示
        std::bitset<32> bits(number);
        std::string binaryString = bits.to_string();

        // 截取从最高有效位开始的子字符串
        return binaryString.substr(32 - (highestBit + 1));
    }
    int result = 999;
    vector<vector<int>> vvii;
    vector<string> new_5;
    int check_string(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        if (s[0] == '0')
        {
            return 999;
        }
        int min_cut = 999;
        int temp_result = 999;
        for (int i = 0; i < new_5.size(); i++)
        {
            string temp_5 = new_5[i];
            int temp_len = temp_5.size();
            if (temp_len > s.size())
            {
                break;
            }
            string head = s.substr(0, temp_len);
            if (head == temp_5)
            {
                int j = check_string(s.substr(temp_len));
                if (j != 999)
                {
                    temp_result = min(temp_result, 1 + j);
                }
            }
        }
        return temp_result;
    }
    int minimumBeautifulSubstrings(string s)
    {
        vector<vector<int>> vvi(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < 10; i++)
        {
            int j = pow(5, i);
            string temp = intToBinaryString(j);
            new_5.push_back(temp);
        }

        // 从i - > j 是一个好的, 最少分几组
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                vvi[i][i] == 1;
            }
        }
        int temp_result = check_string(s);
        return temp_result == 999 ? -1 : temp_result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minimumBeautifulSubstrings
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "1011"\n
// @lcpr case=end

// @lcpr case=start
// "111"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n
// @lcpr case=end

 */
