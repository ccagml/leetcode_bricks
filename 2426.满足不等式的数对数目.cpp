/*
 * @lc app=leetcode.cn id=2426 lang=cpp
 * @lcpr version=20703
 *
 * [2426] 满足不等式的数对数目
 *
 * https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/description/
 *
 * algorithms
 * Hard (44.88%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 7.6K
 * Testcase Example:  '[3,2,5]\n[2,2,1]\n1'
 *
 * 给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，两个数组的大小都为 n ，同时给你一个整数 diff ，统计满足以下条件的 数对
 * (i, j) ：
 *
 *
 * 0 <= i < j <= n - 1 且
 * nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
 *
 *
 * 请你返回满足条件的 数对数目 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
 * 输出：3
 * 解释：
 * 总共有 3 个满足条件的数对：
 * 1. i = 0, j = 1：3 - 2 <= 2 - 2 + 1 。因为 i < j 且 1 <= 1 ，这个数对满足条件。
 * 2. i = 0, j = 2：3 - 5 <= 2 - 1 + 1 。因为 i < j 且 -2 <= 2 ，这个数对满足条件。
 * 3. i = 1, j = 2：2 - 5 <= 2 - 1 + 1 。因为 i < j 且 -3 <= 2 ，这个数对满足条件。
 * 所以，我们返回 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [3,-1], nums2 = [-2,2], diff = -1
 * 输出：0
 * 解释：
 * 没有满足条件的任何数对，所以我们返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums1.length == nums2.length
 * 2 <= n <= 10^5
 * -10^4 <= nums1[i], nums2[i] <= 10^4
 * -10^4 <= diff <= 10^4
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

class nodeHead
{
public:
    nodeHead *leftNode;
    nodeHead *rightNode;
    int cur_left;
    int cur_right;
    int cur_sum = 0;
    nodeHead(int left, int right)
    {
        this->cur_left = left;
        this->cur_right = right;
        this->leftNode = nullptr;
        this->rightNode = nullptr;
    }
    int update(int left, int right, int value)
    {
        if (this->cur_left == this->cur_right && this->cur_left == left && left == right)
        {
            this->cur_sum += value;
        }
        else if (left >= this->cur_left && right <= this->cur_right)
        {
            int mid = (this->cur_left + this->cur_right) / 2;
            // 需要更新左边
            if (left <= mid)
            {
                if (this->leftNode == nullptr)
                {
                    this->leftNode = new nodeHead(this->cur_left, mid);
                }
                this->leftNode->update(left, mid, value);
                this->cur_sum += value * (mid - left + 1);
            }
            // 需要更新右边
            if (this->rightNode == nullptr)
            {
                this->rightNode = new nodeHead(mid + 1, this->cur_right);
            }
            this->rightNode->update(mid + 1, this->cur_right, value);
            this->cur_sum += value * (this->cur_right - mid + 2);
            // if (left <= mid)
            // {
            //     if (this->leftNode == nullptr)
            //     {
            //         this->leftNode = new nodeHead(this->cur_left, mid);
            //     }
            //     this->leftNode->update(left, mid, value);
            //     this->cur_sum += value * (mid - left + 1);
            // }
            // else
            // {
            //     if (this->rightNode == nullptr)
            //     {
            //         this->rightNode = new nodeHead(mid + 1, this->cur_right);
            //     }
            //     this->rightNode->update(index, value);
            //     this->cur_sum += value;
            // }
            // std::cout << "(" << this->cur_left << "->" << this->cur_right << "=" << this->cur_max << ")";
        }
        return 0;
    }
    int range_max(int left, int right)
    {
        if (this->cur_left > right)
        {
            return 0;
        }
        else if (this->cur_right < left)
        {
            return 0;
        }
        else if (this->cur_left >= left && this->cur_right <= right)
        {
            return this->cur_sum;
        }
        else
        {
            int mid = (this->cur_left + this->cur_right) / 2;
            int left_max = 0;
            if (this->leftNode != nullptr)
            {
                left_max = this->leftNode->range_max(left, right);
            }

            int right_max = 0;
            if (this->rightNode != nullptr)
            {
                right_max = this->rightNode->range_max(left, right);
            }
            int ccc = left_max + right_max;
            return ccc;
        }
    }
};
class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int d)
    {
        // 超时思路
        // long long result = 0;
        // for (int i = 0; i < nums1.size(); i++)
        // {
        //     for (int j = i + 1; j < nums2.size(); j++)
        //     {
        //         if (nums1[i] - nums1[j] - nums2[i] + nums2[j] <= d)
        //         {
        //             result++;
        //         }
        //     }
        // }
        // return result;
        //(nums1[i] - nums2[i]) - (nums[j] - nums2[j]) <= d;
        // -2000 , 2000
        // 从尾巴来
        // ?动态维护前缀和?
        unordered_map<int, int> umii;
        long long reuslt = 0;
        bool debug = false;
        // if (nums1.size() > 10)
        // {
        //     vector<int> temp_vi = {3858,
        //                            -7670,
        //                            -7640,
        //                            6453,
        //                            -2155};
        //     debug = true;
        //     for (int j = 0; j < temp_vi.size(); j++)
        //     {
        //         if (nums1[j] != temp_vi[j])
        //         {
        //             debug = false;
        //             break;
        //         }
        //     }
        // }

        nodeHead *root = new nodeHead(0, 50000);
        long long debug_reuslt = 0;
        for (int j = nums1.size() - 1; j >= 0; j--)
        {
            int cur = nums1[j] - nums2[j];

            cur += 25000;
            int temp = root->range_max(cur - d, 50000);
            reuslt += temp;
            root->update(cur, cur, 1);
            if (debug)
            {
                long long temp_debug_add = 0;
                for (pair<int, int> pii : umii)
                {
                    if (cur - d <= pii.first)
                    {
                        temp_debug_add += pii.second;
                    }
                }
                debug_reuslt += temp_debug_add;
                std::cout << cur << ":" << temp << ":" << temp_debug_add << ")";
                umii[cur]++;
            }
        }
        if (debug)
        {
            std::cout << reuslt << ":debug:" << debug_reuslt << std::endl;
        }
        return reuslt;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,5]\n[2,2,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,-1]\n[-2,2]\n-1\n
// @lcpr case=end

 */
