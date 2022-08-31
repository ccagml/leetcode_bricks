/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
 *
 * https://leetcode.cn/problems/reverse-nodes-in-even-length-groups/description/
 *
 * algorithms
 * Medium (43.98%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    5.4K
 * Total Submissions: 12.3K
 * Testcase Example:  '[5,2,6,3,9,1,7,3,8,4]'
 *
 * 给你一个链表的头节点 head 。
 *
 * 链表中的节点 按顺序 划分成若干 非空 组，这些非空组的长度构成一个自然数序列（1, 2, 3, 4, ...）。一个组的 长度
 * 就是组中分配到的节点数目。换句话说：
 *
 *
 * 节点 1 分配给第一组
 * 节点 2 和 3 分配给第二组
 * 节点 4、5 和 6 分配给第三组，以此类推
 *
 *
 * 注意，最后一组的长度可能小于或者等于 1 + 倒数第二组的长度 。
 *
 * 反转 每个 偶数 长度组中的节点，并返回修改后链表的头节点 head 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [5,2,6,3,9,1,7,3,8,4]
 * 输出：[5,6,2,3,9,1,4,8,3,7]
 * 解释：
 * - 第一组长度为 1 ，奇数，没有发生反转。
 * - 第二组长度为 2 ，偶数，节点反转。
 * - 第三组长度为 3 ，奇数，没有发生反转。
 * - 最后一组长度为 4 ，偶数，节点反转。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,1,0,6]
 * 输出：[1,0,1,6]
 * 解释：
 * - 第一组长度为 1 ，没有发生反转。
 * - 第二组长度为 2 ，节点反转。
 * - 最后一组长度为 1 ，没有发生反转。
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：head = [2,1]
 * 输出：[2,1]
 * 解释：
 * - 第一组长度为 1 ，没有发生反转。
 * - 最后一组长度为 1 ，没有发生反转。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目范围是 [1, 10^5]
 * 0 <= Node.val <= 10^5
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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        unordered_map<int, vector<ListNode *>> uivl;
        ListNode *temp_head = head;
        int start = 0;
        while (temp_head != nullptr)
        {
            if(uivl[start].size() < start){
                uivl[start].push_back(temp_head);
                // std::cout << "(" << start << ":" << temp_head->val << ")";
            }else{
                start++;
                // std::cout <<  "\n(" <<  start << ":" << temp_head->val  << ")";
                uivl[start].push_back(temp_head);
            }
            ListNode *next = temp_head->next;
            temp_head->next = nullptr;
            temp_head = next;
        }
        ListNode *result = head;
        for(int i = 2; i < 100000; i++){
            if(uivl.count(i) > 0 && uivl[i].size() > 0){
                if(uivl[i].size() % 2 == 0){
                    // 反
                    for(int j = uivl[i].size() - 1; j >= 0; j--){
                        head->next = uivl[i][j];
                        head = head->next;
                    }
                }else{
                    // 拼
                    for(int j = 0; j < uivl[i].size(); j++){
                        head->next = uivl[i][j];
                        head = head->next;
                    }
                }
            }else{
                break;
            }
        }
        return result;
    }
};
// @lc code=end
