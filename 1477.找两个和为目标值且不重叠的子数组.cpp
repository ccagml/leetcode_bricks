/*
 * @lc app=leetcode.cn id=1477 lang=cpp
 * @lcpr version=21113
 *
 * [1477] 找两个和为目标值且不重叠的子数组
 *
 * https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/
 *
 * algorithms
 * Medium (30.68%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 26.4K
 * Testcase Example:  '[3,2,2,4,3]\n3'
 *
 * 给你一个整数数组 arr 和一个整数值 target 。
 *
 * 请你在 arr 中找 两个互不重叠的子数组 且它们的和都等于 target 。可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。
 *
 * 请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [3,2,2,4,3], target = 3
 * 输出：2
 * 解释：只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
 *
 *
 * 示例 2：
 *
 * 输入：arr = [7,3,4,7], target = 7
 * 输出：2
 * 解释：尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2
 * 是最小值。
 *
 *
 * 示例 3：
 *
 * 输入：arr = [4,3,2,6,2,3,4], target = 6
 * 输出：-1
 * 解释：我们只有一个和为 6 的子数组。
 *
 *
 * 示例 4：
 *
 * 输入：arr = [5,5,4,4,5], target = 3
 * 输出：-1
 * 解释：我们无法找到和为 3 的子数组。
 *
 *
 * 示例 5：
 *
 * 输入：arr = [3,1,1,1,5,1,2,1], target = 3
 * 输出：3
 * 解释：注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10^5
 * 1 <= arr[i] <= 1000
 * 1 <= target <= 10^8
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

// 设置范围值
// 查询范围最小值

class nodeHead
{

public:
    nodeHead *leftNode;
    nodeHead *rightNode;
    int cur_left;
    int cur_right;
    int cur_min = 99999999;
    nodeHead(int left, int right)
    {
        this->cur_left = left;
        this->cur_right = right;
        this->leftNode = nullptr;
        this->rightNode = nullptr;
    }
    int update(int left, int right, int value)
    {
        if (this->cur_left >= left && right <= this->cur_right)
        {
            // 到这里结束
            this->cur_min = min(this->cur_min, value);
        }
        else if (right < this->cur_left || left > this->cur_right)
        {
            // 没有
            return 99999999;
        }
        else
        {
            int mid = (this->cur_left + this->cur_right) / 2;
            if (this->leftNode == nullptr)
            {
                this->leftNode = new nodeHead(this->cur_left, mid);
            }
            this->leftNode->update(left, mid, value);

            if (this->rightNode == nullptr)
            {
                this->rightNode = new nodeHead(mid + 1, this->cur_right);
            }
            this->rightNode->update(mid + 1, right, value);
        }
        return this->cur_min;
    }
    int range_min(int left, int right)
    {
        if (this->cur_left > right)
        {
            return 99999999;
        }
        else if (this->cur_right < left)
        {
            return 99999999;
        }
        else if (this->cur_left >= left && this->cur_right <= right)
        {
            return this->cur_min;
        }
        else
        {
            int mid = (this->cur_left + this->cur_right) / 2;
            int left_min = 99999999;
            if (this->leftNode != nullptr)
            {
                if (left <= mid)
                {
                    left_min = this->leftNode->range_min(left, mid);
                }
            }

            int right_min = 99999999;
            if (this->rightNode != nullptr)
            {
                if (right >= mid + 1)
                {
                    right_min = this->rightNode->range_min(mid + 1, right);
                }
            }
            int ccc = min(left_min, right_min);

            std::cout << "cha(" << left << "," << right << ":" << ccc << ")";
            return ccc;
        }
    }
};

class Solution
{
public:
    int minSumOfLengths(vector<int> &arr, int target)
    {

        int left = 0;
        int right = 0;
        int sum = 0;
        vector<pair<int, int>> vpii;
        int n = arr.size();
        nodeHead *nnn = new nodeHead(0, 100001);
        while (right < arr.size() && left < arr.size())
        {
            sum += arr[right];
            right++;
            while (sum > target)
            {
                sum -= arr[left];
                left++;
            }
            if (sum == target)
            {
                vpii.push_back({left, right - 1});
                nnn->update(left, right - 1, (right - left));
                std::cout << "update(" << left << "," << right - 1 << ":" << (right - left) << "|";
            }
        }
        int result = 9999999;
        // for (int i = 0; i < vpii.size(); i++)
        // {
        //     for (int j = i + 1; j < vpii.size(); j++)
        //     {
        //         if (vpii[j].first > vpii[i].second)
        //         {
        //             int a_len = vpii[i].second - vpii[i].first + 1;
        //             int b_len = vpii[j].second - vpii[j].first + 1;
        //             result = min(result, a_len + b_len);
        //         }
        //     }
        // }

        // 一个快速查询 k-尾最短的长度 方法 // 线段树?
        sort(vpii.begin(), vpii.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second < b.second; });

        for (int i = 0; i < vpii.size(); i++)
        {
            int a_len = vpii[i].second - vpii[i].first + 1;
            int a_min = nnn->range_min(vpii[i].second + 1, 100001);
            std::cout << "(" << vpii[i].first << "," << vpii[i].second << ")" << a_min << "|";
            result = min(result, a_len + a_min);
        }
        return result == 9999999
                   ? -1
                   : result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,4,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,3,4,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,6,2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [5,5,4,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [3,1,1,1,5,1,2,1]\n3\n
// @lcpr case=end

 */
