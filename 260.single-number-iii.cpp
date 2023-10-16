/*
 * @lc app=leetcode.cn id=260 lang=cpp
 * @lcpr version=30102
 *
 * [260] 只出现一次的数字 III
 *
 * https://leetcode.cn/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (71.49%)
 * Likes:    806
 * Dislikes: 0
 * Total Accepted:    134.7K
 * Total Submissions: 186.1K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * 给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
 * 
 * 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,1,3,2,5]
 * 输出：[3,5]
 * 解释：[5, 3] 也是有效的答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [-1,0]
 * 输出：[-1,0]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [0,1]
 * 输出：[1,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 除两个只出现一次的整数外，nums 中的其他数字都出现两次
 * 
 * 
 */


// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num: nums) {
            xorsum ^= num;
        }
        // 防止溢出
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num: nums) {
            if (num & lsb) {
                type1 ^= num;
            }
            else {
                type2 ^= num;
            }
        }
        return {type1, type2};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,3,2,5]\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

 */

