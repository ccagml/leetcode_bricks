/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 *
 * https://leetcode.cn/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (58.80%)
 * Likes:    513
 * Dislikes: 0
 * Total Accepted:    65.3K
 * Total Submissions: 109.6K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * 给定一棵二叉树 root，返回所有重复的子树。
 *
 * 对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 *
 * 如果两棵树具有相同的结构和相同的结点值，则它们是重复的。
 *
 *
 *
 * 示例 1：
 *
 *
 *[1,2,3,4,null,2,4,null,null,4]\n[2,2,2,3,null,3,null]\n[ 2 ,1 ,2 ,null, null, 1, null]
 *
 * 输入：root = [1,2,3,4,null,2,4,null,null,4]
 * 输出：[[2,4],[4]]
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root = [2,1,1]
 * 输出：[[1]]
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：root = [2,2,2,3,null,3,null]
 *     2
 *   2  2
 * 3  3  3 3
 *  1  null 1 null 1 null 1 null
 * 输出：[[2,3],[3]]
 *
 *   2  1  2 null null 1 null
 * 提示：
 *
 *
 * 树中的结点数在[1,10^4]范围内。
 * -200 <= Node.val <= 200
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

// 思路不对 原本以为会相同层比较
// 思路不对,应该序列化成字符串比较,不是同层比较
// class Solution
// {
// public:
//     vector<TreeNode *> result;

//     bool is_same(TreeNode *root1, TreeNode *root2)
//     {
//         if (root1->val == root2->val)
//         {
//             bool left_same = true;
//             if (root1->left != nullptr && root2->left != nullptr)
//             {
//                 left_same = is_same(root1, root2);
//             }
//             else if (root1->left != nullptr && root2->left == nullptr)
//             {
//                 left_same = false;
//             }
//             else if (root1->left == nullptr && root2->left != nullptr)
//             {
//                 left_same = false;
//             }
//             bool right_same = true;
//             if (root1->right != nullptr && root2->right != nullptr)
//             {
//                 right_same = is_same(root1, root2);
//             }
//             else if (root1->right != nullptr && root2->right == nullptr)
//             {
//                 right_same = false;
//             }
//             else if (root1->right == nullptr && root2->right != nullptr)
//             {
//                 right_same = false;
//             }
//             return left_same && right_same;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
//     {
//         queue<TreeNode *> qt;
//         qt.push(root);
//         while (qt.size() > 0)
//         {
//             int n = qt.size();
//             vector<TreeNode *> temo_vt;
//             for (int i = 0; i < n; i++)
//             {
//                 TreeNode *tt = qt.front();
//                 qt.pop();
//                 temo_vt.push_back(tt);
//                 if (tt->left != nullptr)
//                 {
//                     qt.push(tt->left);
//                 }
//                 if (tt->right != nullptr)
//                 {
//                     qt.push(tt->right);
//                 }
//             }
//             unordered_set<int> usi_t;
//             for (int tvi = 0; tvi < temo_vt.size(); tvi++)
//             {
//                 for (int tvj = tvi + 1; tvj < temo_vt.size(); tvj++)
//                 {
 
//                     if (is_same(temo_vt[tvi], temo_vt[tvj]))
//                     {
//                         if (usi_t.count(tvi) == 0 && usi_t.count(tvj))
//                         {
//                             usi_t.insert(tvi);
//                             usi_t.insert(tvj);
//                             result.push_back(temo_vt[tvi]);
//                         }
//                         else
//                         {
//                             usi_t.insert(tvi);
//                             usi_t.insert(tvj);
//                         }
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };
// 思路不对,应该序列化成字符串比较,不是同层比较
class Solution
{
public:
    vector<TreeNode *> result;
    unordered_map<string, int> us;
    
    string is_same(TreeNode *root1)
    {
        if(root1 == nullptr){
            return "null";
        }
        string temp = "";
        temp += ("(" + std::to_string(root1->val));
        temp += ("(left" + is_same(root1->left) + ")");
        temp += ("(right" + is_same(root1->right) + "))");
        us[temp] ++;
        if(us[temp] == 2){
            result.push_back(root1);
        }
        return temp;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        is_same(root);
        return result;
    }
};

// @lc code=end
