/*
 * @lc app=leetcode.cn id=2305 lang=cpp
 *
 * [2305] 公平分发饼干
 *
 * https://leetcode.cn/problems/fair-distribution-of-cookies/description/
 *
 * algorithms
 * Medium (71.51%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 11.6K
 * Testcase Example:  '[8,15,10,20,8]\n2'
 *
 * 给你一个整数数组 cookies ，其中 cookies[i] 表示在第 i 个零食包中的饼干数量。另给你一个整数 k
 * 表示等待分发零食包的孩子数量，所有 零食包都需要分发。在同一个零食包中的所有饼干都必须分发给同一个孩子，不能分开。
 *
 * 分发的 不公平程度 定义为单个孩子在分发过程中能够获得饼干的最大总数。
 *
 * 返回所有分发的最小不公平程度。
 *
 *
 *
 * 示例 1：
 *
 * 输入：cookies = [8,15,10,20,8], k = 2
 * 输出：31
 * 解释：一种最优方案是 [8,15,8] 和 [10,20] 。
 * - 第 1 个孩子分到 [8,15,8] ，总计 8 + 15 + 8 = 31 块饼干。
 * - 第 2 个孩子分到 [10,20] ，总计 10 + 20 = 30 块饼干。
 * 分发的不公平程度为 max(31,30) = 31 。
 * 可以证明不存在不公平程度小于 31 的分发方案。
 *
 *
 * 示例 2：
 *
 * 输入：cookies = [6,1,3,2,2,4,1,2], k = 3
 * 输出：7
 * 解释：一种最优方案是 [6,1]、[3,2,2] 和 [4,1,2] 。
 * - 第 1 个孩子分到 [6,1] ，总计 6 + 1 = 7 块饼干。
 * - 第 2 个孩子分到 [3,2,2] ，总计 3 + 2 + 2 = 7 块饼干。
 * - 第 3 个孩子分到 [4,1,2] ，总计 4 + 1 + 2 = 7 块饼干。
 * 分发的不公平程度为 max(7,7,7) = 7 。
 * 可以证明不存在不公平程度小于 7 的分发方案。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= cookies.length <= 8
 * 1 <= cookies[i] <= 10^5
 * 2 <= k <= cookies.length
 *
 *
 */

// @lc code=start
// 看这个数据量 第一直觉 应该是 要一个数字打标记位 然后遍历所有组合 思路是对的
// 把cookie_flag转成result1_v 可以让速度变快
class Solution
{
public:
    unordered_map<int, int> cookie_flag;
    vector<int> mycookies;
    int my_k;
    int result;
    int all_cookie_k;

    vector<pair<int, int>> result1_v;

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

    void dfs_cookie(int cur_index, int flag, int sum)
    {
        if (cur_index >= mycookies.size())
        {
            return;
        }
        int new_flag = set_bit_1(flag, cur_index);
        int new_sum = sum + mycookies[cur_index];
        cookie_flag[new_flag] = new_sum;
        dfs_cookie(cur_index + 1, flag, sum);
        dfs_cookie(cur_index + 1, new_flag, new_sum);
    }

    void check_result(int cur_result, int cur_all_flag, int cur_k)
    {
        // 看看有么有出结果
        if (cur_k == my_k)
        {
            if (all_cookie_k == cur_all_flag)
            {
                // std::cout << "cur_result:" << cur_result << std::endl;
                result = min(result, cur_result);
            }
            return;
        }
        for (pair<int, int> tt : cookie_flag)
        {
            if (((tt.first & cur_all_flag) == 0) && (tt.second <= result))
            {
                check_result(max(cur_result, tt.second), (tt.first | cur_all_flag), cur_k + 1);
            }
        }
    }

    void check_result_other(int cur_result, int cur_all_flag, int cur_k, int v_index)
    {
        // 看看有么有出结果
        if (cur_k == my_k)
        {
            if (all_cookie_k == cur_all_flag)
            {
                // std::cout << "cur_result:" << cur_result << std::endl;
                result = min(result, cur_result);
            }
            return;
        }
        for (int i = v_index; i < result1_v.size(); i++)
        {
            pair<int, int> tt = result1_v[i];
            if (((tt.first & cur_all_flag) == 0) && (tt.second <= result))
            {
                check_result_other(max(cur_result, tt.second), (tt.first | cur_all_flag), cur_k + 1, i + 1);
            }
        }
    }

    void other()
    {
        for (pair<int, int> tt : cookie_flag)
        {
            result1_v.push_back(tt);
        }
        check_result_other(0, 0, 0, 0);
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        my_k = k;
        result = 1000000;
        all_cookie_k = 0;
        for (int i = 0; i < cookies.size(); i++)
        {
            all_cookie_k = set_bit_1(all_cookie_k, i);
        }
        // std::cout << "all_cookie_k" << all_cookie_k << std::endl;
        mycookies = cookies;
        dfs_cookie(0, 0, 0);
        // check_result(0, 0, 0);
        other();

        return result;
    }
};
// @lc code=end
