/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 * @lcpr version=21902
 *
 * [1041] 困于环中的机器人
 *
 * https://leetcode.cn/problems/robot-bounded-in-circle/description/
 *
 * algorithms
 * Medium (50.44%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 26.2K
 * Testcase Example:  '"GGLLGG"'
 *
 * 在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。注意:
 * 
 * 
 * 北方向 是y轴的正方向。
 * 南方向 是y轴的负方向。
 * 东方向 是x轴的正方向。
 * 西方向 是x轴的负方向。
 * 
 * 
 * 机器人可以接受下列三条指令之一：
 * 
 * 
 * "G"：直走 1 个单位
 * "L"：左转 90 度
 * "R"：右转 90 度
 * 
 * 
 * 机器人按顺序执行指令 instructions，并一直重复它们。
 * 
 * 只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：instructions = "GGLLGG"
 * 输出：true
 * 解释：机器人最初在(0,0)处，面向北方。
 * “G”:移动一步。位置:(0,1)方向:北。
 * “G”:移动一步。位置:(0,2).方向:北。
 * “L”:逆时针旋转90度。位置:(0,2).方向:西。
 * “L”:逆时针旋转90度。位置:(0,2)方向:南。
 * “G”:移动一步。位置:(0,1)方向:南。
 * “G”:移动一步。位置:(0,0)方向:南。
 * 重复指令，机器人进入循环:(0,0)——>(0,1)——>(0,2)——>(0,1)——>(0,0)。
 * 在此基础上，我们返回true。
 * 
 * 
 * 示例 2：
 * 
 * 输入：instructions = "GG"
 * 输出：false
 * 解释：机器人最初在(0,0)处，面向北方。
 * “G”:移动一步。位置:(0,1)方向:北。
 * “G”:移动一步。位置:(0,2).方向:北。
 * 重复这些指示，继续朝北前进，不会进入循环。
 * 在此基础上，返回false。
 * 
 * 
 * 示例 3：
 * 
 * 输入：instructions = "GL"
 * 输出：true
 * 解释：机器人最初在(0,0)处，面向北方。
 * “G”:移动一步。位置:(0,1)方向:北。
 * “L”:逆时针旋转90度。位置:(0,1).方向:西。
 * “G”:移动一步。位置:(- 1,1)方向:西。
 * “L”:逆时针旋转90度。位置:(- 1,1)方向:南。
 * “G”:移动一步。位置:(- 1,0)方向:南。
 * “L”:逆时针旋转90度。位置:(- 1,0)方向:东方。
 * “G”:移动一步。位置:(0,0)方向:东方。
 * “L”:逆时针旋转90度。位置:(0,0)方向:北。
 * 重复指令，机器人进入循环:(0,0)——>(0,1)——>(- 1,1)——>(- 1,0)——>(0,0)。
 * 在此基础上，我们返回true。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= instructions.length <= 100
 * instructions[i] 仅包含 'G', 'L', 'R'
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> direc {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direcIndex = 0;
        int x = 0, y = 0;
        for (char instruction : instructions) {
            if (instruction == 'G') {
                x += direc[direcIndex][0];
                y += direc[direcIndex][1];
            } else if (instruction == 'L') {
                direcIndex += 3;
                direcIndex %= 4;
            } else {
                direcIndex++;
                direcIndex %= 4;
            }
        }
        return direcIndex != 0 || (x == 0 && y == 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "GGLLGG"\n
// @lcpr case=end

// @lcpr case=start
// "GG"\n
// @lcpr case=end

// @lcpr case=start
// "GL"\n
// @lcpr case=end

 */


