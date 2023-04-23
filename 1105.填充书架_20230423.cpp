// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 * @lcpr version=21906
 *
 * [1105] 填充书架
 *
 * https://leetcode.cn/problems/filling-bookcase-shelves/description/
 *
 * algorithms
 * Medium (58.49%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 17.5K
 * Testcase Example:  '[[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]\n4'
 *
 * 给定一个数组 books ，其中 books[i] = [thicknessi, heighti] 表示第 i 本书的厚度和高度。你也会得到一个整数
 * shelfWidth 。
 *
 * 按顺序 将这些书摆放到总宽度为 shelfWidth 的书架上。
 *
 * 先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 shelfWidth ），然后再建一层书架。重复这个过程，直到把所有的书都放在书架上。
 *
 * 需要注意的是，在上述过程的每个步骤中，摆放书的顺序与你整理好的顺序相同。
 *
 *
 * 例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二本书放在第一层书架上，第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。
 *
 *
 * 每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。
 *
 * 以这种方式布置书架，返回书架整体可能的最小高度。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
 * 输出：6
 * 解释：
 * 3 层书架的高度和为 1 + 3 + 2 = 6 。
 * 第 2 本书不必放在第一层书架上。
 *
 *
 * 示例 2:
 *
 * 输入: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
 * 输出: 4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= books.length <= 1000
 * 1 <= thicknessi <= shelfWidth <= 1000
 * 1 <= heighti <= 1000
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
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            int maxHeight = 0, curWidth = 0;
            for (int j = i; j >= 0; --j)
            {
                curWidth += books[j][0];
                if (curWidth > shelfWidth)
                {
                    break;
                }
                maxHeight = max(maxHeight, books[j][1]);
                dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight);
            }
        }
        return dp[n];
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2,4],[3,2]]\n6\n
// @lcpr case=end


// @lcpr case=start
// [[7,3],[8,7],[2,7],[2,5]]\n10\n
// @lcpr case=end

 */
