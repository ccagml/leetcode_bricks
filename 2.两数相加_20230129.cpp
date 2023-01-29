/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=21301
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (42.32%)
 * Likes:    9124
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.8M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 *
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 *
 *
 * 示例 1：
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 *
 * 示例 2：
 *
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
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
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> vi;
        int temp = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int cur = temp;
            if (l1 != nullptr && l2 != nullptr)
            {
                cur += (l1->val + l2->val);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 != nullptr)
            {
                cur += (l1->val);
                l1 = l1->next;
            }
            else if (l2 != nullptr)
            {
                cur += (l2->val);
                l2 = l2->next;
            }

            if (cur >= 10)
            {
                temp = 1;
            }
            else
            {
                temp = 0;
            }
            vi.push_back(cur % 10);
        }
        if (temp == 1)
        {
            vi.push_back(1);
        }
        ListNode *result = new ListNode(vi[0]);
        ListNode *head = result;
        for (int i = 1; i < vi.size(); i++)
        {
            head->next = new ListNode(vi[i]);
            head = head->next;
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
