// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2354 lang=cpp
 * @lcpr version=21906
 *
 * [2354] 优质数对的数目
 *
 * https://leetcode.cn/problems/number-of-excellent-pairs/description/
 *
 * algorithms
 * Hard (44.33%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 13.8K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个下标从 0 开始的正整数数组 nums 和一个正整数 k 。
 *
 * 如果满足下述条件，则数对 (num1, num2) 是 优质数对 ：
 *
 *
 * num1 和 num2 都 在数组 nums 中存在。
 * num1 OR num2 和 num1 AND num2 的二进制表示中值为 1 的位数之和大于等于 k ，其中 OR 是按位 或 操作，而 AND
 * 是按位 与 操作。
 *
 *
 * 返回 不同 优质数对的数目。
 *
 * 如果 a != c 或者 b != d ，则认为 (a, b) 和 (c, d) 是不同的两个数对。例如，(1, 2) 和 (2, 1) 不同。
 *
 * 注意：如果 num1 在数组中至少出现 一次 ，则满足 num1 == num2 的数对 (num1, num2) 也可以是优质数对。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：5
 * 解释：有如下几个优质数对：
 * - (3, 3)：(3 AND 3) 和 (3 OR 3) 的二进制表示都等于 (11) 。值为 1 的位数和等于 2 + 2 = 4 ，大于等于 k
 * = 3 。
 * - (2, 3) 和 (3, 2)： (2 AND 3) 的二进制表示等于 (10) ，(2 OR 3) 的二进制表示等于 (11) 。值为 1
 * 的位数和等于 1 + 2 = 3 。
 * - (1, 3) 和 (3, 1)： (1 AND 3) 的二进制表示等于 (01) ，(1 OR 3) 的二进制表示等于 (11) 。值为 1
 * 的位数和等于 1 + 2 = 3 。
 * 所以优质数对的数目是 5 。
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1], k = 10
 * 输出：0
 * 解释：该数组中不存在优质数对。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 60
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
    int check(int x)
    {
        int result = 0;
        while (x)
        {
            x &= (x - 1);
            result++;
        }
        return result;
    }
    long long countExcellentPairs(vector<int> &nums, int k)
    {
        long long result = 0;
        unordered_set<int> usi;
        unordered_map<int, int> umii;
        for (int i = 0; i < nums.size(); i++)
        {
            usi.insert(nums[i]);
        }
        vector<int> temp;
        for (auto p : usi)
        {
            umii[p] = check(p);
            temp.push_back(p);
        }
        for (int i = 0; i < temp.size(); i++)
        {
            int cur = temp[i];
            if (umii[cur] + umii[cur] >= k)
            {
                result += 1;
            }
            for (int j = i + 1; j < temp.size(); j++)
            {
                int and_i = temp[i] & temp[j];
                int or_i = temp[i] | temp[j];
                if (umii.count(and_i) < 1)
                {
                    umii[and_i] = check(and_i);
                }

                if (umii.count(or_i) < 1)
                {
                    umii[or_i] = check(or_i);
                }

                if (umii[and_i] + umii[or_i] >= k)
                {
                    result += 2;
                }
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=countExcellentPairs
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1]\n10\n
// @lcpr case=end

 */
