// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 * @lcpr version=21911
 *
 * [2266] 统计打字方案数
 *
 * https://leetcode.cn/problems/count-number-of-texts/description/
 *
 * algorithms
 * Medium (43.62%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 17.9K
 * Testcase Example:  '"22233"'
 *
 * Alice 在给 Bob 用手机打字。数字到字母的 对应 如下图所示。
 *
 *
 *
 * 为了 打出 一个字母，Alice 需要 按 对应字母 i 次，i 是该字母在这个按键上所处的位置。
 *
 *
 * 比方说，为了按出字母 's' ，Alice 需要按 '7' 四次。类似的， Alice 需要按 '5' 两次得到字母  'k' 。
 * 注意，数字 '0' 和 '1' 不映射到任何字母，所以 Alice 不 使用它们。
 *
 *
 * 但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 按键的字符串信息 。
 *
 *
 * 比方说，Alice 发出的信息为 "bob" ，Bob 将收到字符串 "2266622" 。
 *
 *
 * 给你一个字符串 pressedKeys ，表示 Bob 收到的字符串，请你返回 Alice 总共可能发出多少种文字信息 。
 *
 * 由于答案可能很大，将它对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：pressedKeys = "22233"
 * 输出：8
 * 解释：
 * Alice 可能发出的文字信息包括：
 * "aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
 * 由于总共有 8 种可能的信息，所以我们返回 8 。
 *
 *
 * 示例 2：
 *
 * 输入：pressedKeys = "222222222222222222222222222222222222"
 * 输出：82876089
 * 解释：
 * 总共有 2082876103 种 Alice 可能发出的文字信息。
 * 由于我们需要将答案对 10^9 + 7 取余，所以我们返回 2082876103 % (10^9 + 7) = 82876089 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= pressedKeys.length <= 10^5
 * pressedKeys 只包含数字 '2' 到 '9' 。
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
    int countTexts(string pressedKeys)
    {
        int last = 0;
        int cnt = 0;
        unsigned long long result = 1;
        for (int i = 0; i < pressedKeys.size(); i++)
        {
            long long temp_cnt = 0;
            if (pressedKeys[i] - '0' != last)
            {

                if (cnt > 0)
                {
                    if (last == 7 || last == 9)
                    {
                        temp_cnt = f_4(cnt);
                    }
                    else
                    {
                        temp_cnt = f_3(cnt);
                    }
                }
                last = pressedKeys[i] - '0';
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            if (temp_cnt > 0)
            {
                result *= temp_cnt;
                std::cout << "* " << temp_cnt << std::endl;
                int e97 = 1e9 + 7;
                result %= e97;
                temp_cnt = 0;
            }
            if (i == pressedKeys.size() - 1)
            {
                if (last == 7 || last == 9)
                {
                    temp_cnt = f_4(cnt);
                }
                else
                {
                    temp_cnt = f_3(cnt);
                }
            }
            if (temp_cnt > 0)
            {
                result *= temp_cnt;
                int e97 = 1e9 + 7;
                result %= e97;
            }
        }
        return result;
    }

    unordered_map<int, long long> umill3;
    unordered_map<int, long long> umill4;
    long long f_3(int need)
    {
        vector<int> coin = {1, 2, 3};
        vector<long long> vi(need + 1, 0);
        vi[0] = 1;
        vi[1] = 1;
        if (umill3.count(need) > 0)
        {
            return umill3[need];
        }
        for (int i = 2; i <= need; i++)
        {
            for (int c : coin)
            {
                if (c <= i)
                {
                    vi[i] += vi[i - c];
                    int e97 = 1e9 + 7;
                    vi[i] %= e97;
                }
            }
            umill3[i] = vi[i];
        }
        return vi[need];
    }
    long long f_4(int need)
    {
        vector<int> coin = {1, 2, 3, 4};
        vector<long long> vi(need + 1, 0);
        vi[0] = 1;
        vi[1] = 1;
        if (umill4.count(need) > 0)
        {
            return umill4[need];
        }
        for (int i = 2; i <= need; i++)
        {
            for (int c : coin)
            {
                if (c <= i)
                {
                    vi[i] += vi[i - c];
                    int e97 = 1e9 + 7;
                    vi[i] %= e97;
                }
            }
            umill4[i] = vi[i];
        }
        return vi[need];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=countTexts
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "22233"\n
// @lcpr case=end

// @lcpr case=start
// "222222222222222222222222222222222222"\n
// @lcpr case=end

// @lcpr case=start
// "444479999555588866"\n
// @lcpr case=end

// @lcpr case=start
// "344644885"\n
// @lcpr case=end

// @lcpr case=start
// "444444444444444444444444444444448888888888888888999999999999333333333333333366666666666666662222222222222222666666666666666633333333333333338888888888888888222222222222222244444444444444448888888888888222222222222222288888888888889999999999999999333333333444444664"\n
// @lcpr case=end
// 537551452

// @lcpr case=start
// "44444444444444444444444444444444"\n"8888888888888888"\n"999999999999"\n"3333333333333333"\n"6666666666666666"\n"2222222222222222"\n"6666666666666666"\n"3333333333333333"\n"8888888888888888"\n"2222222222222222"\n"4444444444444444"\n"8888888888888"\n"2222222222222222"\n"8888888888888"\n"9999999999999999"\n"333333333"\n"444444664"\n
// @lcpr case=end

 */
