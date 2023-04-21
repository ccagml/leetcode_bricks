// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2271 lang=cpp
 * @lcpr version=21906
 *
 * [2271] 毯子覆盖的最多白色砖块数
 *
 * https://leetcode.cn/problems/maximum-white-tiles-covered-by-a-carpet/description/
 *
 * algorithms
 * Medium (32.26%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    5.8K
 * Total Submissions: 17.9K
 * Testcase Example:  '[[1,5],[10,11],[12,18],[20,25],[30,32]]\n10'
 *
 * 给你一个二维整数数组 tiles ，其中 tiles[i] = [li, ri] ，表示所有在 li <= j <= ri 之间的每个瓷砖位置 j
 * 都被涂成了白色。
 *
 * 同时给你一个整数 carpetLen ，表示可以放在 任何位置 的一块毯子。
 *
 * 请你返回使用这块毯子，最多 可以盖住多少块瓷砖。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
 * 输出：9
 * 解释：将毯子从瓷砖 10 开始放置。
 * 总共覆盖 9 块瓷砖，所以返回 9 。
 * 注意可能有其他方案也可以覆盖 9 块瓷砖。
 * 可以看出，瓷砖无法覆盖超过 9 块瓷砖。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：tiles = [[10,11],[1,1]], carpetLen = 2
 * 输出：2
 * 解释：将毯子从瓷砖 10 开始放置。
 * 总共覆盖 2 块瓷砖，所以我们返回 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tiles.length <= 5 * 10^4
 * tiles[i].length == 2
 * 1 <= li <= ri <= 10^9
 * 1 <= carpetLen <= 10^9
 * tiles 互相 不会重叠 。
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
    int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        int result = 0;
        int temp_result = 0;
        int temp_pos = 0;
        int temp_index = 0;
        for (int head = 0; head < tiles.size(); head++)
        {
            if (head == 0)
            {
                int head_end = tiles[head][0] + carpetLen - 1;
                int index_end = tiles[temp_index][1];

                // 全覆盖
                while (head_end >= index_end && temp_index < tiles.size())
                {
                    temp_result += (tiles[temp_index][1] - tiles[temp_index][0] + 1);
                    temp_index++;
                    if (temp_index >= tiles.size())
                    {
                        return max(temp_result, result);
                    }
                    index_end = tiles[temp_index][1];
                }
                // 计算偏移
                int index_start = tiles[temp_index][0];
                temp_pos = max(0, (head_end + 1) - index_start);

                result = max(result, temp_result + temp_pos);
            }
            else
            {
                temp_result -= (tiles[head - 1][1] - tiles[head - 1][0] + 1);

                int head_end = tiles[head][0] + carpetLen - 1;
                int index_end = tiles[temp_index][1];

                // 全覆盖
                while (head_end >= index_end && temp_index < tiles.size())
                {
                    temp_result += (tiles[temp_index][1] - tiles[temp_index][0] + 1);
                    temp_index++;
                    if (temp_index >= tiles.size())
                    {
                        return max(temp_result, result);
                    }
                    index_end = tiles[temp_index][1];
                }
                // 计算偏移
                int index_start = tiles[temp_index][0];
                temp_pos = max(0, (head_end + 1) - index_start);

                result = max(result, temp_result + temp_pos);
            }
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maximumWhiteTiles
// paramTypes= ["number[][]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,5],[10,11],[12,18],[20,25],[30,32]]\n10\n
// @lcpr case=end

// @lcpr case=start
// [[10,11],[1,1]]\n2\n
// @lcpr case=end

 */
