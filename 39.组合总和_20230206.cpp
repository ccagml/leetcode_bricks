/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=21502
 *
 * [39] 组合总和
 *
 * https://leetcode.cn/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.64%)
 * Likes:    2337
 * Dislikes: 0
 * Total Accepted:    665.9K
 * Total Submissions: 916.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target
 * 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 *
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 *
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 *
 *
 *
 * 示例 1：
 *
 * 输入：candidates = [2,3,6,7], target = 7
 * 输出：[[2,2,3],[7]]
 * 解释：
 * 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
 * 7 也是一个候选， 7 = 7 。
 * 仅有这两种组合。
 *
 * 示例 2：
 *
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 *
 * 示例 3：
 *
 * 输入: candidates = [2], target = 1
 * 输出: []
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * candidates 的所有元素 互不相同
 * 1 <= target <= 40
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
// class Solution
// {
// public:
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         unordered_map<int, vector<vector<int>>> uivvi;
//         uivvi[0] = {{}};
//         sort(candidates.begin(), candidates.end());
//         for (int need_tar = 1; need_tar <= target; need_tar++)
//         {
//             for (int j : candidates)
//             {
//                 if (j <= need_tar)
//                 {
//                     int other = need_tar - j;
//                     if (uivvi.count(other) > 0)
//                     {
//                         for (auto pp : uivvi[other])
//                         {
//                             // vector<int> new_pp(pp.begin(), pp.end());
//                             if (pp.size() == 0 || j >= pp[pp.size() - 1])
//                             {
//                                 pp.push_back(j);
//                                 uivvi[need_tar].push_back(pp);
//                             }
//                         }
//                     }
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//         return uivvi[target];
//         // // 随便去重一下
//         // unordered_set<string> us;
//         // vector<vector<int>> reuslt;
//         // for (auto pp : uivvi[target])
//         // {
//         //     sort(pp.begin(), pp.end());
//         //     std::string str(pp.begin(), pp.end());
//         //     if (us.count(str) < 1)
//         //     {
//         //         us.insert(str);
//         //         reuslt.push_back(pp);
//         //     }
//         // }

//         // return reuslt;
//     }
// };
class Solution
{
public:
    void dfs(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx)
    {
        if (idx == candidates.size())
        {
            return;
        }
        if (target == 0)
        {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
