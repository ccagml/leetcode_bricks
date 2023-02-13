/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 * @lcpr version=21505
 *
 * [1234] 替换子串得到平衡字符串
 *
 * https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (36.08%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    24.4K
 * Total Submissions: 56.2K
 * Testcase Example:  '"QWER"'
 *
 * 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
 *
 * 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
 *
 *
 *
 * 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
 *
 * 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
 *
 * 请返回待替换子串的最小可能长度。
 *
 * 如果原字符串自身就是一个平衡字符串，则返回 0。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "QWER"
 * 输出：0
 * 解释：s 已经是平衡的了。
 *
 * 示例 2：
 *
 * 输入：s = "QQWE"
 * 输出：1
 * 解释：我们需要把一个 'Q' 替换成 'R'，这样得到的 "RQWE" (或 "QRWE") 是平衡的。
 *
 *
 * 示例 3：
 *
 * 输入：s = "QQQW"
 * 输出：2
 * 解释：我们可以把前面的 "QQ" 替换成 "ER"。
 *
 *
 * 示例 4：
 *
 * 输入：s = "QQQQ"
 * 输出：3
 * 解释：我们可以替换后 3 个 'Q'，使 s = "QWER"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s.length 是 4 的倍数
 * s 中只含有 'Q', 'W', 'E', 'R' 四种字符
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
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
class Solution
{
public:
    int balancedString(string s)
    {
        vector<int> temp(4);
        for (char c : s)
        {
            if (c == 'Q')
            {
                temp[0]++;
            }
            else if (c == 'W')
            {
                temp[1]++;
            }
            else if (c == 'E')
            {
                temp[2]++;
            }
            else
            {
                temp[3]++;
            }
        }
        if (temp[0] == temp[1] && temp[1] == temp[2] && temp[2] == temp[3])
        {
            return 0;
        }

        int need = s.size() / 4;
        vector<int> q(4);
        q[0] = max(0, temp[0] - need);
        q[1] = max(0, temp[1] - need);
        q[2] = max(0, temp[2] - need);
        q[3] = max(0, temp[3] - need);
        //  QWERQWEE
        //  2 2 3 1
        int left = 0;
        int right = 0;
        vector<int> q1(4);
        int result = s.size();
        unordered_map<char, int> uci;
        uci['Q'] = 0;
        uci['W'] = 1;
        uci['E'] = 2;
        uci['R'] = 3;
        while (right <= s.size())
        {
            char cur = s[right];
            q1[uci[cur]]++;
            right++;
            while (q[uci[cur]] > 0 && q1[uci[cur]] > q[uci[cur]] && left < right)
            {
                int new_v = max(0, q1[uci[left]] - 1);
                q1[uci[left]] = new_v;
                left++;
            }
            std::cout << "(" << q[0] << "," << q[1] << "," << q[2] << "," << q[3] << "|";
            std::cout << q1[0] << "," << q1[1] << "," << q1[2] << "," << q1[3] << "=" << left << "," << right << ")" << std::endl;

            if (check(q, q1))
            {

                result = min(result, right - left);
            }
        }
        return result;
    }
    bool check(vector<int> &a, vector<int> &b)
    {
        if (a[0] > 0 && a[0] != b[0])
        {
            return false;
        }
        if (a[1] > 0 && a[1] != b[1])
        {
            return false;
        }
        if (a[2] > 0 && a[2] != b[2])
        {
            return false;
        }
        if (a[3] > 0 && a[3] != b[3])
        {
            return false;
        }
        return true;
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
// "QWER"\n
// @lcpr case=end

// @lcpr case=start
// "QQWE"\n
// @lcpr case=end

// @lcpr case=start
// "QQQW"\n
// @lcpr case=end

// @lcpr case=start
// "QQQQ"\n
// @lcpr case=end


// @lcpr case=start
// "WQWRQQQW"\n
// @lcpr case=end
 */
