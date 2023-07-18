// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1851 lang=cpp
 * @lcpr version=21910
 *
 * [1851] 包含每个查询的最小区间
 *
 * https://leetcode.cn/problems/minimum-interval-to-include-each-query/description/
 *
 * algorithms
 * Hard (44.23%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 10K
 * Testcase Example:  '[[1,4],[2,4],[3,6],[4,4]]\n[2,3,4,5]'
 *
 * 给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti
 * 、结束于 righti（包含两侧取值，闭区间）。区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。
 *
 * 再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i
 * 的长度 。如果不存在这样的区间，那么答案是 -1 。
 *
 * 以数组形式返回对应查询的所有答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
 * 输出：[3,3,1,4]
 * 解释：查询处理如下：
 * - Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
 * - Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
 * - Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
 * - Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。
 *
 *
 * 示例 2：
 *
 * 输入：intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
 * 输出：[2,-1,4,6]
 * 解释：查询处理如下：
 * - Query = 2 ：区间 [2,3] 是包含 2 的最小区间，答案为 3 - 2 + 1 = 2 。
 * - Query = 19：不存在包含 19 的区间，答案为 -1 。
 * - Query = 5 ：区间 [2,5] 是包含 5 的最小区间，答案为 5 - 2 + 1 = 4 。
 * - Query = 22：区间 [20,25] 是包含 22 的最小区间，答案为 25 - 20 + 1 = 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 1 <= lefti <= righti <= 10^7
 * 1 <= queries[j] <= 10^7
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
int temp_max = 99999999;

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {

        // 自定义比较函数pair//返回true使得第一个参数排后面
        auto cmp_pair = [](const std::pair<int, int> &t1, const std::pair<int, int> &t2)
        {
            // true使得t1排后面?
            if (t1.first > t2.first)
            {
                return true;
            }
            else if (t1.first == t2.first && t1.second > t2.second)
            {
                return true;
            }
            return false;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp_pair)> pair_pq(cmp_pair);
        unordered_set<int> usi;
        vector<int> vi;
        for (int q : queries)
        {
            usi.insert(q);
        }
        for (int q : usi)
        {
            vi.push_back(q);
        }
        sort(vi.begin(), vi.end());
        sort(intervals.begin(), intervals.end());
        int vii = 0;
        int ii = 0;
        unordered_map<int, int> umii;
        while (vii < vi.size())
        {
            int need_check = vi[vii];
            while (ii < intervals.size())
            {
                int a = intervals[ii][0];
                int b = intervals[ii][1];
                int len = b - a + 1;
                if (a <= need_check)
                {
                    pair_pq.push({len, a});
                    ii++;
                }
                else
                {
                    break;
                }
            }

            // 过滤掉无效区间
            while (pair_pq.size() > 0)
            {
                pair<int, int> top = pair_pq.top();
                int a = top.second;
                int c = top.first;
                int b = c + a - 1;
                if (b < need_check)
                {
                    pair_pq.pop();
                }
                else
                {
                    break;
                }
            }
            // 结果
            if (pair_pq.size() == 0)
            {
                umii[need_check] = -1;
            }
            else
            {
                pair<int, int> top = pair_pq.top();
                int a = top.second;
                int c = top.first;
                int b = c + a - 1;
                if (a > need_check)
                {
                    umii[need_check] = -1;
                }
                else
                {
                    umii[need_check] = c;
                }
            }
            vii++;
        }
        vector<int> result;
        for (int q : queries)
        {
            result.push_back(umii[q]);
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minInterval
// paramTypes= ["number[][]","number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,4],[2,4],[3,6],[4,4]]\n[2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[2,5],[1,8],[20,25]]\n[2,19,5,22]\n
// @lcpr case=end

// @lcpr case=start
// [[4,5],[5,8],[1,9],[8,10],[1,6]]\n[7,9,3,9,3]\n
// @lcpr case=end
//[4,3,6,3,6]

 */
