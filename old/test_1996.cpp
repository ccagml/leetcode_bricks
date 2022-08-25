/*
 * @lc app=leetcode.cn id=1996 lang=cpp
 *
 * [1996] 游戏中弱角色的数量
 *
 * https://leetcode-cn.com/problems/the-number-of-weak-characters-in-the-game/description/
 *
 * algorithms
 * Medium (25.21%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 37.5K
 * Testcase Example:  '[[5,5],[6,3],[3,6]]'
 *
 * 你正在参加一个多角色游戏，每个角色都有两个主要属性：攻击 和 防御 。给你一个二维整数数组 properties ，其中 properties[i] =
 * [attacki, defensei] 表示游戏中第 i 个角色的属性。
 * 
 * 如果存在一个其他角色的攻击和防御等级 都严格高于 该角色的攻击和防御等级，则认为该角色为 弱角色 。更正式地，如果认为角色 i 弱于 存在的另一个角色
 * j ，那么 attackj > attacki 且 defensej > defensei 。
 * 
 * 返回 弱角色 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：properties = [[5,5],[6,3],[3,6]]
 * 输出：0
 * 解释：不存在攻击和防御都严格高于其他角色的角色。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：properties = [[2,2],[3,3]]
 * 输出：1
 * 解释：第一个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：properties = [[1,5],[10,4],[4,3]]
 * 输出：1
 * 解释：第三个角色是弱角色，因为第二个角色的攻击和防御严格大于该角色。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= properties.length <= 10^5
 * properties[i].length == 2
 * 1 <= attacki, defensei <= 10^5
 * 
 * 
 */











// @lc code=start
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), std::greater<vector<int>>());

        // for(int i = 0; i < properties.size(); i++){
        //     std::cout << "(" << i << "-"<< properties[i][0] << "," << properties[i][1] << "),";
        // }
        int result = 0;
        int last_def = properties[0][1];
        int last_att = properties[0][0];
        int next_i = 0;
        int start_max_def = last_def;
        int start_max_att = last_att;
        for (int i = 0; i < properties.size(); i++){
                        next_i = i;
            if(properties[i][0] != last_att){
                break;
            }
        }
        if(next_i == properties.size()){
            return 0;
        }

        for(int i = next_i; i < properties.size(); i++){
            if(properties[i][0] != properties[i - 1][0] && properties[i - 1][0] != start_max_att ){
                start_max_att = properties[i - 1][0];
                start_max_def = max(start_max_def, last_def);
            }
            if(start_max_att > properties[i][0] && start_max_def > properties[i][1]){
                result++;
            }

            
            // if(last_att > properties[i][0] && last_def > properties[i][1]){
            //     result++;
            // }
            last_def = max(last_def,  properties[i][1]);
        }
        return result;
    }
};
// @lc code=end

