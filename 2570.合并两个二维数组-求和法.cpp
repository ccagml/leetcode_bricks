/*
 * @lc app=leetcode.cn id=2570 lang=cpp
 * @lcpr version=21704
 *
 * [2570] 合并两个二维数组 - 求和法
 *
 * https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values/description/
 *
 * algorithms
 * Easy (69.83%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 8.8K
 * Testcase Example:  '[[1,2],[2,3],[4,5]]\n[[1,4],[3,2],[4,1]]'
 *
 * 给你两个 二维 整数数组 nums1 和 nums2.
 *
 *
 * nums1[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
 * nums2[i] = [idi, vali] 表示编号为 idi 的数字对应的值等于 vali 。
 *
 *
 * 每个数组都包含 互不相同 的 id ，并按 id 以 递增 顺序排列。
 *
 * 请你将两个数组合并为一个按 id 以递增顺序排列的数组，并符合下述条件：
 *
 *
 * 只有在两个数组中至少出现过一次的 id 才能包含在结果数组内。
 * 每个 id 在结果数组中 只能出现一次 ，并且其对应的值等于两个数组中该 id 所对应的值求和。如果某个数组中不存在该 id ，则认为其对应的值等于 0
 * 。
 *
 *
 * 返回结果数组。返回的数组需要按 id 以递增顺序排列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
 * 输出：[[1,6],[2,3],[3,2],[4,6]]
 * 解释：结果数组中包含以下元素：
 * - id = 1 ，对应的值等于 2 + 4 = 6 。
 * - id = 2 ，对应的值等于 3 。
 * - id = 3 ，对应的值等于 2 。
 * - id = 4 ，对应的值等于5 + 1 = 6 。
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
 * 输出：[[1,3],[2,4],[3,6],[4,3],[5,5]]
 * 解释：不存在共同 id ，在结果数组中只需要包含每个 id 和其对应的值。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 200
 * nums1[i].length == nums2[j].length == 2
 * 1 <= idi, vali <= 1000
 * 数组中的 id 互不相同
 * 数据均按 id 以严格递增顺序排列
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
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<vector<int>> result;
        int left = 0;
        int right = 0;
        while (left < nums1.size() && right < nums2.size())
        {
            if (nums1[left][0] < nums2[right][0])
            {
                result.push_back(nums1[left]);
                left++;
            }
            else if (nums1[left][0] > nums2[right][0])
            {
                result.push_back(nums2[right]);
                right++;
            }
            else
            {
                int c = nums1[left][1] + nums2[right][1];
                result.push_back({nums1[left][0], c});
                left++;
                right++;
            }
        }

        if (left < nums1.size())
        {
            result.insert(result.end(), nums1.begin() + left, nums1.end());
        }

        if (right < nums2.size())
        {
            result.insert(result.end(), nums2.begin() + right, nums2.end());
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=
// paramTypes= []
// returnType=
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,2],[2,3],[4,5]]\n[[1,4],[3,2],[4,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,4],[3,6],[5,5]]\n[[1,3],[4,3]]\n
// @lcpr case=end

 */
