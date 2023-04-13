/*
 * @lc app=leetcode.cn id=2595 lang=cpp
 * @lcpr version=21906
 *
 * [2595] 奇偶位数
 *
 * https://leetcode.cn/problems/number-of-even-and-odd-bits/description/
 *
 * algorithms
 * Easy (72.87%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    8.7K
 * Total Submissions: 11.9K
 * Testcase Example:  '17'
 *
 * 给你一个 正 整数 n 。
 *
 * 用 even 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的偶数下标的个数。
 *
 * 用 odd 表示在 n 的二进制形式（下标从 0 开始）中值为 1 的奇数下标的个数。
 *
 * 返回整数数组 answer ，其中 answer = [even, odd] 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 17
 * 输出：[2,0]
 * 解释：17 的二进制形式是 10001 。
 * 下标 0 和 下标 4 对应的值为 1 。
 * 共有 2 个偶数下标，0 个奇数下标。
 *
 *
 * 示例 2：
 *
 * 输入：n = 2
 * 输出：[0,1]
 * 解释：2 的二进制形式是 10 。
 * 下标 1 对应的值为 1 。
 * 共有 0 个偶数下标，1 个奇数下标。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
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
    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    vector<int> evenOddBit(int n)
    {
        vector<int> result = {0, 0};
        for (int i = 0; i < 13; i++)
        {
            if (is_bit_1(n, i))
            {
                if (i % 2 == 0)
                {
                    result[0]++;
                }
                else
                {
                    result[1]++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 17\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
