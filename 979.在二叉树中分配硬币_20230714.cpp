// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=979 lang=cpp
 * @lcpr version=21910
 *
 * [979] 在二叉树中分配硬币
 *
 * https://leetcode.cn/problems/distribute-coins-in-binary-tree/description/
 *
 * algorithms
 * Medium (72.46%)
 * Likes:    430
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 27.7K
 * Testcase Example:  '[3,0,0]'
 *
 * 给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。
 *
 * 在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。
 *
 * 返回使每个结点上只有一枚硬币所需的移动次数。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[3,0,0]
 * 输出：2
 * 解释：从树的根结点开始，我们将一枚硬币移到它的左子结点上，一枚硬币移到它的右子结点上。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[0,3,0]
 * 输出：3
 * 解释：从根结点的左子结点开始，我们将两枚硬币移到根结点上 [移动两次]。然后，我们把一枚硬币从根结点移到右子结点上。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：[1,0,2]
 * 输出：2
 *
 *
 * 示例 4：
 *
 *
 *
 * 输入：[1,0,0,null,3]
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1<= N <= 100
 * 0 <= node.val <= N
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
    int get(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            int up = root->val - 1;
            result += abs(up);
            // 传给上级
            return up;
        }
        int a = 0;
        int b = 0;
        if (root->left != nullptr)
        {
            a = get(root->left);
        }
        if (root->right != nullptr)
        {
            b = get(root->right);
        }

        int up = root->val - 1 + a + b;
        result += abs(up);
        return up;
    }

    int distributeCoins(TreeNode *root)
    {
        result = 0;
        get(root);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,0]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,null,3]\n
// @lcpr case=end

 */
