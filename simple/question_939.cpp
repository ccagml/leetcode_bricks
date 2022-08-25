/*
 * @lc app=leetcode.cn id=939 lang=cpp
 *
 * [939] 最小面积矩形
 *
 * https://leetcode.cn/problems/minimum-area-rectangle/description/
 *
 * algorithms
 * Medium (47.31%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 15.7K
 * Testcase Example:  '[[1,1],[1,3],[3,1],[3,3],[2,2]]'
 *
 * 给定在 xy 平面上的一组点，确定由这些点组成的矩形的最小面积，其中矩形的边平行于 x 轴和 y 轴。
 *
 * 如果没有任何矩形，就返回 0。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[[1,1],[1,3],[3,1],[3,3],[2,2]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 * 输出：2
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= points.length <= 500
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * 所有的点都是不同的。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int max_result = 40000 * 40000 + 10000;
        int cur_result = max_result;
        int n = points.size();

        unordered_map<int, unordered_set<int>> x_to_y;
        // unordered_map<int, unordered_set<int>> y_to_x;

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            x_to_y[x].insert(y);
            // y_to_x[y].insert(x);
        }

        /*
        (ax, ay)          (nbx, ay)


        (nax, nby)        (bx,by)
        */

        sort(points.begin(), points.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int ax = points[i][0];
                int ay = points[i][1];
                int bx = points[j][0];
                int by = points[j][1];
                if (ax != bx && ay != by)
                {
                    int lenx = abs(ax - bx);
                    int leny = abs(ay - by);
                    if (lenx * leny < cur_result && x_to_y.count(bx) > 0 && x_to_y[bx].count(ay) > 0 && x_to_y.count(ax) > 0 && x_to_y[ax].count(by) > 0)
                    {
                        cur_result = lenx * leny;
                    }
                }
            }
        }

        return cur_result < max_result ? cur_result : 0;
    }
};
// @lc code=end
