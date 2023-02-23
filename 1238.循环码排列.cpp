// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 * @lcpr version=21704
 *
 * [1238] 循环码排列
 *
 * https://leetcode.cn/problems/circular-permutation-in-binary-representation/description/
 *
 * algorithms
 * Medium (67.70%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 17.3K
 * Testcase Example:  '2\n3'
 *
 * 给你两个整数 n 和 start。你的任务是返回任意 (0,1,2,,...,2^n-1) 的排列 p，并且满足：
 *
 *
 * p[0] = start
 * p[i] 和 p[i+1] 的二进制表示形式只有一位不同
 * p[0] 和 p[2^n -1] 的二进制表示形式也只有一位不同
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2, start = 3
 * 输出：[3,2,0,1]
 * 解释：这个排列的二进制表示是 (11,10,00,01)
 * ⁠    所有的相邻元素都有一位是不同的，另一个有效的排列是 [3,1,0,2]
 *
 *
 * 示例 2：
 *
 * 输出：n = 3, start = 2
 * 输出：[2,6,7,5,4,0,1,3]
 * 解释：这个排列的二进制表示是 (010,110,111,101,100,000,001,011)
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 16
 * 0 <= start < 2^n
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

    vector<unordered_set<int>> vus;
    unordered_set<int> has_temp;
    int max_v;

    bool dfs(vector<int> &temp)
    {
        if (temp.size() == max_v + 1)
        {
            if (temp.size() == 1 || vus[temp[0]].count(temp[temp.size() - 1]) > 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        int last = temp[temp.size() - 1];
        for (auto &can_next : vus[last])
        {
            if (has_temp.count(can_next) < 1)
            {
                temp.push_back(can_next);
                has_temp.insert(can_next);
                if (dfs(temp))
                {
                    return true;
                }
                else
                {
                    temp.pop_back();
                    has_temp.erase(can_next);
                }
            }
        }
        return false;
    }

    vector<int> circularPermutation(int n, int start)
    {
        vector<int> ret;
        ret.reserve(1 << n);
        ret.push_back(start);
        for (int i = 1; i <= n; i++)
        {
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--)
            {
                ret.push_back(((ret[j] ^ start) | (1 << (i - 1))) ^ start);
            }
        }
        return ret;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=circularPermutation
// paramTypes=["number","number"]
// returnType=number[]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 2\n3\n
// @lcpr case=end
// @lcpr case=start
// 2\n3\n
// @lcpr case=end

 */
