/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 *
 * https://leetcode.cn/problems/sort-array-by-increasing-frequency/description/
 *
 * algorithms
 * Easy (71.58%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 30.9K
 * Testcase Example:  '[1,1,2,2,2,3]'
 *
 * 给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 
 *
 * 请你返回排序后的数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,2,2,2,3]
 * 输出：[3,1,1,2,2,2]
 * 解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,3,1,3,2]
 * 输出：[1,3,3,2,2]
 * 解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [-1,1,-6,4,5,-6,1,4,1]
 * 输出：[5,-1,4,4,-6,-6,1,1,1]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 100
 * -100 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
        }
        vector<pair<int, int>> v_pair;
        for (pair<int, int> pp : um)
        {
            // std::cout << "ru" << pp.first << ":" << pp.second << std::endl;
            v_pair.push_back({pp.first, pp.second});
        }
        //(4,3),(3,5),(2,3),(1,5),(1,3),
        std::sort(v_pair.begin(), v_pair.end(),
                  [](const std::pair<int, int> &left, const std::pair<int, int> &right)
                  {
                      // true使得left排前面
                      if (left.second < right.second)
                      {
                          return true;
                      }
                      else if (left.second == right.second && left.first > right.first)
                      {
                          return true;
                      }
                      return false;
                  });
        vector<int> result;
        for (int i = 0; i < v_pair.size(); i++)
        {
            pair<int, int> pii = v_pair[i];

            for (int j = 0; j < pii.second; j++)
            {
                result.push_back(pii.first);
            }
        }
        return result;
    }
};
// @lc code=end
