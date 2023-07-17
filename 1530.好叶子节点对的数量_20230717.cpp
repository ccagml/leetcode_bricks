// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 * @lcpr version=21910
 *
 * [1530] 好叶子节点对的数量
 *
 * https://leetcode.cn/problems/number-of-good-leaf-nodes-pairs/description/
 *
 * algorithms
 * Medium (58.50%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 19.6K
 * Testcase Example:  '[1,2,3,null,4]\n3'
 *
 * 给你二叉树的根节点 root 和一个整数 distance 。
 *
 * 如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。
 *
 * 返回树中 好叶子节点对的数量 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 *
 * 输入：root = [1,2,3,null,4], distance = 3
 * 输出：1
 * 解释：树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：root = [1,2,3,4,5,6,7], distance = 3
 * 输出：2
 * 解释：好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4
 * 。
 *
 *
 * 示例 3：
 *
 * 输入：root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
 * 输出：1
 * 解释：唯一的好叶子节点对是 [2,5] 。
 *
 *
 * 示例 4：
 *
 * 输入：root = [100], distance = 1
 * 输出：0
 *
 *
 * 示例 5：
 *
 * 输入：root = [1,1,1], distance = 2
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * tree 的节点数在 [1, 2^10] 范围内。
 * 每个节点的值都在 [1, 100] 之间。
 * 1 <= distance <= 10
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
    int distanced;
    unordered_map<int, int> d(TreeNode *root, int ceng)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            unordered_map<int, int> temp;
            temp[ceng] = 1;
            return temp;
        }

        unordered_map<int, int> up;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        if (root->left != nullptr)
        {
            left = d(root->left, ceng + 1);
        }
        if (root->right != nullptr)
        {
            right = d(root->right, ceng + 1);
        }
        // 计算左子树 -> 本点 -> 右子树 的长度
        for (pair<int, int> pl : left)
        {
            int l_ceng = pl.first;
            int l_n = pl.second;
            for (pair<int, int> pr : right)
            {
                int r_ceng = pr.first;
                int r_n = pr.second;
                int a = l_ceng - ceng;
                int b = r_ceng - ceng;

                // std::cout << "l_ceng:" << l_ceng << ",l_n:" << l_n << ",r_ceng:" << r_ceng << ",r_n:" << r_n << std::endl;

                if (a + b <= distanced)
                {
                    result += l_n * r_n;
                }
            }
        }

        for (pair<int, int> pl : left)
        {
            int l_ceng = pl.first;
            int l_n = pl.second;
            up[l_ceng] += l_n;
        }
        for (pair<int, int> pr : right)
        {
            int r_ceng = pr.first;
            int r_n = pr.second;
            up[r_ceng] += r_n;
        }

        return up;
    }
    int countPairs(TreeNode *root, int distance)
    {
        distanced = distance;
        result = 0;
        d(root, 0);
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=countPairs
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3,null,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,1,4,6,null,5,3,null,null,null,null,null,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [100]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

 */
