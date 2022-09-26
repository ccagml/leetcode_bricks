/*
 * @lc app=leetcode.cn id=6190 lang=cpp
 *
 * [6190] 找到所有好下标
 *
 * https://leetcode.cn/problems/find-all-good-indices/description/
 *
 * algorithms
 * Medium (26.39%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 17.5K
 * Testcase Example:  '[2,1,1,1,3,4,1]\n2'
 *
 * 给你一个大小为 n 下标从 0 开始的整数数组 nums 和一个正整数 k 。
 * 
 * 对于 k <= i < n - k 之间的一个下标 i ，如果它满足以下条件，我们就称它为一个 好 下标：
 * 
 * 
 * 下标 i 之前 的 k 个元素是 非递增的 。
 * 下标 i 之后 的 k 个元素是 非递减的 。
 * 
 * 
 * 按 升序 返回所有好下标。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,1,1,1,3,4,1], k = 2
 * 输出：[2,3]
 * 解释：数组中有两个好下标：
 * - 下标 2 。子数组 [2,1] 是非递增的，子数组 [1,3] 是非递减的。
 * - 下标 3 。子数组 [1,1] 是非递增的，子数组 [3,4] 是非递减的。
 * 注意，下标 4 不是好下标，因为 [4,1] 不是非递减的。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,1,1,2], k = 2
 * 输出：[]
 * 解释：数组中没有好下标。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 3 <= n <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= n / 2
 * 
 * 
 */

// @lc code=start

// 思路可能是找出变化的点
// 二分查找变化点的位置
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> add_bian;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                add_bian.push_back(i - 1);
            }
        }
        // 1,1,2 // 上升前
        vector<int> cost_bian;
        for(int i =  nums.size() - 2; i >= 0; i--){
            if(nums[i] > nums[i + 1]){
                cost_bian.push_back(i);
            }
        }
        // 2, 1, 1 // 递减前
    }
};
// @lc code=end

