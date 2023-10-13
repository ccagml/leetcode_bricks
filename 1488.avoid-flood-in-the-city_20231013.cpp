// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1488 lang=cpp
 * @lcpr version=21918
 *
 * [1488] 避免洪水泛滥
 *
 * https://leetcode.cn/problems/avoid-flood-in-the-city/description/
 *
 * algorithms
 * Medium (28.84%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 76.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 n 个湖泊下雨前是空的，那么它就会装满水。如果第 n 个湖泊下雨前是 满的 ，这个湖泊会发生 洪水
 * 。你的目标是避免任意一个湖泊发生洪水。
 *
 * 给你一个整数数组 rains ，其中：
 *
 *
 * rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。
 * rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并 抽干 这个湖泊的水。
 *
 *
 * 请返回一个数组 ans ，满足：
 *
 *
 * ans.length == rains.length
 * 如果 rains[i] > 0 ，那么ans[i] == -1 。
 * 如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。
 *
 *
 * 如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个 空的数组 。
 *
 * 请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生。
 *
 *
 *
 * 示例 1：
 *
 * 输入：rains = [1,2,3,4]
 * 输出：[-1,-1,-1,-1]
 * 解释：第一天后，装满水的湖泊包括 [1]
 * 第二天后，装满水的湖泊包括 [1,2]
 * 第三天后，装满水的湖泊包括 [1,2,3]
 * 第四天后，装满水的湖泊包括 [1,2,3,4]
 * 没有哪一天你可以抽干任何湖泊的水，也没有湖泊会发生洪水。
 *
 *
 * 示例 2：
 *
 * 输入：rains = [1,2,0,0,2,1]
 * 输出：[-1,-1,2,1,-1,-1]
 * 解释：第一天后，装满水的湖泊包括 [1]
 * 第二天后，装满水的湖泊包括 [1,2]
 * 第三天后，我们抽干湖泊 2 。所以剩下装满水的湖泊包括 [1]
 * 第四天后，我们抽干湖泊 1 。所以暂时没有装满水的湖泊了。
 * 第五天后，装满水的湖泊包括 [2]。
 * 第六天后，装满水的湖泊包括 [1,2]。
 * 可以看出，这个方案下不会有洪水发生。同时， [-1,-1,1,2,-1,-1] 也是另一个可行的没有洪水的方案。
 *
 *
 * 示例 3：
 *
 * 输入：rains = [1,2,0,1,2]
 * 输出：[]
 * 解释：第二天后，装满水的湖泊包括 [1,2]。我们可以在第三天抽干一个湖泊的水。
 * 但第三天后，湖泊 1 和 2 都会再次下雨，所以不管我们第三天抽干哪个湖泊的水，另一个湖泊都会发生洪水。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= rains.length <= 10^5
 * 0 <= rains[i] <= 10^9
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        // vector<int> tt = {0, 0, 0, 1, 1};
        vector<int> result(rains.size(), -1);
        vector<int> zero_index;
        for (int i = 0; i < rains.size(); i++)
        {
            if (rains[i] == 0)
            {
                zero_index.push_back(i);
                result[i] = 1;
            }
        }
        unordered_map<int, int> umil; // 池子号 - 上一次注水
        unordered_set<int> zero_use;
        for (int day_index = 0; day_index < rains.size(); day_index++)
        {
            int hao = rains[day_index];
            if (hao != 0 && umil.count(hao) > 0 && umil[hao] >= 0)
            {
                // 有水,找一个0抽水
                // 1, 2, 0, 2, 3 , 0 , 0 , 1,  0, 1, 2, 3
                // 找的0要 大于 umil[hao] 小于 day_index
                // //第一个大于 i
                auto upper = std::upper_bound(zero_index.begin(), zero_index.end(), umil[hao]);
                int clear = 0;
                if (upper != zero_index.end())
                {
                    int index = std::distance(zero_index.begin(), upper);
                    // std::cout << *upper << " at index " << std::distance(data.begin(), upper);
                    for (int chc = index; chc < zero_index.size(); chc++)
                    {
                        int ture_zero = zero_index[chc];
                        if (ture_zero >= day_index)
                        {
                            break;
                        }
                        if (zero_use.count(ture_zero) > 0)
                        {
                            continue;
                        }
                        zero_index.erase(zero_index.begin() + chc);
                        zero_use.insert(ture_zero);
                        result[ture_zero] = hao;
                        umil[hao] = day_index;
                        clear = 1;
                        break;
                    }
                }
                if (clear == 0)
                {
                    return {};
                }
            }
            else
            {
                umil[hao] = day_index;
            }
        }

        return result;
    }
};

// @lc code=end

// @lcpr-div-debug-arg-start
// funName=avoidFlood
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,0,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0,1,2]\n
// @lcpr case=end

 */
