/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=21401
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.02%)
 * Likes:    2283
 * Dislikes: 0
 * Total Accepted:    626.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
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
    vector<string> result;
    string dig;
    unordered_map<int, string> uis;
    vector<string> letterCombinations(string digits)
    {
        dig = digits;
        uis[2] = "abc";
        uis[3] = "def";
        uis[4] = "ghi";
        uis[5] = "jkl";
        uis[6] = "mno";
        uis[7] = "pqrs";
        uis[8] = "tuv";
        uis[9] = "wxyz";
        string temp = "";
        dfs(0, temp);
        return result;
    }
    void dfs(int i, string &temp)
    {
        if (i >= dig.size())
        {
            if (temp.size() > 0)
            {

                string new_str(temp);
                result.push_back(new_str);
            }
            return;
        }
        int cur = dig[i] - '0';
        string cur_str = uis[cur];
        for (int j = 0; j < cur_str.size(); j++)
        {
            temp.push_back(cur_str[j]);
            dfs(i + 1, temp);
            temp.pop_back();
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
