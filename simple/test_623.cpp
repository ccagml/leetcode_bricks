/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 *
 * https://leetcode.cn/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (54.93%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 38.2K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * 给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth 处添加一个值为 val 的节点行。
 * 
 * 注意，根节点 root 位于深度 1 。
 * 
 * 加法规则如下:
 * 
 * 
 * 给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val 的树节点作为 cur
 * 的左子树根和右子树根。
 * cur 原来的左子树应该是新的左子树根的左子树。
 * cur 原来的右子树应该是新的右子树根的右子树。
 * 如果 depth == 1 意味着 depth - 1 根本没有深度，那么创建一个树节点，值 val
 * 作为整个原始树的新根，而原始树就是新根的左子树。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [4,2,6,3,1,5], val = 1, depth = 2
 * 输出: [4,1,1,2,null,null,6,3,1,5]
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: root = [4,2,null,3,1], val = 1, depth = 3
 * 输出:  [4,2,null,1,1,3,null,null,1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 节点数在 [1, 10^4] 范围内
 * 树的深度在 [1, 10^4]范围内
 * -100 <= Node.val <= 100
 * -10^5 <= val <= 10^5
 * 1 <= depth <= the depth of tree + 1
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
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* result = new TreeNode(val);
            result->left = root;
            return result;
        }
        int cur_level = depth - 1;
        queue<TreeNode*> qt;
        qt.push(root);
        int root_level = 0;
        while(!qt.empty()){
            root_level++;
            int qt_level_size = qt.size();
            for(int i = 0; i < qt_level_size; i++){
                TreeNode* temp = qt.front();
                qt.pop();
                if(root_level < cur_level){
                    if(temp->left != nullptr){
                        qt.push(temp->left);
                    }
                    if(temp->right != nullptr){
                        qt.push(temp->right);
                    }
                }else if(root_level == cur_level){
                    TreeNode* new_left = new TreeNode(val);
                    TreeNode* new_right = new TreeNode(val);
                    if(temp->left != nullptr){
                        new_left->left = temp->left;
                    }
                    if(temp->right != nullptr){
                        new_right->right = temp->right;
                    }
                    temp->left = new_left;
                    temp->right = new_right;
                }
            }
        }
    return root;
    }
};
// @lc code=end

