/*
 * @lc app=leetcode.cn id=2384 lang=cpp
 *
 * [2384] 最大回文数字
 *
 * https://leetcode.cn/problems/largest-palindromic-number/description/
 *
 * algorithms
 * Medium (29.66%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 23.6K
 * Testcase Example:  '"444947137"'
 *
 * 给你一个仅由数字（0 - 9）组成的字符串 num 。
 *
 * 请你找出能够使用 num 中数字形成的 最大回文 整数，并以字符串形式返回。该整数不含 前导零 。
 *
 * 注意：
 *
 *
 * 你 无需 使用 num 中的所有数字，但你必须使用 至少 一个数字。
 * 数字可以重新排序。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：num = "444947137"
 * 输出："7449447"
 * 解释：
 * 从 "444947137" 中选用数字 "4449477"，可以形成回文整数 "7449447" 。
 * 可以证明 "7449447" 是能够形成的最大回文整数。
 *
 *
 * 示例 2：
 *
 *
 * 输入：num = "00009"
 * 输出："9"
 * 解释：
 * 可以证明 "9" 能够形成的最大回文整数。
 * 注意返回的整数不应含前导零。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= num.length <= 10^5
 * num 由数字（0 - 9）组成
 *
 *
 */

// @lc code=start

// 1636分
// 计数
class Solution
{
public:
    string largestPalindromic(string num)
    {
        vector<int> vc;
        unordered_map<int, int> uci;
        for (int i = 0; i < num.size(); i++)
        {
            uci[num[i] - '0']++;
        }
        // 没有数字,0没用
        bool zero_flag = false;
        int max_zero = -1;
        for (int i = 9; i >= 0; i--)
        {
            while(uci[i] >= 2){
                vc.push_back(i);
                uci[i] -= 2;
                zero_flag = true;
            }
            if(uci[i] >= 1){
                max_zero = max(max_zero, i);
            }
            if(i == 1 && !zero_flag){
                if(uci[0] >= 1){
                    max_zero = max(max_zero, 0);
                }
                break;
            }
        }
        string result;
        for(int i = 0; i < vc.size(); i++){
            result.push_back(vc[i] + '0');
        }
        if(max_zero >= 0){
            result.push_back(max_zero + '0');
        }
        for(int i = vc.size() - 1; i >= 0; i--){
            result.push_back(vc[i] + '0');
        }
        return result;
        

    }
};
// @lc code=end
