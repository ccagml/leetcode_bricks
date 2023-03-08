// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2584 lang=cpp
 * @lcpr version=21801
 *
 * [2584] 分割数组使乘积互质
 *
 * https://leetcode.cn/problems/split-the-array-to-make-coprime-products/description/
 *
 * algorithms
 * Medium (22.81%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 15.7K
 * Testcase Example:  '[4,7,8,15,3,5]'
 *
 * 给你一个长度为 n 的整数数组 nums ，下标从 0 开始。
 *
 * 如果在下标 i 处 分割 数组，其中 0 <= i <= n - 2 ，使前 i + 1 个元素的乘积和剩余元素的乘积互质，则认为该分割 有效
 * 。
 *
 *
 * 例如，如果 nums = [2, 3, 3] ，那么在下标 i = 0 处的分割有效，因为 2 和 9 互质，而在下标 i = 1 处的分割无效，因为
 * 6 和 3 不互质。在下标 i = 2 处的分割也无效，因为 i == n - 1 。
 *
 *
 * 返回可以有效分割数组的最小下标 i ，如果不存在有效分割，则返回 -1 。
 *
 * 当且仅当 gcd(val1, val2) == 1 成立时，val1 和 val2 这两个值才是互质的，其中 gcd(val1, val2) 表示
 * val1 和 val2 的最大公约数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：nums = [4,7,8,15,3,5]
 * 输出：2
 * 解释：上表展示了每个下标 i 处的前 i + 1 个元素的乘积、剩余元素的乘积和它们的最大公约数的值。
 * 唯一一个有效分割位于下标 2 。
 *
 * 示例 2：
 *
 *
 *
 * 输入：nums = [4,7,15,8,3,5]
 * 输出：-1
 * 解释：上表展示了每个下标 i 处的前 i + 1 个元素的乘积、剩余元素的乘积和它们的最大公约数的值。
 * 不存在有效分割。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * 1 <= nums[i] <= 10^6
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
    // 分解质因数
    unordered_set<int> get_primes_list(int n)
    {
        unordered_set<int> result;
        int num = n;
        while (num > 1)
        {
            for (int i = 2; i <= n; i++)
            {
                while (num > 1 && num % i == 0)
                {
                    result.insert(i);
                    num /= i;
                }
            }
        }
        return result;
    }

    unordered_set<int> fff(int x)
    {
        unordered_set<int> result;
        for (int d = 2; d * d <= x; ++d)
        { // 分解质因数
            if (x % d == 0)
            {
                result.insert(d);
                for (x /= d; x % d == 0; x /= d)
                    ;
            }
        }
        if (x > 1)
        {
            result.insert(x);
        }
        return result;
    }

    int findValidSplit(vector<int> &nums)
    {

        unordered_map<int, unordered_set<int>> uivi;

        unordered_map<int, int> right;
        vector<int> nums_right(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            int j = nums[i];
            if (uivi.count(j) < 1)
            {
                uivi[j] = fff(j);
            }
            for (int p : uivi[j])
            {
                right[p] = i;
            }
        }

        int cur_cut = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int j = nums[i];
            for (int p : uivi[j])
            {
                cur_cut = max(cur_cut, right[p]);
            }
            if (cur_cut <= i)
            {
                return (i < nums.size() - 1) ? i : -1;
            }
        }

        return -1;
    }
};

// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findValidSplit
// paramTypes=["number[]"]
// returnType=number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [4,7,8,15,3,5]\n
// @lcpr case=end

// @lcpr case=start
// [4,7,15,8,3,5]\n
// @lcpr case=end

 */
