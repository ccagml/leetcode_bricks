// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2830 lang=cpp
 * @lcpr version=30102
 *
 * [2830] 销售利润最大化
 *
 * https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/description/
 *
 * algorithms
 * Medium (41.07%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 12.8K
 * Testcase Example:  '5\n[[0,0,1],[0,2,2],[1,3,2]]'
 *
 * 给你一个整数 n 表示数轴上的房屋数量，编号从 0 到 n - 1 。
 *
 * 另给你一个二维整数数组 offers ，其中 offers[i] = [starti, endi, goldi] 表示第 i 个买家想要以 goldi
 * 枚金币的价格购买从 starti 到 endi 的所有房屋。
 *
 * 作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。
 *
 * 返回你可以赚取的金币的最大数目。
 *
 * 注意 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
 * 输出：3
 * 解释：
 * 有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
 * 将位于 [0,0] 范围内的房屋以 1 金币的价格出售给第 1 位买家，并将位于 [1,3] 范围内的房屋以 2 金币的价格出售给第 3 位买家。
 * 可以证明我们最多只能获得 3 枚金币。
 *
 * 示例 2：
 *
 * 输入：n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
 * 输出：10
 * 解释：有 5 所房屋，编号从 0 到 4 ，共有 3 个购买要约。
 * 将位于 [0,2] 范围内的房屋以 10 金币的价格出售给第 2 位买家。
 * 可以证明我们最多只能获得 10 枚金币。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * 1 <= offers.length <= 10^5
 * offers[i].length == 3
 * 0 <= starti <= endi <= n - 1
 * 1 <= goldi <= 10^3
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
    int maximizeTheProfit(int n, vector<vector<int>> &offers)
    {
        vector<int> vi(n + 1);
        sort(offers.begin(), offers.end(), [](vector<int> a, vector<int> b)
             {
                 if (a[1] < b[1])
                 {
                     return true;
                 }
                 else if (a[1] == b[1] && a[0] < b[0])
                 {
                     return true;
                 }
                 return false; });
        int temp = 0;
        for (int j = 0; j < offers.size(); j++)
        {
            int left = offers[j][0];
            int right = offers[j][1];
            int g = offers[j][2];
            int cur_max = 0;
            if (left > 0)
            {
                cur_max = vi[left];
            }
            int all = cur_max + g;
            temp = max(temp, all);
            for (int i = right + 1; i < n; i++)
            {
                vi[i] = max(vi[i], all);
            }
        }
        return vi[n - 1];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maximizeTheProfit
// paramTypes= ["number","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 5\n[[0,0,1],[0,2,2],[1,3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,0,1],[0,2,10],[1,3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,3,10],[1,3,3],[0,0,1],[0,0,7]]\n
// @lcpr case=end

 */
