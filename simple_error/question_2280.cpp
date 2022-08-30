/*
 * @lc app=leetcode.cn id=2280 lang=cpp
 *
 * [2280] 表示一个折线图的最少线段数
 *
 * https://leetcode.cn/problems/minimum-lines-to-represent-a-line-chart/description/
 *
 * algorithms
 * Medium (21.36%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 39.3K
 * Testcase Example:  '[[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]'
 *
 * 给你一个二维整数数组 stockPrices ，其中 stockPrices[i] = [dayi, pricei] 表示股票在 dayi 的价格为
 * pricei 。折线图 是一个二维平面上的若干个点组成的图，横坐标表示日期，纵坐标表示价格，折线图由相邻的点连接而成。比方说下图是一个例子：
 * 
 * 请你返回要表示一个折线图所需要的 最少线段数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：stockPrices = [[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
 * 输出：3
 * 解释：
 * 上图为输入对应的图，横坐标表示日期，纵坐标表示价格。
 * 以下 3 个线段可以表示折线图：
 * - 线段 1 （红色）从 (1,7) 到 (4,4) ，经过 (1,7) ，(2,6) ，(3,5) 和 (4,4) 。
 * - 线段 2 （蓝色）从 (4,4) 到 (5,4) 。
 * - 线段 3 （绿色）从 (5,4) 到 (8,1) ，经过 (5,4) ，(6,3) ，(7,2) 和 (8,1) 。
 * 可以证明，无法用少于 3 条线段表示这个折线图。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：stockPrices = [[3,4],[1,2],[7,8],[2,3]]
 * 输出：1
 * 解释：
 * 如上图所示，折线图可以用一条线段表示。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= stockPrices.length <= 10^5
 * stockPrices[i].length == 2
 * 1 <= dayi, pricei <= 10^9
 * 所有 dayi 互不相同 。
 * 
 * 
 */
// 精度问题,符号问题
// @lc code=start
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int result = 0;
        if(stockPrices.size() == 1){
            return result;
        }
        sort(stockPrices.begin(), stockPrices.end());
        result = 1;
        for(int i = 2; i < stockPrices.size(); i++){
            vector<int> a = stockPrices[i - 2];
            vector<int> b = stockPrices[i - 1];
            vector<int> c = stockPrices[i];
            long long ba_1 = b[0] - a[0];
            long long ba_2 = b[1] - a[1];

            long long cb_1 = c[0] - b[0];
            long long cb_2 = c[1] - b[1];
            long long aaa = ba_2 * cb_1;
            long long bbb = ba_1 * cb_2;
            // ba_2/ba_1 == cb_2/cb_1
            // ba_2 * cb_1 == ba_1 * cb_2
            if(aaa != bbb){
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

