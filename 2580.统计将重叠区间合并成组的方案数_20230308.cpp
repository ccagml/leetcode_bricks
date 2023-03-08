// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 * @lcpr version=21801
 *
 * [2580] 统计将重叠区间合并成组的方案数
 *
 * https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/description/
 *
 * algorithms
 * Medium (32.33%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 10.1K
 * Testcase Example:  '[[6,10],[5,15]]'
 *
 * 给你一个二维整数数组 ranges ，其中 ranges[i] = [starti, endi] 表示 starti 到 endi
 * 之间（包括二者）的所有整数都包含在第 i 个区间中。
 *
 * 你需要将 ranges 分成 两个 组（可以为空），满足：
 *
 *
 * 每个区间只属于一个组。
 * 两个有 交集 的区间必须在 同一个 组内。
 *
 *
 * 如果两个区间有至少 一个 公共整数，那么这两个区间是 有交集 的。
 *
 *
 * 比方说，区间 [1, 3] 和 [2, 5] 有交集，因为 2 和 3 在两个区间中都被包含。
 *
 *
 * 请你返回将 ranges 划分成两个组的 总方案数 。由于答案可能很大，将它对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：ranges = [[6,10],[5,15]]
 * 输出：2
 * 解释：
 * 两个区间有交集，所以它们必须在同一个组内。
 * 所以有两种方案：
 * - 将两个区间都放在第 1 个组中。
 * - 将两个区间都放在第 2 个组中。
 *
 *
 * 示例 2：
 *
 * 输入：ranges = [[1,3],[10,20],[2,5],[4,8]]
 * 输出：4
 * 解释：
 * 区间 [1,3] 和 [2,5] 有交集，所以它们必须在同一个组中。
 * 同理，区间 [2,5] 和 [4,8] 也有交集，所以它们也必须在同一个组中。
 * 所以总共有 4 种分组方案：
 * - 所有区间都在第 1 组。
 * - 所有区间都在第 2 组。
 * - 区间 [1,3] ，[2,5] 和 [4,8] 在第 1 个组中，[10,20] 在第 2 个组中。
 * - 区间 [1,3] ，[2,5] 和 [4,8] 在第 2 个组中，[10,20] 在第 1 个组中。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= ranges.length <= 10^5
 * ranges[i].length == 2
 * 0 <= starti <= endi <= 10^9
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

class unionFind
{
public:
    vector<int> v_father;
    unionFind(int n)
    {
        for (int i = 0; i < n; i++)
        {
            v_father.push_back(i);
        }
    }
    int get(int i)
    {
        if (v_father[i] == i)
        {
            return i;
        }
        v_father[i] = get(v_father[i]);
        return v_father[i];
    }
    void set(int a, int b)
    {
        int fa = get(a);
        int fb = get(b);
        if (fa > fb)
        {
            v_father[fa] = fb;
        }
        else if (fb > fa)
        {
            v_father[fb] = fa;
        }
    }
};

class Solution
{
public:
    int countWays(vector<vector<int>> &ranges)
    {
        unordered_set<int> usi;
        for (int i = 0; i < ranges.size(); i++)
        {
            usi.insert(ranges[i][0]);
            usi.insert(ranges[i][1]);
        }
        vector<int> vi;
        for (int p : usi)
        {
            vi.push_back(p);
        }

        sort(vi.begin(), vi.end());
        unordered_map<int, int> umii;
        for (int i = 0; i < vi.size(); i++)
        {
            umii[vi[i]] = i;
        }

        unionFind *uf = new unionFind(vi.size());
        for (int i = 0; i < ranges.size(); i++)
        {
            int a = ranges[i][0];
            int b = ranges[i][1];
            int a_index = umii[a];
            int b_index = umii[b];
            for (int j = a_index; j <= b_index; j++)
            {
                uf->set(a_index, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < vi.size(); i++)
        {
            if (uf->get(i) == i)
            {
                cnt++;
            }
        }
        return quick_pow(2, cnt);
    }

    long long quick_pow(long long a, long long b)
    {
        static const int MOD = 1e9 + 7;
        long long ret = 1;
        while (b)
        {
            if (b & 1)
            {
                ret = ret * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return ret;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=countWays
// paramTypes=["number[][]"]
// returnType=number
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[6,10],[5,15]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[10,20],[2,5],[4,8]]\n
// @lcpr case=end

 */
