// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1465 lang=cpp
 * @lcpr version=30102
 *
 * [1465] 切割后面积最大的蛋糕
 *
 * https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/
 *
 * algorithms
 * Medium (33.34%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    21.2K
 * Total Submissions: 51.7K
 * Testcase Example:  '5\n4\n[1,2,4]\n[1,3]'
 *
 * 矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 和 verticalCuts，其中：
 *
 *
 * horizontalCuts[i] 是从矩形蛋糕顶部到第  i 个水平切口的距离
 * verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离
 *
 *
 * 请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，请你找出 面积最大 的那份蛋糕，并返回其 面积
 * 。由于答案可能是一个很大的数字，因此需要将结果 对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
 * 输出：4
 * 解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色的那份蛋糕面积最大。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
 * 输出：6
 * 解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色和黄色的两份蛋糕面积最大。
 *
 * 示例 3：
 *
 * 输入：h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= h, w <= 10^9
 * 1 <= horizontalCuts.length <= min(h - 1, 10^5)
 * 1 <= verticalCuts.length <= min(w - 1, 10^5)
 * 1 <= horizontalCuts[i] < h
 * 1 <= verticalCuts[i] < w
 * 题目数据保证 horizontalCuts 中的所有元素各不相同
 * 题目数据保证 verticalCuts 中的所有元素各不相同
 *
 *
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int h_max = 0;
        int v_max = 0;
        for (int j = 1; j < horizontalCuts.size(); j++)
        {
            h_max = max(h_max, horizontalCuts[j] - horizontalCuts[j - 1]);
        }
        for (int j = 1; j < verticalCuts.size(); j++)
        {
            v_max = max(v_max, verticalCuts[j] - verticalCuts[j - 1]);
        }
        long long temp = 1;
        long long result = temp * h_max * v_max;
        int j = result % (1000000007);
        return j;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxArea
// paramTypes= ["number","number","number[]","number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 5\n4\n[1,2,4]\n[1,3]\n
// @lcpr case=end

// @lcpr case=start
// 5\n4\n[3,1]\n[1]\n
// @lcpr case=end

// @lcpr case=start
// 5\n4\n[3]\n[3]\n
// @lcpr case=end

 */
