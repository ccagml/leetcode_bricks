// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2009 lang=cpp
 * @lcpr version=30121
 *
 * [2009] 使数组连续的最少操作数
 *
 * https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/description/
 *
 * algorithms
 * Hard (51.82%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 19.1K
 * Testcase Example:  '[4,2,5,3]'
 *
 * 给你一个整数数组 nums 。每一次操作中，你可以将 nums 中 任意 一个元素替换成 任意 整数。
 *
 * 如果 nums 满足以下条件，那么它是 连续的 ：
 *
 *
 * nums 中所有元素都是 互不相同 的。
 * nums 中 最大 元素与 最小 元素的差等于 nums.length - 1 。
 *
 *
 * 比方说，nums = [4, 2, 5, 3] 是 连续的 ，但是 nums = [1, 2, 3, 5, 6] 不是连续的 。
 *
 * 请你返回使 nums 连续 的 最少 操作次数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,2,5,3]
 * 输出：0
 * 解释：nums 已经是连续的了。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,5,6]
 * 输出：1
 * 解释：一个可能的解是将最后一个元素变为 4 。
 * 结果数组为 [1,2,3,5,4] ，是连续数组。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,10,100,1000]
 * 输出：3
 * 解释：一个可能的解是：
 * - 将第二个元素变为 2 。
 * - 将第三个元素变为 3 。
 * - 将第四个元素变为 4 。
 * 结果数组为 [1,2,3,4] ，是连续数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int result = nums.size();
        queue<int> qi;
        unordered_set<int> usi;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            if (qi.size() == 0)
            {
                qi.push(cur);
                usi.insert(cur);
                continue;
            }
            else
            {
                int qi_top = qi.front();
                if ((qi_top + (nums.size() - 1)) < (cur))
                {
                    result = min(result, int(nums.size() - qi.size()));
                };
                while (qi.size() > 0 && ((qi_top + (nums.size() - 1)) < (cur)))
                {
                    qi.pop();
                    if (qi.size() > 0)
                    {
                        qi_top = qi.front();
                    }
                };
                // 判断能不能放进去
                if (usi.count(cur) == 0)
                {
                    usi.insert(cur);
                    qi.push(cur);
                }
            }
        }

        result = min(result, int(nums.size() - qi.size()));
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minOperations
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [4,2,5,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,100,1000]\n
// @lcpr case=end

 */
