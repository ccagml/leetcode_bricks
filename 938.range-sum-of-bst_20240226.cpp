/*
 * @lc app=leetcode.cn id=938 lang=cpp
 * @lcpr version=30117
 *
 * [938] 二叉搜索树的范围和
 *
 * https://leetcode.cn/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (82.11%)
 * Likes:    361
 * Dislikes: 0
 * Total Accepted:    142.2K
 * Total Submissions: 171.5K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
 * 输出：32
 *
 *
 * 示例 2：
 *
 * 输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 2 * 10^4] 内
 * 1 <= Node.val <= 10^5
 * 1 <= low <= high <= 10^5
 * 所有 Node.val 互不相同
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
    int result;
    void dfs(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val >= low && root->val <= high)
        {
            result += root->val;
        }
        dfs(root->left, low, high);
        dfs(root->right, low, high);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        result = 0;
        dfs(root, low, high);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,5,15,3,7,null,18]\n7\n15\n
// @lcpr case=end

// @lcpr case=start
// [10,5,15,3,7,13,18,1,null,6]\n6\n10\n
// @lcpr case=end

 */
