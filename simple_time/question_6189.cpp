/*
 * @lc app=leetcode.cn id=6189 lang=cpp
 *
 * [6189] 按位与最大的最长子数组
 *
 * https://leetcode.cn/problems/longest-subarray-with-maximum-bitwise-and/description/
 *
 * algorithms
 * Medium (39.45%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 14.5K
 * Testcase Example:  '[1,2,3,3,2,2]'
 *
 * 给你一个长度为 n 的整数数组 nums 。
 *
 * 考虑 nums 中进行 按位与（bitwise AND）运算得到的值 最大 的 非空 子数组。
 *
 *
 * 换句话说，令 k 是 nums 任意 子数组执行按位与运算所能得到的最大值。那么，只需要考虑那些执行一次按位与运算后等于 k 的子数组。
 *
 *
 * 返回满足要求的 最长 子数组的长度。
 *
 * 数组的按位与就是对数组中的所有数字进行按位与运算。
 *
 * 子数组 是数组中的一个连续元素序列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,3,2,2]
 * 输出：2
 * 解释：
 * 子数组按位与运算的最大值是 3 。
 * 能得到此结果的最长子数组是 [3,3]，所以返回 2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3,4]
 * 输出：1
 * 解释：
 * 子数组按位与运算的最大值是 4 。
 * 能得到此结果的最长子数组是 [4]，所以返回 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 *
 *
 * [1,2,3,3,2,2]\n[1,2,3,4]\n[323376,323376,323376,323376,323376,323376,323376,75940,75940]\n[25,25]
 */

// @lc code=start
/*
一开始是想滑动窗口,结果思路不太对
后来考虑到 数组最大值,那么其中两个的值一定也是最大值

*/

class Solution
{
public:
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }
    int set_bit_0(int x, int index)
    {
        x &= ~(1 << index);
        return x;
    }

    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }

    // int longestSubarray(vector<int> &nums)
    // {
    //     vector<int> temp(32);
    //     queue<int> win;
    //     int max_cur = 0;
    //     int max_result = 0;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int temp_0 = 0;
    //         win.push(i);
    //         int cur_need = win.size();
    //         for (int check_bit = 0; check_bit < 22; check_bit++)
    //         {
    //             if (is_bit_1(nums[i], check_bit))
    //             {
    //                 temp[check_bit]++;
    //                 if (temp[check_bit] == cur_need)
    //                 {
    //                     temp_0 = set_bit_1(temp_0, check_bit);
    //                 }
    //             }
    //         }
    //         std::cout << "cur:" << i << ":" << temp_0 << ":size:" << cur_need << std::endl;
    //         if (temp_0 > 0)
    //         {
    //             if (temp_0 > max_cur)
    //             {
    //                 max_cur = temp_0;
    //                 max_result = cur_need;
    //             }
    //             else if (temp_0 == max_cur)
    //             {
    //                 max_result = max(cur_need, max_result);
    //             }
    //         }
    //         else
    //         {
    //             while (win.size() > 0)
    //             {

    //                 int temp_index = win.front();
    //                 win.pop();
    //                 int pop_num = nums[temp_index];
    //                 int need_size = win.size();
    //                 int temp_0 = 0;
    //                 for (int check_bit = 0; check_bit < 22; check_bit++)
    //                 {
    //                     if (is_bit_1(pop_num, check_bit))
    //                     {
    //                         temp[check_bit]--;
    //                     }
    //                     if (temp[check_bit] == need_size)
    //                     {
    //                         temp_0 = set_bit_1(temp_0, check_bit);
    //                     }
    //                 }
    //                 std::cout << "out" << temp_index << ":" << temp_0 << ":size:" << need_size << std::endl;
    //                 if (temp_0 > 0)
    //                 {
    //                     if (temp_0 > max_cur)
    //                     {
    //                         max_cur = temp_0;
    //                         max_result = need_size;
    //                     }
    //                     else if (temp_0 == max_cur)
    //                     {
    //                         max_result = max(need_size, max_result);
    //                     }
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return max_result;
    // }
    int longestSubarray(vector<int> &nums)
    {
        // 单数的最大值
        // 两个的最大值
        int max_dan = 0;
        int max_shuang = 0;
        vector<int> shuang;
        for (int i = 0; i < nums.size(); i++)
        {
            max_dan = max(max_dan, nums[i]);
            if (i > 0)
            {
                if ((nums[i - 1] & nums[i]) > max_shuang)
                {
                    vector<int> te;
                    shuang = te;
                    shuang.push_back(i - 1);
                    max_shuang = (nums[i - 1] & nums[i]);
                }
                else if ((nums[i - 1] & nums[i]) == max_shuang)
                {
                    shuang.push_back(i - 1);
                }
            }
        }
        if (max_dan > max_shuang)
        {
            return 1;
        }
        int temp_len = 0;
        // std::cout << 11 ;
        int last_check = 0;
        for (int i = 0; i < shuang.size(); i++)
        {
            int start_len_index = shuang[i];
            int start = nums[start_len_index];
            int q = 1;
            if(start_len_index < last_check){
                continue;
            }
            // std::cout << "cout " << start_len_index ;
            while ((start >= max_shuang) && ((start_len_index + q) < nums.size()))
            {
                temp_len = max(temp_len, q);
                q++;
                // std::cout << "while" << start_len_index + q - 1 << ",";
                int next = nums[start_len_index + q - 1];
                start = start & next;
                last_check = start_len_index + q - 2;
            }
            if(start >= max_shuang){
                temp_len = max(temp_len, q);
            }
        }
        return temp_len;
    }
};
// @lc code=end
