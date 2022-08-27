/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 *
 * https://leetcode.cn/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (41.31%)
 * Likes:    442
 * Dislikes: 0
 * Total Accepted:    59.6K
 * Total Submissions: 141.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给你一棵二叉树的根节点 root ，返回树的 最大宽度 。
 *
 * 树的 最大宽度 是所有层中最大的 宽度 。
 *
 *
 *
 * 每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的
 * null 节点，这些 null 节点也计入长度。
 *
 * 题目数据保证答案将会在  32 位 带符号整数范围内。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,3,2,5,3,null,9]
 * 输出：4
 * 解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,3,2,5,null,null,9,6,null,7]
 * 输出：7
 * 解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1,3,2,5]
 * 输出：2
 * 解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是 [1, 3000]
 * -100 <= Node.val <= 100
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

/*
      1
    2  3
   4 5 6 7

*/

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        queue<pair<unsigned long long, TreeNode *>> qplt;

        qplt.push({1, root});
        while (qplt.size() > 0)
        {
            unsigned long long temp1 = 0;
            unsigned long long temp2 = 0;
            int n = qplt.size();
            for (int i = 0; i < n; i++)
            {
                pair<unsigned long long, TreeNode *> plt = qplt.front();
                qplt.pop();
                // std::cout << plt.first << ",";
                if (i == 0)
                {
                    temp1 = plt.first;
                }
                if (i == n - 1)
                {
                    temp2 = plt.first;
                }
                if (plt.second->left != nullptr)
                {
                    qplt.push({2 * plt.first, plt.second->left});
                }
                if (plt.second->right != nullptr)
                {
                    qplt.push({2 * plt.first + 1, plt.second->right});
                }
            }
            // std::cout << "----" << temp1 << ":" << temp2 <<   std::endl;

            if (n != 1)
            {
                result = max(result, int(temp2 - temp1 + 1));
            }
            else
            {
                result = max(result, 1);
            }
        }
        return result;
    }
};
// @lc code=end
