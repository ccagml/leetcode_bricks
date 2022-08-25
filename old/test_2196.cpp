/*
 * @lc app=leetcode.cn id=2196 lang=cpp
 *
 * [2196] 根据描述创建二叉树
 *
 * https://leetcode-cn.com/problems/create-binary-tree-from-descriptions/description/
 *
 * algorithms
 * Medium (71.76%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 7.1K
 * Testcase Example:  '[[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]'
 *
 * 给你一个二维整数数组 descriptions ，其中 descriptions[i] = [parenti, childi, isLefti] 表示
 * parenti 是 childi 在 二叉树 中的 父节点，二叉树中各节点的值 互不相同 。此外：
 * 
 * 
 * 如果 isLefti == 1 ，那么 childi 就是 parenti 的左子节点。
 * 如果 isLefti == 0 ，那么 childi 就是 parenti 的右子节点。
 * 
 * 
 * 请你根据 descriptions 的描述来构造二叉树并返回其 根节点 。
 * 
 * 测试用例会保证可以构造出 有效 的二叉树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
 * 输出：[50,20,80,15,17,19]
 * 解释：根节点是值为 50 的节点，因为它没有父节点。
 * 结果二叉树如上图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：descriptions = [[1,2,1],[2,3,0],[3,4,1]]
 * 输出：[1,2,null,null,3,4]
 * 解释：根节点是值为 1 的节点，因为它没有父节点。 
 * 结果二叉树如上图所示。 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= descriptions.length <= 10^4
 * descriptions[i].length == 3
 * 1 <= parenti, childi <= 10^5
 * 0 <= isLefti <= 1
 * descriptions 所描述的二叉树是一棵有效二叉树
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> source_fa;
        unordered_map<int, TreeNode*> node_map;
        for(int i = 0; i < descriptions.size(); i++){
            int fa = descriptions[i][0];
            int cur = descriptions[i][1];
            int is_left = descriptions[i][2];
            TreeNode* fa_node;
            TreeNode* cur_node;
            if (node_map.count(fa) > 0){
                fa_node = node_map[fa];
            }else{
                fa_node = new TreeNode(fa);
                node_map[fa] = fa_node;
            }
            if (node_map.count(cur) > 0){
                cur_node = node_map[cur];
            }else{
                cur_node = new TreeNode(cur);
                node_map[cur] = cur_node;
            }
            if(is_left){
                fa_node->left = cur_node;
            }else{
                fa_node->right = cur_node;
            }
            source_fa[cur] = fa;
        }
        for(pair<int, TreeNode*> pp:node_map){
            if(source_fa.count(pp.first) == 0 ){
                return pp.second;
            }
        }
        return new TreeNode();
    }
};

// @lc code=end

