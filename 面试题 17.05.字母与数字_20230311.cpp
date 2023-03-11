/*
 * @lc app=leetcode.cn id=面试题 17.05 lang=cpp
 * @lcpr version=21802
 *
 * [面试题 17.05]  字母与数字
 *
 * https://leetcode.cn/problems/find-longest-subarray-lcci/description/
 *
 * LCCI
 * Medium (45.26%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 39.4K
 * Testcase Example:  '["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]'
 *
 * 给定一个放有字母和数字的数组，找到最长的子数组，且包含的字母和数字的个数相同。
 *
 * 返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。
 *
 * 示例 1:
 *
 * 输入:
 * ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
 *
 * 输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]
 *
 *
 * 示例 2:
 *
 * 输入: ["A","A"]
 *
 * 输出: []
 *
 *
 * 提示：
 *
 *
 * array.length <= 100000
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
    vector<string> findLongestSubarray(vector<string> &array)
    {
        unordered_map<int, int> indices;
        indices[0] = -1;
        int sum = 0;
        int maxLength = 0;
        int startIndex = -1;
        int n = array.size();
        for (int i = 0; i < n; i++)
        {
            if (isalpha(array[i][0]))
            {
                sum++;
            }
            else
            {
                sum--;
            }
            if (indices.count(sum))
            {
                int firstIndex = indices[sum];
                if (i - firstIndex > maxLength)
                {
                    maxLength = i - firstIndex;
                    startIndex = firstIndex + 1;
                }
            }
            else
            {
                indices[sum] = i;
            }
        }
        if (maxLength == 0)
        {
            return {};
        }
        return vector<string>(array.begin() + startIndex, array.begin() + startIndex + maxLength);
    }
};
// class Solution
// {
// public:
//     vector<string> findLongestSubarray(vector<string> &array)
//     {
//         int n = array.size();
//         vector<int> zic(n);
//         vector<int> shuc(n);
//         unordered_map<string, int> umsvi;
//         int zi = 0;
//         int shu = 0;
//         std::string temp = std::to_string(zi) + "|" + std::to_string(shu);
//         umsvi[temp] = -1;
//         for (int i = 0; i < array.size(); i++)
//         {
//             if ((array[i][0] >= 'A' && array[i][0] <= 'Z') || (array[i][0] >= 'a' && array[i][0] <= 'z'))
//             {
//                 zi++;
//             }
//             else
//             {
//                 shu++;
//             }

//             zic[i] = zi;
//             shuc[i] = shu;
//             std::string temp = std::to_string(zi) + "|" + std::to_string(shu);
//             umsvi[temp] = i;
//         }

//         int result_left = -1;
//         int result_right = -1;

//         for (int i = 0; i < array.size(); i++)
//         {
//             int cur_zi = zic[i];
//             int cur_shu = shuc[i];
//             if (cur_zi > 0 && cur_shu > 0)
//             {
//                 int cur_min = min(cur_shu, cur_zi);
//                 for (int tempj = cur_min; tempj > 0; tempj--)
//                 {
//                     // 找到相同 cur_min 数量的字
//                     int need_zi = cur_zi - cur_min;
//                     int need_shu = cur_shu - cur_min;
//                     std::string temp = std::to_string(need_zi) + "|" + std::to_string(need_shu);
//                     if (umsvi.count(temp) > 0 && umsvi[temp] < i)
//                     {
//                         // 找到
//                         int cur_len = result_right - result_left + 1;
//                         int next_left = umsvi[temp] + 1;
//                         int j_len = i - next_left + 1;
//                         if (j_len > cur_len || (j_len == cur_len && next_left < result_left))
//                         {
//                             result_left = next_left;
//                             result_right = i;
//                         }
//                         break;
//                     }
//                 }
//             }
//         }

//         vector<string> result;
//         if (result_left >= 0)
//         {
//             for (int i = result_left; i <= result_right; i++)
//             {
//                 result.push_back(array[i]);
//             }
//         }

//         return result;
//     }
// };
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findLongestSubarray
// paramTypes=["string[]"]
// returnType=string[]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// ["42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"]
// @lcpr case=end

// @lcpr case=start
//
// @lcpr case=end

 */
