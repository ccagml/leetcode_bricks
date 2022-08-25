/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] 感染二叉树需要的总时间
 *
 * https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/description/
 *
 * algorithms
 * Medium (45.07%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 12.6K
 * Testcase Example:  '[1,5,3,null,4,10,6,9,2]\n3'
 *
 * 给你一棵二叉树的根节点 root ，二叉树中节点的值 互不相同 。另给你一个整数 start 。在第 0 分钟，感染 将会从值为 start
 * 的节点开始爆发。
 *
 * 每分钟，如果节点满足以下全部条件，就会被感染：
 *
 *
 * 节点此前还没有感染。
 * 节点与一个已感染节点相邻。
 *
 *
 * 返回感染整棵树需要的分钟数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [1,5,3,null,4,10,6,9,2], start = 3
 * 输出：4
 * 解释：节点按以下过程被感染：
 * - 第 0 分钟：节点 3
 * - 第 1 分钟：节点 1、10、6
 * - 第 2 分钟：节点5
 * - 第 3 分钟：节点 4
 * - 第 4 分钟：节点 9 和 2
 * 感染整棵树需要 4 分钟，所以返回 4 。
 *
 *
 * 示例 2：
 *
 * 输入：root = [1], start = 1
 * 输出：0
 * 解释：第 0 分钟，树中唯一一个节点处于感染状态，返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
 * 每个节点的值 互不相同
 * 树中必定存在值为 start 的节点
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// 模拟 dfs树遍历 
class Solution
{
public:
    // 记录每个点的爸爸
    unordered_map<int, TreeNode *> umit;
    unordered_map<int, int> u_father;
    unordered_set<int> us;
    int amountOfTime(TreeNode *root, int start)
    {
        int result = -1;
        dfs(root, 0);
        queue<int> qi;
        qi.push(start);
        us.insert(start);
        while (qi.size() > 0)
        {
            result++;
            int qi_s = qi.size();
            for (int i = 0; i < qi_s; i++)
            {
                int temp = qi.front();
                qi.pop();
                if (u_father[temp] > 0 && us.count(u_father[temp]) < 1)
                {
                    qi.push(u_father[temp]);
                    us.insert(u_father[temp]);
                }
                if (umit[temp]->left != nullptr)
                {
                    if (us.count(umit[temp]->left->val) < 1)
                    {
                        qi.push(umit[temp]->left->val);
                        us.insert(umit[temp]->left->val);
                    }
                }
                if (umit[temp]->right != nullptr)
                {
                    if (us.count(umit[temp]->right->val) < 1)
                    {
                        qi.push(umit[temp]->right->val);
                        us.insert(umit[temp]->right->val);
                    }
                }
            }
        }
        return result;
    }
    void dfs(TreeNode *root, int father)
    {
        umit[root->val] = root;
        u_father[root->val] = father;
        if (root->left != nullptr)
        {
            dfs(root->left, root->val);
        }
        if (root->right != nullptr)
        {
            dfs(root->right, root->val);
        }
    }
};
// @lc code=end
