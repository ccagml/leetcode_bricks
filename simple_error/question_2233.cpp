/*
 * @lc app=leetcode.cn id=2233 lang=cpp
 *
 * [2233] K 次增加后的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-after-k-increments/description/
 *
 * algorithms
 * Medium (36.24%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 21K
 * Testcase Example:  '[0,4]\n5'
 *
 * 给你一个非负整数数组 nums 和一个整数 k 。每次操作，你可以选择 nums 中 任一 元素并将它 增加 1 。
 * 
 * 请你返回 至多 k 次操作后，能得到的 nums的 最大乘积 。由于答案可能很大，请你将答案对 10^9 + 7 取余后返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,4], k = 5
 * 输出：20
 * 解释：将第一个数增加 5 次。
 * 得到 nums = [5, 4] ，乘积为 5 * 4 = 20 。
 * 可以证明 20 是能得到的最大乘积，所以我们返回 20 。
 * 存在其他增加 nums 的方法，也能得到最大乘积。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [6,3,3,2], k = 2
 * 输出：216
 * 解释：将第二个数增加 1 次，将第四个数增加 1 次。
 * 得到 nums = [6, 4, 3, 3] ，乘积为 6 * 4 * 3 * 3 = 216 。
 * 可以证明 216 是能得到的最大乘积，所以我们返回 216 。
 * 存在其他增加 nums 的方法，也能得到最大乘积。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length, k <= 10^5
 * 0 <= nums[i] <= 10^6
 * 
 * 
 */

// @lc code=start
// 又是禁止问题 需要long long
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(int i = 0; i < nums.size(); i++){
            q.push(nums[i]);
        }
        for(int i = 0; i < k; i++){
            int cur = q.top();
            q.pop();
            q.push(cur+1);
        }
        
        long long result = q.top();
        result %= ((int)1e9 + 7);;
        // std::cout << result << ",";
        q.pop();
        while(q.size() > 0){
            int cur = q.top();
            // std::cout << cur << ",";
            q.pop();
            result *= cur;
            result %= ((int)1e9 + 7);;
        }
        return result;
    }
};
// @lc code=end

