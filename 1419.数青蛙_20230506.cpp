// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 * @lcpr version=21907
 *
 * [1419] 数青蛙
 *
 * https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/
 *
 * algorithms
 * Medium (43.63%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 43.5K
 * Testcase Example:  '"croakcroak"'
 *
 * 给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以
 * croakOfFrogs 中会混合多个 “croak” 。
 *
 * 请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。
 *
 * 要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5
 * 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回
 * -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：croakOfFrogs = "croakcroak"
 * 输出：1
 * 解释：一只青蛙 “呱呱” 两次
 *
 *
 * 示例 2：
 *
 * 输入：croakOfFrogs = "crcoakroak"
 * 输出：2
 * 解释：最少需要两只青蛙，“呱呱” 声用黑体标注
 * 第一只青蛙 "crcoakroak"
 * 第二只青蛙 "crcoakroak"
 *
 *
 * 示例 3：
 *
 * 输入：croakOfFrogs = "croakcrook"
 * 输出：-1
 * 解释：给出的字符串不是 "croak" 的有效组合。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= croakOfFrogs.length <= 10^5
 * 字符串中的字符只有 'c', 'r', 'o', 'a' 或者 'k'
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
    int minNumberOfFrogs(string croakOfFrogs)
    {
        vector<int> vi(5);
        int max_result = 0;
        unordered_map<char, int> uci = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'ck', 4}};
        for (char c : croakOfFrogs)
        {
            vi[uci[c]]++;
            if (c == 'c')
            {
                max_result = max(max_result, vi[0]);
            }
            if (uci[c] > 0 && vi[uci[c] - 1] < vi[uci[c]])
            {
                return -1;
            }
            if (c == 'k')
            {
                vi[0]--;
                vi[1]--;
                vi[2]--;
                vi[3]--;
                vi[4]--;
            }
        }
        for (int j : vi)
        {
            if (j > 0)
            {
                return -1;
            }
        }
        return max_result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minNumberOfFrogs
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "croakcroak"\n
// @lcpr case=end

// @lcpr case=start
// "crcoakroak"\n
// @lcpr case=end

// @lcpr case=start
// "croakcrook"\n
// @lcpr case=end


// @lcpr case=start
// "craok"\n
// @lcpr case=end

 */
