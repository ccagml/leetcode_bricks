/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 * @lcpr version=20801
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 *
 * https://leetcode.cn/problems/determine-color-of-a-chessboard-square/description/
 *
 * algorithms
 * Easy (77.91%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    19.4K
 * Total Submissions: 24.3K
 * Testcase Example:  '"a1"'
 *
 * 给你一个坐标 coordinates ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。
 *
 *
 *
 * 如果所给格子的颜色是白色，请你返回 true，如果是黑色，请返回 false 。
 *
 * 给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。
 *
 *
 *
 * 示例 1：
 *
 * 输入：coordinates = "a1"
 * 输出：false
 * 解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
 *
 *
 * 示例 2：
 *
 * 输入：coordinates = "h3"
 * 输出：true
 * 解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
 *
 *
 * 示例 3：
 *
 * 输入：coordinates = "c7"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * coordinates.length == 2
 * 'a' <= coordinates[0] <= 'h'
 * '1' <= coordinates[1] <= '8'
 *
 *
 */
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
// @lc code=start
class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        char a = coordinates[0];
        char b = coordinates[1] - '0';
        if (a == 'a' || a == 'c' || a == 'e' || a == 'g')
        {
            return b % 2 == 0;
        }
        else
        {
            return b % 2 == 1;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "a1"\n
// @lcpr case=end

// @lcpr case=start
// "h3"\n
// @lcpr case=end

// @lcpr case=start
// "c7"\n
// @lcpr case=end

 */
