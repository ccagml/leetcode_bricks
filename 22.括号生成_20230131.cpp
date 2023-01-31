/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=21401
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.58%)
 * Likes:    3040
 * Dislikes: 0
 * Total Accepted:    641.2K
 * Total Submissions: 826.5K
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
    // 左括号要大于等于右括号
    vector<string> result;
    int nnn;
    int half = 0;
    vector<string> generateParenthesis(int n)
    {
        nnn = n * 2;
        half = n;
        string temp = "";
        dfs(0, temp, 0, 0);
        return result;
    }
    void dfs(int cur, string &temp, int left, int right)
    {
        if (cur >= nnn)
        {
            if (temp.size() > 0)
            {
                result.push_back(temp);
            }
            return;
        }
        if (right > left)
        {
            return;
        }
        if (left < half)
        {
            temp.push_back('(');
            dfs(cur + 1, temp, left + 1, right);
            temp.pop_back();
        }

        if (right < half)
        {
            temp.push_back(')');
            dfs(cur + 1, temp, left, right + 1);
            temp.pop_back();
        }
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
