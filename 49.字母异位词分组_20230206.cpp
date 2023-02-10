/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=21504
 *
 * [49] 字母异位词分组
 *
 * https://leetcode.cn/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (67.80%)
 * Likes:    1374
 * Dislikes: 0
 * Total Accepted:    420.5K
 * Total Submissions: 620.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 * 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
 *
 *
 *
 * 示例 1:
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 示例 2:
 *
 * 输入: strs = [""]
 * 输出: [[""]]
 *
 *
 * 示例 3:
 *
 * 输入: strs = ["a"]
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
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
    int set_bit_1(int x, int index)
    {
        x |= (1 << index);
        return x;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> uivs;
        for (int i = 0; i < strs.size(); i++)
        {
            string cur = strs[i];
            // int temp = 0;
            vector<int> temp_v(26);
            for (char c : cur)
            {
                // temp = set_bit_1(temp, c - 'a');
                temp_v[c - 'a']++;
            }
            string temp = "";
            for (int i = 0; i < 26; i++)
            {
                temp.append(temp_v[i]);
                temp.push_back('|');
            }
            uivs[temp].push_back(cur);
        }
        vector<vector<string>> result;
        for (auto pp : uivs)
        {
            result.push_back(pp.second);
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
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
