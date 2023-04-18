/*
 * @lc app=leetcode.cn id=2251 lang=cpp
 * @lcpr version=21906
 *
 * [2251] 花期内花的数目
 *
 * https://leetcode.cn/problems/number-of-flowers-in-full-bloom/description/
 *
 * algorithms
 * Hard (48.90%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 13.1K
 * Testcase Example:  '[[1,6],[3,7],[9,12],[4,13]]\n[2,3,7,11]'
 *
 * 给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从
 * starti 到 endi （都 包含）。同时给你一个下标从 0 开始大小为 n 的整数数组 persons ，persons[i] 是第 i
 * 个人来看花的时间。
 *
 * 请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
 * 输出：[1,2,2,2]
 * 解释：上图展示了每朵花的花期时间，和每个人的到达时间。
 * 对每个人，我们返回他们到达时在花期内花的数目。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：flowers = [[1,10],[3,3]], persons = [3,3,2]
 * 输出：[2,2,1]
 * 解释：上图展示了每朵花的花期时间，和每个人的到达时间。
 * 对每个人，我们返回他们到达时在花期内花的数目。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= flowers.length <= 5 * 10^4
 * flowers[i].length == 2
 * 1 <= starti <= endi <= 10^9
 * 1 <= persons.length <= 5 * 10^4
 * 1 <= persons[i] <= 10^9
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
class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {
        int n = flowers.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; ++i)
        {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        n = persons.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = (upper_bound(starts.begin(), starts.end(), persons[i]) - starts.begin()) -
                     (lower_bound(ends.begin(), ends.end(), persons[i]) - ends.begin());
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,6],[3,7],[9,12],[4,13]]\n[2,3,7,11]\n
// @lcpr case=end

// @lcpr case=start
// [[1,10],[3,3]]\n[3,3,2]\n
// @lcpr case=end

 */
