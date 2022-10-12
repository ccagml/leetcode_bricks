/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 *
 * https://leetcode.cn/problems/linked-list-components/description/
 *
 * algorithms
 * Medium (61.11%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    34.8K
 * Total Submissions: 56.9K
 * Testcase Example:  '[0,1,2,3]\n[0,1,3]'
 *
 * 给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。同时给定列表 nums，该列表是上述链表中整型值的一个子集。
 *
 * 返回列表 nums 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 nums 中）构成的集合。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: head = [0,1,2,3], nums = [0,1,3]
 * 输出: 2
 * 解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回
 * 2。
 *
 * 示例 2：
 *
 *
 *
 * 输入: head = [0,1,2,3,4], nums = [0,3,1,4]
 * 输出: 2
 * 解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数为n
 * 1 <= n <= 10^4
 * 0 <= Node.val < n
 * Node.val 中所有值 不同
 * 1 <= nums.length <= n
 * 0 <= nums[i] < n
 * nums 中所有值 不同
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> usi;
        for (int i = 0; i < nums.size(); i++)
        {
            usi.insert(nums[i]);
        }
        bool start = false;
        int result = 0;
        while (head != nullptr)
        {
            if (usi.count(head->val) > 0)
            {
                if (!start)
                {
                    result++;
                    start = true;
                }
            }
            else
            {
                start = false;
            }
            head = head->next;
        }
        return result;
    }
};
// @lc code=end
