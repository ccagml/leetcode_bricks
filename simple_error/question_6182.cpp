/*
 * @lc app=leetcode.cn id=6182 lang=cpp
 *
 * [6182] 反转二叉树的奇数层
 *
 * https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/description/
 *
 * algorithms
 * Medium (69.62%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 9K
 * Testcase Example:  '[2,3,5,8,13,21,34]'
 *
 * 给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。
 *
 *
 * 例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
 *
 *
 * 反转后，返回树的根节点。
 *
 * 完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。
 *
 * 节点的 层数 等于该节点到根节点之间的边数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [2,3,5,8,13,21,34]
 * 输出：[2,5,3,8,13,21,34]
 * 解释：
 * 这棵树只有一个奇数层。
 * 在第 1 层的节点分别是 3、5 ，反转后为 5、3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [7,13,11]
 * 输出：[7,11,13]
 * 解释：
 * 在第 1 层的节点分别是 13、11 ，反转后为 11、13 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
 * 输出：[0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
 * 解释：奇数层由非零值组成。
 * 在第 1 层的节点分别是 1、2 ，反转后为 2、1 。
 * 在第 3 层的节点分别是 1、1、1、1、2、2、2、2 ，反转后为 2、2、2、2、1、1、1、1 。
 *
 *
 *[2,3,5,8,13,21,34]\n[7,13,11]\n[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
 *
 * 提示：
 *
 *
 * 树中的节点数目在范围 [1, 2^14] 内
 * 0 <= Node.val <= 10^5
 * root 是一棵 完美 二叉树
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
// 一开始想用dfs 然后dfs只会翻转孩子,不是全层反转
// 改用队列每一层读出来
// 一直没反应出来的点, 奇层翻转后, 偶数层得从奇数层的尾巴来时接(周赛一小时,没反应过来)
class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        vector<vector<TreeNode *>> vvt;
        queue<TreeNode *> qt;
        qt.push(root);
        while (qt.size() > 0)
        {
            int n = qt.size();
            vector<TreeNode *> vt;
            for (int i = 0; i < n; i++)
            {
                vt.push_back(qt.front());
                qt.pop();
            }
            vvt.push_back(vt);
            for (int i = 0; i < vt.size(); i++)
            {
                if (vt[i]->left != nullptr)
                {
                    qt.push(vt[i]->left);
                }
                if (vt[i]->right != nullptr)
                {
                    qt.push(vt[i]->right);
                }
            }
        }
        for (int ceng = 1; ceng < vvt.size(); ceng++)
        {
            if (ceng % 2 == 1)
            {
                int end = vvt[ceng].size() - 1;
                for (int j = 0; j < vvt[ceng - 1].size(); j++)
                {
                    // std::cout << ceng << ":" << vvt[ceng - 1][j]->val << ":" << vvt[ceng][end]->val << ":" << vvt[ceng][end - 1]->val << std::endl;
                    vvt[ceng - 1][j]->left = vvt[ceng][end];
                    vvt[ceng - 1][j]->right = vvt[ceng][end - 1];
                    end -= 2;
                }
            }
            else
            {
                int start = 0;
                for (int j = vvt[ceng - 1].size() - 1; j >= 0; j--)
                {
                    // std::cout << ceng << ":" << vvt[ceng - 1][j]->val << ":" << vvt[ceng][start]->val << ":" << vvt[ceng][start + 1]->val << std::endl;
                    vvt[ceng - 1][j]->left = vvt[ceng][start];
                    vvt[ceng - 1][j]->right = vvt[ceng][start + 1];
                    start += 2;
                }
            }
        }
        return vvt[0][0];
    }
};
// @lc code=end
