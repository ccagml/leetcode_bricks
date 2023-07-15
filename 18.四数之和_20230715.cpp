// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=21910
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.76%)
 * Likes:    1653
 * Dislikes: 0
 * Total Accepted:    476.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
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

class MyHash
{
public:
    std::size_t operator()(const vector<int> &v) const
    {
        std::size_t x = 0;

        for (auto &i : v)
        {
            x ^= std::hash<int>()(i);
        }

        return x;
    }
};

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> umi;
        for (int j : nums)
        {
            umi[j]++;
        }

        vector<int> new_num;
        for (pair<int, int> pii : umi)
        {
            for (int i = 0; i < min(pii.second, 4); i++)
            {
                new_num.push_back(pii.first);
            }
        }
        sort(new_num.begin(), new_num.end());
        nums = new_num;
        unordered_set<vector<int>, MyHash> result;
        unordered_map<long long, vector<pair<int, int>>> uivii;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                long long ij = nums[i] + nums[j];
                pair<int, int> pij = {i, j};
                uivii[ij].push_back(pij);
            }
        }

        for (pair<long long, vector<pair<int, int>>> pp : uivii)
        {
            long long ij = pp.first;
            long long need_ij = target - ij;

            if (ij >= need_ij && uivii.count(need_ij) > 0)
            {
                for (int ppi = 0; ppi < pp.second.size(); ppi++)
                {
                    int i = pp.second[ppi].first;
                    int j = pp.second[ppi].second;
                    for (int xx = 0; xx < uivii[need_ij].size(); xx++)
                    {
                        pair<int, int> tt = uivii[need_ij][xx];
                        int k = tt.first;
                        int l = tt.second;
                        // i j k l 互不相等
                        if (i != j && i != k && i != l && j != k && j != l && k != l)
                        {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            sort(temp.begin(), temp.end());
                            result.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> vvi;
        for (vector<int> p : result)
        {
            vvi.push_back(p);
        }
        return vvi;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

// @lcpr case=start
// [1000000000,1000000000,1000000000,1000000000]\n-294967296\n
// @lcpr case=end

 */
