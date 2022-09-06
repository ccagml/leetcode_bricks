/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 *
 * https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/description/
 *
 * algorithms
 * Medium (35.08%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 16.9K
 * Testcase Example:  '[4,4,4,5,6]'
 *
 * 给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。
 *
 * 如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：
 *
 *
 * 子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
 * 子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
 * 子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
 *
 *
 * 如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,4,4,5,6]
 * 输出：true
 * 解释：数组可以划分成子数组 [4,4] 和 [4,5,6] 。
 * 这是一种有效划分，所以返回 true 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,1,1,2]
 * 输出：false
 * 解释：该数组不存在有效划分。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start

// vv2 vv3如果是 二维数组会超时, 1维数组可以过 ....
// class Solution
// {
// public:
//     bool validPartition(vector<int> &nums)
//     {
//         //分为 2 是否已划分 3 是否已划分
//         int n = nums.size();
//         vector<bool> vv2(n);
//         vector<bool> vv3(n);
//         for (int i = 0; i < n - 1; i++)
//         {
//             if (nums[i] == nums[i + 1])
//             {
//                 // std::cout << "vv2 ->" << i << ":" << i + 1 << std::endl;
//                 vv2[i] = true;
//             }

//             if (i < n - 2)
//             {
//                 if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
//                 {
//                     // std::cout << "vv3 -> " << i << ":" << i + 2 << std::endl;
//                     vv3[i] = true;
//                 }
//                 if ((nums[i + 1] - nums[i] == 1) && (nums[i + 2] - nums[i + 1] == 1))
//                 {
//                     // std::cout << "vv3 -> " << i << ":" << i + 2 << std::endl;
//                     vv3[i] = true;
//                 }
//             }
//         }

//         // 检查是否能完成
//         std::priority_queue<int, std::vector<int>, std::less<int>> q2;
//         q2.push(0);
//         unordered_set<int> flag;
//         flag.insert(0);
//         while (q2.size() > 0)
//         {
//             int cur = q2.top();
//             q2.pop();
//             // std::cout << "出" << cur << std::endl;
//             if (cur >= n)
//             {
//                 continue;
//             }
//             // std::cout << "vv2:" << vv2[cur][cur + 1] << std::endl;
//             if (vv2[cur])
//             {
//                 if (cur + 1 == n - 1)
//                 {
//                     return true;
//                 }

//                 if (cur + 2 < n && flag.count(cur + 2) == 0)
//                 {
//                     // std::cout << "放入 " << cur + 2 << std::endl;
//                     flag.insert(cur + 2);
//                     q2.push(cur + 2);
//                 }
//             }
//             if (cur >= n - 1)
//             {
//                 continue;
//             }
//             // std::cout << "vv3:" << vv3[cur][cur + 2] << std::endl;
//             if (vv3[cur])
//             {
//                 if (cur + 2 == n - 1)
//                 {
//                     return true;
//                 }
//                 if (cur + 3 < n && flag.count(cur + 3) == 0)
//                 {
//                     // std::cout << "放入 " << cur + 3 << std::endl;
//                     flag.insert(cur + 3);
//                     q2.push(cur + 3);
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        //分为 2 是否已划分 3 是否已划分
        int n = nums.size();
        vector<bool> vv2(n);
        vector<bool> vv3(n);
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                // std::cout << "vv2 ->" << i << ":" << i + 1 << std::endl;
                vv2[i] = true;
            }

            if (i < n - 2)
            {
                if (nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
                {
                    // std::cout << "vv3 -> " << i << ":" << i + 2 << std::endl;
                    vv3[i] = true;
                }
                if ((nums[i + 1] - nums[i] == 1) && (nums[i + 2] - nums[i + 1] == 1))
                {
                    // std::cout << "vv3 -> " << i << ":" << i + 2 << std::endl;
                    vv3[i] = true;
                }
            }
        }
        vector<bool> result(n, false);
        for (int i = 1; i < n; i++)
        {
            if (i == 1)
            {
                if (vv2[i - 1])
                {
                    // std::cout << i << "已划分222" << std::endl;
                    result[i] = true;
                }
            }
            else if (i == 2)
            {
                if (vv3[i - 2])
                {
                    // std::cout << i << "已划分333" << std::endl;
                    result[i] = true;
                }
            }
            else if (i > 2)
            {
                if (result[i - 2] && vv2[i - 1])
                {
                    // std::cout << i << "已划分222" << std::endl;
                    result[i] = true;
                }
                if (i > 3)
                {
                    if (result[i - 3] && vv3[i - 2])
                    {
                        // std::cout << i << "已划分333" << std::endl;
                        result[i] = true;
                    }
                }
            }
        }

        return result[n - 1];
    }
};
// @lc code=end
