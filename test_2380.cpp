/*
 * @lc app=leetcode.cn id=2380 lang=cpp
 *
 * [2380] 二进制字符串重新安排顺序需要的时间
 *
 * https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string/description/
 *
 * algorithms
 * Medium (55.11%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 7.5K
 * Testcase Example:  '"0110101"'
 *
 * 给你一个二进制字符串 s 。在一秒之中，所有 子字符串 "01" 同时 被替换成 "10" 。这个过程持续进行到没有 "01" 存在。
 * 
 * 请你返回完成这个过程所需要的秒数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "0110101"
 * 输出：4
 * 解释：
 * 一秒后，s 变成 "1011010" 。
 * 再过 1 秒后，s 变成 "1101100" 。
 * 第三秒过后，s 变成 "1110100" 。
 * 第四秒后，s 变成 "1111000" 。
 * 此时没有 "01" 存在，整个过程花费 4 秒。
 * 所以我们返回 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "11100"
 * 输出：0
 * 解释：
 * s 中没有 "01" 存在，整个过程花费 0 秒。
 * 所以我们返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] 要么是 '0' ，要么是 '1' 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        vector<int>vc(s.size());
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                vc[i] = 1;
            }
        }
        int result = 0;
        while(true){
            bool flag = false;
            for(int i = 0; i < s.size() - 1; i ++){
                if(vc[i] == 0 && vc[i + 1] == 1){
                    vc[i] = 1;
                    vc[i + 1] = 0;
                    flag = true;
                    i++;
                }
            }
            if(flag){
                result++;
            }else{
                break;
            }
        }
        return result;
    }
};
// @lc code=end

