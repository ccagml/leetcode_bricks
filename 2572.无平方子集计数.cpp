// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2572 lang=cpp
 * @lcpr version=21704
 *
 * [2572] 无平方子集计数
 *
 * https://leetcode.cn/problems/count-the-number-of-square-free-subsets/description/
 *
 * algorithms
 * Medium (25.74%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    2.2K
 * Total Submissions: 8.7K
 * Testcase Example:  '[3,4,4,5]'
 *
 * 给你一个正整数数组 nums 。
 *
 * 如果数组 nums 的子集中的元素乘积是一个 无平方因子数 ，则认为该子集是一个 无平方 子集。
 *
 * 无平方因子数 是无法被除 1 之外任何平方数整除的数字。
 *
 * 返回数组 nums 中 无平方 且 非空 的子集数目。因为答案可能很大，返回对 10^9 + 7 取余的结果。
 *
 * nums 的 非空子集 是可以由删除 nums
 * 中一些元素（可以不删除，但不能全部删除）得到的一个数组。如果构成两个子集时选择删除的下标不同，则认为这两个子集不同。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,4,4,5]
 * 输出：3
 * 解释：示例中有 3 个无平方子集：
 * - 由第 0 个元素 [3] 组成的子集。其元素的乘积是 3 ，这是一个无平方因子数。
 * - 由第 3 个元素 [5] 组成的子集。其元素的乘积是 5 ，这是一个无平方因子数。
 * - 由第 0 个和第 3 个元素 [3,5] 组成的子集。其元素的乘积是 15 ，这是一个无平方因子数。
 * 可以证明给定数组中不存在超过 3 个无平方子集。
 *
 * 示例 2：
 *
 * 输入：nums = [1]
 * 输出：1
 * 解释：示例中有 1 个无平方子集：
 * - 由第 0 个元素 [1] 组成的子集。其元素的乘积是 1 ，这是一个无平方因子数。
 * 可以证明给定数组中不存在超过 1 个无平方子集。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 30
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
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }
    int set_bit_0(int x, int index)
    {
        x &= ~(1 << index);
        return x;
    }

    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }
    int squareFreeSubsets(vector<int> &nums)
    {
        // 计算一个数有没有因子
        vector<int> vi(31);
        // 给i分解质因数

        vector<int> PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        unordered_map<int, int> num_to_p_index;
        for (int i = 0; i < PRIMES.size(); i++)
        {
            num_to_p_index[PRIMES[i]] = i;
        }
        for (int i = 2; i <= 30; i++)
        {

            unordered_map<int, int> temp = get_primes_list(i);

            for (pair<int, int> pp : temp)
            {
                if (pp.second > 1)
                {
                    vi[i] = -1;
                    break;
                }
                vi[i] = set_bit_1(vi[i], num_to_p_index[pp.first]);
            }
        }

        vector<int> result(2000);
        result[0] = 1;

        int e9 = 1e9 + 7;

        // result[msk] = 1 数量是msk的数量
        for (int x : nums)
        {
            // x拥有的质因子
            int x_msk = vi[x];

            if (x_msk >= 0)
            {
                // y 质因子的结果数
                for (int all_msk = 1024; all_msk >= x_msk; all_msk--)
                {
                    if ((all_msk | x_msk) == all_msk)
                    {
                        result[all_msk] = (result[all_msk] + result[all_msk ^ x_msk]);
                        result[all_msk] %= e9;
                    }
                }
            }
        }
        result[0]--;
        int int_result = 0;
        for (int i = 0; i < result.size(); i++)
        {
            int_result += result[i];
            int_result %= e9;
        }
        return int_result;
    }

    unordered_map<int, int> get_primes_list(int n)
    {
        unordered_map<int, int> result;
        int num = n;
        while (num > 1)
        {
            for (int i = 2; i <= n; i++)
            {
                while (num > 1 && num % i == 0)
                {
                    result[i]++;
                    num /= i;
                }
            }
        }
        return result;
    }
};

// @lc code=end

// @lcpr-div-debug-arg-start
// funName=squareFreeSubsets
// paramTypes=["number[]"]
// returnType=number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end
// @lcpr case=start
// [1, 1, 1, 2]\n
// @lcpr case=end

 */
