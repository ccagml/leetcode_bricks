/*
 * @lc app=leetcode.cn id=2381 lang=cpp
 *
 * [2381] 字母移位 II
 *
 * https://leetcode.cn/problems/shifting-letters-ii/description/
 *
 * algorithms
 * Medium (31.96%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 10.5K
 * Testcase Example:  '"abc"\n[[0,1,0],[1,2,1],[0,2,1]]'
 *
 * 给你一个小写英文字母组成的字符串 s 和一个二维整数数组 shifts ，其中 shifts[i] = [starti, endi,
 * directioni] 。对于每个 i ，将 s 中从下标 starti 到下标 endi （两者都包含）所有字符都进行移位运算，如果
 * directioni = 1 将字符向后移位，如果 directioni = 0 将字符向前移位。
 *
 * 将一个字符 向后 移位的意思是将这个字符用字母表中 下一个 字母替换（字母表视为环绕的，所以 'z' 变成 'a'）。类似的，将一个字符 向前
 * 移位的意思是将这个字符用字母表中 前一个 字母替换（字母表是环绕的，所以 'a' 变成 'z' ）。
 *
 * 请你返回对 s 进行所有移位操作以后得到的最终字符串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
 * 输出："ace"
 * 解释：首先，将下标从 0 到 1 的字母向前移位，得到 s = "zac" 。
 * 然后，将下标从 1 到 2 的字母向后移位，得到 s = "zbd" 。
 * 最后，将下标从 0 到 2 的字符向后移位，得到 s = "ace" 。
 *
 * 示例 2:
 *
 * 输入：s = "dztz", shifts = [[0,0,0],[1,1,1]]
 * 输出："catz"
 * 解释：首先，将下标从 0 到 0 的字母向前移位，得到 s = "cztz" 。
 * 最后，将下标从 1 到 1 的字符向后移位，得到 s = "catz" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length, shifts.length <= 5 * 10^4
 * shifts[i].length == 3
 * 0 <= starti <= endi < s.length
 * 0 <= directioni <= 1
 * s 只包含小写英文字母。
 *
 *
 */

// @lc code=start

typedef long long LL;

class Solution
{
public:
    LL n, a[100005], d[270000], b[270000];
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {

        int n = s.size();
        build(1, n, 1);
        for (int i = 0; i < shifts.size(); i++)
        {
            if (shifts[i][2] == 1)
            {
                update(shifts[i][0] + 1, shifts[i][1] + 1, 1, 1, n, 1);
            }
            else
            {
                update(shifts[i][0] + 1, shifts[i][1] + 1, -1, 1, n, 1);
            }
        }
        string result = "";
        for (int i = 0; i < s.size(); i++)
        {
            int num = getsum(i + 1, i + 1, 1, n, 1);
            int cur = s[i] - 'a';
            int old = s[i] - 'a';
            cur += num;
            while (cur > 25)
            {
                cur -= 26;
            }
            while (cur < 0)
            {
                cur += 26;
            }
            // std::cout << i << ":增加:" << num << ":" << old << "->" << cur << std::endl;
            result.push_back(cur + 'a');
        }
        return result;
    }
    void build(LL l, LL r, LL p)
    { // l:区间左端点 r:区间右端点 p:节点标号
        if (l == r)
        {
            d[p] = a[l]; // 将节点赋值
            return;
        }
        LL m = l + ((r - l) >> 1);
        build(l, m, p << 1);
        build(m + 1, r, (p << 1) | 1); // 分别建立子树
        d[p] = d[p << 1] + d[(p << 1) | 1];
    }

    void update(LL l, LL r, LL c, LL s, LL t, LL p)
    {
        if (l <= s && t <= r)
        {
            d[p] += (t - s + 1) * c;
            b[p] += c; // 如果区间被包含了，直接得出答案
            return;
        }
        LL m = s + ((t - s) >> 1);
        if (b[p])
            d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
                b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
        b[p] = 0;
        if (l <= m)
            update(l, r, c, s, m, p << 1); // 本行和下面的一行用来更新p*2和p*2+1的节点
        if (r > m)
            update(l, r, c, m + 1, t, (p << 1) | 1);
        d[p] = d[p << 1] + d[(p << 1) | 1]; // 计算该节点区间和
    }

    LL getsum(LL l, LL r, LL s, LL t, LL p)
    {
        if (l <= s && t <= r)
            return d[p];
        LL m = s + ((t - s) >> 1);
        if (b[p])
            d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
                b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
        b[p] = 0;
        LL sum = 0;
        if (l <= m)
            sum =
                getsum(l, r, s, m, p << 1); // 本行和下面的一行用来更新p*2和p*2+1的答案
        if (r > m)
            sum += getsum(l, r, m + 1, t, (p << 1) | 1);
        return sum;
    }
};
// @lc code=end
