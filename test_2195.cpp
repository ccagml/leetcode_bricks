/*
 * @lc app=leetcode.cn id=2195 lang=cpp
 *
 * [2195] 向数组中追加 K 个整数
 *
 * https://leetcode-cn.com/problems/append-k-integers-with-minimal-sum/description/
 *
 * algorithms
 * Medium (19.18%)
 * Likes:    19
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 32.4K
 * Testcase Example:  '[1,4,25,10,25]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k 。请你向 nums 中追加 k 个 未 出现在 nums 中的、互不相同 的 正 整数，并使结果数组的元素和
 * 最小 。
 * 
 * 返回追加到 nums 中的 k 个整数之和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,4,25,10,25], k = 2
 * 输出：5
 * 解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 2 和 3 。
 * nums 最终元素和为 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70 ，这是所有情况中的最小值。
 * 所以追加到数组中的两个整数之和是 2 + 3 = 5 ，所以返回 5 。
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,6], k = 6
 * 输出：25
 * 解释：在该解法中，向数组中追加的两个互不相同且未出现的正整数是 1 、2 、3 、4 、7 和 8 。
 * nums 最终元素和为 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36 ，这是所有情况中的最小值。
 * 所以追加到数组中的两个整数之和是 1 + 2 + 3 + 4 + 7 + 8 = 25 ，所以返回 25 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++){
        //     std::cout << nums[i] << ",";
        // }
        // std::cout << std::endl;
        long long need = k;
        int cur_index = 0;
        int end_index = nums.size() - 1;
        long long result = 0;
        while(need > 0){
            // 计算1-
            long long s_s = 1;
            long long ncur = nums[cur_index] - 1;
            long long e_e = min(ncur, s_s + need -1);
            if (e_e >= s_s){
                result += ((s_s + e_e) * (e_e - s_s + 1)) / 2;
                need -= (e_e - s_s + 1);
            }
            // std::cout << result << ":还需要:" << need << std::endl;
            //计算之后
            if(need == 0){
                break;
            }
            // 计算空格
            while(cur_index < end_index){
                long long diff_num = nums[cur_index + 1] - nums[cur_index];
                if(diff_num > 1){
                    long long s_s = nums[cur_index] + 1;
                    long long ncur = nums[cur_index + 1] - 1;
                    long long e_e = min(ncur, s_s + need - 1);
                    long long temp = (s_s + e_e) * min(diff_num - 1, need ) / 2;
                    result += temp;
                    // std::cout << result << ":中间:" << nums[cur_index] << ":" << nums[cur_index + 1] << ":" << need << ":增加了" << temp << std::endl;

                    need -= min(diff_num - 1, need );
                    cur_index++;
                }else{
                    cur_index++;
                }
                if(need == 0){
                    break;
                }
            }
            // std::cout << result << ":22还需要:" << need << std::endl;
            //计算之后
            if(need == 0){
                break;
            }
            s_s = nums[end_index] + 1;
            e_e =  s_s + need - 1;
            result += ((s_s + e_e) * need) / 2;
            need = 0;
            // std::cout << result << ":" << need << std::endl;
        }
        return result;
    }
};
// @lc code=end

