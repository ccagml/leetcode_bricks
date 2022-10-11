/*
 * @lc app=leetcode.cn id=1073 lang=cpp
 *
 * [1073] 负二进制数相加
 *
 * https://leetcode.cn/problems/adding-two-negabinary-numbers/description/
 *
 * algorithms
 * Medium (35.16%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 9.5K
 * Testcase Example:  '[1,1,1,1,1]\n[1,0,1]'
 *
 * 给出基数为 -2 的两个数 arr1 和 arr2，返回两数相加的结果。
 *
 * 数字以 数组形式 给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。例如，arr = [1,1,0,1] 表示数字 (-2)^3
 * + (-2)^2 + (-2)^0 = -3。数组形式 中的数字 arr 也同样不含前导零：即 arr == [0] 或 arr[0] == 1。
 *
 * 返回相同表示形式的 arr1 和 arr2 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]
 * 输出：[1,0,0,0,0]
 * 解释：arr1 表示 11，arr2 表示 5，输出表示 16 。
 *
 *
 *
 *
 * 示例 2：
 *
 * 输入：arr1 = [0], arr2 = [0]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 * 输入：arr1 = [0], arr2 = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 * 1 <= arr1.length, arr2.length <= 1000
 * arr1[i] 和 arr2[i] 都是 0 或 1
 * arr1 和 arr2 都没有前导0
 *
 *
 */

// @lc code=start
// 进制的分析 应该是 两个 当前位可以抵消一个下一位
// 如果下一位没有, 则可以表示成 下二位 和 下一位

class Solution
{
public:
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> result;
        int a = arr1.size() - 1;
        int b = arr2.size() - 1;
        while (a >= 0 && b >= 0)
        {
            result.push_back(arr1[a] + arr2[b]);
            a--;
            b--;
        }
        while (a >= 0)
        {
            result.push_back(arr1[a]);
            a--;
        }
        while (b >= 0)
        {
            result.push_back(arr2[b]);

            b--;
        }
        result.push_back(0);
        result.push_back(0);
        result.push_back(0);
        result.push_back(0);
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i] == 2)
            {
                if (result[i + 1] == 0)
                {
                    result[i + 2]++;
                    result[i + 1]++;
                }
                else
                {
                    result[i + 1]--;
                }
                result[i] = 0;
            }
            else if (result[i] == 3)
            {
                if (result[i + 1] == 0)
                {
                    result[i + 2]++;
                    result[i + 1]++;
                }
                else
                {
                    result[i + 1]--;
                }
                result[i] = 1;
            }
        }
        vector<int> resultb;
        bool flag = false;
        for (int i = result.size() - 1; i >= 0; i--)
        {
            if (!flag && result[i] == 0)
            {
                continue;
            }
            flag = true;
            resultb.push_back(result[i]);
        }
        if (resultb.size() == 0)
        {
            return {0};
        }
        return resultb;
    }
};
// @lc code=end
