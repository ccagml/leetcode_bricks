// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1292 lang=cpp
 * @lcpr version=21909
 *
 * [1292] 元素和小于等于阈值的正方形的最大边长
 *
 * https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/
 *
 * algorithms
 * Medium (50.73%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 22.5K
 * Testcase Example:  '[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]\n4'
 *
 * 给你一个大小为 m x n 的矩阵 mat 和一个整数阈值 threshold。
 *
 * 请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 0 。
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
 * 输出：2
 * 解释：总和小于或等于 4 的正方形的最大边长为 2，如图所示。
 *
 *
 * 示例 2：
 *
 * 输入：mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]],
 * threshold = 1
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 300
 * 0 <= mat[i][j] <= 10^4
 * 0 <= threshold <= 10^5^ 
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
    int y;
    int x;
    int ttt;
    vector<vector<int>> mat_sum;
    bool check(int len)
    {
        int add = len - 1;
        if (add < 0)
        {
            return true;
        }
        for (int yy = 0; yy < y; yy++)
        {
            int end_yy = yy + add;
            if (end_yy >= y)
            {
                break;
            }
            for (int xx = 0; xx < x; xx++)
            {
                int end_yy = yy + add;
                int end_xx = xx + add;
                if (end_yy < y && end_xx < x)
                {
                    int a = 0;
                    int b = 0;
                    int c = 0;
                    int d = 0;

                    int a_y = end_yy - len;
                    int a_x = end_xx - len;

                    int b_y = end_yy - len;
                    int b_x = end_xx;
                    int c_y = end_yy;
                    int c_x = end_xx - len;
                    int d_y = end_yy;
                    int d_x = end_xx;
                    if (a_y >= 0 && a_x >= 0)
                    {
                        a = mat_sum[a_y][a_x];
                    }
                    if (b_y >= 0 && b_x >= 0)
                    {
                        b = mat_sum[b_y][b_x];
                    }
                    if (c_y >= 0 && c_x >= 0)
                    {
                        c = mat_sum[c_y][c_x];
                    }
                    if (d_y >= 0 && d_x >= 0)
                    {
                        d = mat_sum[d_y][d_x];
                    }
                    int temp = d - b - c + a;
                    if (temp <= ttt)
                    {
                        return true;
                    }
                    /*  y, x
                        (0, 0),(0, 1),(0, 2),(0, 3)
                        (1, 0),(1, 1),(1, 2),(1, 3)
                        (2, 0),(2, 1),(2, 2),(2, 3)
                        (3, 0),(3, 1),(3, 2),(3, 3)

                    */
                }
                else
                {
                    break;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        y = mat.size();
        x = mat[0].size();
        ttt = threshold;
        vector<vector<int>> mat_temp(y, vector<int>(x, 0));
        for (int yy = 0; yy < y; yy++)
        {
            for (int xx = 0; xx < x; xx++)
            {
                if (yy == 0 && xx == 0)
                {
                    mat_temp[yy][xx] = mat[yy][xx];
                }
                else if (yy == 0)
                {
                    mat_temp[yy][xx] = mat_temp[yy][xx - 1] + mat[yy][xx];
                }
                else if (xx == 0)
                {
                    mat_temp[yy][xx] = mat_temp[yy - 1][xx] + mat[yy][xx];
                }
                else
                {
                    int a = mat_temp[yy - 1][xx - 1];
                    int b = mat_temp[yy - 1][xx];
                    int c = mat_temp[yy][xx - 1];
                    int d = mat[yy][xx];
                    mat_temp[yy][xx] = b + c + d - a;
                }
            }
        }
        mat_sum = mat_temp;

        int left = 0;
        int right = min(mat.size(), mat[0].size());
        unordered_map<int, bool> umii;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;

            // [left, mid - 1]
            // [mid, right]
            if (check(mid))
            {
                left = mid;
                umii[mid] = true;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (umii.count(left))
        {
            return left;
        }
        return 0;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=maxSideLength
// paramTypes= ["number[][]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]]\n1\n
// @lcpr case=end


// @lcpr case=start
// [[1,1,1,1],[1,0,0,0],[1,0,0,0],[1,0,0,0]]\n6
// @lcpr case=end



 */
