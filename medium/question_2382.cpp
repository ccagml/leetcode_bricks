/*
 * @lc app=leetcode.cn id=2382 lang=cpp
 *
 * [2382] 删除操作后的最大子段和
 *
 * https://leetcode.cn/problems/maximum-segment-sum-after-removals/description/
 *
 * algorithms
 * Hard (50.10%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 4.6K
 * Testcase Example:  '[1,2,5,6,1]\n[0,3,2,4,1]'
 *
 * 给你两个下标从 0 开始的整数数组 nums 和 removeQueries ，两者长度都为 n 。对于第 i 个查询，nums 中位于下标
 * removeQueries[i] 处的元素被删除，将 nums 分割成更小的子段。
 *
 * 一个 子段 是 nums 中连续 正 整数形成的序列。子段和 是子段中所有元素的和。
 *
 * 请你返回一个长度为 n 的整数数组 answer ，其中 answer[i]是第 i 次删除操作以后的 最大 子段和。
 *
 * 注意：一个下标至多只会被删除一次。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
 * 输出：[14,7,2,2,0]
 * 解释：用 0 表示被删除的元素，答案如下所示：
 * 查询 1 ：删除第 0 个元素，nums 变成 [0,2,5,6,1] ，最大子段和为子段 [2,5,6,1] 的和 14 。
 * 查询 2 ：删除第 3 个元素，nums 变成 [0,2,5,0,1] ，最大子段和为子段 [2,5] 的和 7 。
 * 查询 3 ：删除第 2 个元素，nums 变成 [0,2,0,0,1] ，最大子段和为子段 [2] 的和 2 。
 * 查询 4 ：删除第 4 个元素，nums 变成 [0,2,0,0,0] ，最大子段和为子段 [2] 的和 2 。
 * 查询 5 ：删除第 1 个元素，nums 变成 [0,0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
 * 所以，我们返回 [14,7,2,2,0] 。
 *
 * 示例 2：
 *
 * 输入：nums = [3,2,11,1], removeQueries = [3,2,1,0]
 * 输出：[16,5,3,0]
 * 解释：用 0 表示被删除的元素，答案如下所示：
 * 查询 1 ：删除第 3 个元素，nums 变成 [3,2,11,0] ，最大子段和为子段 [3,2,11] 的和 16 。
 * 查询 2 ：删除第 2 个元素，nums 变成 [3,2,0,0] ，最大子段和为子段 [3,2] 的和 5 。
 * 查询 3 ：删除第 1 个元素，nums 变成 [3,0,0,0] ，最大子段和为子段 [3] 的和 3 。
 * 查询 5 ：删除第 0 个元素，nums 变成 [0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
 * 所以，我们返回 [16,5,3,0] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums.length == removeQueries.length
 * 1 <= n <= 10^5
 * 1 <= nums[i] <= 10^9
 * 0 <= removeQueries[i] < n
 * removeQueries 中所有数字 互不相同 。
 *
 *
 */

// @lc code=start
// 2136
class uf
{
    vector<int> uii_father;
    vector<long long> uii_score;
    long long max_score = 0;
    public:
    uf(int n, vector<int> &nums)
    {
        for (int i = 0; i < n; i++)
        {
            uii_father.push_back(i);
            uii_score.push_back(nums[i]);
        }
    }
    int get_father(int id)
    {
        if (uii_father[id] == id)
        {
            return id;
        }
        uii_father[id] = get_father(uii_father[id]);
        return uii_father[id];
    }

    // 合并两个爸爸
    void merge(int id, int id_2)
    {
        int id_fa = get_father(id);
        int id_fa2 = get_father(id_2);
        if (id_fa > id_fa2)
        {
            uii_father[id_fa] = id_fa2;
            uii_score[id_fa2] += uii_score[id_fa];
            max_score = max(max_score, uii_score[id_fa2]);
        }
        else if (id_fa == id_fa2)
        {
            max_score = max(max_score, uii_score[id_fa]);
        }
        else
        {
            uii_father[id_fa2] = id_fa;
            uii_score[id_fa] += uii_score[id_fa2];
            max_score = max(max_score, uii_score[id_fa]);
        }
    }
    long long get_max_score()
    {
        return max_score;
    }
};

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
    {
        int n = nums.size();
        uf* my_uf = new uf(n, nums);
        unordered_set<int> usi; // 已恢复的,用来判断要不要跟左右合并
        vector<long long> result(n);
        for (int i = removeQueries.size() - 2; i >= 0; i--)
        {
            int add_index = removeQueries[i + 1];
            usi.insert(add_index);
            my_uf->merge(add_index, add_index);
            if (usi.count(add_index + 1) > 0)
            {
                my_uf->merge(add_index, add_index + 1);
            }
            if (usi.count(add_index - 1) > 0)
            {
                my_uf->merge(add_index, add_index - 1);
            }
            result[i] = my_uf->get_max_score();
        }
        return result;
    }
};
// @lc code=end
