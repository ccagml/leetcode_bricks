/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 *
 * https://leetcode.cn/problems/reach-a-number/description/
 *
 * algorithms
 * Medium (44.40%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 25.4K
 * Testcase Example:  '2'
 *
 * 在一根无限长的数轴上，你站在0的位置。终点在target的位置。
 *
 * 你可以做一些数量的移动 numMoves :
 *
 *
 * 每次你可以选择向左或向右移动。
 * 第 i 次移动（从  i == 1 开始，到 i == numMoves ），在选择的方向上走 i 步。
 *
 *
 * 给定整数 target ，返回 到达目标所需的 最小 移动次数(即最小 numMoves ) 。
 *
 *
 *
 * 示例 1:
 *
 * 输入: target = 2
 * 输出: 3
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 -1 。
 * 第三次移动，从 -1 到 2 。
 *
 *
 * 示例 2:
 *
 * 输入: target = 3
 * 输出: 2
 * 解释:
 * 第一次移动，从 0 到 1 。
 * 第二次移动，从 1 到 3 。
 *
 *
 *
 *
 * 提示:
 *
 *
 * -10^9 <= target <= 10^9
 * target != 0
 *
 *
 */

// @lc code=start

// 条件反射的模拟会超时
// 看不出这是考什么?动态规划?数学?
class Solution
{
public:
    int reachNumber(int target)
    {
        unordered_set<int> kk;
        kk.insert(0);
        int result = 0;
        while(true){
            unordered_set<int> new_kk;
            result++;
            for(auto &get : kk){
                new_kk.insert(get + result);
                new_kk.insert(get - result);
                if((get + result == target) || (get - result == target)){
                    return result;
                }
            }
            kk = new_kk;
        }
        return result;
    }
};
// @lc code=end
