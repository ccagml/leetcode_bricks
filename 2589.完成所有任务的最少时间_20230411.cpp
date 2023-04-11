/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 * @lcpr version=21905
 *
 * [2589] 完成所有任务的最少时间
 *
 * https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/description/
 *
 * algorithms
 * Hard (41.77%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 8.3K
 * Testcase Example:  '[[2,3,1],[4,5,1],[1,5,2]]'
 *
 * 你有一台电脑，它可以 同时 运行无数个任务。给你一个二维整数数组 tasks ，其中 tasks[i] = [starti, endi,
 * durationi] 表示第 i 个任务需要在 闭区间 时间段 [starti, endi] 内运行 durationi
 * 个整数时间点（但不需要连续）。
 *
 * 当电脑需要运行任务时，你可以打开电脑，如果空闲时，你可以将电脑关闭。
 *
 * 请你返回完成所有任务的情况下，电脑最少需要运行多少秒。
 *
 *
 *
 * 示例 1：
 *
 * 输入：tasks = [[2,3,1],[4,5,1],[1,5,2]]
 * 输出：2
 * 解释：
 * - 第一个任务在闭区间 [2, 2] 运行。
 * - 第二个任务在闭区间 [5, 5] 运行。
 * - 第三个任务在闭区间 [2, 2] 和 [5, 5] 运行。
 * 电脑总共运行 2 个整数时间点。
 *
 *
 * 示例 2：
 *
 * 输入：tasks = [[1,3,2],[2,5,3],[5,6,2]]
 * 输出：4
 * 解释：
 * - 第一个任务在闭区间 [2, 3] 运行
 * - 第二个任务在闭区间 [2, 3] 和 [5, 5] 运行。
 * - 第三个任务在闭区间 [5, 6] 运行。
 * 电脑总共运行 4 个整数时间点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tasks.length <= 2000
 * tasks[i].length == 3
 * 1 <= starti, endi <= 2000
 * 1 <= durationi <= endi - starti + 1
 *
 *
 */

// @lc code=start
class Solution
{
    bool run[2001];

public:
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int ans = 0;
        for (auto &t : tasks)
        {
            int start = t[0], end = t[1], d = t[2];
            for (int i = start; i <= end; ++i)
                d -= run[i];              // 去掉运行中的时间点
            for (int i = end; d > 0; --i) // 剩余的 d 填充区间后缀
                if (!run[i])
                {
                    run[i] = true;
                    --d;
                    ++ans;
                }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,3,1],[4,5,1],[1,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[2,5,3],[5,6,2]]\n
// @lcpr case=end

 */
