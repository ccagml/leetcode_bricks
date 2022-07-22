/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 *
 * https://leetcode-cn.com/problems/shortest-bridge/description/
 *
 * algorithms
 * Medium (47.19%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 52.4K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * 在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1
 * 形成的一个最大组。）
 *
 * 现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
 *
 * 返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：A = [[0,1],[1,0]]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：A = [[0,1,0],[0,0,0],[0,0,1]]
 * 输出：2
 *
 *
 * 示例 3：
 *
 *
 * 输入：A = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
 * 输出：1
 *
 *
 *
 * 提示：
 *
 *
 * 2
 * A[i][j] == 0 或 A[i][j] == 1
 *
 *
 */

// @lc code=start
class Solution
{
    vector<vector<int>> dir;
    int y;
    int x;
    queue<pair<int, int>> stque;

public : int shortestBridge(vector<vector<int>> &grid)
    {
        // 1, 0, 00, 20, 11,1-1
        dir = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        y = grid.size();
        x = grid[0].size();
        int flag = 0;
        for (int xx = 0; xx < x;xx++){
            for(int yy = 0; yy<y; yy++){
                if(grid[yy][xx] == 1){
                    to_2(yy, xx, grid);
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
        }

        // print_g(grid);
        int result = 0;
        while(stque.size() > 0){
            int sn = stque.size();
            for (int i = 0; i < sn; i++){
                pair<int, int> temp = stque.front();
                stque.pop();
                int yy = temp.first;
                int xx = temp.second;
                for (vector<int> temp_dir : dir)
                {
                    int next_t_x = xx + temp_dir[0];
                    int next_t_y = yy + temp_dir[1];
                    if (next_t_x >= 0 && next_t_x < x && next_t_y >= 0 && next_t_y < y && grid[next_t_y][next_t_x] == 0)
                    {
                        grid[next_t_y][next_t_x] = 2;
                        pair<int, int> yyxx = make_pair(next_t_y, next_t_x);
                        stque.push(yyxx);
                    }
                    else if (next_t_x >= 0 && next_t_x < x && next_t_y >= 0 && next_t_y < y && grid[next_t_y][next_t_x] == 1){
                        return result;
                    }
                }
            }
            result++;
        }
        return result;
    }
    void to_2(int yy, int xx, vector<vector<int>> &grid)
    {
        //std::cout << "to_2:" << yy << ", " << xx << std::endl;
        grid[yy][xx] = 2;
        pair<int, int> yyxx = make_pair(yy, xx);
        stque.push(yyxx);
        for (vector<int> temp_dir : dir)
        {
            int next_t_x = xx + temp_dir[0];
            int next_t_y = yy + temp_dir[1];
            //std::cout << "to_2:" << yy << ", " << xx << "next:" << next_t_y << "," << next_t_x << std::endl;
            if (next_t_x >= 0 && next_t_x < x && next_t_y >= 0 && next_t_y < y && grid[next_t_y][next_t_x] == 1){
                to_2(next_t_y, next_t_x, grid);
            }
        }
    }
    void print_g(vector<vector<int>> &grid){
        for (int i = 0; i < y; i++){
            for (int j = 0; j < x; j++){
                std::cout << grid[i][j] <<  ",";
            }
            std::cout << std::endl;
        }
    }
};
// @lc code=end
