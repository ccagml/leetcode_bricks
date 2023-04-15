// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 * @lcpr version=21906
 *
 * [1042] 不邻接植花
 *
 * https://leetcode.cn/problems/flower-planting-with-no-adjacent/description/
 *
 * algorithms
 * Medium (55.43%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    19.7K
 * Total Submissions: 34.3K
 * Testcase Example:  '3\n[[1,2],[2,3],[3,1]]'
 *
 * 有 n 个花园，按从 1 到 n 标记。另有数组 paths ，其中 paths[i] = [xi, yi] 描述了花园 xi 到花园 yi
 * 的双向路径。在每个花园中，你打算种下四种花之一。
 *
 * 另外，所有花园 最多 有 3 条路径可以进入或离开.
 *
 * 你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
 *
 * 以数组形式返回 任一 可行的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用
 * 1、2、3、4 表示。保证存在答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3, paths = [[1,2],[2,3],[3,1]]
 * 输出：[1,2,3]
 * 解释：
 * 花园 1 和 2 花的种类不同。
 * 花园 2 和 3 花的种类不同。
 * 花园 3 和 1 花的种类不同。
 * 因此，[1,2,3] 是一个满足题意的答案。其他满足题意的答案有 [1,2,4]、[1,4,2] 和 [3,2,1]
 *
 *
 * 示例 2：
 *
 * 输入：n = 4, paths = [[1,2],[3,4]]
 * 输出：[1,2,1,2]
 *
 *
 * 示例 3：
 *
 * 输入：n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
 * 输出：[1,2,3,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 * 0 <= paths.length <= 2 * 10^4
 * paths[i].length == 2
 * 1 <= xi, yi <= n
 * xi != yi
 * 每个花园 最多 有 3 条路径可以进入或离开
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
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }
    int set_bit_0(int x, int index)
    {
        x &= ~(1 << index);
        return x;
    }

    bool is_bit_1(int x, int index)
    {
        return ((1 << index) & (x));
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<int> result(n);
        queue<int> qi;
        qi.push(1);
        unordered_map<int, int> umi;
        unordered_map<int, vector<int>> uv;

        for (int i = 0; i < paths.size(); i++)
        {
            int a = paths[i][0];
            int b = paths[i][1];
            uv[a].push_back(b);
            uv[b].push_back(a);
        }
        // std::cout << " 1111 " << std::endl;
        while (qi.size() > 0)
        {
            int cur = qi.front();
            // std::cout << " 111 cur " << cur << std::endl;
            qi.pop();
            // cur可以上的颜色
            int temp = 0;
            for (int j : uv[cur])
            {
                // std::cout << " 111 cur " << cur << "j:" << j << std::endl;
                if (result[j - 1] > 0)
                {
                    temp = set_bit_1(temp, result[j - 1]);
                }
                else
                {
                    qi.push(j);
                }
            }

            // std::cout << " 222 cur " << cur << std::endl;
            for (int k = 1; k <= 4; k++)
            {
                if (!is_bit_1(temp, k))
                {
                    result[cur - 1] = k;
                    break;
                }
            }
            // std::cout << " 333 cur " << cur << std::endl;
            if (qi.size() == 0)
            {
                for (int i = 0; i < result.size(); i++)
                {
                    if (result[i] == 0)
                    {
                        qi.push(i + 1);
                        break;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n[[1,2],[2,3],[3,1]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2],[3,4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]\n
// @lcpr case=end

 */
