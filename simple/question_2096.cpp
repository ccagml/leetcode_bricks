/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 *
 * https://leetcode.cn/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/
 *
 * algorithms
 * Medium (43.30%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 14.5K
 * Testcase Example:  '[5,1,2,3,null,6,4]\n3\n6'
 *
 * 给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。给你一个整数
 * startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。
 *
 * 请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U'
 * 分别表示一种方向：
 *
 *
 * 'L' 表示从一个节点前往它的 左孩子 节点。
 * 'R' 表示从一个节点前往它的 右孩子 节点。
 * 'U' 表示从一个节点前往它的 父 节点。
 *
 *
 * 请你返回从 s 到 t 最短路径 每一步的方向。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
 * 输出："UURL"
 * 解释：最短路径为：3 → 1 → 5 → 2 → 6 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [2,1], startValue = 2, destValue = 1
 * 输出："L"
 * 解释：最短路径为：2 → 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目为 n 。
 * 2 <= n <= 10^5
 * 1 <= Node.val <= n
 * 树中所有节点的值 互不相同 。
 * 1 <= startValue, destValue <= n
 * startValue != destValue
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
// 找到公共祖先
class Solution
{
public:
    unordered_map<int, TreeNode *> unmi;
    unordered_map<int, int> father_num;
    unordered_map<int, int> father_left;
    unordered_map<int, int> node_ceng;
    int same_father;
    void create(TreeNode *root, int fa, int ceng)
    {
        if (root != nullptr)
        {
            unmi[root->val] = root;
            father_num[root->val] = fa;
            node_ceng[root->val] = ceng;
        }
        if (root->left != nullptr)
        {
            create(root->left, root->val, ceng + 1);
            father_left[root->left->val] = 1;
        }
        if (root->right != nullptr)
        {
            create(root->right, root->val, ceng + 1);
        }
    }

    void find_father(int startValue, int destValue)
    {
        while (node_ceng[startValue] > node_ceng[destValue])
        {
            startValue = father_num[startValue];
        }
        while (node_ceng[startValue] < node_ceng[destValue])
        {
            destValue = father_num[destValue];
        }
        while (true)
        {
            if (startValue == destValue)
            {
                same_father = startValue;
                break;
            }
            if (father_num[startValue] == father_num[destValue])
            {
                same_father = father_num[startValue];
                break;
            }
            startValue = father_num[startValue];
            destValue = father_num[destValue];
        }
    }

    void get_path(string &path, int start, int dest)
    {
        bool down;
        while (true)
        {
            if (node_ceng[start] > node_ceng[dest])
            {
                path.push_back('U');
                start = father_num[start];
            }
            else if (start == dest)
            {
                break;
            }
            else
            {
                // 向下
                down = true;
                deque<char> dqc;
                while (node_ceng[start] < node_ceng[dest])
                {
                    if (father_left.count(dest) > 0)
                    {
                        dqc.push_front('L');
                    }
                    else
                    {
                        dqc.push_front('R');
                    }
                    dest = father_num[dest];
                }
                while (dqc.size() > 0)
                {
                    path.push_back(dqc.front());
                    dqc.pop_front();
                }
                break;
            }
        }
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        create(root, root->val, 1);
        find_father(startValue, destValue);
        string result = "";
        get_path(result, startValue, same_father);
        get_path(result, same_father, destValue);
        return result;
    }
};
// @lc code=end
