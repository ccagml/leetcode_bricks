/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] 第K个语法符号
 *
 * https://leetcode.cn/problems/k-th-symbol-in-grammar/description/
 *
 * algorithms
 * Medium (48.09%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    36.2K
 * Total Submissions: 75.3K
 * Testcase Example:  '1\n1'
 *
 * 我们构建了一个包含 n 行( 索引从 1  开始 )的表。首先在第一行我们写上一个
 * 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
 * 
 * 
 * 例如，对于 n = 3 ，第 1 行是 0 ，第 2 行是 01 ，第3行是 0110 。
 * 
 * 
 * 给定行数 n 和序数 k，返回第 n 行中第 k 个字符。（ k 从索引 1 开始）
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 1, k = 1
 * 输出: 0
 * 解释: 第一行：0
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 2, k = 1
 * 输出: 0
 * 解释: 
 * 第一行: 0 
 * 第二行: 01
 * 
 * 
 * 示例 3:
 * 
 * 输入: n = 2, k = 2
 * 输出: 1
 * 解释:
 * 第一行: 0
 * 第二行: 01
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= n <= 30
 * 1 <= k <= 2^n - 1
 * 
 * 
 */

// @lc code=start
// 0
// 1 0
// 0 1 1 0
// 1 0 0 1 0 1 1 0
// 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<int> vi = {0};
        for(int i = 1; i < n; i++){
            vector<int> new_vi;
            for(int j = 0; j < vi.size(); j++){
                if(vi[j] == 0){
                    new_vi.push_back(0);
                    new_vi.push_back(1);
                }else{
                    new_vi.push_back(1);
                    new_vi.push_back(0);
                }
            }
            vi = new_vi;
        }
        return vi[k - 1];
    }
};
// @lc code=end

