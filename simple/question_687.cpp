/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode.cn/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (45.38%)
 * Likes:    642
 * Dislikes: 0
 * Total Accepted:    58.7K
 * Total Submissions: 127K
 * Testcase Example:  '[5,4,5,1,1,null,5]'
 *
 * 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
 *
 * 两个节点之间的路径长度 由它们之间的边数表示。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入：root = [5,4,5,1,1,5]
 * 输出：2
 *
 *
 * 示例 2:
 *
 *
 *
 *
 * 输入：root = [1,4,5,4,4,5]
 * 输出：2
 *
 *
 *
 *
 * 提示:
 *
 *
 * 树的节点数的范围是 [0, 10^4] 
 * -1000 <= Node.val <= 1000
 * 树的深度将不超过 1000 
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

// [5,
// 4,5,
// 1,1,5]

class Solution
{
public:
    int result;

    int check_all(TreeNode *root, int fa)
    {
        int rv = root->val;
        int left = 0;
        int temp_max = 0;
        if (root->left != nullptr)
        {
            left = check_all(root->left, rv);
            temp_max += left;
        }
        int right = 0;
        if (root->right != nullptr)
        {
            right = check_all(root->right, rv);
            temp_max += right;
        }
        // std::cout << "当前" << root->val << ":fa:" << fa <<  ":left:" << left <<  ":right:" << right << std::endl;
        result = max(result, temp_max);
        return (root->val == fa) ? max(left, right) + 1 : 0;
    }
    int longestUnivaluePath(TreeNode *root)
    {
        result = 0;
        if (root == nullptr)
        {
            return 0;
        }
        check_all(root, root->val);
        return result;
    }
};
// @lc code=end
