/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] 最高的广告牌
 *
 * https://leetcode.cn/problems/tallest-billboard/description/
 *
 * algorithms
 * Hard (44.99%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 11.7K
 * Testcase Example:  '[1,2,3,6]'
 *
 * 你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。
 * 
 * 你有一堆可以焊接在一起的钢筋 rods。举个例子，如果钢筋的长度为 1、2 和 3，则可以将它们焊接在一起形成长度为 6 的支架。
 * 
 * 返回 广告牌的最大可能安装高度 。如果没法安装广告牌，请返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[1,2,3,6]
 * 输出：6
 * 解释：我们有两个不相交的子集 {1,2,3} 和 {6}，它们具有相同的和 sum = 6。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1,2,3,4,5,6]
 * 输出：10
 * 解释：我们有两个不相交的子集 {2,3,5} 和 {4,6}，它们具有相同的和 sum = 10。
 * 
 * 示例 3：
 * 
 * 
 * 输入：[1,2]
 * 输出：0
 * 解释：没法安装广告牌，所以返回 0。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= rods.length <= 20
 * 1 <= rods[i] <= 1000
 * sum(rods[i]) <= 5000
 * 
 * 
 */


// @lc code=start

// 20220728 有问题, 排序, dfs, 标记位会超时, 提前处理 是分配成两组, 当时同一边的时候又不行, 例如 [2, 3, 3, 3, 4], 没啥想法
// 
// [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
// 11440:108847714:78405
// 
class Solution {
public:
    unordered_map<int, unordered_set<int>> u_sum_us_flag;
    unordered_map<int, vector<unordered_set<int>>> u_sum_v_i_s_flag;
    unordered_map<int, int> u_value_to_index;
    int max_result;
    int half_sum;
    int loop_max;
    int loop_cnt;
    int loop_cnt2;
    int set_bit_1(int x, int index)
    {
        x |= (1 << ( index + 1));
        return x;
    }
    int set_bit_0(int x, int index)
    {
        x &= ~(1 << (index + 1));
        return x;
    }

    void dfs(vector<int>& rods, int cur_index, int cur_sum, int select_flag){
        // if(cur_sum > max_result){
        //     int new_size = u_sum_us_flag[cur_sum].size();
        //     if(loop_max < new_size ){
        //         loop_max = new_size;
        //     }
        //     if(new_size >= 1 ){
        //         for (const auto& elem: u_sum_us_flag[cur_sum]) {
        //             loop_cnt++;
        //             if((elem & select_flag) == 0){
        //                 max_result = cur_sum;
        //                 break;
        //             }
        //         }
        //     }
        //     u_sum_us_flag[cur_sum].insert(select_flag);
        // }
        if(cur_sum > max_result){
            if(u_sum_v_i_s_flag.count(cur_sum) == 0){
                vector<unordered_set<int>> new_vus(22);
                u_sum_v_i_s_flag[cur_sum] = new_vus;
            }
            int new_select_flag = select_flag;
            int cur_last = 0;
            while(new_select_flag > 0 && cur_sum > max_result){
                int delete_last = new_select_flag & (new_select_flag - 1);
                int last_index = new_select_flag - delete_last;
                new_select_flag = delete_last;
                int delete_last_index = u_value_to_index[last_index];
                u_sum_v_i_s_flag[cur_sum][delete_last_index].insert(select_flag);
                for(int iii = cur_last + 1; iii < delete_last_index; iii++){
                    if(u_sum_v_i_s_flag[cur_sum][iii].size() > 0){
                        for(auto &tmp : u_sum_v_i_s_flag[cur_sum][iii] ){
                            if((tmp & select_flag) == 0){
                                max_result = cur_sum;
                                break;
                            }
                        }
                    }
                }
                cur_last = delete_last_index;
            }
        }

        for(int j = cur_index; j < rods.size(); j++){
            int new_select_flag = set_bit_1(select_flag, j);
            int new_cur_sum = cur_sum + rods[j];
            loop_cnt2++;
            if(new_cur_sum <= half_sum){
                dfs(rods, j + 1, new_cur_sum, new_select_flag);
            }else{
                break;
            }
        }
    }

    int tallestBillboard(vector<int>& rods) {
        max_result = 0;
        int tem_sum = 0;
        loop_max = 0;
        loop_cnt = 0;
        loop_cnt2 = 0;
        for(int i = 0; i < rods.size(); i++){
            half_sum += rods[i];
        }

        for(int i = 1; i< 22; i++){
            u_value_to_index[set_bit_1(0, i)] = i;
        }
        half_sum /= 2;
        sort(rods.begin(), rods.end());
        dfs(rods, 0, 0, 0);
        std::cout << loop_max << ":" << loop_cnt << ":" << loop_cnt2 << std::endl;
        return max_result + tem_sum;
    }
};
// @lc code=end




