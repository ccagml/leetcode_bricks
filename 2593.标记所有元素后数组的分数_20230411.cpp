// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2593 lang=cpp
 * @lcpr version=21905
 *
 * [2593] 标记所有元素后数组的分数
 *
 * https://leetcode.cn/problems/find-score-of-an-array-after-marking-all-elements/description/
 *
 * algorithms
 * Medium (52.44%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 7.1K
 * Testcase Example:  '[2,1,3,4,5,2]'
 *
 * 给你一个数组 nums ，它包含若干正整数。
 *
 * 一开始分数 score = 0 ，请你按照下面算法求出最后分数：
 *
 *
 * 从数组中选择最小且没有被标记的整数。如果有相等元素，选择下标最小的一个。
 * 将选中的整数加到 score 中。
 * 标记 被选中元素，如果有相邻元素，则同时标记 与它相邻的两个元素 。
 * 重复此过程直到数组中所有元素都被标记。
 *
 *
 * 请你返回执行上述算法后最后的分数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,1,3,4,5,2]
 * 输出：7
 * 解释：我们按照如下步骤标记元素：
 * - 1 是最小未标记元素，所以标记它和相邻两个元素：[2,1,3,4,5,2] 。
 * - 2 是最小未标记元素，所以标记它和左边相邻元素：[2,1,3,4,5,2] 。
 * - 4 是仅剩唯一未标记的元素，所以我们标记它：[2,1,3,4,5,2] 。
 * 总得分为 1 + 2 + 4 = 7 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,3,5,1,3,2]
 * 输出：5
 * 解释：我们按照如下步骤标记元素：
 * - 1 是最小未标记元素，所以标记它和相邻两个元素：[2,3,5,1,3,2] 。
 * - 2 是最小未标记元素，由于有两个 2 ，我们选择最左边的一个 2 ，也就是下标为 0 处的 2 ，以及它右边相邻的元素：[2,3,5,1,3,2]
 * 。
 * - 2 是仅剩唯一未标记的元素，所以我们标记它：[2,3,5,1,3,2] 。
 * 总得分为 1 + 2 + 2 = 5 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
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
#include <map>
#include <numeric>
#include <queue>
#include <set>
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
    long long findScore(vector<int> &nums)
    {
        long long result = 0;
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

        for (int i = 0; i < nums.size(); i++)
        {
            pair_pq.push({nums[i], i});
        }

        unordered_set<int> usi;
        while (pair_pq.size() > 0)
        {
            std::pair<int, int> cur = pair_pq.top();
            pair_pq.pop();
            int add = cur.first;
            int add_index = cur.second;
            if (usi.count(add_index) == 0)
            {
                result += add;
                usi.insert(add_index - 1);
                usi.insert(add_index);
                usi.insert(add_index + 1);
            }
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findScore
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [2,1,3,4,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [10,44,10,8,48,30,17,38,41,27,16,33,45,45,34,30,22,3,42,42]\n
// @lcpr case=end

 */
