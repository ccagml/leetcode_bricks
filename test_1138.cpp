/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 *
 * https://leetcode.cn/problems/alphabet-board-path/description/
 *
 * algorithms
 * Medium (44.30%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 16.7K
 * Testcase Example:  '"leet"'
 *
 * 我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。
 *
 * 在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。
 *
 *
 *
 * 我们可以按下面的指令规则行动：
 *
 *
 * 如果方格存在，'U' 意味着将我们的位置上移一行；
 * 如果方格存在，'D' 意味着将我们的位置下移一行；
 * 如果方格存在，'L' 意味着将我们的位置左移一列；
 * 如果方格存在，'R' 意味着将我们的位置右移一列；
 * '!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
 *
 *
 * （注意，字母板上只存在有字母的位置。）
 *
 * 返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = "leet"
 * 输出："DDR!UURRR!!DDD!"
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = "code"
 * 输出："RR!DDRR!UUL!R!"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target.length <= 100
 * target 仅含有小写英文字母。
 *
 * ["abcde",
 *  "fghij",
 *  "klmno",
 *  "pqrst",
 *  "uvwxy",
 *  "z"]
 *
 *
 */

// @lc code=start
class Solution
{
public:
    unordered_map<char, pair<int, int>> umcpii = {{'a', {0, 0}}, {'b', {1, 0}}, {'c', {2, 0}}, {'d', {3, 0}}, {'e', {4, 0}}, {'f', {0, 1}}, {'g', {1, 1}}, {'h', {2, 1}}, {'i', {3, 1}}, {'j', {4, 1}}, {'k', {0, 2}}, {'l', {1, 2}}, {'m', {2, 2}}, {'n', {3, 2}}, {'o', {4, 2}}, {'p', {0, 3}}, {'q', {1, 3}}, {'r', {2, 3}}, {'s', {3, 3}}, {'t', {4, 3}}, {'u', {0, 4}}, {'v', {1, 4}}, {'w', {2, 4}}, {'x', {3, 4}}, {'y', {4, 4}}, {'z', {0, 5}}};
    unordered_map<string, string> path;
    string get_path(char a, char b)
    {
        string ab = "";
        ab.push_back(a);
        ab.push_back(b);
        if (path.count(ab) > 0)
        {
            return path[ab];
        }
        string temp_path = "";
        // 寻找ab的路子
        pair<int, int> axy = umcpii[a];
        pair<int, int> bxy = umcpii[b];
        int axy_x = axy.first;
        int axy_y = axy.second;
        int bxy_x = bxy.first;
        int bxy_y = bxy.second;
        // std::cout << axy_x << ":" << axy_y << "|" << bxy_x << ":" <<  bxy_y << std::endl;
        while (axy_x != bxy_x || axy_y != bxy_y)
        {
            if (b == 'z')
            {
                if (axy_x != bxy_x)
                {
                    if (axy_x > bxy_x)
                    {
                        axy_x--;
                        temp_path.push_back('L');
                    }
                    else
                    {
                        axy_x++;
                        temp_path.push_back('R');
                    }
                }
                else
                {
                    if (axy_y > bxy_y)
                    {
                        axy_y--;
                        temp_path.push_back('U');
                    }
                    else
                    {
                        axy_y++;
                        temp_path.push_back('D');
                    }
                }
            }
            else
            {
                if (axy_y != bxy_y)
                {
                    if (axy_y > bxy_y)
                    {
                        axy_y--;
                        temp_path.push_back('U');
                    }
                    else
                    {
                        axy_y++;
                        temp_path.push_back('D');
                    }
                }
                else
                {
                    if (axy_x > bxy_x)
                    {
                        axy_x--;
                        temp_path.push_back('L');
                    }
                    else
                    {
                        axy_x++;
                        temp_path.push_back('R');
                    }
                }
            }
        }
        path[ab] = temp_path;
        return temp_path;
    };
    string alphabetBoardPath(string target)
    {
        string start = "a";
        start.append(target);
        string result = "";
        for (int i = 0; i < start.size() - 1; i++)
        {
            result.append(get_path(start[i], start[i + 1]));
            result.push_back('!');
        }
        return result;
    }
};
// @lc code=end
