// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2680 lang=cpp
 * @lcpr version=21917
 *
 * [2680] 最大或值
 *
 * https://leetcode.cn/problems/maximum-or/description/
 *
 * algorithms
 * Medium (42.94%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 7.3K
 * Testcase Example:  '[12,9]\n1'
 *
 * 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k 。每一次操作中，你可以选择一个数并将它乘 2 。
 *
 * 你最多可以进行 k 次操作，请你返回 nums[0] | nums[1] | ... | nums[n - 1] 的最大值。
 *
 * a | b 表示两个整数 a 和 b 的 按位或 运算。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [12,9], k = 1
 * 输出：30
 * 解释：如果我们对下标为 1 的元素进行操作，新的数组为 [12,18] 。此时得到最优答案为 12 和 18 的按位或运算的结果，也就是 30 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [8,1,2], k = 2
 * 输出：35
 * 解释：如果我们对下标 0 处的元素进行操作，得到新数组 [32,1,2] 。此时得到最优答案为 32|1|2 = 35 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 15
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
    long long set_bit_1(long long x, long long index)
    {
        long long j = 1;
        x |= (j << index);
        return x;
    }

    bool is_bit_1(long long x, long long index)
    {
        long long j = 1;
        return ((j << index) & (x));
    }

    long long get_cur(vector<int> &temp)
    {
        long long result = 0;
        for (int i = 0; i < 48; i++)
        {
            if (temp[i] > 0)
            {
                result = set_bit_1(result, i);
            }
        }
        return result;
    }

    long long maximumOr(vector<int> &nums, int k)
    {
        // 0001 1101 1100 1101 0110 0101 0000 0000 0000 0000 0000 0000
        // 1001
        // 1010
        //  100
        // 最高位的才挪
        vector<int> temp(48);
        int cur_hight = 0;
        unordered_set<int> usll;
        long long result = 0;
        for (int n : nums)
        {
            // 0011 1011 1001 1010 1100 1010 0000 0000
            for (int start = 31; start >= 0; start--)
            {
                if (is_bit_1(n, start))
                {
                    if (start > cur_hight)
                    {
                        cur_hight = start;
                        usll.clear();
                        usll.insert(n);
                    }
                    else if (start == cur_hight)
                    {
                        usll.insert(n);
                    }
                    temp[start]++;
                }
            }
        }

        for (long long p : usll)
        {
            for (int start = 31; start >= 0; start--)
            {
                if (is_bit_1(p, start))
                {
                    temp[start + k]++;
                    temp[start]--;
                }
            }

            result = max(result, get_cur(temp));
            for (int start = 31; start >= 0; start--)
            {
                if (is_bit_1(p, start))
                {
                    temp[start + k]--;
                    temp[start]++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maximumOr
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [12,9]\n1\n
// @lcpr case=end

// @lcpr case=start
// [8,1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1000000000, 1000000001, 1000000002]\n15\n
// @lcpr case=end

 */
