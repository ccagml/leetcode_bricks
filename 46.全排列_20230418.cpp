// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=21906
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.87%)
 * Likes:    2518
 * Dislikes: 0
 * Total Accepted:    846.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
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
    vector<vector<int>> result;
    void dfs(vector<int> &nums, vector<int> &cur, int flag)
    {
        if (cur.size() == nums.size())
        {
            vector<int> vv(cur.begin(), cur.end());
            result.push_back(vv);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!is_bit_1(flag, i))
            {
                int next = set_bit_1(flag, i);
                cur.push_back(nums[i]);
                dfs(nums, cur, next);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> temp;
        dfs(nums, temp, 0);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
