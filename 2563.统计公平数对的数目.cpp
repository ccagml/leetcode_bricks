/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 * @lcpr version=21704
 *
 * [2563] 统计公平数对的数目
 *
 * https://leetcode.cn/problems/count-the-number-of-fair-pairs/description/
 *
 * algorithms
 * Medium (32.01%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 17.2K
 * Testcase Example:  '[0,1,7,4,4,5]\n3\n6'
 *
 * 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，和两个整数 lower 和 upper ，返回 公平数对的数目 。
 *
 * 如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：
 *
 *
 * 0 <= i < j < n，且
 * lower <= nums[i] + nums[j] <= upper
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [0,1,7,4,4,5], lower = 3, upper = 6
 * 输出：6
 * 解释：共计 6 个公平数对：(0,3)、(0,4)、(0,5)、(1,3)、(1,4) 和 (1,5) 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1,7,9,2,5], lower = 11, upper = 11
 * 输出：1
 * 解释：只有单个公平数对：(2,3) 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * nums.length == n
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= lower <= upper <= 10^9
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

class TreeArray
{
private:
    /* data */
    void __add(int k, int v)
    {
        int v1 = k * v;
        while (k <= n)
        {
            // std::cout << "k:" << k << ":";
            t1[k] += v;
            t2[k] += v1;
            // std::cout << "k111:" << k << ":";
            // 注意不能写成 t2[k] += k * v，因为 k 的值已经不是原数组的下标了
            k += lowbit(k);
        }
    }

    int __getsum(vector<int> &t, int k)
    {
        int ret = 0;
        while (k)
        {
            ret += t[k];
            k -= lowbit(k);
        }
        return ret;
    }

public:
    int n;
    vector<int> t1;
    vector<int> t2;
    TreeArray(int maxn)
    {
        n = maxn;
        t1.resize(maxn + 10);
        t2.resize(maxn + 10);
    }

    inline int lowbit(int x) { return x & (-x); }

    void add1(int l, int r, int v)
    {
        __add(l, v);
        __add(r + 1, -v); // 将区间加差分为两个前缀加
    }

    long long getsum1(int l, int r)
    {
        return (r + 1ll) * __getsum(t1, r) - 1ll * l * __getsum(t1, l - 1) -
               (__getsum(t2, r) - __getsum(t2, l - 1));
    }
};

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        // 离散
        unordered_map<int, int> uii;
        for (int i = 0; i < nums.size(); i++)
        {
            uii[nums[i]] = -1;
        }

        vector<int> vi;
        for (pair<int, int> pp : uii)
        {
            vi.push_back(pp.first);
        }
        sort(vi.begin(), vi.end());
        for (int j = 0; j < vi.size(); j++)
        {
            uii[vi[j]] = j;
        }

        TreeArray *mta = new TreeArray(vi.size() + 10);

        long long result = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            int left = lower - nums[k];
            int right = upper - nums[k];

            // 第一个大于等于 i 的位置
            auto l_index = std::lower_bound(vi.begin(), vi.end(), left);
            int left_v = vi.size() + 1;
            int right_v = vi.size() + 1;
            if (l_index != vi.end())
            {
                left_v = std::distance(vi.begin(), l_index) + 1;
            }

            auto r_index = std::upper_bound(vi.begin(), vi.end(), right);

            if (r_index != vi.end())
            {
                right_v = std::distance(vi.begin(), r_index);
            }
            long long add = mta->getsum1(left_v, right_v);
            result += add;
            auto k_index = std::lower_bound(vi.begin(), vi.end(), nums[k]);
            int k_add = std::distance(vi.begin(), k_index) + 1;
            mta->add1(k_add, k_add, 1);
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
// [0,1,7,4,4,5]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,7,9,2,5]\n11\n11\n
// @lcpr case=end


// @lcpr case=start
// [-1,-1,0,0]\n1\n1
// @lcpr case=end


// @lcpr case=start
// [10,-9,-5,8,-2,-1000000000,-1000000000,-1000000000,-1000000000,-1000000000]\n-12\n11
// @lcpr case=end

 */
