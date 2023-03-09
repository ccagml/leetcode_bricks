/*
 * @lc app=leetcode.cn id=2574 lang=cpp
 * @lcpr version=21801
 *
 * [2574] 左右元素和的差值
 *
 * https://leetcode.cn/problems/left-and-right-sum-differences/description/
 *
 * algorithms
 * Easy (86.79%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 9.8K
 * Testcase Example:  '[10,4,8,3]'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中：
 *
 *
 * answer.length == nums.length
 * answer[i] = |leftSum[i] - rightSum[i]|
 *
 *
 * 其中：
 *
 *
 * leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
 * rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
 *
 *
 * 返回数组 answer 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [10,4,8,3]
 * 输出：[15,1,11,22]
 * 解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
 * 数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1]
 * 输出：[0]
 * 解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
 * 数组 answer 为 [|0 - 0|] = [0] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^5
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
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int sum = 0;
        for (int p : nums)
        {
            sum += p;
        }
        int left = 0;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            result.push_back(abs((left) - (sum - nums[i] - left)));
            left += nums[i];
        }
        return result;
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
// [10,4,8,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
