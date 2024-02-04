// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1690 lang=cpp
 * @lcpr version=30115
 *
 * [1690] 石子游戏 VII
 *
 * https://leetcode.cn/problems/stone-game-vii/description/
 *
 * algorithms
 * Medium (56.40%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 17.6K
 * Testcase Example:  '[5,3,1,4,2]'
 *
 * 石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，爱丽丝先开始 。
 *
 * 有 n 块石子排成一排。每个玩家的回合中，可以从行中 移除 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 和
 * 相等的得分。当没有石头可移除时，得分较高者获胜。
 *
 * 鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 减小得分的差值 。爱丽丝的目标是最大限度地 扩大得分的差值 。
 *
 * 给你一个整数数组 stones ，其中 stones[i] 表示 从左边开始 的第 i 个石头的值，如果爱丽丝和鲍勃都 发挥出最佳水平 ，请返回他们
 * 得分的差值 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：stones = [5,3,1,4,2]
 * 输出：6
 * 解释：
 * - 爱丽丝移除 2 ，得分 5 + 3 + 1 + 4 = 13 。游戏情况：爱丽丝 = 13 ，鲍勃 = 0 ，石子 = [5,3,1,4] 。
 * - 鲍勃移除 5 ，得分 3 + 1 + 4 = 8 。游戏情况：爱丽丝 = 13 ，鲍勃 = 8 ，石子 = [3,1,4] 。
 * - 爱丽丝移除 3 ，得分 1 + 4 = 5 。游戏情况：爱丽丝 = 18 ，鲍勃 = 8 ，石子 = [1,4] 。
 * - 鲍勃移除 1 ，得分 4 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [4] 。
 * - 爱丽丝移除 4 ，得分 0 。游戏情况：爱丽丝 = 18 ，鲍勃 = 12 ，石子 = [] 。
 * 得分的差值 18 - 12 = 6 。
 *
 *
 * 示例 2：
 *
 * 输入：stones = [7,90,5,1,100,10,10,2]
 * 输出：122
 *
 *
 *
 * 提示：
 *
 *
 * n == stones.length
 * 2 <= n <= 1000
 * 1 <= stones[i] <= 1000
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
// class Solution
// {
// public:
//     vector<int> v_qian;

//     int stoneGameVII(vector<int> &stones)
//     {
//         int n = stones.size();
//         vector<vector<int>> vvi(n, vector<int>(n, -9999999));
//         for (int i = 0; i < n; i++)
//         {
//             vvi[i][i] = 0;
//         }

//         bool is_bob_end = (n % 2 == 0);

//         int sum = 0;
//         v_qian.push_back(sum);
//         for (int i = 0; i < stones.size(); i++)
//         {
//             sum += stones[i];
//             v_qian.push_back(sum);
//         }
//         // v[i][j] = 最大差值
//         for (int len = 1; len < n; len++)
//         {
//             int is_add = 1;
//             if (is_bob_end)
//             {
//                 if (len % 2 == 1)
//                 {
//                     is_add = 1;
//                 }
//                 else
//                 {
//                     is_add = -1;
//                 }
//             }
//             else
//             {
//                 if (len % 2 == 1)
//                 {
//                     is_add = -1;
//                 }
//                 else
//                 {
//                     is_add = 1;
//                 }
//             }
//             for (int left = 0; left < n; left++)
//             {
//                 int right = left + len;
//                 // 0, 1, 2
//                 if (right < n)
//                 {

//                     // 打算移除左边
//                     int left_1_right_status = vvi[left + 1][right];

//                     int rm_left_add_score = (v_qian[right + 1] - v_qian[left + 1]);

//                     // 打算移除右边
//                     int left_right_1_status = vvi[left][right - 1];
//                     int rm_right_add_score = (v_qian[right] - v_qian[left]);

//                     if (rm_left_add_score > rm_right_add_score)
//                     {
//                         vvi[left][right] = max(vvi[left][right], left_1_right_status + is_add * rm_left_add_score);
//                     }
//                     else if (rm_left_add_score == rm_right_add_score)
//                     {
//                         vvi[left][right] = max(vvi[left][right], left_1_right_status + is_add * rm_left_add_score);
//                         vvi[left][right] = max(vvi[left][right], left_right_1_status + is_add * rm_right_add_score);
//                     }
//                     else
//                     {
//                         vvi[left][right] = max(vvi[left][right], left_right_1_status + is_add * rm_right_add_score);
//                     }
//                 }
//             }
//         }
//         int reuslt = vvi[0][n - 1];
//         return reuslt;
//     }
// };

class Solution
{
public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();
        vector<int> sum(n + 1);
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + stones[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=stoneGameVII
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,3,1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [7,90,5,1,100,10,10,2]\n
// @lcpr case=end

 */
