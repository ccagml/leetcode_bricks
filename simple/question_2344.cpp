/*
 * @lc app=leetcode.cn id=2344 lang=cpp
 *
 * [2344] 使数组可以被整除的最少删除次数
 *
 * https://leetcode.cn/problems/minimum-deletions-to-make-array-divisible/description/
 *
 * algorithms
 * Hard (52.40%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 13.9K
 * Testcase Example:  '[2,3,2,4,3]\n[9,6,9,3,15]'
 *
 * 给你两个正整数数组 nums 和 numsDivide 。你可以从 nums 中删除任意数目的元素。
 *
 * 请你返回使 nums 中 最小 元素可以整除 numsDivide 中所有元素的 最少 删除次数。如果无法得到这样的元素，返回 -1 。
 *
 * 如果 y % x == 0 ，那么我们说整数 x 整除 y 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
 * 输出：2
 * 解释：
 * [2,3,2,4,3] 中最小元素是 2 ，它无法整除 numsDivide 中所有元素。
 * 我们从 nums 中删除 2 个大小为 2 的元素，得到 nums = [3,4,3] 。
 * [3,4,3] 中最小元素为 3 ，它可以整除 numsDivide 中所有元素。
 * 可以证明 2 是最少删除次数。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [4,3,6], numsDivide = [8,2,6,10]
 * 输出：-1
 * 解释：
 * 我们想 nums 中的最小元素可以整除 numsDivide 中的所有元素。
 * 没有任何办法可以达到这一目的。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length, numsDivide.length <= 10^5
 * 1 <= nums[i], numsDivide[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        unordered_map<int, int> uii;
        for (int i = 0; i < nums.size(); i++)
        {
            uii[nums[i]]++;
        }
        unordered_map<int, int> uii_di;
        for (int i = 0; i < numsDivide.size(); i++)
        {
            uii_di[numsDivide[i]] = 1;
        }

        vector<int> vi;
        for (pair<int, int> pii : uii)
        {
            vi.push_back(pii.first);
        }
        sort(vi.begin(), vi.end());
        int result = 0;
        for (int i = 0; i < vi.size(); i++)
        {
            bool flag = true;
            for (pair<int, int> pii : uii_di)
            {
                if (pii.first % vi[i] != 0)
                {
                    flag = false;
                }
            }
            if (flag)
            {
                return result;
            }
            result += uii[vi[i]];
        }
        return -1;
    }
};
// @lc code=end
