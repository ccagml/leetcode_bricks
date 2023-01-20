/*
 * @lc app=leetcode.cn id=1411 lang=cpp
 * @lcpr version=21113
 *
 * [1411] 给 N x 3 网格图涂色的方案数
 *
 * https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid/description/
 *
 * algorithms
 * Hard (56.71%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 16.7K
 * Testcase Example:  '1'
 *
 * 你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿
 * 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。
 *
 * 给你网格图的行数 n 。
 *
 * 请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 1
 * 输出：12
 * 解释：总共有 12 种可行的方法：
 *
 *
 *
 * 示例 2：
 *
 * 输入：n = 2
 * 输出：54
 *
 *
 * 示例 3：
 *
 * 输入：n = 3
 * 输出：246
 *
 *
 * 示例 4：
 *
 * 输入：n = 7
 * 输出：106494
 *
 *
 * 示例 5：
 *
 * 输入：n = 5000
 * 输出：30228214
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == grid.length
 * grid[i].length == 3
 * 1 <= n <= 5000
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
    int numOfWays(int n)
    {
        int mod = 1e9 + 7;
        vector<int> vi;
        unordered_map<int, unordered_set<int>> check;
        unordered_map<int, int> kk_index;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (i != j && j != k)
                    {
                        int kk = 100 * i + 10 * j + k;
                        kk_index[kk] = vi.size();
                        vi.push_back(kk);
                        check[kk] = unordered_set<int>();
                    }
                }
            }
        }

        for (int i = 0; i < vi.size(); i++)
        {

            for (int j = i; j < vi.size(); j++)
            {
                int cur = vi[i];
                int c1 = cur % 10;
                cur /= 10;
                int b1 = cur % 10;
                cur /= 10;
                int a1 = cur;

                int cur2 = vi[j];
                int c2 = cur2 % 10;
                cur2 /= 10;
                int b2 = cur2 % 10;
                cur2 /= 10;
                int a2 = cur2;
                if (a1 != a2 && b1 != b2 && c1 != c2)
                {
                    int vii = vi[i];
                    int vij = vi[j];
                    check[vii].insert(vij);
                    check[vij].insert(vii);

                    // std::cout << "(" << vii << "," << vij << "|" << a1 << "-" << b1 << "-" << c1 << "|" << a2 << "-" << b2 << "-" << c2
                    //           << ")";
                }
            }
        }
        // vvi[n][type] = 1
        vector<vector<int>> vvi(n, vector<int>(vi.size()));
        for (int i = 0; i < n; i++)
        {
            for (int type : vi)
            {
                int type_index = kk_index[type];
                if (i == 0)
                {
                    vvi[0][type_index] = 1;
                }
                else
                {
                    unordered_set<int> last = check[type];
                    for (auto p : last)
                    {
                        int p_index = kk_index[p];
                        vvi[i][type_index] += vvi[i - 1][p_index];
                        vvi[i][type_index] %= mod;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < vi.size(); i++)
        {
            sum += vvi[n - 1][i];
            sum %= mod;
        }
        return sum;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 5000\n
// @lcpr case=end

 */
