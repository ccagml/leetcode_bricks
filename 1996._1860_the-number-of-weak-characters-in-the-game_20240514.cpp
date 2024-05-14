// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1996 lang=cpp
 * @lcpr version=30203
 *
 * [1996] 游戏中弱角色的数量
 *
 * https://leetcode.cn/problems/the-number-of-weak-characters-in-the-game/description/
 *
 * algorithms
 * Medium (41.57%)
 * Likes:    194
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 74K
 * Testcase Example:  '[[5,5],[6,3],[3,6]]'
 *
 * 你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。给你一个二维整数数组 properties ，其中 properties[i] =
 * [attacki, defensei] 表示游戏中第 i 个角色的属性。
 *
 * 如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色
 * j ，那么 attackj > attacki 且 defensej > defensei 。
 *
 * 返回 弱角色 的数量。
 *
 *
 *
 * 示例 1：
 *
 * 输入：properties = [[5,5],[6,3],[3,6]]
 * 输出：0
 * 解释：不存在攻击和防御都严格高于其他角色的角色。
 *
 *
 * 示例 2：
 *
 * 输入：properties = [[2,2],[3,3]]
 * 输出：1
 * 解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 *
 *
 * 示例 3：
 *
 * 输入：properties = [[1,5],[10,4],[4,3]]
 * 输出：1
 * 解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= properties.length <= 10^5
 * properties[i].length == 2
 * 1 <= attacki, defensei <= 10^5
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
class Solution
{
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] > b[0])
                 {
                     return true;
                 }
                 else if (a[0] == b[0] && a[1] < b[1])
                 {
                     return true;
                 }
                 return false; });

        int max_att = properties[0][0];
        int max_def = properties[0][1];
        int result = 0;
        for (int i = 1; i < properties.size(); i++)
        {
            vector<int> &temp = properties[i];
            if (max_att > temp[0] && max_def > temp[1])
            {
                result++;
            }
            max_def = max(max_def, temp[1]);
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=numberOfWeakCharacters
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[5,5],[6,3],[3,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,2],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,5],[10,4],[4,3]]\n
// @lcpr case=end
// @lcpr case=start
// [[1,1],[2,1],[2,2],[1,2]]\n
// @lcpr case=end

 */
