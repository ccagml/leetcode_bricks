/*
 * @lc app=leetcode.cn id=2335 lang=cpp
 * @lcpr version=21504
 *
 * [2335] 装满杯子需要的最短总时长
 *
 * https://leetcode.cn/problems/minimum-amount-of-time-to-fill-cups/description/
 *
 * algorithms
 * Easy (57.19%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 35.9K
 * Testcase Example:  '[1,4,2]'
 *
 * 现有一台饮水机，可以制备冷水、温水和热水。每秒钟，可以装满 2 杯 不同 类型的水或者 1 杯任意类型的水。
 * 
 * 给你一个下标从 0 开始、长度为 3 的整数数组 amount ，其中 amount[0]、amount[1] 和 amount[2]
 * 分别表示需要装满冷水、温水和热水的杯子数量。返回装满所有杯子所需的 最少 秒数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：amount = [1,4,2]
 * 输出：4
 * 解释：下面给出一种方案：
 * 第 1 秒：装满一杯冷水和一杯温水。
 * 第 2 秒：装满一杯温水和一杯热水。
 * 第 3 秒：装满一杯温水和一杯热水。
 * 第 4 秒：装满一杯温水。
 * 可以证明最少需要 4 秒才能装满所有杯子。
 * 
 * 
 * 示例 2：
 * 
 * 输入：amount = [5,4,4]
 * 输出：7
 * 解释：下面给出一种方案：
 * 第 1 秒：装满一杯冷水和一杯热水。
 * 第 2 秒：装满一杯冷水和一杯温水。
 * 第 3 秒：装满一杯冷水和一杯温水。
 * 第 4 秒：装满一杯温水和一杯热水。
 * 第 5 秒：装满一杯冷水和一杯热水。
 * 第 6 秒：装满一杯冷水和一杯温水。
 * 第 7 秒：装满一杯热水。
 * 
 * 
 * 示例 3：
 * 
 * 输入：amount = [5,0,0]
 * 输出：5
 * 解释：每秒装满一杯冷水。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * amount.length == 3
 * 0 <= amount[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int fillCups(vector<int>& amount) {
        
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
// [1,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,0,0]\n
// @lcpr case=end

 */


