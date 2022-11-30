/*
 * @lc app=leetcode.cn id=795 lang=cpp
 * @lcpr version=20204
 *
 * [795] 区间子数组个数
 *
 * https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (57.78%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    33.2K
 * Total Submissions: 57.5K
 * Testcase Example:  '[2,1,4,3]\n2\n3'
 *
 * 给你一个整数数组 nums 和两个整数：left 及 right 。找出 nums 中连续、非空且其中最大元素在范围 [left, right]
 * 内的子数组，并返回满足条件的子数组的个数。
 *
 * 生成的测试用例保证结果符合 32-bit 整数范围。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,1,4,3], left = 2, right = 3
 * 输出：3
 * 解释：满足条件的三个子数组：[2], [2, 1], [3]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,9,2,5,6], left = 2, right = 8
 * 输出：7
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= left <= right <= 10^9
 *
 *
 */

// 双指针,可以在一个循环里,把右边更大的也算上
// 想不到的结果是 左边数量 * 右边数量

using namespace std;
#include "stack"
#include "vector"

// @lc code=start
// class Solution
// {
// public:
//     int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
//     {
//         stack<int> sleft;
//         stack<int> sright;
//         int n = nums.size();
//         vector<int> left_big(n, -1);
//         vector<int> right_big(n, n);
//         for (int i = 0; i < n; i++)
//         {
//             // 左边更大值
//             while (sleft.size() > 0 && nums[sleft.top()] < nums[i])
//             {
//                 sleft.pop();
//             }
//             left_big[i] = sleft.size() > 0 ? sleft.top() : -1;
//             sleft.push(i);

//             while (!sright.empty() && nums[sright.top()] < nums[i])
//             {
//                 right_big[sright.top()] = i;
//                 sright.pop();
//             }
//             sright.push(i);
//         }

//         // for (int i = n - 1; i >= 0; i--)
//         // {
//         //     // 左边更大值
//         //     while (sright.size() > 0 && nums[sright.top()] < nums[i])
//         //     {
//         //         sright.pop();
//         //     }
//         //     right_big[i] = sright.size() > 0 ? sright.top() : n;
//         //     sright.push(i);
//         // }
//         int result = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] >= left && nums[i] <= right)
//             {
//                 result += (right_big[i] - i) * (i - left_big[i]);
//             }
//         }
//         return result;
//     }
// };

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        stack<int> s_l;
        stack<int> s_r;
        int n = nums.size();
        vector<int> vi_l(n, -1);
        vector<int> vi_r(n, n);

        for (int i = 0; i < n; i++)
        {
            while (s_l.size() > 0 && nums[s_l.top()] < nums[i])
            {
                s_l.pop();
            }
            vi_l[i] = s_l.size() > 0 ? s_l.top() : -1;
            s_l.push(i);

            while (s_r.size() > 0 && nums[s_r.top()] < nums[i])
            {
                vi_r[s_r.top()] = i;
                s_r.pop();
            }
            s_r.push(i);
        }

        int reuslt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= left && nums[i] <= right)
            {
                // std::cout << i << ":" << vi_l[i] << ":" << vi_r[i] << std::endl;

                reuslt += (i - vi_l[i]) * (vi_r[i] - i);
            }
        }

        return reuslt;
    }
};
// 1, 2, 1, 1, 1
// @lc code=end

/*
// @lcpr case=start
// [2,1,4,3]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,9,2,5,6]\n2\n8\n
// @lcpr case=end

 */
