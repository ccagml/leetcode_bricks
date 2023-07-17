// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1589 lang=cpp
 * @lcpr version=21910
 *
 * [1589] 所有排列中的最大和
 *
 * https://leetcode.cn/problems/maximum-sum-obtained-of-any-permutation/description/
 *
 * algorithms
 * Medium (32.38%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 20.2K
 * Testcase Example:  '[1,2,3,4,5]\n[[1,3],[0,1]]'
 *
 * 有一个整数数组 nums ，和一个查询数组 requests ，其中 requests[i] = [starti, endi] 。第 i 个查询求
 * nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi] 的结果
 * ，starti 和 endi 数组索引都是 从 0 开始 的。
 *
 * 你可以任意排列 nums 中的数字，请你返回所有查询结果之和的最大值。
 *
 * 由于答案可能会很大，请你将它对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
 * 输出：19
 * 解释：一个可行的 nums 排列为 [2,1,3,4,5]，并有如下结果：
 * requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
 * requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
 * 总和为：8 + 3 = 11。
 * 一个总和更大的排列为 [3,5,4,2,1]，并有如下结果：
 * requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
 * requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
 * 总和为： 11 + 8 = 19，这个方案是所有排列中查询之和最大的结果。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,3,4,5,6], requests = [[0,1]]
 * 输出：11
 * 解释：一个总和最大的排列为 [6,5,4,3,2,1] ，查询和为 [11]。
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
 * 输出：47
 * 解释：一个和最大的排列为 [4,10,5,3,2,1] ，查询结果分别为 [19,18,10]。
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length
 * 1 <= n <= 10^5
 * 0 <= nums[i] <= 10^5
 * 1 <= requests.length <= 10^5
 * requests[i].length == 2
 * 0 <= starti <= endi < n
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
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int max_n = nums.size() + 1;
        vector<int> flag(max_n, 0);

        for (int i = 0; i < requests.size(); i++)
        {
            int a = requests[i][0];
            int b = requests[i][1];
            flag[a]++;
            flag[b + 1]--;
        }
        long long cur = 0;
        vector<long long> check_flag(max_n, 0);
        for (int check = 0; check < max_n; check++)
        {
            cur += flag[check];
            check_flag[check] = cur;
        }
        long long result = 0;
        sort(nums.begin(), nums.end(), [](int a, int b)
             { return a > b; });
        sort(check_flag.begin(), check_flag.end(), [](int a, int b)
             { return a > b; });

        for (int i = 0; i < nums.size(); i++)
        {
            result += (check_flag[i] * nums[i]);
            int e97 = 1e9 + 7;
            result %= e97;
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxSumRangeQuery
// paramTypes= ["number[]","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3,4,5]\n[[1,3],[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n[[0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,10]\n[[0,2],[1,3],[1,1]]\n
// @lcpr case=end

 */
