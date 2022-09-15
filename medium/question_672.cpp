/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 *
 * https://leetcode.cn/problems/bulb-switcher-ii/description/
 *
 * algorithms
 * Medium (53.95%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 14.1K
 * Testcase Example:  '1\n1'
 *
 * 房间中有 n 只已经打开的灯泡，编号从 1 到 n 。墙上挂着 4 个开关 。
 *
 * 这 4 个开关各自都具有不同的功能，其中：
 *
 *
 * 开关 1 ：反转当前所有灯的状态（即开变为关，关变为开）
 * 开关 2 ：反转编号为偶数的灯的状态（即 2, 4, ...）
 * 开关 3 ：反转编号为奇数的灯的状态（即 1, 3, ...）
 * 开关 4 ：反转编号为 j = 3k + 1 的灯的状态，其中 k = 0, 1, 2, ...（即 1, 4, 7, 10, ...）
 *
 *  1  1 3 4
 *  2  1 2
 *  3  1 3
 *  4  1 2 4
 *  5  1 3
 *  6  1 2
 *  7  1 3 4
 * 你必须 恰好 按压开关 presses 次。每次按压，你都需要从 4 个开关中选出一个来执行按压操作。
 *
 * 给你两个整数 n 和 presses ，执行完所有按压之后，返回 不同可能状态 的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 1, presses = 1
 * 输出：2
 * 解释：状态可以是：
 * - 按压开关 1 ，[关]
 * - 按压开关 2 ，[开]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2, presses = 1
 * 输出：3
 * 解释：状态可以是：
 * - 按压开关 1 ，[关, 关]
 * - 按压开关 2 ，[开, 关]
 * - 按压开关 3 ，[关, 开]
 *
 *
 * 示例 3：
 *
 *
 * 输入：n = 3, presses = 1
 * 输出：4
 * 解释：状态可以是：
 * - 按压开关 1 ，[关, 关, 关]
 * - 按压开关 2 ，[关, 开, 关]
 * - 按压开关 3 ，[开, 关, 开]
 * - 按压开关 4 ，[关, 开, 开]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 1000
 * 0 <= presses <= 1000
 *
 *
 */

// @lc code=start

//  d  1  1 3 4
//  d  2  1 2
//  d  3  1 3
//  d  4  1 2 4
// ==================
//  k  1  1,2,3,4
//  k  2  2,4
//  k  3  1,3
//  k  4  1,4

// 强行模拟
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

    int new_d(int kaiguan, int old)
    {
        //  k  0  1,2,3,4
        //  k  1  2,4
        //  k  2  1,3
        //  k  3  1,4
        int result = old;
        for (int d_id = 1; d_id < need + 1; d_id++)
        {
            if (kaiguan == 0)
            {
                unordered_set<int> k0 = {1, 2, 3, 4};
                if (k0.count(d_id) > 0)
                {
                    if (is_bit_1(result, d_id))
                    {
                        result = set_bit_0(result, d_id);
                    }
                    else
                    {
                        result = set_bit_1(result, d_id);
                    }
                }
            }
            else if (kaiguan == 1)
            {
                unordered_set<int> k0 = {2, 4};
                if (k0.count(d_id) > 0)
                {
                    if (is_bit_1(result, d_id))
                    {
                        result = set_bit_0(result, d_id);
                    }
                    else
                    {
                        result = set_bit_1(result, d_id);
                    }
                }
            }
            else if (kaiguan == 2)
            {
                unordered_set<int> k0 = {1, 3};
                if (k0.count(d_id) > 0)
                {
                    if (is_bit_1(result, d_id))
                    {
                        result = set_bit_0(result, d_id);
                    }
                    else
                    {
                        result = set_bit_1(result, d_id);
                    }
                }
            }
            else if (kaiguan == 3)
            {
                unordered_set<int> k0 = {1, 4};
                if (k0.count(d_id) > 0)
                {
                    if (is_bit_1(result, d_id))
                    {
                        result = set_bit_0(result, d_id);
                    }
                    else
                    {
                        result = set_bit_1(result, d_id);
                    }
                }
            }
        }

        return result;
    }
    int need;
    int flipLights(int n, int presses)
    {
        unordered_set<int> us;
        need = min(4, n);
        int start = 0;
        for (int i = 1; i < need + 1; i++)
        {
            start = set_bit_1(start, i);
        }
        us.insert(start);
        for (int i = 0; i < presses; i++)
        {
            unordered_set<int> n_us;
            for (const auto &get : us)
            {
                for (int kaiguan = 0; kaiguan < 4; kaiguan++)
                {
                    int new_r = new_d(kaiguan, get);
                    n_us.insert(new_r);
                }
            }
            us = n_us;
        }
        return us.size();
    }
};
// @lc code=end
