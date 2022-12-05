/*
 * @lc app=leetcode.cn id=1687 lang=cpp
 * @lcpr version=20701
 *
 * [1687] 从仓库到码头运输箱子
 *
 * https://leetcode.cn/problems/delivering-boxes-from-storage-to-ports/description/
 *
 * algorithms
 * Hard (56.36%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 9.4K
 * Testcase Example:  '[[1,1],[2,1],[1,1]]\n2\n3\n3'
 *
 * 你有一辆货运卡车，你需要用这一辆车把一些箱子从仓库运送到码头。这辆卡车每次运输有 箱子数目的限制 和 总重量的限制 。
 *
 * 给你一个箱子数组 boxes 和三个整数 portsCount, maxBoxes 和 maxWeight ，其中 boxes[i] =
 * [ports​​i​, weighti] 。
 *
 *
 * ports​​i 表示第 i 个箱子需要送达的码头， weightsi 是第 i 个箱子的重量。
 * portsCount 是码头的数目。
 * maxBoxes 和 maxWeight 分别是卡车每趟运输箱子数目和重量的限制。
 *
 *
 * 箱子需要按照 数组顺序 运输，同时每次运输需要遵循以下步骤：
 *
 *
 * 卡车从 boxes 队列中按顺序取出若干个箱子，但不能违反 maxBoxes 和 maxWeight 限制。
 * 对于在卡车上的箱子，我们需要 按顺序 处理它们，卡车会通过 一趟行程 将最前面的箱子送到目的地码头并卸货。如果卡车已经在对应的码头，那么不需要 额外行程
 * ，箱子也会立马被卸货。
 * 卡车上所有箱子都被卸货后，卡车需要 一趟行程 回到仓库，从箱子队列里再取出一些箱子。
 *
 *
 * 卡车在将所有箱子运输并卸货后，最后必须回到仓库。
 *
 * 请你返回将所有箱子送到相应码头的 最少行程 次数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 3, maxWeight = 3
 * 输出：4
 * 解释：最优策略如下：
 * - 卡车将所有箱子装上车，到达码头 1 ，然后去码头 2 ，然后再回到码头 1 ，最后回到仓库，总共需要 4 趟行程。
 * 所以总行程数为 4 。
 * 注意到第一个和第三个箱子不能同时被卸货，因为箱子需要按顺序处理（也就是第二个箱子需要先被送到码头 2 ，然后才能处理第三个箱子）。
 *
 *
 * 示例 2：
 *
 * 输入：boxes = [[1,2],[3,3],[3,1],[3,1],[2,4]], portsCount = 3, maxBoxes = 3,
 * maxWeight = 6
 * 输出：6
 * 解释：最优策略如下：
 * - 卡车首先运输第一个箱子，到达码头 1 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第二、第三、第四个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第五个箱子，到达码头 3 ，回到仓库，总共 2 趟行程。
 * 总行程数为 2 + 2 + 2 = 6 。
 *
 *
 * 示例 3：
 *
 * 输入：boxes = [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]], portsCount = 3, maxBoxes =
 * 6, maxWeight = 7
 * 输出：6
 * 解释：最优策略如下：
 * - 卡车运输第一和第二个箱子，到达码头 1 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第三和第四个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第五和第六个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
 * 总行程数为 2 + 2 + 2 = 6 。
 *
 *
 * 示例 4：
 *
 * 输入：boxes = [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]],
 * portsCount = 5, maxBoxes = 5, maxWeight = 7
 * 输出：14
 * 解释：最优策略如下：
 * - 卡车运输第一个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第二个箱子，到达码头 2 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第三和第四个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第五个箱子，到达码头 3 ，然后回到仓库，总共 2 趟行程。
 * - 卡车运输第六和第七个箱子，到达码头 3 ，然后去码头 4 ，然后回到仓库，总共 3 趟行程。
 * - 卡车运输第八和第九个箱子，到达码头 1 ，然后去码头 5 ，然后回到仓库，总共 3 趟行程。
 * 总行程数为 2 + 2 + 2 + 2 + 3 + 3 = 14 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= boxes.length <= 10^5
 * 1 <= portsCount, maxBoxes, maxWeight <= 10^5
 * 1 <= ports​​i <= portsCount
 * 1 <= weightsi <= maxWeight
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
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// @lc code=start
// 前缀和重量
// dp[i][j] = x次

// class Solution
// {
// public:
//     vector<int> pre;
//     vector<vector<int>> dp;
//     vector<vector<int>> bbb;
//     int bbbportsCount;
//     int bbbmaxBoxes;
//     int bbbmaxWeight;
//     int dfs(int cur, int end)
//     {
//         if (dp[cur][end] >= 0)
//         {
//             return dp[cur][end];
//         }
//         int temp_min = 999999999;
//         for (int k = cur; k < end; k++)
//         {
//             temp_min = min(temp_min, dfs(cur, k) + dfs(k + 1, end));
//         }
//         dp[cur][end] = temp_min;
//         return temp_min;
//     }
//     int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
//     {

//         bbb = boxes;
//         bbbportsCount = portsCount;
//         bbbmaxBoxes = maxBoxes;
//         bbbmaxWeight = maxWeight;
//         int sum = 0;
//         for (int i = 0; i < boxes.size(); i++)
//         {
//             vector<int> &p = boxes[i];
//             int hei = p[1];
//             sum += hei;
//             pre.push_back(sum);
//         }
//         int n = boxes.size();
//         vector<vector<int>> vvi(n, vector<int>(n, -1));
//         for (int i = 0; i < n; i++)
//         {
//             vvi[i][i] = 2;
//         }
//         dp = vvi;
//         return dfs(0, n - 1);
//     }
// };
class Solution
{
public:
    vector<vector<int>> boxes;
    int ports, max_box, max_wt, n;
    vector<int> dp;

    int backtrack(int index)
    {
        if (index == n)
            return 0;
        if (dp[index] != 0)
            return dp[index];

        int start = index, end = index, currWt = boxes[index][1], boxCount = 1, lastPort = boxes[index][0], ports_visited = 0;

        while (end + 1 < n && currWt + boxes[end + 1][1] <= max_wt && boxCount + 1 <= max_box)
        {
            end++;
            currWt += boxes[end][1];
            boxCount++;
            if (lastPort != boxes[end][0])
            {
                ports_visited++;
                lastPort = boxes[end][0];
            }
        }

        int trips = 2 + ports_visited + backtrack(end + 1);

        int x = -1;
        for (int i = end - 1; i >= index; i--)
        {
            if (boxes[i][0] != lastPort)
            {

                x = i;
                break;
            }
        }
        if (x != -1)
        {
            trips = min(trips, 2 + ports_visited - 1 + backtrack(x + 1));
        }

        dp[index] = trips;

        return trips;
    }

    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight)
    {
        this->boxes = boxes;
        // ports,boxes
        n = boxes.size();
        dp.assign(n, 0);
        ports = portsCount;
        max_box = maxBoxes;
        max_wt = maxWeight;
        return backtrack(0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1],[2,1],[1,1]]\n2\n3\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,3],[3,1],[3,1],[2,4]]\n3\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[1,2],[2,1],[2,1],[3,2],[3,4]]\n3\n6\n7\n
// @lcpr case=end

// @lcpr case=start
// [[2,4],[2,5],[3,1],[3,2],[3,7],[3,1],[4,4],[1,3],[5,2]]\n5\n5\n7\n
// @lcpr case=end

 */
