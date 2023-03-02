// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2573 lang=cpp
 * @lcpr version=21707
 *
 * [2573] 找出对应 LCP 矩阵的字符串
 *
 * https://leetcode.cn/problems/find-the-string-with-lcp/description/
 *
 * algorithms
 * Hard (34.62%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    1.4K
 * Total Submissions: 4K
 * Testcase Example:  '[[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]'
 *
 * 对任一由 n 个小写英文字母组成的字符串 word ，我们可以定义一个 n x n 的矩阵，并满足：
 *
 *
 * lcp[i][j] 等于子字符串 word[i,...,n-1] 和 word[j,...,n-1] 之间的最长公共前缀的长度。
 *
 *
 * 给你一个 n x n 的矩阵 lcp 。返回与 lcp 对应的、按字典序最小的字符串 word 。如果不存在这样的字符串，则返回空字符串。
 *
 * 对于长度相同的两个字符串 a 和 b ，如果在 a 和 b 不同的第一个位置，字符串 a 的字母在字母表中出现的顺序先于 b 中的对应字母，则认为字符串
 * a 按字典序比字符串 b 小。例如，"aabd" 在字典上小于 "aaca" ，因为二者不同的第一位置是第三个字母，而 'b' 先于 'c'
 * 出现。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
 * 输出："abab"
 * 解释：lcp 对应由两个交替字母组成的任意 4 字母字符串，字典序最小的是 "abab" 。
 *
 *
 * 示例 2：
 *
 * 输入：lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
 * 输出："aaaa"
 * 解释：lcp 对应只有一个不同字母的任意 4 字母字符串，字典序最小的是 "aaaa" 。
 *
 *
 * 示例 3：
 *
 * 输入：lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
 * 输出：""
 * 解释：lcp[3][3] 无法等于 3 ，因为 word[3,...,3] 仅由单个字母组成；因此，不存在答案。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n == lcp.length == lcp[i].length <= 1000
 * 0 <= lcp[i][j] <= n
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
    string findTheString(vector<vector<int>> &lcp)
    {
        int i = 0, n = lcp.size();
        string result(n, '0');
        for (char c = 'a'; c <= 'z'; c++)
        {
            // 找到第一个不是 0 的位置,填入 s
            while (i < n && result[i] != '0')
            {
                i++;
            }
            if (i == n)
            {
                break;
            }
            // 如果 lcp[i][j] > 0 那么j也是c
            for (int j = i; j < n; j++)
            {
                if (lcp[i][j] > 0)
                {
                    result[j] = c;
                }
            }
        }

        int check = 0;
        for (int i = 0; i < n; i++)
        {
            if (result[i] == '0')
            {
                return "";
            }
        }

        // 验证这个串
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int cur_lcp = 0;
                if (result[i] == result[j])
                {
                    cur_lcp = 1;
                }
                if (cur_lcp > 0 && i < n - 1 && j < n - 1)
                {
                    cur_lcp += lcp[i + 1][j + 1];
                }
                if (lcp[i][j] != cur_lcp)
                {
                    return "";
                }
            }
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findTheString
// paramTypes=["number[][]"]
// returnType=string
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]\n
// @lcpr case=end


//"abcbbaab"
// @lcpr case=start
// [[8,0,0,0,0,1,2,0],[0,7,0,1,1,0,0,1],[0,0,6,0,0,0,0,0],[0,1,0,5,1,0,0,1],[0,1,0,1,4,0,0,1],[1,0,0,0,0,3,1,0],[2,0,0,0,0,1,2,0],[0,1,0,1,1,0,0,1]]\n
// @lcpr case=end

 */
