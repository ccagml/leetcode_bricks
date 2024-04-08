// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1847 lang=cpp
 * @lcpr version=30121
 *
 * [1847] 最近的房间
 *
 * https://leetcode.cn/problems/closest-room/description/
 *
 * algorithms
 * Hard (40.79%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 10.5K
 * Testcase Example:  '[[2,2],[1,2],[3,2]]\n[[3,1],[3,3],[5,2]]'
 *
 * 一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为
 * roomIdi 的房间且它的面积为 sizei 。每一个房间号 roomIdi 保证是 独一无二 的。
 *
 * 同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。第 j
 * 个查询的答案是满足如下条件的房间 id ：
 *
 *
 * 房间的面积 至少 为 minSizej ，且
 * abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。
 *
 *
 * 如果差的绝对值有 相等 的，选择 最小 的 id 。如果 没有满足条件的房间 ，答案为 -1 。
 *
 * 请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。
 *
 *
 *
 * 示例 1：
 *
 * 输入：rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
 * 输出：[3,-1,3]
 * 解释：查询的答案如下：
 * 查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
 * 查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
 * 查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。
 *
 * 示例 2：
 *
 * 输入：rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
 * 输出：[2,1,3]
 * 解释：查询的答案如下：
 * 查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
 * 查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
 * 查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。
 *
 *
 *
 * 提示：
 *
 *
 * n == rooms.length
 * 1 <= n <= 10^5
 * k == queries.length
 * 1 <= k <= 10^4
 * 1 <= roomIdi, preferredj <= 10^7
 * 1 <= sizei, minSizej <= 10^7
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <set>
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
    int findClosest(const std::set<int> &s, int target)
    {
        auto it = s.lower_bound(target);
        if (it == s.begin())
        {
            return *it;
        }
        auto prev = std::prev(it);
        if (it == s.end() || std::abs(static_cast<int>(*it - target)) >= std::abs(static_cast<int>(*prev - target)))
        {
            return *prev;
        }
        else
        {
            return *it;
        }
    }
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        int TYPE_ROOM = 1;
        int TYPE_QUE = 2;

        // tuple<int, int, int> t1 = make_tuple(1, 1, 1);
        vector<tuple<int, int, int>> vt;

        for (int i = 0; i < rooms.size(); i++)
        {
            vt.push_back({rooms[i][0], rooms[i][1], TYPE_ROOM});
        }
        for (int i = 0; i < queries.size(); i++)
        {
            vt.push_back({queries[i][0], queries[i][1], TYPE_QUE});
        }

        sort(vt.begin(), vt.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b)
             {
                 if (std::get<1>(a) > std::get<1>(b))
                 {
                     return true;
                 }else if(std::get<1>(a) == std::get<1>(b) && std::get<2>(a) < std::get<2>(b) ){
                    return true;
                 } 
                 return false; });
        int cur_min_room = 999999999;
        set<int> si;

        unordered_map<int, unordered_map<int, int>> umumii;
        // 查询 room = size = result
        for (int jj = 0; jj < vt.size(); jj++)
        {
            int id = std::get<0>(vt[jj]);
            int id_size = std::get<1>(vt[jj]);
            int id_type = std::get<2>(vt[jj]);
            if (id_type == TYPE_ROOM)
            {
                si.insert(id);
                cur_min_room = min(cur_min_room, id_size);
            }
            else if (id_type == TYPE_QUE)
            {
                if (si.size() == 0)
                {
                    // 没结果
                    umumii[id][id_size] = -1;
                }
                else
                {
                    if (id_size > cur_min_room)
                    {
                        // 没结果
                        umumii[id][id_size] = -1;
                    }
                    else
                    {
                        // 有结果,si中最接近id的数字
                        int value = id;

                        umumii[id][id_size] = findClosest(si, value);
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++)
        {
            result.push_back(umumii[queries[i][0]][queries[i][1]]);
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=closestRoom
// paramTypes= ["number[][]","number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[2,2],[1,2],[3,2]]\n[[3,1],[3,3],[5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[2,3],[3,5],[4,1],[5,2]]\n[[2,3],[2,4],[2,5]]\n
// @lcpr case=end

 */
