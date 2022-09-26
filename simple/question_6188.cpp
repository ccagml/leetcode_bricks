/*
 * @lc app=leetcode.cn id=6188 lang=cpp
 *
 * [6188] 按身高排序
 *
 * https://leetcode.cn/problems/sort-the-people/description/
 *
 * algorithms
 * Easy (79.90%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 8.6K
 * Testcase Example:  '["Mary","John","Emma"]\n[180,165,170]'
 *
 * 给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。
 *
 * 对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。
 *
 * 请按身高 降序 顺序返回对应的名字数组 names 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：names = ["Mary","John","Emma"], heights = [180,165,170]
 * 输出：["Mary","Emma","John"]
 * 解释：Mary 最高，接着是 Emma 和 John 。
 *
 *
 * 示例 2：
 *
 * 输入：names = ["Alice","Bob","Bob"], heights = [155,185,150]
 * 输出：["Bob","Alice","Bob"]
 * 解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == names.length == heights.length
 * 1 <= n <= 10^3
 * 1 <= names[i].length <= 20
 * 1 <= heights[i] <= 10^5
 * names[i] 由大小写英文字母组成
 * heights 中的所有值互不相同
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> vpis;
        for (int i = 0; i < names.size(); i++)
        {
            vpis.push_back({heights[i], names[i]});
        }

        sort(vpis.begin(), vpis.end(),
             [](const std::pair<int, string> &left, const std::pair<int, string> &right)
             {
                 // true使得left排前面
                 if (left.first > right.first)
                 {
                     return true;
                 }
                 return false;
             });
        vector<string> result;
        for (int i = 0; i < names.size(); i++)
        {
            result.push_back(vpis[i].second);
        }
        return result;
    }
};
// @lc code=end
