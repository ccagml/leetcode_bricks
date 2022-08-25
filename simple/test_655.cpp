/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
 *
 * https://leetcode.cn/problems/print-binary-tree/description/
 *
 * algorithms
 * Medium (60.77%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    17.2K
 * Total Submissions: 26.2K
 * Testcase Example:  '[1,2]'
 *
 * 给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局
 * 。构造此格式化布局矩阵需要遵循以下规则：
 *
 *
 * 树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
 * 矩阵的列数 n 应该等于 2^height+1 - 1 。
 * 根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
 * 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2^height-r-1] ，右子节点放置在
 * res[r+1][c+2^height-r-1] 。
 * 继续这一过程，直到树中的所有节点都妥善放置。
 * 任意空单元格都应该包含空字符串 "" 。
 *
 *
 * 返回构造得到的矩阵 res 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2]
 * 输出：
 * [["","1",""],
 * ["2","",""]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,null,4]
 * 输出：
 * [["","","","1","","",""],
 * ["","2","","","","3",""],
 * ["","","4","","","",""]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数在范围 [1, 2^10] 内
 * -99 <= Node.val <= 99
 * 树的深度在范围 [1, 10] 内
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
public:
    int get_height(TreeNode *root, int cur)
    {
        int a = cur;
        int b = cur;
        if (root->left != nullptr)
        {
            a = get_height(root->left, cur + 1);
        }
        if (root->right != nullptr)
        {
            b = get_height(root->right, cur + 1);
        }
        return max(a, b);
    }
    vector<vector<string>> printTree(TreeNode *root)
    {
        int height = get_height(root, 1);
        int n = pow(2, height) - 1;
        std::cout << height << std::endl;
        vector<vector<string>> result(height, vector<string>(n, ""));

        result[0][(n - 1) / 2] = std::to_string(root->val);
        queue<pair<int, TreeNode *>> qt; // c, 点
        //  * 对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，
        //  将其左子节点放置在 res[r+1][c-2^height-r-1] ，
        //  右子节点放置在 * res[r+1][c+2^height-r-1] 。
        int c = (n - 1) / 2;
        int r = 0;
        // std::cout << c << std::endl;
        if (root->left != nullptr)
        {
            qt.push({c - pow(2, (height - r - 2)), root->left});
        }
        if (root->right != nullptr)
        {
            qt.push({c + pow(2, (height - r - 2)), root->right});
        }
        int cur_r = 0;
        while (!qt.empty())
        {
            cur_r++;
            int temp_n = qt.size();
            for (int i = 0; i < temp_n; i++)
            {
                pair<int, TreeNode *> pit = qt.front();
                qt.pop();
                int temp_c = pit.first;
                TreeNode *temp_node = pit.second;
                // std::cout << cur_r << ":" << temp_c << std::endl;
                result[cur_r][temp_c] = std::to_string(temp_node->val);

                if (temp_node->left != nullptr)
                {
                    qt.push({temp_c - pow(2, (height - cur_r - 2)), temp_node->left});
                }
                if (temp_node->right != nullptr)
                {
                    qt.push({temp_c + pow(2, (height - cur_r - 2)), temp_node->right});
                }
            }
        }
        return result;
    }
};
// @lc code=end
