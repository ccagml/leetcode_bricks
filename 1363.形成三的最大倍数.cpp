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
    string get(vector<int> &vi)
    {
        bool flag = false;
        string result = "";
        for (int i = 9; i >= 0; i--)
        {
            for (int j = 0; j < vi[i]; j++)
            {
                if (i > 0)
                {
                    flag = true;
                    result.push_back('0' + i);
                }
                else
                {
                    if (flag)
                    {
                        result.push_back('0');
                    }
                    else
                    {
                        return "0";
                    }
                }
            }
        }
        return result;
    }
    string largestMultipleOfThree(vector<int> &digits)
    {
        vector<int> vi(10);
        int sum = 0;
        for (int j : digits)
        {
            vi[j]++;
            sum += j;
        }

        if (sum % 3 == 1)
        {
            // 减少一个147
            // 或者两个258
            // std::cout << sum << "余数1";
            int cut_1 = vi[1] + vi[4] + vi[7];
            int cut_2 = vi[2] + vi[5] + vi[8];
            if (cut_1 >= 1)
            {

                int cost_need = 1;
                while (cost_need >= 1 && vi[1] >= 1)
                {
                    cost_need--;
                    vi[1]--;
                    // std::cout << "cost:" << 1;
                }
                while (cost_need >= 1 && vi[4] >= 1)
                {
                    cost_need--;
                    vi[4]--;
                    // std::cout << "cost:" << 4;
                }
                while (cost_need >= 1 && vi[7] >= 1)
                {
                    cost_need--;
                    vi[7]--;
                    // std::cout << "cost:" << 7;
                }

                return get(vi);
            }
            else if (cut_2 >= 2)
            {
                int cost_need = 2;
                while (cost_need >= 1 && vi[2] >= 1)
                {
                    cost_need--;
                    vi[2]--;
                    // std::cout << "cost:" << 2;
                }
                while (cost_need >= 1 && vi[5] >= 1)
                {
                    cost_need--;
                    vi[5]--;
                    // std::cout << "cost:" << 5;
                }
                while (cost_need >= 1 && vi[8] >= 1)
                {
                    cost_need--;
                    vi[8]--;
                    // std::cout << "cost:" << 8;
                }
                return get(vi);
            }
        }
        else if (sum % 3 == 2)
        {
            // 减少一个258
            // 或者两个147
            // std::cout << "余数2";
            int cut_1 = vi[1] + vi[4] + vi[7];
            int cut_2 = vi[2] + vi[5] + vi[8];
            if (cut_2 >= 1)
            {
                int cost_need = 1;
                while (cost_need >= 1 && vi[2] >= 1)
                {
                    cost_need--;
                    vi[2]--;
                    // std::cout << "cost:" << 2;
                }
                while (cost_need >= 1 && vi[5] >= 1)
                {
                    cost_need--;
                    vi[5]--;
                    // std::cout << "cost:" << 5;
                }
                while (cost_need >= 1 && vi[8] >= 1)
                {
                    cost_need--;
                    vi[8]--;
                    // std::cout << "cost:" << 8;
                }
                return get(vi);
            }
            else if (cut_1 >= 2)
            {
                int cost_need = 2;
                while (cost_need >= 1 && vi[1] >= 1)
                {
                    cost_need--;
                    vi[1]--;
                    // std::cout << "cost:" << 1;
                }
                while (cost_need >= 1 && vi[4] >= 1)
                {
                    cost_need--;
                    vi[4]--;
                    // std::cout << "cost:" << 4;
                }
                while (cost_need >= 1 && vi[7] >= 1)
                {
                    cost_need--;
                    vi[7]--;
                    // std::cout << "cost:" << 7;
                }
                return get(vi);
            }
        }
        return get(vi);
        // 处理前置0
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
