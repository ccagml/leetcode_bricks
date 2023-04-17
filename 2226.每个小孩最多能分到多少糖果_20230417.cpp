// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2226 lang=cpp
 * @lcpr version=21906
 *
 * [2226] 每个小孩最多能分到多少糖果
 *
 * https://leetcode.cn/problems/maximum-candies-allocated-to-k-children/description/
 *
 * algorithms
 * Medium (33.83%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    11.1K
 * Total Submissions: 32.7K
 * Testcase Example:  '[5,8,6]\n3'
 *
 * 给你一个 下标从 0 开始 的整数数组 candies 。数组中的每个元素表示大小为 candies[i] 的一堆糖果。你可以将每堆糖果分成任意数量的
 * 子堆 ，但 无法 再将两堆合并到一起。
 *
 * 另给你一个整数 k 。你需要将这些糖果分配给 k 个小孩，使每个小孩分到 相同 数量的糖果。每个小孩可以拿走 至多一堆 糖果，有些糖果可能会不被分配。
 *
 * 返回每个小孩可以拿走的 最大糖果数目 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：candies = [5,8,6], k = 3
 * 输出：5
 * 解释：可以将 candies[1] 分成大小分别为 5 和 3 的两堆，然后把 candies[2] 分成大小分别为 5 和 1
 * 的两堆。现在就有五堆大小分别为 5、5、3、5 和 1 的糖果。可以把 3 堆大小为 5 的糖果分给 3 个小孩。可以证明无法让每个小孩得到超过 5
 * 颗糖果。
 *
 *
 * 示例 2：
 *
 * 输入：candies = [2,5], k = 11
 * 输出：0
 * 解释：总共有 11 个小孩，但只有 7 颗糖果，但如果要分配糖果的话，必须保证每个小孩至少能得到 1 颗糖果。因此，最后每个小孩都没有得到糖果，答案是
 * 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candies.length <= 10^5
 * 1 <= candies[i] <= 10^7
 * 1 <= k <= 10^12
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
    bool check(int need, vector<int> &candies, long long k)
    {
        for (int i = 0; i < candies.size(); i++)
        {
            k -= candies[i] / need;
            if (k <= 0)
            {
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {

        int left = 0;
        int right = 10000005;
        while (left < right)
        {
            int mid = (right + left + 1) / 2;
            if (check(mid, candies, k))
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
// funName=maximumCandies
// paramTypes= ["number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [5,8,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n11\n
// @lcpr case=end


// @lcpr case=start
// [4,7,5]\n4\n
// @lcpr case=end

 */
