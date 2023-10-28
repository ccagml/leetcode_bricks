// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 * @lcpr version=30102
 *
 * [2558] 从数量最多的堆取走礼物
 *
 * https://leetcode.cn/problems/take-gifts-from-the-richest-pile/description/
 *
 * algorithms
 * Easy (71.03%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 19.5K
 * Testcase Example:  '[25,64,9,4,100]\n4'
 *
 * 给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：
 *
 *
 * 选择礼物数量最多的那一堆。
 * 如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
 * 选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
 *
 *
 * 返回在 k 秒后剩下的礼物数量。
 *
 *
 *
 * 示例 1：
 *
 * 输入：gifts = [25,64,9,4,100], k = 4
 * 输出：29
 * 解释：
 * 按下述方式取走礼物：
 * - 在第一秒，选中最后一堆，剩下 10 个礼物。
 * - 接着第二秒选中第二堆礼物，剩下 8 个礼物。
 * - 然后选中第一堆礼物，剩下 5 个礼物。
 * - 最后，再次选中最后一堆礼物，剩下 3 个礼物。
 * 最后剩下的礼物数量分别是 [5,8,9,4,3] ，所以，剩下礼物的总数量是 29 。
 *
 *
 * 示例 2：
 *
 * 输入：gifts = [1,1,1,1], k = 4
 * 输出：4
 * 解释：
 * 在本例中，不管选中哪一堆礼物，都必须剩下 1 个礼物。
 * 也就是说，你无法获取任一堆中的礼物。
 * 所以，剩下礼物的总数量是 4 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= gifts.length <= 10^3
 * 1 <= gifts[i] <= 10^9
 * 1 <= k <= 10^3
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    long long mysqrt(long long a)
    {
        long long min = 1;
        // long long max=1<<32;
        long long max = ((long long)1) << 32; // chux' bugfix
        while (1)
        {
            if (max <= 1 + min)
                return min;

            long long sqt = min + (max - min) / 2;
            long long sq = sqt * sqt;

            if (sq == a)
                return sqt;

            if (sq > a)
                max = sqt;
            else
                min = sqt;
        };
    }
    long long pickGifts(vector<int> &gifts, int k)
    {
        sort(gifts.begin(), gifts.end(), [](int a, int b)
             { return a > b; });
        for (int i = 0; i < k; i++)
        {
            int g = gifts[0];
            int _g = mysqrt(g);
            gifts[0] = _g;
            sort(gifts.begin(), gifts.end(), [](int a, int b)
                 { return a > b; });
        }
        long long result = 0;
        for (int p : gifts)
        {
            result += p;
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=pickGifts
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [25,64,9,4,100]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n4\n
// @lcpr case=end

 */
