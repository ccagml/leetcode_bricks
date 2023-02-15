/*
 * @lc app=leetcode.cn id=894 lang=cpp
 * @lcpr version=21504
 *
 * [894] 所有可能的真二叉树
 *
 * https://leetcode.cn/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (77.78%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    18.3K
 * Total Submissions: 23.5K
 * Testcase Example:  '7'
 *
 * 给你一个整数 n ，请你找出所有可能含 n 个节点的 真二叉树 ，并以列表形式返回。答案中每棵树的每个节点都必须符合 Node.val == 0 。
 *
 * 答案的每个元素都是一棵真二叉树的根节点。你可以按 任意顺序 返回最终的真二叉树列表。
 *
 * 真二叉树 是一类二叉树，树中每个节点恰好有 0 或 2 个子节点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 7
 *
 * 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 *
 *
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：[[0,0,0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 20
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
    vector<TreeNode *> allPossibleFBT(int n)
    {
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
