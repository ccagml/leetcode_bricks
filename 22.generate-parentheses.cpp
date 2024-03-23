/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30117
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.60%)
 * Likes:    3523
 * Dislikes: 0
 * Total Accepted:    797.8K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
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
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = vector<string>{""};
        dp[1] = vector<string>{"()"};
        for (int i = 2; i <= n; ++i)
        {
            for (int pNum = 0; pNum < i; ++pNum)
            {
                int qNum = i - pNum - 1;
                for (auto &itemp : dp[pNum]){
                    for(auto &itemq:dp[qNum]){
                        dp[i].emplace_back("("+itemp+")"+itemq);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

