/*
 * @lc app=leetcode.cn id=850 lang=cpp
 *
 * [850] 矩形面积 II
 *
 * https://leetcode.cn/problems/rectangle-area-ii/description/
 *
 * algorithms
 * Hard (57.83%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 12.4K
 * Testcase Example:  '[[0,0,2,2],[1,0,2,3],[1,0,3,1]]'
 *
 * 我们给出了一个（轴对齐的）二维矩形列表 rectangles 。 对于 rectangle[i] = [x1, y1, x2,
 * y2]，其中（x1，y1）是矩形 i 左下角的坐标， (xi1, yi1) 是该矩形 左下角 的坐标， (xi2, yi2) 是该矩形 右上角
 * 的坐标。
 *
 * 计算平面中所有 rectangles 所覆盖的 总面积 。任何被两个或多个矩形覆盖的区域应只计算 一次 。
 *
 * 返回 总面积 。因为答案可能太大，返回 10^9 + 7 的 模 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：rectangles = [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
 * 输出：6
 * 解释：如图所示，三个矩形覆盖了总面积为6的区域。
 * 从(1,1)到(2,2)，绿色矩形和红色矩形重叠。
 * 从(1,0)到(2,3)，三个矩形都重叠。
 *
 *
 * 示例 2：
 *
 *
 * 输入：rectangles = [[0,0,1000000000,1000000000]]
 * 输出：49
 * 解释：答案是 10^18 对 (10^9 + 7) 取模的结果， 即 49 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rectangles.length <= 200
 * rectanges[i].length = 4
 * 0 <= xi1, yi1, xi2, yi2 <= 10^9
 * 矩形叠加覆盖后的总面积不会超越 2^63 - 1 ，这意味着可以用一个 64 位有符号整数来保存面积结果。
 *
 *
 */

// @lc code=start

// 离散化 扫描线 不懂

// [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
// 0, 1, 2, 3

// class Solution0
// {
// public:
//     int rectangleArea(vector<vector<int>> &rectangles)
//     {
//         int n = rectangles.size();
//         vector<int> hbound;
//         set<int> hs;
//         for (int i = 0; i < n; i++)
//         {
//             hs.insert(rectangles[i][1]);
//             hs.insert(rectangles[i][3]);
//         }
//         for (auto &get : hs)
//         {
//             hbound.push_back(get);
//         }
//         int m = hbound.size();
//         // 「思路与算法部分」的 length 数组并不需要显式地存储下来
//         // length[i] 可以通过 hbound[i+1] - hbound[i] 得到
//         vector<int> seg(m - 1);

//         vector<tuple<int, int, int>> sweep;
//         for (int i = 0; i < n; ++i)
//         {
//             // 左边界
//             sweep.push_back({rectangles[i][0], i, 1});
//             // 右边界
//             sweep.push_back({rectangles[i][2], i, -1});
//         }
//         sort(sweep.begin(), sweep.end());

//         long long ans = 0;
//         for (int i = 0; i < sweep.size(); ++i)
//         {
//             int j = i;
//             while (j + 1 < sweep.size() && get<0>(sweep[i]) == get<0>(sweep[j + 1]))
//             {
//                 ++j;
//             }
//             if (j + 1 == sweep.size())
//             {
//                 break;
//             }
//             // 一次性地处理掉一批横坐标相同的左右边界

//             for (int k = i; k <= j; ++k)
//             {
//                 auto &&[_, idx, diff] = sweep[k];
//                 int left = rectangles[idx][1], right = rectangles[idx][3];

//                 for (int x = 0; x < m - 1; ++x)
//                 {
//                     if (left <= hbound[x] && hbound[x + 1] <= right)
//                     {
//                         seg[x] += diff;
//                     }
//                 }
//             }
//             int cover = 0;
//             for (int k = 0; k < m - 1; ++k)
//             {
//                 if (seg[k] > 0)
//                 {
//                     cover += (hbound[k + 1] - hbound[k]);
//                 }
//             }
//             std::cout << "cur" << i << "," << j << "," << cover << "|";
//             ans += static_cast<long long>(cover) * (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
//             // std::cout << "(" << cover << "*" << ((get<0>(sweep[j + 1]))) << "-" << get<0>(sweep[j]) << "=" << cover * (get<0>(sweep[j + 1]) - get<0>(sweep[j])) << ") = " << ans << "||";
//             i = j;
//         }
//         return ans % static_cast<int>(1e9 + 7);
//     }
// };

// 写了很久
/*
离散化 + 扫描线
1.高度去重放入 排序放入数组中
2.横坐标的左右两边放入一个数组中, 注意可能左右两边值一样(调试了很久)就不需要放入了(没有面积)
3.横坐标排序
4.遍历横坐标数组,计算所有相同的点
5.将点在高度数组对应部分打上标记,如果是左边就+, 右边就-
6.计算所有 高度标记>0的总长度 * 当前坐标到下一段坐标的长度 就是本部分的面积


*/

class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        set<int> hs;
        for (int i = 0; i < n; i++)
        {
            hs.insert(rectangles[i][1]);
            hs.insert(rectangles[i][3]);
        }
        vector<int> height_node;
        for (auto &get : hs)
        {
            height_node.push_back(get);
        }

        int height_size = height_node.size();
        vector<int> heright_flag(height_size);

        vector<pair<int, int>> all_x;
        for (int i = 0; i < rectangles.size(); i++)
        {
            if (rectangles[i][0] != rectangles[i][2])
            {
                all_x.push_back({rectangles[i][0], i});
                all_x.push_back({rectangles[i][2], i});
            }
        }
        sort(all_x.begin(), all_x.end());

        long long result = 0;
        for (int i = 0; i < all_x.size(); i++)
        {
            int i_x = all_x[i].first;
            int all_i = i;

            while (all_i + 1 < all_x.size() && all_x[all_i + 1].first == i_x)
            {
                all_i++;
            }
            // 全扫完了
            if (all_i + 1 >= all_x.size())
            {
                break;
            }

            // 打高度标记
            for (int check_i = i; check_i <= all_i; check_i++)
            {
                pair<int, int> pii = all_x[check_i];
                vector<int> node_info = rectangles[pii.second];
                int node_low = node_info[1];
                int node_top = node_info[3];

                // 判断是左右边

                bool left_flag = !(node_info[2] == pii.first);
                for (int hi = 0; hi < heright_flag.size() - 1; hi++)
                {
                    if (node_low <= height_node[hi] && node_top >= height_node[hi + 1])
                    {
                        left_flag ? (heright_flag[hi]++) : (heright_flag[hi]--);
                    }
                }
            }
            // 计算覆盖段数
            long long cur_height = 0;
            for (int ttt = 0; ttt < heright_flag.size() - 1; ttt++)
            {
                if (heright_flag[ttt] > 0)
                {
                    cur_height += ((height_node[ttt + 1]) - (height_node[ttt]));
                }
            }
            // std::cout << "cur" << i << "," << all_i << "," << cur_height << "|";

            result += cur_height * (all_x[all_i + 1].first - all_x[i].first);

            i = all_i;
        }
        int mod = 1e9 + 7;
        return result % mod;
    };
};

// @lc code=end
