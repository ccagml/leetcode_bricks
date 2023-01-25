/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 * @lcpr version=21115
 *
 * [1301] 最大得分的路径数目
 *
 * https://leetcode.cn/problems/number-of-paths-with-max-score/description/
 *
 * algorithms
 * Hard (37.64%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 16.5K
 * Testcase Example:  '["E23","2X2","12S"]\r'
 *
 * 给你一个正方形字符数组 board ，你从数组最右下方的字符 'S' 出发。
 *
 * 你的目标是到达数组最左上角的字符 'E' ，数组剩余的部分为数字字符 1, 2, ..., 9 或者障碍
 * 'X'。在每一步移动中，你可以向上、向左或者左上方移动，可以移动的前提是到达的格子没有障碍。
 *
 * 一条路径的 「得分」 定义为：路径上所有数字的和。
 *
 * 请你返回一个列表，包含两个整数：第一个整数是 「得分」 的最大值，第二个整数是得到最大得分的方案数，请把结果对 10^9 + 7 取余。
 *
 * 如果没有任何路径可以到达终点，请返回 [0, 0] 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：board = ["E23","2X2","12S"]
 * 输出：[7,1]
 *
 *
 * 示例 2：
 *
 * 输入：board = ["E12","1X1","21S"]
 * 输出：[4,2]
 *
 *
 * 示例 3：
 *
 * 输入：board = ["E11","XXX","11S"]
 * 输出：[0,0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= board.length == board[i].length <= 100
 *
 *
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
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
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int y = board.size();
        int x = board[0].size();
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> vvpii(y, vector<pair<int, int>>(x));
        vector<pair<int, int>> dir = {{1, 1}, {1, 0}, {0, 1}};
        vector<vector<bool>> vvb(y, vector<bool>(x, false));
        for (int yy = y - 1; yy >= 0; yy--)
        {
            for (int xx = x - 1; xx >= 0; xx--)
            {
                if (yy == y - 1 && xx == x - 1)
                {
                    vvpii[yy][xx] = {0, 1};
                    vvb[yy][xx] = true;
                }
                else if (board[yy][xx] == 'X')
                {
                }
                else
                {
                    int aaa = board[yy][xx];
                    if (aaa != 'X')
                    {
                        aaa = board[yy][xx];
                        if (aaa == 'E')
                        {
                            aaa = 0;
                        }
                        else
                        {
                            aaa = board[yy][xx] - '0';
                        }
                        if (yy + 1 < y && xx + 1 < x && board[yy + 1][xx + 1] != 'X' && vvb[yy + 1][xx + 1])
                        {
                            vvb[yy][xx] = true;
                            int new_a = vvpii[yy + 1][xx + 1].first + aaa;
                            if (new_a > vvpii[yy][xx].first)
                            {
                                vvpii[yy][xx] = {new_a, vvpii[yy + 1][xx + 1].second};
                            }
                            else if (new_a == vvpii[yy][xx].first)
                            {
                                vvpii[yy][xx].second += vvpii[yy + 1][xx + 1].second;
                                vvpii[yy][xx].second %= mod;
                            }
                        }
                        if (yy + 1 < y && board[yy + 1][xx] != 'X' && vvb[yy + 1][xx])
                        {
                            vvb[yy][xx] = true;
                            int new_b = vvpii[yy + 1][xx].first + aaa;
                            if (new_b > vvpii[yy][xx].first)
                            {
                                vvpii[yy][xx] = {new_b, vvpii[yy + 1][xx].second};
                            }
                            else if (new_b == vvpii[yy][xx].first)
                            {
                                vvpii[yy][xx].second += vvpii[yy + 1][xx].second;
                                vvpii[yy][xx].second %= mod;
                            }
                        }
                        if (xx + 1 < x && board[yy][xx + 1] != 'X' && vvb[yy][xx + 1])
                        {
                            vvb[yy][xx] = true;
                            int new_c = vvpii[yy][xx + 1].first + aaa;
                            if (new_c > vvpii[yy][xx].first)
                            {
                                vvpii[yy][xx] = {new_c, vvpii[yy][xx + 1].second};
                            }
                            else if (new_c == vvpii[yy][xx].first)
                            {
                                vvpii[yy][xx].second += vvpii[yy][xx + 1].second;
                                vvpii[yy][xx].second %= mod;
                            }
                        }
                    }

                    // std::cout << "(" << yy << "," << xx << "=" << vvpii[yy][xx].first << "," << vvpii[yy][xx].second << ")|";
                }
            }
        }

        return {vvpii[0][0].first, vvpii[0][0].second};
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["E23","2X2","12S"]\n
// @lcpr case=end

// @lcpr case=start
// ["E12","1X1","21S"]\n
// @lcpr case=end

// @lcpr case=start
// ["E11","XXX","11S"]\n
// @lcpr case=end

 */

// [ "E23",
//   "2X2",
//   "12S" ]

//     | (0, 0 = 0, 0) | (0, 1 = 4, 1) | (0, 2 = 5, 1) | (1, 0 = 4, 1) | | (1, 2 = 2, 1) | (2, 0 = 3, 1) | (2, 1 = 2, 1) | |
