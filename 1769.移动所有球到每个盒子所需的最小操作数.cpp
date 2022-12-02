/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 * @lcpr version=20602
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 *
 * https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
 *
 * algorithms
 * Medium (85.35%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    21.5K
 * Total Submissions: 24.5K
 * Testcase Example:  '"110"'
 *
 * 有 n 个盒子。给你一个长度为 n 的二进制字符串 boxes ，其中 boxes[i] 的值为 '0' 表示第 i 个盒子是 空 的，而
 * boxes[i] 的值为 '1' 表示盒子里有 一个 小球。
 *
 * 在一步操作中，你可以将 一个 小球从某个盒子移动到一个与之相邻的盒子中。第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1
 * 。注意，操作执行后，某些盒子中可能会存在不止一个小球。
 *
 * 返回一个长度为 n 的数组 answer ，其中 answer[i] 是将所有小球移动到第 i 个盒子所需的 最小 操作数。
 *
 * 每个 answer[i] 都需要根据盒子的 初始状态 进行计算。
 *
 *
 *
 * 示例 1：
 *
 * 输入：boxes = "110"
 * 输出：[1,1,3]
 * 解释：每个盒子对应的最小操作数如下：
 * 1) 第 1 个盒子：将一个小球从第 2 个盒子移动到第 1 个盒子，需要 1 步操作。
 * 2) 第 2 个盒子：将一个小球从第 1 个盒子移动到第 2 个盒子，需要 1 步操作。
 * 3) 第 3 个盒子：将一个小球从第 1 个盒子移动到第 3 个盒子，需要 2 步操作。将一个小球从第 2 个盒子移动到第 3 个盒子，需要 1
 * 步操作。共计 3 步操作。
 *
 *
 * 示例 2：
 *
 * 输入：boxes = "001011"
 * 输出：[11,8,5,4,3,4]
 *
 *
 *
 * 提示：
 *
 *
 * n == boxes.length
 * 1 <= n <= 2000
 * boxes[i] 为 '0' 或 '1'
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        int n = boxes.size();
        vector<int> leftCost(n), leftCount(n);
        vector<int> rightCost(n), rightCount(n);
        vector<int> res;

        for (int i = 1; i < n; i++)
        {
            if (boxes[i - 1] == '1')
                leftCount[i] = leftCount[i - 1] + 1;
            else
                leftCount[i] = leftCount[i - 1];
            leftCost[i] = leftCost[i - 1] + leftCount[i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (boxes[i + 1] == '1')
                rightCount[i] = rightCount[i + 1] + 1;
            else
                rightCount[i] = rightCount[i + 1];
            rightCost[i] = rightCost[i + 1] + rightCount[i];
        }

        for (int i = 0; i < n; i++)
        {
            res.push_back(leftCost[i] + rightCost[i]);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "110"\n
// @lcpr case=end

// @lcpr case=start
// "001011"\n
// @lcpr case=end

 */
