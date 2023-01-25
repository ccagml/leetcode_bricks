/*
 * @lc app=leetcode.cn id=2547 lang=cpp
 * @lcpr version=21115
 *
 * [2547] 拆分数组的最小代价
 *
 * https://leetcode.cn/problems/minimum-cost-to-split-an-array/description/
 *
 * algorithms
 * Hard (55.55%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    1.9K
 * Total Submissions: 3.3K
 * Testcase Example:  '[1,2,1,2,1,3,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k 。
 *
 * 将数组拆分成一些非空子数组。拆分的 代价 是每个子数组中的 重要性 之和。
 *
 * 令 trimmed(subarray) 作为子数组的一个特征，其中所有仅出现一次的数字将会被移除。
 *
 *
 * 例如，trimmed([3,1,2,4,3,4]) = [3,4,3,4] 。
 *
 *
 * 子数组的 重要性 定义为 k + trimmed(subarray).length 。
 *
 *
 * 例如，如果一个子数组是 [1,2,3,3,3,4,4] ，trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4]
 * 。这个子数组的重要性就是 k + 5 。
 *
 *
 * 找出并返回拆分 nums 的所有可行方案中的最小代价。
 *
 * 子数组 是数组的一个连续 非空 元素序列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,1,2,1,3,3], k = 2
 * 输出：8
 * 解释：将 nums 拆分成两个子数组：[1,2], [1,2,1,3,3]
 * [1,2] 的重要性是 2 + (0) = 2 。
 * [1,2,1,3,3] 的重要性是 2 + (2 + 2) = 6 。
 * 拆分的代价是 2 + 6 = 8 ，可以证明这是所有可行的拆分方案中的最小代价。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,2,1,2,1], k = 2
 * 输出：6
 * 解释：将 nums 拆分成两个子数组：[1,2], [1,2,1] 。
 * [1,2] 的重要性是 2 + (0) = 2 。
 * [1,2,1] 的重要性是 2 + (2) = 4 。
 * 拆分的代价是 2 + 4 = 6 ，可以证明这是所有可行的拆分方案中的最小代价。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,1,2,1], k = 5
 * 输出：10
 * 解释：将 nums 拆分成一个子数组：[1,2,1,2,1].
 * [1,2,1,2,1] 的重要性是 5 + (3 + 2) = 10 。
 * 拆分的代价是 10 ，可以证明这是所有可行的拆分方案中的最小代价。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] < nums.length
 * 1 <= k <= 10^9
 *
 *
 *
 *
 */
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
// @lc code=start
class Solution
{
public:
    int minCost(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> vi(n, INT_MAX);
        unordered_map<int, int> umii;
        for (int i = 0; i < n; i++)
        {
            umii.clear();
            int uni = 0;
            // std::cout << "(" << i << ",";
            for (int j = i; j >= 0; j--)
            {
                int j_value = nums[j];
                umii[j_value]++;
                if (umii[j_value] == 2)
                {
                    uni += 2;
                }
                else if (umii[j_value] > 2)
                {
                    uni++;
                }
                int jjj = 0;
                if (j > 0)
                {
                    jjj = vi[j - 1];
                }
                // std::cout << "j:" << j << "=" << jjj + uni + k << "|";
                vi[i] = min(vi[i], jjj + uni + k);
            }
            // std::cout << i << ":" << vi[i] << ")" << std::endl;
        }
        return vi[n - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,1,2,1,3,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,2,1]\n5\n
// @lcpr case=end

 */
