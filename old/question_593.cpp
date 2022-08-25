/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 *
 * https://leetcode-cn.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (44.16%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    8.7K
 * Total Submissions: 19.6K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * 给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。
 * 
 * 一个点的坐标（x，y）由一个有两个整数的整数数组表示。
 * 
 * 示例:
 * 
 * 
 * 输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * 输出: True
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 所有输入整数都在 [-10000，10000] 范围内。
 * 一个有效的正方形有四个等长的正长和四个等角（90度角）。
 * 输入点没有顺序。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> vv;
        vv.push_back(p1);
        vv.push_back(p2);
        vv.push_back(p3);
        vv.push_back(p4);
        sort(vv.begin(), vv.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] < b[0] || (a[0] == b[0] && a[1] < b[1])){
                return true;
            }
            return false;
        });
        // for(int i = 0; i < vv.size(); i++){
        //     std::cout << vv[i][0] << "," << vv[i][1]<< std::endl;
        // }
        int d0, d1, d2, d3;
        // computing the distances between ordered points
        d0 = d(vv[0], vv[1]), d1 = d(vv[0], vv[2]), d2 = d(vv[0], vv[3]), d3 = d(vv[1], vv[2]);
        return d0 && d1 && d2 && d3 &&(d0 == d1) &&( d2 == d3);
    }
    int d(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        // return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
    }
};
// @lc code=end

