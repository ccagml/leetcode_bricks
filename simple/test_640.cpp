/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 *
 * https://leetcode.cn/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (42.46%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 39.6K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * 求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。
 *
 * 如果方程没有解，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。
 *
 * 题目保证，如果方程中只有一个解，则 'x' 的值是一个整数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: equation = "x+5-3+x=6+x-2"
 * 输出: "x=2"
 *
 *
 * 示例 2:
 *
 *
 * 输入: equation = "x=x"
 * 输出: "Infinite solutions"
 *
 *
 * 示例 3:
 *
 *
 * 输入: equation = "2x=x"
 * 输出: "x=0"
 *
 *
 *
 *
 * 提示:
 *
 *
 * 3 <= equation.length <= 1000
 * equation 只有一个 '='.
 * equation 方程由整数组成，其绝对值在 [0, 100] 范围内，不含前导零和变量 'x' 。 ​​​
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string solveEquation(string equation)
    {
        std::string::size_type equal_index = equation.find("=");
        int left_x = 0;
        int left_value = 0;
        int right_x = 0;
        int right_value = 0;
        int n = equation.size();
        int add_flag = 1;
        int x = 0;
        int temp_value = 99999;
        for (int i = 0; i < equal_index; i++)
        {

            if (i == equal_index - 1)
            {
                if (equation[i] == 'x')
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 1;
                    }
                    x = 1;
                }
                else
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 0;
                    }
                    temp_value = temp_value * 10 + (equation[i] - '0');
                }
            }

            if (equation[i] == '+' || equation[i] == '-' || i == equal_index - 1)
            {

                if (add_flag)
                {
                    if (x)
                    {
                        left_x += (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "左边x" <<(temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                    else
                    {
                        left_value += (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "左边值" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                }
                else
                {
                    if (x)
                    {
                        left_x -= (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "左边-x" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                    else
                    {
                        left_value -= (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "左边-值" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                }

                add_flag = 1;
                if (equation[i] == '-')
                {
                    add_flag = 0;
                }
                x = 0;
                temp_value = 99999;
            }
            else
            {
                if (equation[i] == 'x')
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 1;
                    }
                    x = 1;
                }
                else
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 0;
                    }
                    temp_value = temp_value * 10 + (equation[i] - '0');
                    // std::cout << "temp_value:" << temp_value << ":,";
                }
            }
        }

        add_flag = 1;

        x = 0;
        temp_value = 99999;
        for (int i = equal_index + 1; i < n; i++)
        {

            if (i == n - 1)
            {
                if (equation[i] == 'x')
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 1;
                    }
                    x = 1;
                }
                else
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 0;
                    }
                    temp_value = temp_value * 10 + (equation[i] - '0');
                }
            }

            if (equation[i] == '+' || equation[i] == '-' || i == n - 1)
            {

                if (add_flag)
                {
                    if (x)
                    {
                        right_x += (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "右边x" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                    else
                    {
                        right_value += (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "右边值" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                }
                else
                {
                    if (x)
                    {
                        right_x -= (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "右边-x" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                    else
                    {
                        right_value -= (temp_value == 99999 ? 0 : temp_value);
                        // std::cout << "右边-值" << (temp_value == 99999 ? 0 : temp_value) << ",";
                    }
                }

                add_flag = 1;
                if (equation[i] == '-')
                {
                    add_flag = 0;
                }
                x = 0;
                temp_value = 99999;
            }
            else
            {
                if (equation[i] == 'x')
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 1;
                    }

                    x = 1;
                }
                else
                {
                    if (temp_value == 99999)
                    {
                        temp_value = 0;
                    }
                    temp_value = temp_value * 10 + (equation[i] - '0');
                }
            }
        }
        // std::cout << left_x << ":" << left_value << "|" << right_x << ":" << right_value << std::endl;
        left_x -= right_x;
        right_value -= left_value;

        if (left_x == 0 && right_value == 0)
        {
            return "Infinite solutions";
        }
        if (left_x == 0)
        {
            return "No solution";
        }
        int temp = right_value / left_x;
        if (right_value % abs(left_x) == 0)
        {
            return "x=" + std::to_string(temp);
        }
        return "No solution";
    }
};
// @lc code=end
