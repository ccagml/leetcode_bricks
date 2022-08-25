/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 *
 * https://leetcode-cn.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (42.70%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    21.2K
 * Total Submissions: 49.8K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 在本问题中，有根树指满足以下条件的 有向
 * 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。
 * 
 * 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n
 * 中的两个不同顶点间，这条附加的边不属于树中已存在的边。
 * 
 * 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是
 * vi 的一个父节点。
 * 
 * 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：edges = [[1,2],[1,3],[2,3]]
 * 输出：[2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * 输出：[4,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == edges.length
 * 3 
 * edges[i].length == 2
 * 1 i, vi 
 * 
 * 
 */


// @lc code=start

class UNID_F{
public:
    vector<int> group;
    UNID_F(int n){
        for(int i = 0; i < n;i++){
            group.push_back(i);
        }
    }
    int find(int v){
        int fa = group[v];
        if(fa != v){
            group[v] = find(group[v]);
        }
        return group[v];
    }
    void merge(int a, int b){
        int fa = find(a);
        int fb = find(b);
        if(fa != fb){
            if(fa > fb){
                group[fa] = fb;
            }else{
                group[fb] = fa;
            }
        }
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        // 有多个父亲, 或者有环
        int n = edges.size();
        UNID_F* uuu = new UNID_F(n);
        vector<int> par;
        for(int i = 0; i < n; i++){
            par.push_back(i);
        }
        int error_1 = -1;
        int error_2 = -1;
        vector<int> temp_result;
        for(int i = 0; i < n; i++){
            int left = edges[i][0] - 1;
            int right = edges[i][1] - 1;
            if(par[right] != right && par[right] != left){
                std::cout << "111" << "(" << left + 1 << "," << right + 1<<")" << par[right] << std::endl;
                error_1 = i;
                temp_result = {par[right], edges[i][1]};
            }else{
                par[right] = left;
            }
            int r_fa = uuu->find(right);
            int l_fa = uuu->find(left);
            if(r_fa == l_fa){
                std::cout << "222" << std::endl;
                error_2 = i;
            }else{
                uuu->merge(r_fa, l_fa);
            }
        }
        if(error_1 == -1){
            return edges[error_2];
        }else if(error_2 == -1){
            return edges[error_1];
        }else if(error_1 == error_2){
            return edges[error_1];
        }
        else{
            std::cout << "333(" << edges[error_1][0] << "," << edges[error_1][1] << "(" << edges[error_2][0] << "," << edges[error_2][1];
            int right = edges[error_1][1] - 1;
            return {par[right]+1, right + 1};
        }
        return {0,0 };
    }
};
// @lc code=end


