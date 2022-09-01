/*
 * @lc app=leetcode.cn id=2002 lang=cpp
 *
 * [2002] 两个回文子序列长度的最大乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/description/
 *
 * algorithms
 * Medium (59.75%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    5K
 * Total Submissions: 8.4K
 * Testcase Example:  '"leetcodecom"'
 *
 * 给你一个字符串 s ，请你找到 s 中两个 不相交回文子序列 ，使得它们长度的 乘积最大 。两个子序列在原字符串中如果没有任何相同下标的字符，则它们是
 * 不相交 的。
 *
 * 请你返回两个回文子序列长度可以达到的 最大乘积 。
 *
 * 子序列
 * 指的是从原字符串中删除若干个字符（可以一个也不删除）后，剩余字符不改变顺序而得到的结果。如果一个字符串从前往后读和从后往前读一模一样，那么这个字符串是一个
 * 回文字符串 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：s = "leetcodecom"
 * 输出：9
 * 解释：最优方案是选择 "ete" 作为第一个子序列，"cdc" 作为第二个子序列。
 * 它们的乘积为 3 * 3 = 9 。
 *
 *
 * 示例 2：
 *
 * 输入：s = "bb"
 * 输出：1
 * 解释：最优方案为选择 "b" （第一个字符）作为第一个子序列，"b" （第二个字符）作为第二个子序列。
 * 它们的乘积为 1 * 1 = 1 。
 *
 *
 * 示例 3：
 *
 * 输入：s = "accbcaxxcxx"
 * 输出：25
 * 解释：最优方案为选择 "accca" 作为第一个子序列，"xxcxx" 作为第二个子序列。
 * 它们的乘积为 5 * 5 = 25 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= s.length <= 12
 * s 只含有小写英文字母。
 *
 *
 */

// @lc code=start

// 先找一个?然后看剩下的能不能拼成另外一个
// 应该要有一个数字 用来表示选取哪几个
// 然后两个数字 & 是 0 就可以计算结果

// 思路是对的, 两个中心的回文,没考虑到 两个值不是连一起的情况"zqz"

class Solution
{
public:
    string my_string;
    unordered_map<int, int> all_hui;
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

    void check_all(int left, int right, int flag, int one_cnt)
    {
        if (all_hui.count(flag) == 0)
        {
            if (166 == flag)
            {
                // std::cout << left << ":" <<  right << ":" <<  flag << ":" <<  one_cnt << ":" << get_print(flag) << std::endl;
            }
            all_hui[flag] = one_cnt;
            // 以当前的边界扩展
            int start_left = left;
            int start_right = right;
            while (start_left >= 0 && start_right < my_string.size())
            {
                // 检查两边
                if (my_string[start_left] == my_string[start_right])
                {
                    int new_flag = flag;
                    new_flag = set_bit_1(new_flag, start_left);
                    new_flag = set_bit_1(new_flag, start_right);
                    check_all(start_left - 1, start_right + 1, new_flag, one_cnt + 2);
                }
                start_right++;
                if (start_right == my_string.size())
                {
                    start_left--;
                    start_right = right;
                }
            }
        }
    }
    string get_print(int num)
    {
        string result;
        for (int i = 0; i < my_string.size(); i++)
        {
            if (is_bit_1(num, i))
            {
                result.push_back(my_string[i]);
            }
        }
        return result;
    }
    int maxProduct(string s)
    {
        my_string = s;
        for (int i = 0; i < s.size(); i++)
        {
            check_all(i - 1, i + 1, set_bit_1(0, i), 1);
        }
        // 以两个字符为中心的回文
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    int temp_flag = 0;
                    temp_flag = set_bit_1(temp_flag, i);
                    temp_flag = set_bit_1(temp_flag, j);
                    check_all(i - 1, j + 1, temp_flag, 2);
                }
            }
        }

        // std::cout << all_hui.size() << "个回文串" << std::endl;
        int result = 1;
        for (pair<int, int> get : all_hui)
        {
            for (pair<int, int> get1 : all_hui)
            {
                if ((get.first & get1.first) == 0)
                {
                    // if ((get.second * get1.second) == 15)
                    // {
                    // std::cout << get.first << "(" << get_print(get.first) << ")"
                    //               << ":" << get1.first << "(" << get_print(get1.first) << ")" << std::endl;
                    // }
                    result = max(result, (get.second * get1.second));
                }
            }
        }
        return result;
    }
};
// @lc code=end
