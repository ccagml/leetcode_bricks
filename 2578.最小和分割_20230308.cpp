/*
 * @lc app=leetcode.cn id=2578 lang=cpp
 * @lcpr version=21801
 *
 * [2578] 最小和分割
 *
 * https://leetcode.cn/problems/split-with-minimum-sum/description/
 *
 * algorithms
 * Easy (76.26%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 5.1K
 * Testcase Example:  '4325'
 *
 * 给你一个正整数 num ，请你将它分割成两个非负整数 num1 和 num2 ，满足：
 *
 *
 * num1 和 num2 直接连起来，得到 num 各数位的一个排列。
 *
 *
 * 换句话说，num1 和 num2 中所有数字出现的次数之和等于 num 中所有数字出现的次数。
 *
 *
 * num1 和 num2 可以包含前导 0 。
 *
 *
 * 请你返回 num1 和 num2 可以得到的和的 最小 值。
 *
 * 注意：
 *
 *
 * num 保证没有前导 0 。
 * num1 和 num2 中数位顺序可以与 num 中数位顺序不同。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：num = 4325
 * 输出：59
 * 解释：我们可以将 4325 分割成 num1 = 24 和 num2 = 35 ，和为 59 ，59 是最小和。
 *
 *
 * 示例 2：
 *
 * 输入：num = 687
 * 输出：75
 * 解释：我们可以将 687 分割成 num1 = 68 和 num2 = 7 ，和为最优值 75 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 10 <= num <= 10^9
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
    int splitNum(int num)
    {
        vector<int> vi(10);
        while (num > 0)
        {
            vi[num % 10]++;
            num /= 10;
        }
        int a = 0;
        int b = 0;
        int cnt = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < vi[i]; j++)
            {
                if (cnt % 2 == 0)
                {
                    a *= 10;
                    a += i;
                }
                else
                {
                    b *= 10;
                    b += i;
                }
                cnt++;
            }
        }

        return a + b;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 4325\n
// @lcpr case=end

// @lcpr case=start
// 687\n
// @lcpr case=end

 */
