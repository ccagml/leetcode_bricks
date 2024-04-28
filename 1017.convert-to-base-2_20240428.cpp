// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 * @lcpr version=30125
 *
 * [1017] 负二进制转换
 *
 * https://leetcode.cn/problems/convert-to-base-2/description/
 *
 * algorithms
 * Medium (64.93%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 42K
 * Testcase Example:  '2'
 *
 * 给你一个整数 n ，以二进制字符串的形式返回该整数的 负二进制（base -2）表示。
 *
 * 注意，除非字符串就是 "0"，否则返回的字符串中不能含有前导零。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出："110"
 * 解释：(-2)^2 + (-2)^1 = 2
 *
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出："111"
 * 解释：(-2)^2 + (-2)^1 + (-2)^0 = 3
 *
 *
 * 示例 3：
 *
 * 输入：n = 4
 * 输出："100"
 * 解释：(-2)^2 = 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= n <= 10^9
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
    unordered_map<int, int> uivi_zheng;
    unordered_map<int, int> uivi_fu;
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }

    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    void dfs(vector<int> &a, int cur_index, int cur_sum, int cur_flag)
    {
        if (a.size() <= cur_index)
        {
            return;
        }
        int cur = a[cur_index];

        int xuan = cur_sum + cur;
        int xuan_flag = set_bit_1(cur_flag, cur_index);
        int bu_xuan = cur_sum;
        int bu_xian_flag = cur_flag;
        if (cur > 0)
        {
            uivi_zheng[xuan] = xuan_flag;
            uivi_zheng[bu_xuan] = bu_xian_flag;
        }
        else if (cur < 0)
        {
            uivi_fu[xuan] = xuan_flag;
            uivi_fu[bu_xuan] = bu_xian_flag;
        }
        dfs(a, cur_index + 1, xuan, xuan_flag);
        dfs(a, cur_index + 1, bu_xuan, bu_xian_flag);
    }
    string baseNeg2(int n)
    {
        if (n == 0)
        {
            return "0";
        }
        vector<int> zheng;
        vector<int> zheng_index;

        vector<int> fu;
        vector<int> fu_index;
        long long temp = 1;
        for (int i = 0; i < 32; i++)
        {
            if (temp > 0)
            {
                zheng.push_back(temp);
                zheng_index.push_back(i);
            }
            else if (temp < 0 && temp > -2147483648)
            {
                fu.push_back(temp);
                fu_index.push_back(i);
            }
            temp *= (long long)-2;
        }
        dfs(zheng, 0, 0, 0);
        dfs(fu, 0, 0, 0);

        int zheng_flag = 0;
        int fu_flag = 0;
        for (pair<int, int> pii : uivi_zheng)
        {
            if (pii.first > 0)
            {
                int fu = n - pii.first;
                if (fu < 0 && uivi_fu.count(fu) > 0)
                {
                    zheng_flag = pii.second;
                    fu_flag = uivi_fu[fu];
                    break;
                }
                else if (fu == 0)
                {
                    zheng_flag = pii.second;
                    fu_flag = 0;
                    break;
                }
            }
        }
        vector<int> result(33, 0);
        for (int j = 0; j < 18; j++)
        {
            if (is_bit_1(zheng_flag, j))
            {
                result[zheng_index[j]] = 1;
            }
            if (is_bit_1(fu_flag, j))
            {
                result[fu_index[j]] = 1;
            }
        }
        string res = "";
        bool find = false;
        for (int i = 32; i >= 0; i--)
        {
            if (result[i] == 1)
            {
                find = true;
            }
            if (find)
            {
                res.push_back(result[i] + '0');
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
