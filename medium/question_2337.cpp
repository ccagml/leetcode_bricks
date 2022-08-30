/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 *
 * [2337] 移动片段得到字符串
 *
 * https://leetcode.cn/problems/move-pieces-to-obtain-a-string/description/
 *
 * algorithms
 * Medium (37.72%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 18.1K
 * Testcase Example:  '"_L__R__R_"\n"L______RR"'
 *
 * 给你两个字符串 start 和 target ，长度均为 n 。每个字符串 仅 由字符 'L'、'R' 和 '_' 组成，其中：
 *
 *
 * 字符 'L' 和 'R' 表示片段，其中片段 'L' 只有在其左侧直接存在一个 空位 时才能向 左 移动，而片段 'R' 只有在其右侧直接存在一个 空位
 * 时才能向 右 移动。
 * 字符 '_' 表示可以被 任意 'L' 或 'R' 片段占据的空位。
 *
 *
 * 如果在移动字符串 start 中的片段任意次之后可以得到字符串 target ，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：start = "_L__R__R_", target = "L______RR"
 * 输出：true
 * 解释：可以从字符串 start 获得 target ，需要进行下面的移动：
 * - 将第一个片段向左移动一步，字符串现在变为 "L___R__R_" 。
 * - 将最后一个片段向右移动一步，字符串现在变为 "L___R___R" 。
 * - 将第二个片段向右移动散步，字符串现在变为 "L______RR" 。
 * 可以从字符串 start 得到 target ，所以返回 true 。
 *
 *
 * 示例 2：
 *
 * 输入：start = "R_L_", target = "__LR"
 * 输出：false
 * 解释：字符串 start 中的 'R' 片段可以向右移动一步得到 "_RL_" 。
 * 但是，在这一步之后，不存在可以移动的片段，所以无法从字符串 start 得到 target 。
 *
 *
 * 示例 3：
 *
 * 输入：start = "_R", target = "R_"
 * 输出：false
 * 解释：字符串 start 中的片段只能向右移动，所以无法从字符串 start 得到 target 。
 *
 *
 *
 * 提示：
 *
 *
 * n == start.length == target.length
 * 1 <= n <= 10^5
 * start 和 target 由字符 'L'、'R' 和 '_' 组成
 *
 *
 */

// @lc code=start

// 栈的思路,想得到应该挺简单的,但是想不到
class Solution
{
public:
    bool canChange(string start, string target)
    {
        stack<pair<char, int>> ss;
        stack<pair<char, int>> st;
        for (int i = 0; i < start.size(); i++)
        {
            if (start[i] == 'R')
            {
                ss.push({'R', i});
            }
            else if (start[i] == 'L')
            {
                ss.push({'L', i});
            }
            if (target[i] == 'R')
            {
                st.push({'R', i});
            }
            else if (target[i] == 'L')
            {
                st.push({'L', i});
            }
        }
        if (ss.size() != st.size())
        {
            return false;
        }
        while (!ss.empty() && !st.empty())
        {
            if(ss.top().first != st.top().first){
                return false;
            }
            if(ss.top().first == 'R' && st.top().second < ss.top().second){
                return false;
            }
            if(ss.top().first == 'L' && st.top().second > ss.top().second){
                return false;
            }
            ss.pop();
            st.pop();
        }
        return true;
    }
};
// @lc code=end
