/*
 * @lc app=leetcode.cn id=2375 lang=cpp
 *
 * [2375] 根据模式串构造最小数字
 *
 * https://leetcode.cn/problems/construct-smallest-number-from-di-string/description/
 *
 * algorithms
 * Medium (68.95%)
 * Likes:    23
 * Dislikes: 0
 * Total Accepted:    7.9K
 * Total Submissions: 11.5K
 * Testcase Example:  '"IIIDIDDD"'
 *
 * 给你下标从 0 开始、长度为 n 的字符串 pattern ，它包含两种字符，'I' 表示 上升 ，'D' 表示 下降 。
 * 
 * 你需要构造一个下标从 0 开始长度为 n + 1 的字符串，且它要满足以下条件：
 * 
 * 
 * num 包含数字 '1' 到 '9' ，其中每个数字 至多 使用一次。
 * 如果 pattern[i] == 'I' ，那么 num[i] < num[i + 1] 。
 * 如果 pattern[i] == 'D' ，那么 num[i] > num[i + 1] 。
 * 
 * 
 * 请你返回满足上述条件字典序 最小 的字符串 num。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：pattern = "IIIDIDDD"
 * 输出："123549876"
 * 解释：
 * 下标 0 ，1 ，2 和 4 处，我们需要使 num[i] < num[i+1] 。
 * 下标 3 ，5 ，6 和 7 处，我们需要使 num[i] > num[i+1] 。
 * 一些可能的 num 的值为 "245639871" ，"135749862" 和 "123849765" 。
 * "123549876" 是满足条件最小的数字。
 * 注意，"123414321" 不是可行解因为数字 '1' 使用次数超过 1 次。
 * 
 * 示例 2：
 * 
 * 
 * 输入：pattern = "DDD"
 * 输出："4321"
 * 解释：
 * 一些可能的 num 的值为 "9876" ，"7321" 和 "8742" 。
 * "4321" 是满足条件最小的数字。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pattern.length <= 8
 * pattern 只包含字符 'I' 和 'D' 。
 * 
 * 
 */
// 1641
// @lc code=start
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        // * 输入：pattern = "IIIDIDDD"
        // * 输出："123549876"
        // *  "I I I D I D D D"
        // * 1 2 3 5 4 9 8 7 6 
        vector<int> temp;
        temp.push_back(1);
        int next = 2;
        for(int i = 0; i < n; i++){
            if(pattern[i] == 'I'){
                temp.push_back(next);
                next++;
            }else{
                temp.push_back(next);
                next++;
                int temp_start = i;
                while(temp_start >= 0 && pattern[temp_start] == 'D'){
                    swap(temp[temp_start], temp[temp_start + 1]);
                    temp_start--;
                }
            }
        }
        string result;
        for(int i = 0; i < temp.size(); i++){
            result.push_back('0' + temp[i]);
        }
        return result;
    }
};
// @lc code=end

