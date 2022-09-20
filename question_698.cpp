/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 *
 * https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    735
 * Dislikes: 0
 * Total Accepted:    70K
 * Total Submissions: 168K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 *
 * 示例 2:
 *
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
 *[4,4,8,1,8,6,4,1,6,8,4,2,7,5,1,9]\n13\n[1,2,3,4]\n3\n[4, 3, 2, 3, 5, 2, 1]\n4\n
 */

// @lc code=start
// 数据长度才16.可能需要一个数据标记位代表选取,状态压缩
// 会超时
/*
Time Limit Exceeded
162/162 cases passed (N/A)

*/
class Solution
{
public:
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }

    unordered_map<int, int> status_value;
    void dfs(vector<int> &nums, int index, int status, int val)
    {
        if (index >= nums.size())
        {
            return;
        }
        int old_val = val;
        int new_status = set_bit_1(status, index);
        int new_val = val + nums[index];
        status_value[status] = val;
        status_value[new_status] = new_val;
        dfs(nums, index + 1, status, val);
        dfs(nums, index + 1, new_status, new_val);
    }

    bool check(vector<int> &wait_check, int index, int status, int cur_num)
    {
        if (status == key_status && cur_num == key_k)
        {
            return true;
        }
        int need = key_k - cur_num;
        if (wait_check.size() - index < need)
        {
            return false;
            ;
        }
        if (index >= wait_check.size())
        {
            return false;
        }
        int index_status = wait_check[index];
        if ((index_status & status) == 0)
        {
            // 可选
            int new_status = status | index_status;
            if (check(wait_check, index + 1, new_status, cur_num + 1))
            {
                return true;
            }
        }
        if (check(wait_check, index + 1, status, cur_num))
        {
            return true;
        }
        return false;
    }

    int key_status = 0;
    int key_k = 0;
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        key_k = k;
        int all = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            key_status = set_bit_1(key_status, i);
            all += nums[i];
        }
        dfs(nums, 0, 0, 0);
        status_value.erase(0);
        unordered_map<int, vector<int>> uiusi;
        for (pair<int, int> pii : status_value)
        {
            // if(uiusi.count(pii.second) < 1){
            //     unordered_set<int> usi;
            //     uiusi[pii.second] = usi;
            // }
            uiusi[pii.second].push_back(pii.first);
        }

        // for (pair<int, vector<int>> pivi : uiusi)
        // {
        //     if (pivi.second.size() >= k)
        //     {
        //         if (check(pivi.second, 0, 0, 0))
        //         {
        //             return true;
        //         }
        //     }
        // }
        // 所有值分成k份
        return check(uiusi[all / k], 0, 0, 0);
    }
};
// @lc code=end
