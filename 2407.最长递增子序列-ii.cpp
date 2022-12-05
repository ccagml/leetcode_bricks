/*
 * @lc app=leetcode.cn id=2407 lang=cpp
 * @lcpr version=20701
 *
 * [2407] 最长递增子序列 II
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence-ii/description/
 *
 * algorithms
 * Hard (28.31%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 15K
 * Testcase Example:  '[4,2,1,4,3,4,5,8,15]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k 。
 *
 * 找到 nums 中满足以下要求的最长子序列：
 *
 *
 * 子序列 严格递增
 * 子序列中相邻元素的差值 不超过 k 。
 *
 *
 * 请你返回满足上述要求的 最长子序列 的长度。
 *
 * 子序列 是从一个数组中删除部分元素后，剩余元素不改变顺序得到的数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [4,2,1,4,3,4,5,8,15], k = 3
 * 输出：5
 * 解释：
 * 满足要求的最长子序列是 [1,3,4,5,8] 。
 * 子序列长度为 5 ，所以我们返回 5 。
 * 注意子序列 [1,3,4,5,8,15] 不满足要求，因为 15 - 8 = 7 大于 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [7,4,5,1,8,12,4,7], k = 5
 * 输出：4
 * 解释：
 * 满足要求的最长子序列是 [4,5,8,12] 。
 * 子序列长度为 4 ，所以我们返回 4 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,5], k = 1
 * 输出：1
 * 解释：
 * 满足要求的最长子序列是 [1] 。
 * 子序列长度为 1 ，所以我们返回 1 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i], k <= 10^5
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
    int cur_max = 0;
    nodeHead(int left, int right)
    {
        this->cur_left = left;
        this->cur_right = right;
        this->leftNode = nullptr;
        this->rightNode = nullptr;
        // if (cur_left == cur_right)
        // {
        // }
        // else
        // {
        //     int mid = (left + right) / 2;
        //     this->leftNode = new nodeHead(left, mid);
        //     this->rightNode = new nodeHead(mid + 1, right);
        // }
    }
    int update(int index, int value)
    {
        if (this->cur_left == this->cur_right && this->cur_left == index)
        {
            this->cur_max = value;
            // std::cout << "(update" << index << "=" << value << "),";
        }
        else if (index >= this->cur_left && index <= this->cur_right)
        {
            int mid = (this->cur_left + this->cur_right) / 2;
            if (index <= mid)
            {
                if (this->leftNode == nullptr)
                {
                    this->leftNode = new nodeHead(this->cur_left, mid);
                }
                this->cur_max = max(this->cur_max, this->leftNode->update(index, value));
            }
            else
            {
                if (this->rightNode == nullptr)
                {
                    this->rightNode = new nodeHead(mid + 1, this->cur_right);
                }
                this->cur_max = max(this->cur_max, this->rightNode->update(index, value));
            }
            // std::cout << "(" << this->cur_left << "->" << this->cur_right << "=" << this->cur_max << ")";
        }
        return this->cur_max;
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
            // std::cout << "zancun:" << this->cur_left << "->" << this->cur_right << "=" << this->cur_max << ")";
            return this->cur_max;
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
            int ccc = max(left_max, right_max);
            // std::cout << "range:" << this->cur_left << "->" << this->cur_right << "=" << ccc << ")";
            return ccc;
        }
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {
        nodeHead *nh = new nodeHead(0, 100001);
        int n = nums.size();
        vector<int> vvi(100001); // vvi[j结尾] = 最长数量
        int cur_max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            // int temp_map = 0;
            // for (int j = max(0, cur - k); j < cur; j++)
            // {
            //     temp_map = max(temp_map, vvi[j]);
            // }
            int temp_b = nh->range_max(max(0, cur - k), cur - 1);
            // std::cout << "查询" << max(0, cur - k) << "->" << cur - 1 << "=" << temp_map << ":" << temp_b << ")";
            vvi[cur] = temp_b + 1;
            nh->update(cur, vvi[cur]);
            if (vvi[cur] > cur_max)
            {
                cur_max = vvi[cur];
            }
        }

        return cur_max;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,1,4,3,4,5,8,15]\n3\n
// @lcpr case=end

// @lcpr case=start
// [7,4,5,1,8,12,4,7]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n1\n
// @lcpr case=end

 */
