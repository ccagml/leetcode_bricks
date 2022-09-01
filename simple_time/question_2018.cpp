/*
 * @lc app=leetcode.cn id=2018 lang=cpp
 *
 * [2018] 判断单词是否能放入填字游戏内
 *
 * https://leetcode.cn/problems/check-if-word-can-be-placed-in-crossword/description/
 *
 * algorithms
 * Medium (41.45%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    2.7K
 * Total Submissions: 6.6K
 * Testcase Example:  '[["#"," ","#"],[" "," ","#"],["#","c"," "]]\n"abc"'
 *
 * 给你一个 m x n 的矩阵 board ，它代表一个填字游戏 当前 的状态。填字游戏格子中包含小写英文字母（已填入的单词），表示 空 格的 ' '
 * 和表示 障碍 格子的 '#' 。
 *
 * 如果满足以下条件，那么我们可以 水平 （从左到右 或者 从右到左）或 竖直 （从上到下 或者 从下到上）填入一个单词：
 *
 *
 * 该单词不占据任何 '#' 对应的格子。
 * 每个字母对应的格子要么是 ' ' （空格）要么与 board 中已有字母 匹配 。
 * 如果单词是 水平 放置的，那么该单词左边和右边 相邻 格子不能为 ' ' 或小写英文字母。
 * 如果单词是 竖直 放置的，那么该单词上边和下边 相邻 格子不能为 ' ' 或小写英文字母。
 *
 *
 * 给你一个字符串 word ，如果 word 可以被放入 board 中，请你返回 true ，否则请返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
 * 输出：true
 * 解释：单词 "abc" 可以如上图放置（从上往下）。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
 * 输出：false
 * 解释：无法放置单词，因为放置该单词后上方或者下方相邻格会有空格。
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
 * 输出：true
 * 解释：单词 "ca" 可以如上图放置（从右到左）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m * n <= 2 * 10^5
 * board[i][j] 可能为 ' ' ，'#' 或者一个小写英文字母。
 * 1 <= word.length <= max(m, n)
 * word 只包含小写英文字母。
 *
 *
 */

// @lc code=start
// 检查#号间距是不是word.size()
// 或者board 的长宽是不是word.size()
class Solution
{
public:
    vector<vector<char>> myboard;
    string myword;
    bool check_shu(int x, int start_y, int end_y)
    {
        bool result = true;
        for (int i = start_y; i <= end_y; i++)
        {
            if (myboard[i][x] != ' ' && myboard[i][x] != myword[i - start_y])
            {

                result = false;
                break;
            }
        }
        if (result)
        {
            return result;
        }
        result = true;
        for (int i = end_y; i >= start_y; i--)
        {
            if (myboard[i][x] != ' ' && myboard[i][x] != myword[i - end_y])
            {
                result = false;
                break;
            }
        }
        return result;
    }
    bool check_heng(int y, int start_x, int end_x)
    {
        bool result = true;
        for (int i = start_x; i <= end_x; i++)
        {
            if (myboard[y][i] != ' ' && myboard[y][i] != myword[i - start_x])
            {
                result = false;
                break;
            }
        }
        if (result)
        {
            return result;
        }
        result = true;
        for (int i = end_x; i >= start_x; i--)
        {
            if (myboard[y][i] != ' ' && myboard[y][i] != myword[i - end_x])
            {
                result = false;
                break;
            }
        }
        return result;
    }
    bool placeWordInCrossword(vector<vector<char>> &board, string word)
    {
        myboard = board;
        myword = word;
        int max_y = board.size();
        int max_x = board[0].size();
        unordered_map<int, vector<int>> x_to_y;
        unordered_map<int, vector<int>> y_to_x;
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[y].size(); x++)
            {
                if (board[y][x] == '#')
                {

                    x_to_y[x].push_back(y);
                    y_to_x[y].push_back(x);
                }
            }
        }

        int ws = word.size();
        // 如果是等于长宽
        if (word.size() == max_y)
        {

            // 检查竖的够不够
            for (int i = 0; i < max_x; i++)
            {

                if (x_to_y[i].size() == 0)
                {
                    std::cout << i << "竖没有#" << check_shu(i, 0, max_y - 1) << std::endl;
                    if (check_shu(i, 0, max_y - 1))
                    {
                        return true;
                    }
                }
            }
        }
        if (word.size() == max_x)
        {

            // 检查横的够不够
            for (int i = 0; i < max_y; i++)
            {

                if (y_to_x[i].size() == 0)
                {
                    std::cout << i << "横没有#" << (check_heng(i, 0, max_x - 1)) << std::endl;
                    if (check_heng(i, 0, max_x - 1))
                    {
                        return true;
                    }
                }
            }
        }
        // 检查两个#号之间
        for (int i = 0; i < max_x; i++)
        {
            if (x_to_y.count(i) > 0)
            {

                std::cout << "1111111";
                if (x_to_y[i][0] == ws - 1)
                {
                    if (check_shu(i, 0, x_to_y[i][0] - 1))
                    {
                        return true;
                    }
                }
                std::cout << "22222222";
                if (max_y - x_to_y[i][x_to_y[i].size() - 1] == ws)
                {
                    if (check_shu(i, x_to_y[i][x_to_y[i].size() - 1], max_y - 1))
                    {
                        return true;
                    }
                }

                for (int check_start = 0; check_start < x_to_y[i].size() - 1; check_start++)
                {
                    if (x_to_y[i][check_start + 1] - x_to_y[i][check_start] == ws + 1)
                    {
                        std::cout << i << "竖竖没有#" << check_shu(i, x_to_y[i][check_start] + 1, x_to_y[i][check_start + 1] - 1) << std::endl;
                        if (check_shu(i, x_to_y[i][check_start] + 1, x_to_y[i][check_start + 1] - 1))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < max_y; i++)
        {
            if (y_to_x.count(i) > 0)
            {
                std::cout << "33333";
                if (y_to_x[i][0] == ws - 1)
                {
                    if (check_heng(i, 0, y_to_x[i][0] - 1))
                    {
                        return true;
                    }
                }
                std::cout << "444444444";
                if (max_x - y_to_x[i][y_to_x[i].size() - 1] == ws)
                {
                    if (check_heng(i, y_to_x[i][y_to_x[i].size() - 1], max_y - 1))
                    {
                        return true;
                    }
                }

                for (int check_start = 0; check_start < y_to_x[i].size() - 1; check_start++)
                {
                    if (y_to_x[i][check_start + 1] - y_to_x[i][check_start] == ws + 1)
                    {
                        std::cout << i << "横横没有#" << (check_heng(i, 0, max_x - 1)) << std::endl;
                        if (check_heng(i, y_to_x[i][check_start] + 1, y_to_x[i][check_start + 1] - 1))
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end
