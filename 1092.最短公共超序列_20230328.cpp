/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 * @lcpr version=21901
 *
 * [1092] 最短公共超序列
 *
 * https://leetcode.cn/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (58.25%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 18K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * 给出两个字符串 str1 和 str2，返回同时以 str1 和 str2
 * 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。
 *
 * （如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T
 * 的子序列）
 *
 *
 *
 * 示例：
 *
 * 输入：str1 = "abac", str2 = "cab"
 * 输出："cabac"
 * 解释：
 * str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。
 * str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
 * 最终我们给出的答案是满足上述属性的最短字符串。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= str1.length, str2.length <= 1000
 * str1 和 str2 都由小写英文字母组成。
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
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // 前i j 最短长度
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abac"\n"cab"\n
// @lcpr case=end

*/
