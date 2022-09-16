/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 *
 * https://leetcode.cn/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (46.13%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 53.6K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
 * 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
 *
 * 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * 输出：true
 * 解释：5 个矩形一起可以精确地覆盖一个矩形区域。
 *
 *
 * 示例 2：
 *
 *
 * 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * 输出：false
 * 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
 *
 * 示例 3：
 *
 *
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * 输出：false
 * 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 *
 *
 */

// @lc code=start
// 扫描线
// 超时
// 可以把打标记的部分换成线段树再试试看
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        unordered_set<int> si;
        for (int i = 0; i < rectangles.size(); i++)
        {
            si.insert(rectangles[i][1]);
            si.insert(rectangles[i][3]);
        }
        vector<int> vi_height;
        for (auto &get : si)
        {
            vi_height.push_back(get);
        }
        sort(vi_height.begin(), vi_height.end());
        vector<int> vi_height_flag(vi_height.size());

        // 左右
        vector<pair<int, int>> vpii;
        for (int i = 0; i < rectangles.size(); i++)
        {
            if (rectangles[i][0] != rectangles[i][2])
            {
                vpii.push_back({rectangles[i][0], i});
                vpii.push_back({rectangles[i][2], i});
            }
        }
        sort(vpii.begin(), vpii.end());
        for (int i = 0; i < vpii.size(); i++)
        {
            int j = i;
            int cur_x = vpii[i].first;
            while (j + 1 < vpii.size() && vpii[j + 1].first == cur_x)
            {
                j++;
            }
            if (j >= vpii.size() - 1)
            {
                break;
            }
            // 打标记
            for (int flag_i = 0; flag_i < vi_height.size() - 1; flag_i++)
            {
                for (int node_start = i; node_start <= j; node_start++)
                {
                    int node_id = vpii[node_start].second;
                    bool is_left = (vpii[node_start].first == rectangles[node_id][0]);
                    int node_low = rectangles[node_id][1];
                    int node_top = rectangles[node_id][3];
                    if (node_low <= vi_height[flag_i] && node_top >= vi_height[flag_i + 1])
                    {
                        is_left ? (vi_height_flag[flag_i]++) : (vi_height_flag[flag_i]--);
                    }
                }
                if (vi_height_flag[flag_i] != 1)
                {
                    // std::cout <<  i << ":" << j << ":" << flag_i << ":" << vi_height_flag[flag_i] << std::endl;
                    return false;
                }
            }

            i = j;
        }

        return true;
    }
};
// @lc code=end
