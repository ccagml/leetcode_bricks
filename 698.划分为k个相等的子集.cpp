/*
 * @lc app=leetcode.cn id=698 lang=cpp
 * @lcpr version=20701
 *
 * [698] 划分为k个相等的子集
 *
 * https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (42.57%)
 * Likes:    868
 * Dislikes: 0
 * Total Accepted:    92K
 * Total Submissions: 216.2K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 *
 *
 *
 * 示例 1：
 *
 * 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 *
 * 示例 2:
 *
 * 输入: nums = [1,2,3,4], k = 3
 * 输出: false
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= len(nums) <= 16
 * 0 < nums[i] < 10000
 * 每个元素的频率在 [1,4] 范围内
 *
 *
 */

using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// @lc code=start
class Solution
{
public:
    unordered_map<int, bool> all;
    int need = 0;
    vector<int> nnn;

    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }

    void dfs(int cur_index, int cur_flag, int cur_value)
    {
        if (cur_index >= nnn.size())
        {
            return;
        }
        if (cur_value > need)
        {
            return;
        }
        int has_cur_flag = set_bit_1(cur_flag, cur_index);
        int has_cur_value = cur_value + nnn[cur_index];

        if (cur_value < need)
        {
            dfs(cur_index + 1, cur_flag, cur_value);
        }
        if (has_cur_value == need)
        {
            all[has_cur_flag] = true;
        }
        else if (has_cur_value < need)
        {
            dfs(cur_index + 1, has_cur_flag, has_cur_value);
        }
    }

    vector<int> vi;
    int value_need = 0;
    int kkk;
    bool get_result(int all_index, int cur_flag, int cur_k)
    {
        if (cur_k == kkk && cur_flag == value_need)
        {
            return true;
        }
        if (cur_k == kkk)
        {

            return false;
        }
        for (int i = all_index; i < vi.size(); i++)
        {
            int index_flag = vi[i];
            if ((index_flag & cur_flag) == 0)
            {

                bool temp = get_result(i + 1, (index_flag | cur_flag), cur_k + 1);
                // std::cout << all_index << ":" << cur_flag << ":" << cur_k << ":i:" << i << "temp:" << temp << std::endl;
                if (temp)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        nnn = nums;
        kkk = k;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            value_need = set_bit_1(value_need, i);
        }
        if (sum % k != 0)
        {
            return false;
        }
        need = sum / k;
        dfs(0, 0, 0);
        for (pair<int, bool> pib : all)
        {
            vi.push_back(pib.first);
        }
        return get_result(0, 0, 0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4, 3, 2, 3, 5, 2, 1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n3\n
// @lcpr case=end

 */
