/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 *
 * https://leetcode.cn/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (65.84%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 20.9K
 * Testcase Example:  '["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]'
 *
 * 完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
 * 
 * 设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。
 * 
 * 实现 CBTInserter 类:
 * 
 * 
 * CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
 * CBTInserter.insert(int v)  向树中插入一个值为 Node.val == val的新节点
 * TreeNode。使树保持完全二叉树的状态，并返回插入节点 TreeNode 的父节点的值；
 * CBTInserter.get_root() 将返回树的头节点。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入
 * ["CBTInserter", "insert", "insert", "get_root"]
 * [[[1, 2]], [3], [4], []]
 * 输出
 * [null, 1, 2, [1, 2, 3, 4]]
 * 
 * 解释
 * CBTInserter cBTInserter = new CBTInserter([1, 2]);
 * cBTInserter.insert(3);  // 返回 1
 * cBTInserter.insert(4);  // 返回 2
 * cBTInserter.get_root(); // 返回 [1, 2, 3, 4]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数量范围为 [1, 1000] 
 * 0 <= Node.val <= 5000
 * root 是完全二叉树
 * 0 <= val <= 5000 
 * 每个测试用例最多调用 insert 和 get_root 操作 10^4 次
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
class CBTInserter {
public:
    std::vector<TreeNode*> vt;
    int n = 0 ;
    CBTInserter(TreeNode* root) {
        vt.push_back(new TreeNode());
        std::queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            TreeNode* fir = qt.front();
            qt.pop();
            vt.push_back(fir);
            n++;
            if(fir->left != nullptr){
                qt.push(fir->left);
            }
            if(fir->right != nullptr){
                qt.push(fir->right);
            }
        }
        // std::cout << "init n:"<< n << ",size:" << vt.size() << std::endl;
    }
    
    int insert(int val) {
        TreeNode* new_t = new TreeNode(val);
        vt.push_back(new_t);
        n++;
        int next_index = n;
        int father = next_index / 2;
        if(father * 2 == next_index ){
            // left
            vt[father]->left = new_t;
        }else if((father * 2 + 1) == next_index){
            //right
            vt[father]->right = new_t;
        }
        return vt[father]->val;
    }
    
    TreeNode* get_root() {
        return vt[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

