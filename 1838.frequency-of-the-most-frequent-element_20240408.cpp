// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1838 lang=cpp
 * @lcpr version=30121
 *
 * [1838] 最高频元素的频数
 *
 * https://leetcode.cn/problems/frequency-of-the-most-frequent-element/description/
 *
 * algorithms
 * Medium (43.05%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 89.2K
 * Testcase Example:  '[1,2,4]\n5'
 *
 * 元素的 频数 是该元素在一个数组中出现的次数。
 *
 * 给你一个整数数组 nums 和一个整数 k 。在一步操作中，你可以选择 nums 的一个下标，并将该下标对应元素的值增加 1 。
 *
 * 执行最多 k 次操作后，返回数组中最高频元素的 最大可能频数 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,4], k = 5
 * 输出：3
 * 解释：对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums = [4,4,4] 。
 * 4 是数组中最高频元素，频数是 3 。
 *
 * 示例 2：
 *
 * 输入：nums = [1,4,8,13], k = 5
 * 输出：2
 * 解释：存在多种最优解决方案：
 * - 对第一个元素执行 3 次递增操作，此时 nums = [4,4,8,13] 。4 是数组中最高频元素，频数是 2 。
 * - 对第二个元素执行 4 次递增操作，此时 nums = [1,8,8,13] 。8 是数组中最高频元素，频数是 2 。
 * - 对第三个元素执行 5 次递增操作，此时 nums = [1,4,13,13] 。13 是数组中最高频元素，频数是 2 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [3,9,6], k = 2
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= 10^5
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
    int maxFrequency(vector<int> &nums, int k)
    {
        int result = 0;
        sort(nums.begin(), nums.end());
        vector<int> vi;
        unordered_map<int, int> umii;
        int last = 0;
        for (int jj = 0; jj < nums.size(); jj++)
        {
            int cur = nums[jj];
            if (last != cur)
            {
                // 计算结果
                int last_result = 0;
                last_result = last_result + umii[last];
                int last_k = k;
                for (int bb = vi.size() - 1; bb >= 0; bb--)
                {
                    int bb_value = vi[bb];
                    if (bb_value == last)
                    {
                        continue;
                    }
                    long long bb_cnt = umii[bb_value];
                    long long bb_one = last - bb_value;
                    long long cost = bb_one * bb_cnt;
                    if (cost <= last_k)
                    {
                        last_result += bb_cnt;
                    }
                    else
                    {

                        last_result += (last_k / bb_one);
                    }
                    last_k -= cost;
                    if (last_k <= 0)
                    {
                        break;
                    }
                }
                result = max(result, last_result);

                // 放入新的
                vi.push_back(cur);
                umii[cur] = 1;
                last = cur;
            }
            else
            {
                umii[cur]++;
            }
        }

        // 计算结果
        last = nums[nums.size() - 1];
        int last_result = 0;
        last_result = last_result + umii[last];
        int last_k = k;
        for (int bb = vi.size() - 1; bb >= 0; bb--)
        {
            int bb_value = vi[bb];
            if (bb_value == last)
            {
                continue;
            }
            long long bb_cnt = umii[bb_value];
            long long bb_one = last - bb_value;
            long long cost = bb_one * bb_cnt;
            if (cost <= last_k)
            {
                last_result += bb_cnt;
            }
            else
            {

                last_result += (last_k / bb_one);
            }
            last_k -= cost;
            if (last_k <= 0)
            {
                break;
            }
        }
        result = max(result, last_result);

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxFrequency
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,4]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,4,8,13]\n5\n
// @lcpr case=end

// @lcpr case=start
// [3,9,6]\n2\n
// @lcpr case=end

 */
