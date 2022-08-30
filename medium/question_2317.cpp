/*
 * @lc app=leetcode.cn id=2317 lang=cpp
 *
 * [2317] 操作后的最大异或和
 *
 * https://leetcode.cn/problems/maximum-xor-after-operations/description/
 *
 * algorithms
 * Medium (84.60%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 4.5K
 * Testcase Example:  '[3,2,4,6]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。一次操作中，选择 任意 非负整数 x 和一个下标 i ，更新 nums[i] 为 nums[i] AND
 * (nums[i] XOR x) 。
 * 
 * 注意，AND 是逐位与运算，XOR 是逐位异或运算。
 * 
 * 请你执行 任意次 更新操作，并返回 nums 中所有元素 最大 逐位异或和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,2,4,6]
 * 输出：7
 * 解释：选择 x = 4 和 i = 3 进行操作，num[3] = 6 AND (6 XOR 4) = 6 AND 2 = 2 。
 * 现在，nums = [3, 2, 4, 2] 且所有元素逐位异或得到 3 XOR 2 XOR 4 XOR 2 = 7 。
 * 可知 7 是能得到的最大逐位异或和。
 * 注意，其他操作可能也能得到逐位异或和 7 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,2,3,9,2]
 * 输出：11
 * 解释：执行 0 次操作。
 * 所有元素的逐位异或和为 1 XOR 2 XOR 3 XOR 9 XOR 2 = 11 。
 * 可知 11 是能得到的最大逐位异或和。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^8
 * 
 * 
 */

// @lc code=start
// 可能是需要 判断每位1的数量,0的数量

// 想到可能是要每位计数
// 没想到只是保留每位的1就行, 
// 这个例子有点误解 [1,2,3,9,2]
//                  01, 10, 11, 1001, 10

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> bits(33, 0);
        // std::cout << 1111 << std::endl;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 31; j++){
                if(nums[i] & ( 1 << j)){
                    bits[j]++;
                }
            }
        }
        // std::cout << 222 << std::endl;
        int result = 0;
        for(int i = 0; i < 31; i++){
            if(bits[i] > 0){
                result |= (1 << i);
            }
        }
        // std::cout << 333 << std::endl;
        return result;
    }
};
// @lc code=end

