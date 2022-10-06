/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 *
 * https://leetcode.cn/problems/three-equal-parts/description/
 *
 * algorithms
 * Hard (35.45%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 18.2K
 * Testcase Example:  '[1,0,1,0,1]'
 *
 * 给定一个由 0 和 1 组成的数组 arr ，将数组分成  3 个非空的部分 ，使得所有这些部分表示相同的二进制值。
 * 
 * 如果可以做到，请返回任何 [i, j]，其中 i+1 < j，这样一来：
 * 
 * 
 * arr[0], arr[1], ..., arr[i] 为第一部分；
 * arr[i + 1], arr[i + 2], ..., arr[j - 1] 为第二部分；
 * arr[j], arr[j + 1], ..., arr[arr.length - 1] 为第三部分。
 * 这三个部分所表示的二进制值相等。
 * 
 * 
 * 如果无法做到，就返回 [-1, -1]。
 * 
 * 注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，[1,1,0] 表示十进制中的 6，而不会是 3。此外，前导零也是被允许的，所以
 * [0,1,1] 和 [1,1] 表示相同的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [1,0,1,0,1]
 * 输出：[0,3]
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,1,0,1,1]
 * 输出：[-1,-1]
 * 
 * 示例 3:
 * 
 * 输入：arr = [1,1,0,0,1]
 * 输出：[0,2]
 * 
 * 
 * [1,0,1,0,1]\n[1,1,0,1,1]\n[1,1,0,0,1]\n[0,0,0,0,0]
 * 
 * 提示：
 * 
 * 
 * 
 * 3 <= arr.length <= 3 * 10^4
 * arr[i] 是 0 或 1
 * 
 * 
 */

// @lc code=start
// 思考1, 1的数量应该是相等的
// 思考2, 第一部分最后一个1接的0的数量,应该是最后一个1后面0的数量
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> num1;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 1){
                num1.push_back(i);
            }
        }
        vector<int> result;
        if(num1.size() == 0){
            result.push_back(0);
            result.push_back(arr.size()- 1);
            return result;
        }else if(num1.size() < 3){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int zero = (arr.size() - 1) - num1[num1.size() - 1];
        if(num1.size() % 3 != 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int first_end = num1[(num1.size() / 3) - 1];
        int zero_first = first_end + zero;
        // 检查是否包含1
        if(zero_first >= num1[(num1.size() / 3)]){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int second_end = num1[(num1.size() / 3) * 2 - 1];
        int zero_second = second_end + zero;
        if(zero_second >= num1[(num1.size() / 3) * 2]){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        string s1 = "";
        string s2 = "";
        string s3 = "";
        bool f1 = true;
        bool f2 = true;
        bool f3 = true;
        for(int i = 0; i <= zero_first; i++){
            if(arr[i] == 0 && f1){
                continue;
            }else{
                f1 = false;
                s1.push_back(arr[i]);
            }
        }
        for(int i = zero_first + 1; i <= zero_second; i++){
            if(arr[i] == 0 && f2){
                continue;
            }else{
                f2 = false;
                s2.push_back(arr[i]);
            }
        }
        for(int i = zero_second + 1; i < arr.size(); i++){
            if(arr[i] == 0 && f3){
                continue;
            }else{
                f3 = false;
                s3.push_back(arr[i]);
            }
        }
        if(s1 == s2 && s2 == s3){
            result.push_back(zero_first);
            result.push_back(zero_second + 1);
            return result;
        }else{
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
    }
};
// @lc code=end

