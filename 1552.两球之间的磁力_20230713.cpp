// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 * @lcpr version=21909
 *
 * [1552] 两球之间的磁力
 *
 * https://leetcode.cn/problems/magnetic-force-between-two-balls/description/
 *
 * algorithms
 * Medium (56.85%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 31.4K
 * Testcase Example:  '[1,2,3,4,7]\n3'
 *
 * 在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有 n 个空的篮子，第 i
 * 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，使得任意两球间 最小磁力 最大。
 *
 * 已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。
 *
 * 给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：position = [1,2,3,4,7], m = 3
 * 输出：3
 * 解释：将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3
 * 。
 *
 *
 * 示例 2：
 *
 * 输入：position = [5,4,3,2,1,1000000000], m = 2
 * 输出：999999999
 * 解释：我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == position.length
 * 2 <= n <= 10^5
 * 1 <= position[i] <= 10^9
 * 所有 position 中的整数 互不相同 。
 * 2 <= m <= position.length
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
    int check(int ans, vector<int> &position, int m)
    {
        int next_pos = 0;
        int pos_index = 0;

        for (int i = 0; i < m; i++)
        {
            while (pos_index < position.size())
            {
                if (position[pos_index] >= next_pos)
                {
                    next_pos = position[pos_index] + ans;
                    if (i == m - 1)
                    {
                        return true;
                    }
                    pos_index++;
                    break;
                }
                else
                {
                    pos_index++;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int left = 0;
        int right = position[position.size() - 1] - position[0];

        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (check(mid, position, m))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxDistance
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3,4,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3,2,1,1000000000]\n2\n
// @lcpr case=end

 */
