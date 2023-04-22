// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 * @lcpr version=21906
 *
 * [1027] 最长等差数列
 *
 * https://leetcode.cn/problems/longest-arithmetic-subsequence/description/
 *
 * algorithms
 * Medium (44.04%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    29.2K
 * Total Submissions: 61.9K
 * Testcase Example:  '[3,6,9,12]'
 *
 * 给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
 *
 * 回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ...
 * < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1)
 * 的值都相同，那么序列 seq 是等差的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,6,9,12]
 * 输出：4
 * 解释：
 * 整个数组是公差为 3 的等差数列。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [9,4,7,2,10]
 * 输出：3
 * 解释：
 * 最长的等差子序列是 [4,7,10]。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [20,1,15,3,10,5,8]
 * 输出：4
 * 解释：
 * 最长的等差子序列是 [20,15,10,5]。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 1000
 * 0 <= nums[i] <= 500
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
    int longestArithSeqLength(vector<int> &nums)
    {
        // vvi[x][y] x结尾 等差 y
        // vector<vector<int>> vvi();
        int result = 0;
        unordered_map<int, unordered_map<int, int>> uiuii;
        // for (int cur : nums)
        // {
        //     for (int i = -500; i <= 500; i++)
        //     {
        //         int last = cur - i;
        //         int true_i = i + 500;
        //         int cnt = uiuii[last][true_i];
        //         uiuii[cur][true_i] = max(uiuii[cur][true_i], cnt + 1);
        //         result = max(result, uiuii[cur][true_i]);
        //         int ccc = result;
        //     }
        // }

        vector<vector<int>> vvi(502, vector<int>(1002, 0));
        for (int cur : nums)
        {
            for (int i = -500; i <= 500; i++)
            {
                int last = cur - i;
                if (last >= 0 && last <= 501)
                {
                    int true_i = i + 500;
                    int cnt = vvi[last][true_i];
                    vvi[cur][true_i] = max(vvi[cur][true_i], cnt + 1);
                    result = max(result, vvi[cur][true_i]);
                }
                else
                {
                    int true_i = i + 500;

                    vvi[cur][true_i] = max(vvi[cur][true_i], 1);
                    result = max(result, vvi[cur][true_i]);
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,6,9,12]\n
// @lcpr case=end

// @lcpr case=start
// [9,4,7,2,10]\n
// @lcpr case=end

// @lcpr case=start
// [20,1,15,3,10,5,8]\n
// @lcpr case=end

// @lcpr case=start
// [61,28,67,53,13,6,70,5,79,82,60,60,84,17,80,25,82,82,69,76,81,43,58,86,18,78,4,25,8,30,33,87,91,18,90,26,62,11,28,66,9,33,58,66,47,48,80,38,25,57,4,84,79,71,54,84,63,32,97,62,26,68,5,69,54,93,25,26,100,73,24,94,80,39,30,45,95,80,0,29,57,98,92,15,17,76,69,11,57,56,48,10,28,7,63,66,53,58,12,58]\n
// @lcpr case=end

 */
