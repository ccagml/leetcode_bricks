// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2817 lang=cpp
 * @lcpr version=30102
 *
 * [2817] 限制条件下元素之间的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-between-elements-with-constraint/description/
 *
 * algorithms
 * Medium (31.31%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 15.2K
 * Testcase Example:  '[4,3,2,4]\n2'
 *
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 x 。
 *
 * 请你找到数组中下标距离至少为 x 的两个元素的 差值绝对值 的 最小值 。
 *
 * 换言之，请你找到两个下标 i 和 j ，满足 abs(i - j) >= x 且 abs(nums[i] - nums[j]) 的值最小。
 *
 * 请你返回一个整数，表示下标距离至少为 x 的两个元素之间的差值绝对值的 最小值 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,3,2,4], x = 2
 * 输出：0
 * 解释：我们选择 nums[0] = 4 和 nums[3] = 4 。
 * 它们下标距离满足至少为 2 ，差值绝对值为最小值 0 。
 * 0 是最优解。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,3,2,10,15], x = 1
 * 输出：1
 * 解释：我们选择 nums[1] = 3 和 nums[2] = 2 。
 * 它们下标距离满足至少为 1 ，差值绝对值为最小值 1 。
 * 1 是最优解。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3,4], x = 3
 * 输出：3
 * 解释：我们选择 nums[0] = 1 和 nums[3] = 4 。
 * 它们下标距离满足至少为 3 ，差值绝对值为最小值 3 。
 * 3 是最优解。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 0 <= x < nums.length
 *
 *
 */

// @lcpr-template-start
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
#include <set>
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
    int minAbsoluteDifference(vector<int> &nums, int x)
    {
        if (x == 0)
        {
            return 0;
        }
        vector<int> wait;

        int type = 1;
        if (nums.size() > 100)
        {
            type == 2;
        }

        std::set<int> si;
        int ans = abs(nums[nums.size() - 1] - nums[0]);
        for (int start = nums.size() - 1 - x; start >= 0; start--)
        {
            if (start + x < nums.size())
            {
                si.insert(nums[start + x]);
            }

            int cur = nums[start];
            int check_left = cur - ans + 1;
            int check_right = cur + ans - 1;

            auto lower = si.lower_bound(check_left); // std::lower_bound(wait.begin(), wait.end(), check_left);

            if (lower != si.end())
            {
                // std::cout << *lower << " at index " << std::distance(data.begin(), lower);
                // for (int j = std::distance(wait.begin(), lower); j < wait.size(); j++)
                // {
                //     int cur_j = wait[j];
                //     if (cur_j > check_right)
                //     {
                //         break;
                //     }
                //     ans = min(abs(cur_j - cur), ans);
                // }
                while (lower != si.end())
                {
                    int lo_v = *lower;
                    lower++;
                    int new_ans = abs(cur - lo_v);
                    if (lo_v > check_right)
                    {
                        break;
                    }
                    ans = min(new_ans, ans);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minAbsoluteDifference
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [4,3,2,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,3,2,10,15]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n3\n
// @lcpr case=end

 */
