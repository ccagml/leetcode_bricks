// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2576 lang=cpp
 * @lcpr version=21707
 *
 * [2576] 求出最多标记下标
 *
 * https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/description/
 *
 * algorithms
 * Medium (33.37%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 13.4K
 * Testcase Example:  '[3,5,2,4]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 *
 * 一开始，所有下标都没有被标记。你可以执行以下操作任意次：
 *
 *
 * 选择两个 互不相同且未标记 的下标 i 和 j ，满足 2 * nums[i] <= nums[j] ，标记下标 i 和 j 。
 *
 *
 * 请你执行上述操作任意次，返回 nums 中最多可以标记的下标数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,5,2,4]
 * 输出：2
 * 解释：第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] <= nums[1] ，标记下标 2 和 1 。
 * 没有其他更多可执行的操作，所以答案为 2 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [9,2,5,4]
 * 输出：4
 * 解释：第一次操作中，选择 i = 3 和 j = 0 ，操作可以执行的原因是 2 * nums[3] <= nums[0] ，标记下标 3 和 0 。
 * 第二次操作中，选择 i = 1 和 j = 2 ，操作可以执行的原因是 2 * nums[1] <= nums[2] ，标记下标 1 和 2 。
 * 没有其他更多可执行的操作，所以答案为 4 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [7,6,8]
 * 输出：0
 * 解释：没有任何可以执行的操作，所以答案为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
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
// class Solution
// {
// public:
//     int get_f(int n)
//     {
//         return 0 - n;
//     }
//     int maxNumOfMarkedIndices(vector<int> &nums)
//     {
//         // 贪心?
//         for (int i = 0; i < nums.size(); i++)
//         {
//             nums[i] = get_f(nums[i]);
//         }

//         sort(nums.begin(), nums.end());
//         unordered_map<int, int> umii;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             umii[nums[i]]++;
//         }

//         int result = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {
//             int cur = nums[i];
//             if (umii[cur] > 0)
//             {
//                 int next = cur / 2;

//                 while (true)
//                 {
//                     auto upper = std::lower_bound(nums.begin(), nums.end(), next);
//                     // std::cout << i << " < ";
//                     if (upper != nums.end())
//                     {
//                         int value = *upper;
//                         if (umii[value] > 0)
//                         {
//                             umii[value]--;
//                             umii[cur]--;
//                             result += 2;
//                             break;
//                         }
//                         else
//                         {
//                             next = value + 1;
//                         }
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        auto check = [&](int k) -> bool
        {
            for (int i = 0; i < k; ++i)
                if (nums[i] * 2 > nums[nums.size() - k + i])
                    return false;
            return true;
        };

        int left = 0, right = nums.size() / 2 + 1; // 开区间
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left * 2;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxNumOfMarkedIndices
// paramTypes=["number[]"]
// returnType=number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [3,5,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [9,2,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,78,27,48,14,86,79,68,77,20,57,21,18,67,5,51,70,85,47,56,22,79,41,8,39,81,59,74,14,45,49,15,10,28,16,77,22,65,8,36,79,94,44,80,72,8,96,78,39,92,69,55,9,44,26,76,40,77,16,69,40,64,12,48,66,7,59,10]\n
// @lcpr case=end

// 小找大
// @lcpr case=start
// [1, 4, 7, 10]\n
// @lcpr case=end


// 大找小
// @lcpr case=start
// [3, 4, 6, 12]\n
// @lcpr case=end

// @lcpr case=start
// [42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40]\n
// @lcpr case=end


 */
