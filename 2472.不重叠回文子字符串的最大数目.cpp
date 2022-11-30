/*
 * @lc app=leetcode.cn id=2472 lang=cpp
 * @lcpr version=20601
 *
 * [2472] 不重叠回文子字符串的最大数目
 *
 * https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/
 *
 * algorithms
 * Hard (42.77%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 10.1K
 * Testcase Example:  '"abaccdbbd"\n3'
 *
 * 给你一个字符串 s 和一个 正 整数 k 。
 *
 * 从字符串 s 中选出一组满足下述条件且 不重叠 的子字符串：
 *
 *
 * 每个子字符串的长度 至少 为 k 。
 * 每个子字符串是一个 回文串 。
 *
 *
 * 返回最优方案中能选择的子字符串的 最大 数目。
 *
 * 子字符串 是字符串中一个连续的字符序列。
 *
 *
 *
 * 示例 1 ：
 *
 * 输入：s = "abaccdbbd", k = 3
 * 输出：2
 * 解释：可以选择 s = "abaccdbbd" 中斜体加粗的子字符串。"aba" 和 "dbbd" 都是回文，且长度至少为 k = 3 。
 * 可以证明，无法选出两个以上的有效子字符串。
 *
 *
 * 示例 2 ：
 *
 * 输入：s = "adbcda", k = 2
 * 输出：0
 * 解释：字符串中不存在长度至少为 2 的回文子字符串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= s.length <= 2000
 * s 仅由小写英文字母组成
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
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// @lc code=start
// vector<int> 前n字符 有x个回文了?
class Solution
{
public:
    int maxPalindromes(string s, int k)
    {
        int n = s.size();
        vector<vector<bool>> vvb(n, vector<bool>(n, false));
        auto cmp_pair = [](const std::pair<int, int> &t1, const std::pair<int, int> &t2)
        {
            // true使得t1排后面?
            if (t1.second > t2.second)
            {
                return true;
            }
            else if (t1.second == t2.second && t1.second > t2.second)
            {
                return true;
            }
            return false;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp_pair)> pair_pq(cmp_pair);

        for (int i = 0; i < n; i++)
        {
            vvb[i][i] = true;
            if (k == 1)
            {
                pair_pq.push({i, i});
                // std::cout << "(" << i << "," << i << ")";
            }
            if (i < n - 1)
            {
                if (s[i] == s[i + 1])
                {
                    vvb[i][i + 1] = true;
                    if (k <= 2)
                    {
                        pair_pq.push({i, i + 1});
                        // std::cout << "(" << i << "," << i + 1 << ")";
                    }
                }
            }
        }
        for (int len = 2; len < n; len++)
        {
            for (int i = 0; i < n; i++)
            {
                int next = i + len;
                if (next >= n)
                {
                    break;
                }
                if (s[i] == s[next] && vvb[i + 1][next - 1])
                {
                    vvb[i][next] = true;
                    if (k <= len + 1)
                    {
                        pair_pq.push({i, next});
                        // std::cout << "(" << i << "," << next << ")";
                    }
                }
            }
        }

        int result = 0;
        int cur_end = -1;
        while (pair_pq.size() > 0)
        {
            pair<int, int> cur = pair_pq.top();
            pair_pq.pop();
            if (cur.first > cur_end)
            {
                result++;
                cur_end = cur.second;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abaccdbbd"\n3\n
// @lcpr case=end

// @lcpr case=start
// "adbcda"\n2\n
// @lcpr case=end

 */
