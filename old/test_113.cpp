/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (62.76%)
 * Likes:    612
 * Dislikes: 0
 * Total Accepted:    189.6K
 * Total Submissions: 302.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点总数在范围 [0, 5000] 内
 * -1000 
 * -1000 
 * 
 * 
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

class Solution
{
    vector<vector<int>> result;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> cur;
        dfs(root, targetSum, cur);
        return result;
    }
    void dfs(TreeNode *root, int targetSum, vector<int>& cur)
    {
        if (root == nullptr)
        {
            return;
        }
        targetSum -= root->val;
        if (targetSum == 0)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                vector<int> temp;
                for (int i = 0; i < cur.size(); i++)
                {
                    temp.push_back(cur[i]);
                }
                temp.push_back(root->val);
                result.push_back(temp);
                return;
            }
        }
        if(root->left != nullptr){
            cur.push_back(root->val);
            dfs(root->left, targetSum, cur);
            cur.pop_back();
        }
        if (root->right != nullptr)
        {
            cur.push_back(root->val);
            dfs(root->right, targetSum, cur);
            cur.pop_back();
        }
    }
};
// @lc code=end
