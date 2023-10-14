/*
 * @lc app=leetcode.cn id=136 lang=cpp
 * @lcpr version=21918
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode.cn/problems/single-number/description/
 *
 * algorithms
 * Easy (72.58%)
 * Likes:    2989
 * Dislikes: 0
 * Total Accepted:    963.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,2,1]'
 *
 * 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 * 
 * 
 * 
 * 
 * 
 * 示例 1 ：
 * 
 * 输入：nums = [2,2,1]
 * 输出：1
 * 
 * 
 * 示例 2 ：
 * 
 * 输入：nums = [4,1,2,1,2]
 * 输出：4
 * 
 * 
 * 示例 3 ：
 * 
 * 输入：nums = [1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * 除了某个元素只出现一次以外，其余每个元素均出现两次。
 * 
 * 
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
    int singleNumber(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            j ^= nums[i];
        }
        return j;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

