// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2008 lang=cpp
 * @lcpr version=21906
 *
 * [2008] 出租车的最大盈利
 *
 * https://leetcode.cn/problems/maximum-earnings-from-taxi/description/
 *
 * algorithms
 * Medium (46.15%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    5.9K
 * Total Submissions: 12.9K
 * Testcase Example:  '5\n[[2,5,4],[1,5,1]]'
 *
 * 你驾驶出租车行驶在一条有 n 个地点的路上。这 n 个地点从近到远编号为 1 到 n ，你想要从 1 开到 n
 * ，通过接乘客订单盈利。你只能沿着编号递增的方向前进，不能改变方向。
 *
 * 乘客信息用一个下标从 0 开始的二维数组 rides 表示，其中 rides[i] = [starti, endi, tipi] 表示第 i
 * 位乘客需要从地点 starti 前往 endi ，愿意支付 tipi 元的小费。
 *
 * 每一位 你选择接单的乘客 i ，你可以 盈利 endi - starti + tipi 元。你同时 最多 只能接一个订单。
 *
 * 给你 n 和 rides ，请你返回在最优接单方案下，你能盈利 最多 多少元。
 *
 * 注意：你可以在一个地点放下一位乘客，并在同一个地点接上另一位乘客。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 5, rides = [[2,5,4],[1,5,1]]
 * 输出：7
 * 解释：我们可以接乘客 0 的订单，获得 5 - 2 + 4 = 7 元。
 *
 *
 * 示例 2：
 *
 * 输入：n = 20, rides =
 * [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
 * 输出：20
 * 解释：我们可以接以下乘客的订单：
 * - 将乘客 1 从地点 3 送往地点 10 ，获得 10 - 3 + 2 = 9 元。
 * - 将乘客 2 从地点 10 送往地点 12 ，获得 12 - 10 + 3 = 5 元。
 * - 将乘客 5 从地点 13 送往地点 18 ，获得 18 - 13 + 1 = 6 元。
 * 我们总共获得 9 + 5 + 6 = 20 元。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * 1 <= rides.length <= 3 * 10^4
 * rides[i].length == 3
 * 1 <= starti < endi <= n
 * 1 <= tipi <= 10^5
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
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        vector<long long> vll(100002);
        // 到 x 位置 最大可以多少
        sort(rides.begin(), rides.end(), [](vector<int> &v1, vector<int> &v2)
             {
                 if (v1[1] < v2[1])
                 {
                     return true;
                 }
                 else if (v1[1] == v2[1] && v1[2] > v2[2])
                 {
                     return true;
                 }
                 return false; });
        for (int j = 0; j < rides.size(); j++)
        {
            long long cur_start = rides[j][0];
            long long cur_end = rides[j][1];
            long long cur_p = rides[j][2];
            long long cur = cur_end - cur_start + cur_p;

            // 上一个的结束,到本个结束之间,都填充
            if (j > 0)
            {
                int last_end = rides[j - 1][1];
                int cur_end = rides[j][1];
                for (int lll = last_end; lll <= cur_end; lll++)
                {
                    long long temp_max = max(vll[lll], vll[last_end]);
                    vll[lll] = max(vll[lll], temp_max);
                }
            }
            long long last = vll[cur_start];
            vll[cur_end] = max(vll[cur_end], last + cur);
        }
        long long temp = 0;
        for (long long j : vll)
        {
            temp = max(temp, j);
        }
        return temp;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxTaxiEarnings
// paramTypes= ["number","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 5\n[[2,5,4],[1,5,1]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[2,3,4],[4,5,1]]\n
// @lcpr case=end

// @lcpr case=start
// 20\n[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]\n
// @lcpr case=end

 */
