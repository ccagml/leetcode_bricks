// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 * @lcpr version=21906
 *
 * [2300] 咒语和药水的成功对数
 *
 * https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/description/
 *
 * algorithms
 * Medium (38.37%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 17.9K
 * Testcase Example:  '[5,1,3]\n[1,2,3,4,5]\n7'
 *
 * 给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i
 * 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。
 *
 * 同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。
 *
 * 请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * 输出：[4,0,3]
 * 解释：
 * - 第 0 个咒语：5 * [1,2,3,4,5] = [5,10,15,20,25] 。总共 4 个成功组合。
 * - 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
 * - 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,9,12,15] 。总共 3 个成功组合。
 * 所以返回 [4,0,3] 。
 *
 *
 * 示例 2：
 *
 * 输入：spells = [3,1,2], potions = [8,5,8], success = 16
 * 输出：[2,0,2]
 * 解释：
 * - 第 0 个咒语：3 * [8,5,8] = [24,15,24] 。总共 2 个成功组合。
 * - 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
 * - 第 2 个咒语：2 * [8,5,8] = [16,10,16] 。总共 2 个成功组合。
 * 所以返回 [2,0,2] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == spells.length
 * m == potions.length
 * 1 <= n, m <= 10^5
 * 1 <= spells[i], potions[i] <= 10^5
 * 1 <= success <= 10^10
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
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> result;
        for (int i = 0; i < spells.size(); i++)
        {
            long long cur = spells[i];
            long long need = success / cur;
            if (success % cur == 0)
            {
                // >=
                // 第一个大于等于 i 的位置
                auto lower = std::lower_bound(potions.begin(), potions.end(), need);

                if (lower != potions.end())
                {
                    int cur_index = std::distance(potions.begin(), lower);
                    int temp_result = potions.size();
                    result.push_back(temp_result - cur_index);
                }
                else
                {
                    result.push_back(0);
                }
            }
            else
            {
                // >

                // //第一个大于 i
                auto upper = std::upper_bound(potions.begin(), potions.end(), need);

                if (upper != potions.end())
                {
                    int cur_index = std::distance(potions.begin(), upper);
                    int temp_result = potions.size();
                    result.push_back(temp_result - cur_index);
                }
                else
                {
                    result.push_back(0);
                }
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=successfulPairs
// paramTypes= ["number[]","number[]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [5,1,3]\n[1,2,3,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [3,1,2]\n[8,5,8]\n16\n
// @lcpr case=end

 */
