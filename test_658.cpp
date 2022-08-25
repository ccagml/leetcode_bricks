/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 *
 * https://leetcode.cn/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (45.94%)
 * Likes:    375
 * Dislikes: 0
 * Total Accepted:    50.2K
 * Total Submissions: 106.9K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
 *
 * 整数 a 比整数 b 更接近 x 需要满足：
 *
 *
 * |a - x| < |b - x| 或者
 * |a - x| == |b - x| 且 a < b
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [1,2,3,4,5], k = 4, x = 3
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,2,3,4,5], k = 4, x = -1
 * 输出：[1,2,3,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr 按 升序 排列
 * -10^4 <= arr[i], x <= 10^4
 *
 *
 */

// @lc code=start
// 二分 双指针
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> result;
        auto index = std::lower_bound(arr.begin(), arr.end(), x);
        if (index != arr.end())
        {
            int right = index - arr.begin();
            int left = right - 1;
            // std::cout << left << ":" << right << std::endl;
            while (result.size() < k)
            {
                // |a - x| < |b - x| 或者 |a - x| == |b - x| 且 a < b
                bool left_flag = true;
                if (left >= 0 && left < arr.size() && right >= 0 && right < arr.size())
                {
                    if (abs(arr[left] - x) < abs(arr[right] - x))
                    {
                        left_flag = true;
                    }
                    else if (abs(arr[left] - x) == abs(arr[right] - x) && arr[left] < arr[right])
                    {
                        left_flag = true;
                    }
                    else
                    {
                        left_flag = false;
                    }
                }
                else if (left >= 0 && left < arr.size())
                {
                    left_flag = true;
                }
                else if (right >= 0 && right < arr.size())
                {
                    left_flag = false;
                }
                if (left_flag)
                {
                    result.push_back(arr[left--]);
                }
                else
                {
                    result.push_back(arr[right++]);
                }
            }
        }
        else
        {
            // 没找到,说明值 比整个arr还大
            int left = arr.size() - 1;
            while (result.size() < k)
            {
                result.push_back(arr[left--]);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
