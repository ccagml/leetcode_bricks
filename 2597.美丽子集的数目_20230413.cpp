// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2597 lang=cpp
 * @lcpr version=21906
 *
 * [2597] 美丽子集的数目
 *
 * https://leetcode.cn/problems/the-number-of-beautiful-subsets/description/
 *
 * algorithms
 * Medium (34.21%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 18.4K
 * Testcase Example:  '[2,4,6]\n2'
 *
 * 给你一个由正整数组成的数组 nums 和一个 正 整数 k 。
 *
 * 如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。
 *
 * 返回数组 nums 中 非空 且 美丽 的子集数目。
 *
 * nums 的子集定义为：可以经由 nums
 * 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,4,6], k = 2
 * 输出：4
 * 解释：数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
 * 可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1], k = 1
 * 输出：1
 * 解释：数组 nums 中的美丽数组有：[1] 。
 * 可以证明数组 [1] 中只存在 1 个美丽子集。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 20
 * 1 <= nums[i], k <= 1000
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
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = -1;    // 去掉空集
        int cnt[3001]{}; // 用数组实现比哈希表更快
        function<void(int)> dfs = [&](int i)
        {
            if (i == nums.size())
            {
                ans++;
                return;
            }
            dfs(i + 1);          // 不选
            int x = nums[i] + k; // 避免负数下标
            if (cnt[x - k] == 0 && cnt[x + k] == 0)
            {
                ++cnt[x]; // 选
                dfs(i + 1);
                --cnt[x]; // 恢复现场
            }
        };
        dfs(0);
        return ans;
    }
};

// @lc code=end

// @lcpr-div-debug-arg-start
// funName=beautifulSubsets
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [2,4,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [4,2,5,9,10,3]\n1\n
// @lcpr case=end


// @lcpr case=start
// [9,5,7,10,6,2]\n9\n
// @lcpr case=end

 */
