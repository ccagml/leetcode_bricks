/*
 * @lc app=leetcode.cn id=剑指 Offer 51 lang=cpp
 * @lcpr version=21104
 *
 * [剑指 Offer 51] 数组中的逆序对
 *
 * https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
 *
 * LCOF
 * Hard (49.64%)
 * Likes:    920
 * Dislikes: 0
 * Total Accepted:    180.3K
 * Total Submissions: 363.3K
 * Testcase Example:  '[7,5,6,4]'
 *
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [7,5,6,4]
 * 输出: 5
 *
 *
 *
 * 限制：
 *
 * 0 <= 数组长度 <= 50000
 *
 */

// @lc code=start
class Solution
{
public:
    int result;
    void merge(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = (left + right) / 2;
        merge(nums, left, mid);
        merge(nums, mid + 1, right);
        // 计算逆序对
        int left_start = left;
        int right_start = mid + 1;
        for (int right_start = mid + 1; right_start <= right; right_start++)
        {
            // [4, 5, 6] [1, 2]
            // 如果 左边值比右边打 那么就有 左边剩余
            int right_value = nums[right_start];
            while (left_start <= mid && nums[left_start] <= right_value)
            {
                left_start++;
            }
            if (left_start > mid)
            {
                break;
            }
            // 对于right_value 有
            int right_value_left_cnt = mid - left_start + 1;
            // std::cout << "(" << left << ":" << right << ":" << right_start << "+" << right_value_left_cnt << ")";
            result += right_value_left_cnt;
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        // std::cout << "(" << left << ":" << right << ":排序后";
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     std::cout << nums[i] << ",";
        // }
        // std::cout << "结果" << std::endl;
    }
    int reversePairs(vector<int> &nums)
    {
        result = 0;
        merge(nums, 0, nums.size() - 1);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,5,6,4]
// @lcpr case=end

// @lcpr case=start
// [1,3,2,3,1]
// @lcpr case=end

 */
