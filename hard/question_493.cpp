/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 *
 * https://leetcode.cn/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (35.81%)
 * Likes:    372
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 96.7K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
 *
 * 你需要返回给定数组中的重要翻转对的数量。
 *
 * 示例 1:
 *
 *
 * 输入: [1,3,2,3,1]
 * 输出: 2
 *
 *
 * 示例 2:
 *
 *
 * 输入: [2,4,3,5,1]
 * 输出: 3
 *
 *
 * 注意:
 *
 *
 * 给定数组的长度不会超过50000。
 * 输入数组中的所有数字都在32位整数的表示范围内。
 *
 *
 */

// @lc code=start
// 从后往前找
// 想不到的点: 1离散化:把值按大小顺序排到vector中, 这时候查找的点从值范围变成索引
// 想不到的点: 2 set 的 lower_bound 会比vector 的lower_bound 慢
class Solution
{
public:
    class Node
    {
    public:
        Node *ls;
        Node *rs;
        long long val;
    };
    int temp_cnt = 0;
    void my_update(Node *node, long long range_left, long long range_right, long long index, int add_v)
    {
        temp_cnt++;
        node->val += add_v;
        // std::cout << "(up" << range_left << ":" << range_right << ":" << index << ")";
        if (range_left == range_right)
        {
            return;
        }
        long long mid = (range_left + range_right) / 2;
        if (index <= mid)
        {
            if (node->ls == nullptr)
            {
                node->ls = new Node();
            }
            my_update(node->ls, range_left, mid, index, add_v);
        }
        else
        {
            if (node->rs == nullptr)
            {
                node->rs = new Node();
            }
            my_update(node->rs, mid + 1, range_right, index, add_v);
        }
    }
    int my_query(Node *node, long long range_left, long long range_right, long long left, long long right)
    {
        if (node == nullptr)
        {

            return 0;
        }
        if (right < range_left || left > range_right)
        {
            // std::cout << "(0q" << range_left << ":" << range_right << ":" << left << ":" << right << ")";
            return 0;
        }
        // 点的范围在查询的范围内
        if (range_left >= left && range_right < right)
        {
            // std::cout << "(1q" << node->val << ":" << range_left << ":" << range_right << ":" << left << ":" << right << ")";
            return node->val;
        }
        long long mid = (range_left + range_right) / 2;
        return my_query(node->ls, range_left, mid, left, right) + my_query(node->rs, mid + 1, range_right, left, right);
    }

    int reversePairs(vector<int> &nums)
    {
        int result = 0;
        Node *root = new Node();

        set<int> si;
        for (int i = 0; i < nums.size(); i++)
        {
            si.insert(nums[i]);
        }
        si.insert(-__INT_MAX__);
        si.insert(__INT_MAX__);
        vector<int> all;
        unordered_map<int, int> um_value_index;
        for (int i : si)
        {
            um_value_index[i] = all.size();
            all.push_back(i);
        }

        my_update(root, 0, si.size(), 0, 0);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int need = nums[i] / 2;
            if (nums[i] % 2 == 1)
            {
                if (nums[i] >= 0)
                {
                    need++;
                }
                else
                {
                    need--;
                }
            }
            auto lower = lower_bound(all.begin(), all.end(), need);
            int index = 0;
            if (lower != all.end())
            {
                index = std::distance(all.begin(), lower);
            }
            else
            {
                index = all.size();
            }

            int temp_q = my_query(root, 0, si.size(), 0, index);
            result += temp_q;
            std::cout << "当前" << nums[i] << "需要小于" << need << ":" << index << ":" << um_value_index[index] << "|" << temp_q << std::endl;
            my_update(root, 0, si.size(), um_value_index[nums[i]], 1);
        }
        return result;
    }
};
// @lc code=end
