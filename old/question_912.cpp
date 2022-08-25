/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    428
 * Dislikes: 0
 * Total Accepted:    248.7K
 * Total Submissions: 445.9K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int mid = quick_sort(nums, start, end);
        quick_sort(nums, 0, mid-1);
        quick_sort(nums, mid + 1, end);
        return nums;
    }
    int quick_sort(vector<int> &nums, int start, int end)
    {
        int cut_value = nums[start];
        while (start < end)
        {
            while (start < end && nums[end] >= cut_value)
            {
                --end;
            }
            nums[start] = nums[end];
            while (start < end && nums[start] <= cut_value)
            {
                ++start;
            }
            nums[end] = nums[start];
        }
        nums[start] = cut_value;
        return start;
    }
};
// @lc code=end
