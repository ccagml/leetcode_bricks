// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 * @lcpr version=21905
 *
 * [1147] 段式回文
 *
 * https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/description/
 *
 * algorithms
 * Hard (56.66%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 28.8K
 * Testcase Example:  '"ghiabcdefhelloadamhelloabcdefghi"'
 *
 * 你会得到一个字符串 text 。你应该把它分成 k 个子字符串 (subtext1, subtext2，…， subtextk)
 * ，要求满足:
 *
 *
 * subtexti 是 非空 字符串
 * 所有子字符串的连接等于 text ( 即subtext1 + subtext2 + ... + subtextk == text )
 * 对于所有 i 的有效值( 即 1 <= i <= k ) ，subtexti == subtextk - i + 1 均成立
 *
 *
 * 返回k可能最大值。
 *
 *
 *
 * 示例 1：
 *
 * 输入：text = "ghiabcdefhelloadamhelloabcdefghi"
 * 输出：7
 * 解释：我们可以把字符串拆分成 "(ghi)(abcdef)(hello)(adam)(hello)(abcdef)(ghi)"。
 *
 *
 * 示例 2：
 *
 * 输入：text = "merchant"
 * 输出：1
 * 解释：我们可以把字符串拆分成 "(merchant)"。
 *
 *
 * 示例 3：
 *
 * 输入：text = "antaprezatepzapreanta"
 * 输出：11
 * 解释：我们可以把字符串拆分成 "(a)(nt)(a)(pre)(za)(tpe)(za)(pre)(a)(nt)(a)"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text.length <= 1000
 * text 仅由小写英文字符组成
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
    int longestDecomposition(string text)
    {

        if (text.size() < 1)
        {
            return 0;
        }
        else if (text.size() == 1)
        {
            return 1;
        }
        int result = 1;

        for (int i = 1; i <= text.size() / 2; i++)
        {
            string a = text.substr(0, i);
            string b = text.substr(text.size() - i);
            if (a == b)
            {
                // std::cout << "(" << i << "," << a << ":" << b << std::endl;
                int c = 2 + longestDecomposition(text.substr(i, (text.size() - 2 * i)));
                return c;
            }
        }

        return 1;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=longestDecomposition
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "ghiabcdefhelloadamhelloabcdefghi"\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n
// @lcpr case=end

// @lcpr case=start
// "merchant"\n
// @lcpr case=end

// @lcpr case=start
// "antaprezatepzapreanta"\n
// @lcpr case=end

 */
