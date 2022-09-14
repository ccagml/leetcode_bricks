/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (44.39%)
 * Likes:    655
 * Dislikes: 0
 * Total Accepted:    73.2K
 * Total Submissions: 164.8K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
 *
 * 注意 这个数列必须是 严格 递增的。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 *
 *
 * 示例 2:
 *
 *
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 *
 *
 * [1,3,5,4,7]\n[2,2,2,2,2]\n[2,2,2,2,12]\n[2,2,123,124,15,125,1,23,-41,-2,2,2]\n[2,1]
 * 提示: 
 *
 *
 *
 *
 * 1 <= nums.length <= 2000
 * -10^6 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start
// 动态规划的东西
// [2,2,2,2] 例子调了一会, 当长度是1的时候,相同值也要累加
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        // vi[7] = {长度,数量}
        // vi[7][2] = 数量
        map<int, pair<int, int>> uipii;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur_num = nums[i];
            int new_len = uipii[cur_num].first;
            int new_num = uipii[cur_num].second;
            for (auto &[ol_num, pii] : uipii)
            {
                // std::cout << ol_num << ":" << cur_num << std::endl;
                if (ol_num < cur_num)
                {
                    int old_len = pii.first + 1;
                    int old_num = pii.second;
                    if (old_len > new_len)
                    {
                        new_len = old_len;
                        new_num = old_num;
                    }
                    else if (old_len == new_len)
                    {
                        new_num += old_num;
                    }
                } else if(ol_num == cur_num){
                    if(new_len == 1){
                        new_num++;
                    }
                }
            }

            // std::cout << "(" <<  i << ":" << cur_num << ":" << new_len << ":" << new_num << ")";
            uipii[cur_num] = {max(new_len, 1), max(new_num, 1)};
        }
        int new_len = 1;
        int new_num = 1;
        for (auto &&[ol_num, pii] : uipii)
        {
            int old_len = pii.first + 1;
            int old_num = pii.second;
            if (old_len > new_len)
            {
                new_len = old_len;
                new_num = old_num;
            }
            else if (old_len == new_len)
            {
                new_num += old_num;
            }
        }

        return new_num;
    }
};
// @lc code=end
