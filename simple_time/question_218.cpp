/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 *
 * https://leetcode.cn/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (55.11%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    43.4K
 * Total Submissions: 78.8K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * 城市的 天际线 是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回 由这些建筑物形成的 天际线 。
 *
 * 每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti]
 * 表示：
 *
 *
 * lefti 是第 i 座建筑物左边缘的 x 坐标。
 * righti 是第 i 座建筑物右边缘的 x 坐标。
 * heighti 是第 i 座建筑物的高度。
 *
 *
 * 你可以假设所有的建筑都是完美的长方形，在高度为 0 的绝对平坦的表面上。
 *
 * 天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序
 * 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0
 * ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
 *
 * 注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...]
 * 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * 输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * 解释：
 * 图 A 显示输入的所有建筑物的位置和高度，
 * 图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
 *
 * 示例 2：
 *
 *
 * 输入：buildings = [[0,2,3],[2,5,3]]
 * 输出：[[0,3],[5,0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= buildings.length <= 10^4
 * 0 <= lefti < righti <= 2^31 - 1
 * 1 <= heighti <= 2^31 - 1
 * buildings 按 lefti 非递减排序
 *
 *
 */

// @lc code=start
// 扫描线
// 850 之后 显得 218很简单, 调试用得很久
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        // 高度去重
        set<int> si;
        for (int i = 0; i < buildings.size(); i++)
        {
            si.insert(buildings[i][2]);
        }
        vector<int> vi_height;
        for (auto &get : si)
        {
            vi_height.push_back(get);
        }

        int cur_height = 0;
        vector<pair<int, int>> heng;
        for (int i = 0; i < buildings.size(); i++)
        {
            heng.push_back({buildings[i][0], i});
            heng.push_back({buildings[i][1], i});
        }
        sort(heng.begin(), heng.end());
        vector<int> vi_height_flag(vi_height.size());
        vector<vector<int>> result;
        for (int i = 0; i < heng.size(); i++)
        {
            int cur_x = heng[i].first;
            int j = i;
            while (j + 1 < heng.size() && heng[j + 1].first == cur_x)
            {
                j++;
            }

            // 打所有这个点
            int new_height = 0;
            for (int all_i = i; all_i <= j; all_i++)
            {
                int node_id = heng[all_i].second;
                int node_height = buildings[node_id][2];
                bool is_left = (heng[all_i].first == buildings[node_id][0]);
                // 打高度标记
                for (int hi = 0; hi < vi_height.size(); hi++)
                {
                    if (vi_height[hi] <= node_height)
                    {
                        is_left ? (vi_height_flag[hi]++) : (vi_height_flag[hi]--);
                    }

                    // std::cout << "(" << node_id << ":left:" << is_left << ":vih:" << vi_height[hi] << ":node_height:" << node_height << ":flag:" << vi_height_flag[hi] << "),";
                }
            }
            for (int hi = 0; hi < vi_height.size(); hi++)
            {
                if (vi_height_flag[hi] > 0)
                {
                    new_height = max(vi_height[hi], new_height);
                }
            }
            // std::cout << "点" << i << "," << new_height << ":" << cur_height << std::endl;
            if (new_height != cur_height)
            {
                cur_height = new_height;
                result.push_back({cur_x, new_height});
            }
            i = j;
        }
        return result;
    }
};
// @lc code=end
