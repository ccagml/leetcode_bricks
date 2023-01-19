/*
 * @lc app=leetcode.cn id=1363 lang=cpp
 * @lcpr version=21113
 *
 * [1363] 形成三的最大倍数
 *
 * https://leetcode.cn/problems/largest-multiple-of-three/description/
 *
 * algorithms
 * Hard (36.23%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 20.2K
 * Testcase Example:  '[8,1,9]'
 *
 * 给你一个整数数组 digits，你可以通过按任意顺序连接其中某些数字来形成 3 的倍数，请你返回所能得到的最大的 3 的倍数。
 *
 * 由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。
 *
 * 如果无法得到答案，请返回一个空字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：digits = [8,1,9]
 * 输出："981"
 *
 *
 * 示例 2：
 *
 * 输入：digits = [8,6,7,1,0]
 * 输出："8760"
 *
 *
 * 示例 3：
 *
 * 输入：digits = [1]
 * 输出：""
 *
 *
 * 示例 4：
 *
 * 输入：digits = [0,0,0,0,0,0]
 * 输出："0"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= digits.length <= 10^4
 * 0 <= digits[i] <= 9
 * 返回的结果不应包含不必要的前导零。
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
    string largestMultipleOfThree(vector<int> &digits)
    {
        vector<int> cnt(10), modulo(3);
        int sum = 0;
        for (int digit : digits)
        {
            ++cnt[digit];
            ++modulo[digit % 3];
            sum += digit;
        }

        int remove_mod = 0, rest = 0;
        if (sum % 3 == 1)
        {
            if (modulo[1] >= 1)
            {
                remove_mod = 1;
                rest = 1;
            }
            else
            {
                remove_mod = 2;
                rest = 2;
            }
        }
        else if (sum % 3 == 2)
        {
            if (modulo[2] >= 1)
            {
                remove_mod = 2;
                rest = 1;
            }
            else
            {
                remove_mod = 1;
                rest = 2;
            }
        }
        string ans;
        for (int i = 0; i <= 9; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                if (rest && remove_mod == i % 3)
                {
                    --rest;
                }
                else
                {
                    ans += static_cast<char>(i + 48);
                }
            }
        }
        if (ans.size() && ans.back() == '0')
        {
            ans = "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [8,1,9]\n
// @lcpr case=end

// @lcpr case=start
// [8,6,7,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0,0]\n
// @lcpr case=end

 */
