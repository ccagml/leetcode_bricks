// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=982 lang=cpp
 * @lcpr version=21708
 *
 * [982] 按位与为零的三元组
 *
 * https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/description/
 *
 * algorithms
 * Hard (57.79%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 14.6K
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个整数数组 nums ，返回其中 按位与三元组 的数目。
 *
 * 按位与三元组 是由下标 (i, j, k) 组成的三元组，并满足下述全部条件：
 *
 *
 * 0 <= i < nums.length
 * 0 <= j < nums.length
 * 0 <= k < nums.length
 * nums[i] & nums[j] & nums[k] == 0 ，其中 & 表示按位与运算符。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,1,3]
 * 输出：12
 * 解释：可以选出如下 i, j, k 三元组：
 * (i=0, j=0, k=1) : 2 & 2 & 1
 * (i=0, j=1, k=0) : 2 & 1 & 2
 * (i=0, j=1, k=1) : 2 & 1 & 1
 * (i=0, j=1, k=2) : 2 & 1 & 3
 * (i=0, j=2, k=1) : 2 & 3 & 1
 * (i=1, j=0, k=0) : 1 & 2 & 2
 * (i=1, j=0, k=1) : 1 & 2 & 1
 * (i=1, j=0, k=2) : 1 & 2 & 3
 * (i=1, j=1, k=0) : 1 & 1 & 2
 * (i=1, j=2, k=0) : 1 & 3 & 2
 * (i=2, j=0, k=1) : 3 & 2 & 1
 * (i=2, j=1, k=0) : 3 & 1 & 2
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,0,0]
 * 输出：27
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] < 2^16
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
    int countTriplets(vector<int> &nums)
    {
        vector<int> temp(65537);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                int new_k = nums[i] & nums[j];
                // std::cout << nums[i] << "&" << nums[j] << "=" << new_k << ")";

                temp[new_k]++;
            }
        }
        std::cout << std::endl;
        int result = 0;
        for (int i : nums)
        {
            for (int j = 0; j < temp.size(); j++)
            {
                if ((i & j) == 0)
                {
                    result += temp[j];
                }
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
