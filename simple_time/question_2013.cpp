/*
 * @lc app=leetcode.cn id=2013 lang=cpp
 *
 * [2013] 检测正方形
 *
 * https://leetcode.cn/problems/detect-squares/description/
 *
 * algorithms
 * Medium (56.27%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    20.3K
 * Total Submissions: 36.1K
 * Testcase Example:  '["DetectSquares","add","add","add","count","count","add","count"]\n' +
  '[[],[[3,10]],[[11,2]],[[3,2]],[[11,10]],[[14,8]],[[11,2]],[[11,10]]]'
 *
 * 给你一个在 X-Y 平面上的点构成的数据流。设计一个满足下述要求的算法：
 *
 *
 * 添加 一个在数据流中的新点到某个数据结构中。可以添加 重复 的点，并会视作不同的点进行处理。
 * 给你一个查询点，请你从数据结构中选出三个点，使这三个点和查询点一同构成一个 面积为正 的 轴对齐正方形 ，统计 满足该要求的方案数目。
 *
 *
 * 轴对齐正方形 是一个正方形，除四条边长度相同外，还满足每条边都与 x-轴 或 y-轴 平行或垂直。
 *
 * 实现 DetectSquares 类：
 *
 *
 * DetectSquares() 使用空数据结构初始化对象
 * void add(int[] point) 向数据结构添加一个新的点 point = [x, y]
 * int count(int[] point) 统计按上述方式与点 point = [x, y] 共同构造 轴对齐正方形 的方案数。
 *
 *
 *
 *
 * 示例：
 *
 *
 * 输入：
 * ["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
 * [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11,
 * 10]]]
 * 输出：
 * [null, null, null, null, 1, 0, null, 2]
 *
 * 解释：
 * DetectSquares detectSquares = new DetectSquares();
 * detectSquares.add([3, 10]);
 * detectSquares.add([11, 2]);
 * detectSquares.add([3, 2]);
 * detectSquares.count([11, 10]); // 返回 1 。你可以选择：
 * ⁠                              //   - 第一个，第二个，和第三个点
 * detectSquares.count([14, 8]);  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
 * detectSquares.add([11, 2]);    // 允许添加重复的点。
 * detectSquares.count([11, 10]); // 返回 2 。你可以选择：
 * ⁠                              //   - 第一个，第二个，和第三个点
 * ⁠                              //   - 第一个，第三个，和第四个点
 *
 *
 *
 *
 * 提示：
 *
 *
 * point.length == 2
 * 0 <= x, y <= 1000
 * 调用 add 和 count 的 总次数 最多为 5000
 *
 *
 */

// @lc code=start
// 常规模拟,调了很久

class DetectSquares
{
public:
    unordered_map<int, unordered_map<int, int>> x_to_y_cnt;
    unordered_map<int, unordered_map<int, int>> y_to_x_cnt;
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        x_to_y_cnt[x][y]++;
        y_to_x_cnt[y][x]++;
    }

    int temp_count(vector<int> point)
    {
        int x = point[0];
        int y = point[1];
        // 寻找所有相同x的
        // (x, y)
        // (x, yb)
        // 遍历x
        int result = 0;
        for (pair<int, int> y_cnt : x_to_y_cnt[x])
        {
            int yb = y_cnt.first;
            if (yb != y)
            {
                int bian_chang = abs(yb - y);
                // 左
                // (x - bianchang, y)
                // (x - bianchang, yb)
                int xy1 = 1;
                int xy2 = y_cnt.second;
                int xy3 = x_to_y_cnt[x - bian_chang][y];
                int xy4 = x_to_y_cnt[x - bian_chang][yb];

                result += (xy1 * xy2 * xy3 * xy4);
                // 右
                xy1 = 1;
                xy2 = y_cnt.second;
                xy3 = x_to_y_cnt[x + bian_chang][y];
                xy4 = x_to_y_cnt[x + bian_chang][yb];

                result += (xy1 * xy2 * xy3 * xy4);
            }
        }
        return result;
    }

    bool check_result(int temp_result)
    {
        return false;
    }

    int count(vector<int> point)
    {
        int temp_result = temp_count(point);
        if (check_result(temp_result))
        {
            int x = point[0];
            int y = point[1];
            // 寻找所有相同x的
            // (x, y)
            // (x, yb)
            // 遍历x
            int result = 0;
            for (pair<int, int> y_cnt : x_to_y_cnt[x])
            {
                int yb = y_cnt.first;
                if (yb != y)
                {
                    int bian_chang = abs(yb - y);
                    // 左
                    // (x - bianchang, y)
                    // (x - bianchang, yb)
                    int xy1 = 1;
                    int xy2 = y_cnt.second;
                    int xy3 = x_to_y_cnt[x - bian_chang][y];
                    int xy4 = x_to_y_cnt[x - bian_chang][yb];
                    if ((xy1 * xy2 * xy3 * xy4) > 0)
                    {
                        std::cout << "(" << x << "," << y << ")";
                        std::cout << "(" << x << "," << yb << ")";
                        std::cout << "(" << x - bian_chang << "," << y << ")";
                        std::cout << "(" << x - bian_chang << "," << yb << ")";
                        std::cout << "提供" << (xy1 * xy2 * xy3 * xy4) << std::endl;
                    }
                    result += (xy1 * xy2 * xy3 * xy4);
                    // 右
                    xy1 = 1;
                    xy2 = y_cnt.second;
                    xy3 = x_to_y_cnt[x + bian_chang][y];
                    xy4 = x_to_y_cnt[x + bian_chang][yb];
                    if ((xy1 * xy2 * xy3 * xy4) > 0)
                    {
                        std::cout << "(" << x << "," << y << ")";
                        std::cout << "(" << x << "," << yb << ")";
                        std::cout << "(" << x + bian_chang << "," << y << ")";
                        std::cout << "(" << x + bian_chang << "," << yb << ")";
                        std::cout << "提供" << (xy1 * xy2 * xy3 * xy4) << std::endl;
                    }
                    result += (xy1 * xy2 * xy3 * xy4);
                }
            }
        }

        return temp_result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end
