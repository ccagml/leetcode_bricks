/*
 * @lc app=leetcode.cn id=2250 lang=cpp
 *
 * [2250] 统计包含每个点的矩形数目
 *
 * https://leetcode.cn/problems/count-number-of-rectangles-containing-each-point/description/
 *
 * algorithms
 * Medium (33.59%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    5.8K
 * Total Submissions: 17.2K
 * Testcase Example:  '[[1,2],[2,3],[2,5]]\n[[2,1],[1,4]]'
 *
 * 给你一个二维整数数组 rectangles ，其中 rectangles[i] = [li, hi] 表示第 i 个矩形长为 li 高为 hi
 * 。给你一个二维整数数组 points ，其中 points[j] = [xj, yj] 是坐标为 (xj, yj) 的一个点。
 *
 * 第 i 个矩形的 左下角 在 (0, 0) 处，右上角 在 (li, hi) 。
 *
 * 请你返回一个整数数组 count ，长度为 points.length，其中 count[j]是 包含 第 j 个点的矩形数目。
 *
 * 如果 0 <= xj <= li 且 0 <= yj <= hi ，那么我们说第 i 个矩形包含第 j 个点。如果一个点刚好在矩形的 边上
 * ，这个点也被视为被矩形包含。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
 * 输出：[2,1]
 * 解释：
 * 第一个矩形不包含任何点。
 * 第二个矩形只包含一个点 (2, 1) 。
 * 第三个矩形包含点 (2, 1) 和 (1, 4) 。
 * 包含点 (2, 1) 的矩形数目为 2 。
 * 包含点 (1, 4) 的矩形数目为 1 。
 * 所以，我们返回 [2, 1] 。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
 * 输出：[1,3]
 * 解释：
 * 第一个矩形只包含点 (1, 1) 。
 * 第二个矩形只包含点 (1, 1) 。
 * 第三个矩形包含点 (1, 3) 和 (1, 1) 。
 * 包含点 (1, 3) 的矩形数目为 1 。
 * 包含点 (1, 1) 的矩形数目为 3 。
 * 所以，我们返回 [1, 3] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rectangles.length, points.length <= 5 * 10^4
 * rectangles[i].length == points[j].length == 2
 * 1 <= li, xj <= 10^9
 * 1 <= hi, yj <= 100
 * 所有 rectangles 互不相同 。
 * 所有 points 互不相同 。
 *
 *
 */

// @lc code=start
// 想法1: 一个vector<set<int> 按高度放入对应set中, 查找 points.y 到 100 中 大于 points.x 的数量和
// Time Limit Exceeded
// 47/47 cases passed (N/A)
// class Solution
// {
// public:
//     vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
//     {
//         map<int, set<int>> ks;
//         for (int i = 0; i < rectangles.size(); i++)
//         {
//             int hi = rectangles[i][1];
//             int xi = rectangles[i][0];
//             ks[hi].insert(xi);
//             // std::cout << xi << ":" << hi << std::endl;
//         }
//         int n = points.size();
//         vector<int> result(n);
//         for (int i = 0; i < points.size(); i++)
//         {
//             int xj = points[i][0];
//             int yj = points[i][1];
//             int temp = 0;
//             // std::cout << "查找(" <<  xj << ":" << yj << ")";

//             auto map_key = ks.lower_bound(yj);
//             if (map_key != ks.end())
//             {
//                 for (auto iter = map_key; iter != ks.end(); ++iter)
//                 {
//                     auto key = iter->second.lower_bound(xj);
//                     int cur_add = 0;
//                     if (key != iter->second.end())
//                     {
//                         cur_add = iter->second.size() - std::distance(iter->second.begin(), key);
//                     }
//                     temp += cur_add;
//                 }
//             }
//             result[i] = temp;
//         }
//         return result;
//     }
// };
// 想法可以过 
// set 的lower_bound 使用distance计算距离是O(n) 会超时 47/47
// 换成vector 排个序就行
class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        map<int, vector<int>> ks;
        for (int i = 0; i < rectangles.size(); i++)
        {
            int hi = rectangles[i][1];
            int xi = rectangles[i][0];
            ks[hi].push_back(xi);
            // std::cout << xi << ":" << hi << std::endl;
        }
        int n = points.size();
        vector<int> result(n);
        for (auto iter = ks.begin(); iter != ks.end(); ++iter)
        {
            sort(iter->second.begin(), iter->second.end());
            // std::cout << "\"" << iter->first << "\" = \"" << iter->second << "\"\n";
        }

        for (int i = 0; i < points.size(); i++)
        {
            int xj = points[i][0];
            int yj = points[i][1];
            int temp = 0;
            // std::cout << "查找(" <<  xj << ":" << yj << ")";

            auto map_key = ks.lower_bound(yj);
            if (map_key != ks.end())
            {
                for (auto iter = map_key; iter != ks.end(); ++iter)
                {
                    auto key = std::lower_bound(iter->second.begin(), iter->second.end(), xj);
                    int cur_add = 0;
                    if (key != iter->second.end())
                    {
                        cur_add = iter->second.size() - std::distance(iter->second.begin(), key);
                    }
                    temp += cur_add;
                }
            }
            result[i] = temp;
        }
        return result;
    }
};
// @lc code=end
