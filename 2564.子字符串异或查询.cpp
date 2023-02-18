// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2564 lang=cpp
 * @lcpr version=21704
 *
 * [2564] 子字符串异或查询
 *
 * https://leetcode.cn/problems/substring-xor-queries/description/
 *
 * algorithms
 * Medium (35.28%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    4K
 * Total Submissions: 11.3K
 * Testcase Example:  '"101101"\n[[0,5],[1,2]]'
 *
 * 给你一个 二进制字符串 s 和一个整数数组 queries ，其中 queries[i] = [firsti, secondi] 。
 *
 * 对于第 i 个查询，找到 s 的 最短子字符串 ，它对应的 十进制值 val 与 firsti 按位异或 得到 secondi ，换言之，val ^
 * firsti == secondi 。
 *
 * 第 i 个查询的答案是子字符串 [lefti, righti] 的两个端点（下标从 0 开始），如果不存在这样的子字符串，则答案为 [-1, -1]
 * 。如果有多个答案，请你选择 lefti 最小的一个。
 *
 * 请你返回一个数组 ans ，其中 ans[i] = [lefti, righti] 是第 i 个查询的答案。
 *
 * 子字符串 是一个字符串中一段连续非空的字符序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "101101", queries = [[0,5],[1,2]]
 * 输出：[[0,2],[2,3]]
 * 解释：第一个查询，端点为 [0,2] 的子字符串为 "101" ，对应十进制数字 5 ，且 5 ^ 0 = 5 ，所以第一个查询的答案为
 * [0,2]。第二个查询中，端点为 [2,3] 的子字符串为 "11" ，对应十进制数字 3 ，且 3 ^ 1 = 2 。所以第二个查询的答案为
 * [2,3] 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "0101", queries = [[12,8]]
 * 输出：[[-1,-1]]
 * 解释：这个例子中，没有符合查询的答案，所以返回 [-1,-1] 。
 *
 *
 * 示例 3：
 *
 * 输入：s = "1", queries = [[4,5]]
 * 输出：[[0,0]]
 * 解释：这个例子中，端点为 [0,0] 的子字符串对应的十进制值为 1 ，且 1 ^ 4 = 5 。所以答案为 [0,0] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s[i] 要么是 '0' ，要么是 '1' 。
 * 1 <= queries.length <= 10^5
 * 0 <= firsti, secondi <= 10^9
 *
 *
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
    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    string int_to_b_str(int need)
    {
        string temp = "";
        bool flag = false;
        for (int i = 31; i >= 0; i--)
        {
            char ci = '0';
            if (is_bit_1(need, i))
            {
                ci = '1';
            }

            if (flag)
            {
                temp.push_back(ci);
            }
            else if (!flag && ci == '1')
            {
                temp.push_back(ci);
                flag = true;
            }
        }
        if (temp.size() < 1)
        {
            temp.push_back('0');
        }
        return temp;
    }

    int kmp(string &text, string &pattern)
    {
        // 计算前缀
        int size = pattern.size();
        int *pie = new int[size];
        pie[0] = 0;
        int k = 0;
        for (int i = 1; i < size; i++)
        {
            while (k > 0 && pattern[k] != pattern[i])
            {
                k = pie[k - 1];
            }
            if (pattern[k] == pattern[i])
            {
                k = k + 1;
            }
            pie[i] = k;
        }
        // 开始查找

        int matched_pos = 0;
        for (int current = 0; current < text.length(); current++)
        {
            while (matched_pos > 0 && pattern[matched_pos] != text[current])
                matched_pos = pie[matched_pos - 1];

            if (pattern[matched_pos] == text[current])
                matched_pos = matched_pos + 1;

            if (matched_pos == (pattern.length()))
            {
                matched_pos = pie[matched_pos - 1];
                return current - (pattern.length() - 1);
            }
        }
        return -1;
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {

        vector<vector<int>> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int need = queries[i][0] ^ queries[i][1];
            // std::cout << "(int_to_b_str  " << need << ":";
            string temp = int_to_b_str(need);
            // std::cout << "计算" << temp << "|";
            int index = kmp(s, temp);
            // std::cout << "index" << temp << ":" << index << ")";
            if (index >= 0)
            {
                int nn = temp.size();
                result.push_back({index, index + nn - 1});
            }
            else
            {
                result.push_back({-1, -1});
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=substringXorQueries
// paramTypes=["string","number[][]"]
// returnType=number[][]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "101101"\n[[0,5],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// "0101"\n[[12,8]]\n
// @lcpr case=end

// @lcpr case=start
// "1"\n[[4,5]]\n
// @lcpr case=end

// @lcpr case=start
// "11111111011010011101000110010111110"\n[[1,63],[4,186],[3,5]]\n
// @lcpr case=end
// [[3,8],[-1,-1],[6,8]]	[[3,8],[27,34],[6,8]]

 */
