/*
 * @lc app=leetcode.cn id=2217 lang=cpp
 *
 * [2217] 找到指定长度的回文数
 *
 * https://leetcode.cn/problems/find-palindrome-with-fixed-length/description/
 *
 * algorithms
 * Medium (33.05%)
 * Likes:    25
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 20.1K
 * Testcase Example:  '[1,2,3,4,5,90]\n3'
 *
 * 给你一个整数数组 queries 和一个 正 整数 intLength ，请你返回一个数组 answer ，其中 answer[i] 是长度为
 * intLength 的 正回文数 中第 queries[i] 小的数字，如果不存在这样的回文数，则为 -1 。
 *
 * 回文数 指的是从前往后和从后往前读一模一样的数字。回文数不能有前导 0 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：queries = [1,2,3,4,5,90], intLength = 3
 * 输出：[101,111,121,131,141,999]
 * 解释：
 * 长度为 3 的最小回文数依次是：
 * 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
 * 第 90 个长度为 3 的回文数是 999 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：queries = [2,4,6], intLength = 4
 * 输出：[1111,1331,1551]
 * 解释：
 * 长度为 4 的前 6 个回文数是：
 * 1001, 1111, 1221, 1331, 1441 和 1551 。
 *
 *[1,2,3,4,5,90]\n3\n[2,4,6]\n4\n[1,2,333,91,5,90]\n3\n[1,2,333,91,92,90]\n3\n[2,201429812,8,520498110,492711727,339882032,462074369,9,7,6]\n1


 * 提示：
 *
 *
 * 1 <= queries.length <= 5 * 10^4
 * 1 <= queries[i] <= 10^9
 * 1 <= intLength <= 15
 *
 *
 */

// @lc code=start
// 想法是 根据值 直接计算
// queries[i] - 1 然后 / 10 求余数,对应增加
class Solution
{
public:
    vector<long long> kthPalindrome(vector<int> &queries, int intLength)
    {
        // 1 0 1
        // 1 1 1
        // 20小
        //  20 - 1/  19 / 10 =
        vector<long long> result;
        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i];
            vector<int> temp(intLength);
            temp[0] = 1;
            temp[intLength - 1] = 1;
            // 偶数
            int new_i = index - 1;
            int left = 0;  // 0, 1, 2   0, 1, 2, 3
            int right = 0; // 0, 1, 2   0, 1, 2, 3
            bool is_error = false;
            if (intLength % 2 == 0)
            {
                left = (intLength / 2 - 1);
                right = (intLength / 2);
            }
            else
            {
                left = (intLength / 2);
                right = (intLength / 2);
            }

            while (new_i > 0 && left >= 0)
            {
                int b = new_i % 10;
                if (left == right)
                {
                    temp[left] += b;
                }
                else
                {
                    temp[left] += b;
                    temp[right] += b;
                }
                left--;
                right++;
                new_i /= 10;
                // std::cout << i << ":" << left << ":" << new_i << std::endl;
                if (left == 0 && new_i > 8)
                {
                    is_error = true;
                }
                if (left == -1 && new_i > 0)
                {
                    is_error = true;
                }
            }
            if (is_error)
            {
                result.push_back(-1);
            }
            else
            {
                long long ttemp = 0;
                for (int kk = 0; kk < temp.size(); kk++)
                {
                    ttemp *= 10;
                    ttemp += temp[kk];
                    if (temp[kk] >= 10)
                    {
                        ttemp = -1;
                        break;
                    }
                }
                result.push_back(ttemp);
            }
        }
        return result;
    }
};
// @lc code=end
