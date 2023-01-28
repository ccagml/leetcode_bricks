/*
 * @lc app=leetcode.cn id=1664 lang=cpp
 * @lcpr version=21301
 *
 * [1664] 生成平衡数组的方案数
 *
 * https://leetcode.cn/problems/ways-to-make-a-fair-array/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 30.9K
 * Testcase Example:  '[2,1,6,4]'
 *
 * 给你一个整数数组 nums 。你需要选择 恰好 一个下标（下标从 0 开始）并删除对应的元素。请注意剩下元素的下标可能会因为删除操作而发生改变。
 *
 * 比方说，如果 nums = [6,1,7,4,1] ，那么：
 *
 *
 * 选择删除下标 1 ，剩下的数组为 nums = [6,7,4,1] 。
 * 选择删除下标 2 ，剩下的数组为 nums = [6,1,4,1] 。
 * 选择删除下标 4 ，剩下的数组为 nums = [6,1,7,4] 。
 *
 *
 * 如果一个数组满足奇数下标元素的和与偶数下标元素的和相等，该数组就是一个 平衡数组 。
 *
 * 请你返回删除操作后，剩下的数组 nums 是 平衡数组 的 方案数 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,1,6,4]
 * 输出：1
 * 解释：
 * 删除下标 0 ：[1,6,4] -> 偶数元素下标为：1 + 4 = 5 。奇数元素下标为：6 。不平衡。
 * 删除下标 1 ：[2,6,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：6 。平衡。
 * 删除下标 2 ：[2,1,4] -> 偶数元素下标为：2 + 4 = 6 。奇数元素下标为：1 。不平衡。
 * 删除下标 3 ：[2,1,6] -> 偶数元素下标为：2 + 6 = 8 。奇数元素下标为：1 。不平衡。
 * 只有一种让剩余数组成为平衡数组的方案。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,1,1]
 * 输出：3
 * 解释：你可以删除任意元素，剩余数组都是平衡数组。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3]
 * 输出：0
 * 解释：不管删除哪个元素，剩下数组都不是平衡数组。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
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
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dan(n);
        vector<int> shuang(n);
        int dan_v = 0;
        int shuang_v = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                shuang_v += nums[i];
                dan[i] = dan_v;
                shuang[i] = shuang_v;
            }
            else
            {
                dan_v += nums[i];
                dan[i] = dan_v;
                shuang[i] = shuang_v;
            }
        }
        int result = 0;
        for (int del = 0; del < n; del++)
        {
            int dan_left = get(dan, 0, del - 1);
            int shuang_right = get(shuang, del + 1, n - 1);
            int shuang_left = get(shuang, 0, del - 1);
            int dan_right = get(dan, del + 1, n - 1);
            if (dan_left + shuang_right == shuang_left + dan_right)
            {
                result++;
            }
        }
        return result;
    }
    int get(vector<int> &vi, int left, int right)
    {
        if (right < left)
        {
            return 0;
        }
        if (left > right)
        {
            return 0;
        }
        if (left == 0)
        {
            return vi[right];
        }
        else
        {
            return vi[right] - vi[left - 1];
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

 */
