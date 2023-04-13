/*
 * @lc app=leetcode.cn id=2404 lang=cpp
 * @lcpr version=21906
 *
 * [2404] 出现最频繁的偶数元素
 *
 * https://leetcode.cn/problems/most-frequent-even-element/description/
 *
 * algorithms
 * Easy (54.65%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    29.7K
 * Total Submissions: 50.9K
 * Testcase Example:  '[0,1,2,2,4,4,1]'
 *
 * 给你一个整数数组 nums ，返回出现最频繁的偶数元素。
 *
 * 如果存在多个满足条件的元素，只需要返回 最小 的一个。如果不存在这样的元素，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [0,1,2,2,4,4,1]
 * 输出：2
 * 解释：
 * 数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
 * 返回最小的那个，即返回 2 。
 *
 * 示例 2：
 *
 * 输入：nums = [4,4,4,9,2,4]
 * 输出：4
 * 解释：4 是出现最频繁的偶数元素。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [29,47,21,41,13,37,25,7]
 * 输出：-1
 * 解释：不存在偶数元素。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2000
 * 0 <= nums[i] <= 10^5
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
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> um;
        for (int i : nums)
        {
            if (i % 2 == 0)
            {
                um[i]++;
            }
        }
        int result = -1;
        int cnt = 0;
        for (pair<int, int> pii : um)
        {
            if (pii.second > cnt || (pii.second == cnt && pii.first < result))
            {
                result = pii.first;
                cnt = pii.second;
            }
        }
        return result;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [0,1,2,2,4,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,4,9,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [29,47,21,41,13,37,25,7]\n
// @lcpr case=end

 */
