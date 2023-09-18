// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=337 lang=cpp
 * @lcpr version=21914
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode.cn/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (61.10%)
 * Likes:    1833
 * Dislikes: 0
 * Total Accepted:    303.3K
 * Total Submissions: 494.4K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 *
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
 * 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 *
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: root = [3,2,3,null,3,null,1]
 * 输出: 7
 * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
 *
 * 示例 2:
 *
 *
 *
 * 输入: root = [3,4,5,1,3,null,1]
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 树的节点数在 [1, 10^4] 范围内
 * 0 <= Node.val <= 10^4
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    int max_result = 0;
    unordered_map<TreeNode *, pair<int, int>> umm;
    int get_cur_max(TreeNode *root, bool flag)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            umm[root] = {root->val, 0};
            if (flag)
            {
                return root->val;
            }
            else
            {
                return 0;
            }
        }

        if (umm.count(root) > 0)
        {
            if (flag)
            {
                return umm[root].first;
            }
            else
            {
                return umm[root].second;
            }
        }
        int left_max_1 = 0;
        int left_max_2 = 0;
        if (root->left != nullptr)
        {
            left_max_1 = get_cur_max(root->left, true);
            left_max_2 = get_cur_max(root->left, false);
        }
        int right_max_1 = 0;
        int right_max_2 = 0;

        if (root->right != nullptr)
        {
            right_max_1 = get_cur_max(root->right, true);
            right_max_2 = get_cur_max(root->right, false);
        }

        // 选取root
        int a = root->val + left_max_2 + right_max_2;
        int b = max(left_max_1, left_max_2) + max(right_max_1, right_max_2);
        umm[root] = {a, b};
        if (flag)
        {
            return umm[root].first;
        }
        else
        {
            return umm[root].second;
        }
        return 0;
    }

    int rob(TreeNode *root)
    {
        int temp_max1 = get_cur_max(root, false);
        int temp_max2 = get_cur_max(root, true);
        return max(temp_max1, temp_max2);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3,null,3,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,3,null,1]\n
// @lcpr case=end

 */
