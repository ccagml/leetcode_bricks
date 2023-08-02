/*
 * @lc app=leetcode.cn id=822 lang=cpp
 * @lcpr version=21913
 *
 * [822] 翻转卡片游戏
 *
 * https://leetcode.cn/problems/card-flipping-game/description/
 *
 * algorithms
 * Medium (51.63%)
 * Likes:    66
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 26.1K
 * Testcase Example:  '[1,2,4,4,7]\n[1,3,4,1,3]'
 *
 * 在桌子上有 n 张卡片，每张卡片的正面和背面都写着一个正数（正面与背面上的数有可能不一样）。
 *
 * 我们可以先翻转任意张卡片，然后选择其中一张卡片。
 *
 * 如果选中的那张卡片背面的数字 x 与任意一张卡片的正面的数字都不同，那么这个数字是我们想要的数字。
 *
 * 哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？如果没有一个数字符合要求的，输出 0 。
 *
 * 其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和背面的数字。
 *
 * 如果我们通过翻转卡片来交换正面与背面上的数，那么当初在正面的数就变成背面的数，背面的数就变成正面的数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
 * 输出：2
 * 解释：假设我们翻转第二张卡片，那么在正面的数变成了 [1,3,4,4,7] ， 背面的数变成了 [1,2,4,1,3]。
 * 接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。
 *
 * 示例 2：
 *
 * 输入：fronts = [1], backs = [1]
 * 输出：0
 * 解释：
 * 无论如何翻转都无法得到想要的数字，所以返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == fronts.length == backs.length
 * 1 <= n <= 1000
 * 1 <= fronts[i], backs[i] <= 2000
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
class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        unordered_map<int, unordered_set<int>> umiusf;
        unordered_map<int, unordered_set<int>> umiusb;
        int result = 9999;
        for (int i = 0; i < fronts.size(); i++)
        {
            int f = fronts[i];
            int b = backs[i];
            umiusf[f].insert(b);
            umiusb[b].insert(f);
        }

        for (int i = 0; i < fronts.size(); i++)
        {
            int f = fronts[i];
            int b = backs[i];

            // 如果结果是f, 那么需要把所有的f都翻过去
            if (umiusf[f].count(f) == 0)
            {
                result = min(f, result);
            }
        }

        for (int i = 0; i < backs.size(); i++)
        {
            int f = fronts[i];
            int b = backs[i];

            // 如果结果是b, 那么需要把所有的b都翻过去
            if (umiusf[b].count(b) == 0)
            {
                result = min(b, result);
            }
        }

        return result == 9999 ? 0 : result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4,4,7]\n[1,3,4,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1]\n
// @lcpr case=end

 */
