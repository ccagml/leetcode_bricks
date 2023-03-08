/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=21801
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (42.35%)
 * Likes:    9312
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 3.9M
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
        ListNode *result = new ListNode(0);
        ListNode *temp = result;

        int flag = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int new_v = l1->val + l2->val + flag;
            if (new_v >= 10)
            {
                flag = 1;
                new_v %= 10;
            }
            else
            {
                flag = 0;
            }
            temp->next = new ListNode(new_v);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }

        while (l1 != nullptr)
        {
            int new_v = l1->val + flag;
            if (new_v >= 10)
            {
                flag = 1;
                new_v %= 10;
            }
            else
            {
                flag = 0;
            }
            temp->next = new ListNode(new_v);
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2 != nullptr)
        {
            int new_v = l2->val + flag;
            if (new_v >= 10)
            {
                flag = 1;
                new_v %= 10;
            }
            else
            {
                flag = 0;
            }
            temp->next = new ListNode(new_v);
            l2 = l2->next;
            temp = temp->next;
        }
        if (flag > 0)
        {
            temp->next = new ListNode(flag);
        }
        return result->next;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

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
