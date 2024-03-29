// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 * @lcpr version=30113
 *
 * [1334] 阈值距离内邻居最少的城市
 *
 * https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
 *
 * algorithms
 * Medium (61.25%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 46.5K
 * Testcase Example:  '4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4'
 *
 * 有 n 个城市，按从 0 到 n-1 编号。给你一个边数组 edges，其中 edges[i] = [fromi, toi, weighti] 代表
 * fromi 和 toi 两个城市之间的双向加权边，距离阈值是一个整数 distanceThreshold。
 *
 * 返回能通过某些路径到达其他城市数目最少、且路径距离 最大 为 distanceThreshold 的城市。如果有多个这样的城市，则返回编号最大的城市。
 *
 * 注意，连接城市 i 和 j 的路径的距离等于沿该路径的所有边的权重之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
 * 输出：3
 * 解释：城市分布图如上。
 * 每个城市阈值距离 distanceThreshold = 4 内的邻居城市分别是：
 * 城市 0 -> [城市 1, 城市 2] 
 * 城市 1 -> [城市 0, 城市 2, 城市 3] 
 * 城市 2 -> [城市 0, 城市 1, 城市 3] 
 * 城市 3 -> [城市 1, 城市 2] 
 * 城市 0 和 3 在阈值距离 4 以内都有 2 个邻居城市，但是我们必须返回城市 3，因为它的编号最大。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]],
 * distanceThreshold = 2
 * 输出：0
 * 解释：城市分布图如上。 
 * 每个城市阈值距离 distanceThreshold = 2 内的邻居城市分别是：
 * 城市 0 -> [城市 1] 
 * 城市 1 -> [城市 0, 城市 4] 
 * 城市 2 -> [城市 3, 城市 4] 
 * 城市 3 -> [城市 2, 城市 4]
 * 城市 4 -> [城市 1, 城市 2, 城市 3] 
 * 城市 0 在阈值距离 2 以内只有 1 个邻居城市。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 100
 * 1 <= edges.length <= n * (n - 1) / 2
 * edges[i].length == 3
 * 0 <= fromi < toi < n
 * 1 <= weighti, distanceThreshold <= 10^4
 * 所有 (fromi, toi) 都是不同的。
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
// 看不出为什么过不去
//  因为保存的值 uiusi_len[start_flag][pii_next.first] 不对
//  进入 pii_next.first 应当保存  cur_len - pii_next.second
class Solution
{
public:
    void check_n(int start_flag, int cur_n, int cur_len, int deep)
    {
        if (cur_len <= 0)
        {
            return;
        }
        for (pair<int, int> pii_next : uiuii[cur_n])
        {
            // 还没到过
            if ((uiusi[start_flag].count(pii_next.first) == 0 || (uiusi_len[start_flag].count(pii_next.first) > 0 && uiusi_len[start_flag][pii_next.first] < (cur_len - pii_next.second))) && cur_len >= pii_next.second && pii_next.first != start_flag)
            {
                uiusi_len[start_flag][pii_next.first] = cur_len - pii_next.second;
                uiusi[start_flag].insert(pii_next.first);
                check_n(start_flag, pii_next.first, cur_len - pii_next.second, deep + 1);
            }
        }
    }
    unordered_map<int, unordered_set<int>> uiusi;
    unordered_map<int, unordered_map<int, int>> uiusi_len;

    unordered_map<int, unordered_map<int, int>> uiuii;
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // dfs?
        for (int j = 0; j < edges.size(); j++)
        {
            int a = edges[j][0];
            int b = edges[j][1];
            int len = edges[j][2];
            if (len <= distanceThreshold)
            {
                uiuii[a][b] = len;
                uiuii[b][a] = len;
            }
        }

        for (int j = 0; j < n; j++)
        {
            check_n(j, j, distanceThreshold, 0);
        }

        int result = 0;
        int cur_cnt = 99999;

        for (int j = 0; j < n; j++)
        {
            if (uiusi[j].size() <= cur_cnt)
            {
                cur_cnt = uiusi[j].size();
                result = j;
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findTheCity
// paramTypes= ["number","number[][]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]\n2\n
// @lcpr case=end


// @lcpr case=start
// 34\n[[3,8,6065],[27,33,6596],[1,21,5037],[24,27,7612],[2,12,9802],[0,22,5578],[7,30,8719],[4,9,8316],[9,29,2750],[13,18,477],[32,33,2431],[19,22,4099],[4,15,3624],[8,26,9221],[17,32,2186],[9,24,1848],[2,16,3025],[27,30,6736],[11,12,821],[7,10,1626],[0,30,8941],[1,8,4354],[2,32,1753],[17,26,3348],[23,27,4288],[8,23,1095],[21,22,9359],[15,18,8625],[18,24,1287],[2,31,1193],[13,15,3562],[5,8,2841],[4,22,8381],[16,18,7080],[16,33,358],[1,14,9673],[28,29,6032],[8,31,7974],[23,28,4649],[16,29,3604],[1,5,3284],[9,15,9799],[20,29,8088],[8,15,3854],[6,25,6971],[9,31,7409],[12,13,6016],[13,24,8921],[4,33,3094],[2,14,7900],[10,21,1192],[4,10,4204],[19,23,6674],[6,14,3300],[24,29,136],[20,24,8717],[19,27,6238],[5,27,8427],[25,28,7981],[9,17,1252],[1,15,6615],[10,27,8357],[2,18,9475],[2,33,9579],[4,26,6973],[0,14,658],[22,23,5765],[6,11,7512],[3,19,105],[12,19,3110],[1,11,4905],[3,28,91],[4,28,8861],[10,30,1967],[0,32,4959],[5,18,8397],[3,15,5171],[14,15,8897],[15,27,9372],[4,32,9034],[9,14,4629],[4,25,8612],[27,29,6741],[4,29,8881],[6,13,8485],[6,10,6690],[10,13,9876],[7,31,9521],[8,33,5043],[24,30,7415],[0,33,4947],[7,27,2146],[13,21,8296],[2,5,7278],[5,15,9606],[15,21,2300],[5,11,9012],[5,22,2671],[13,25,4141],[3,20,158],[24,25,6950],[7,15,9272],[0,5,594],[4,8,6036],[0,17,6896],[3,24,6589],[10,15,4613],[17,23,301],[8,18,1483],[18,19,1476],[31,33,79],[5,26,6282],[23,29,4406],[7,9,7609],[10,24,4456],[17,24,6106],[8,13,7888],[3,27,5514],[6,18,6365],[25,26,7474],[0,27,1909],[3,25,7926],[8,14,5809],[0,20,2371],[17,28,6803],[20,23,2430],[0,23,298],[22,29,2820],[0,19,4264],[15,25,6026],[8,27,2083],[22,24,9660],[1,20,4705],[29,32,6766],[2,28,4226],[11,18,8418],[20,21,4707],[3,17,6894],[2,27,4484],[7,17,7103],[5,12,5504],[25,30,7960],[18,23,3531],[13,26,8051],[2,6,6585],[6,22,6966],[21,33,1498],[3,22,1056],[28,32,2122],[2,9,3378],[16,27,2452],[6,21,3756],[23,31,429],[1,17,1692],[11,30,4149],[3,18,2552],[25,29,7861],[16,26,1622],[11,20,6540],[9,11,3071],[13,20,50],[12,18,1461],[21,31,7008],[0,10,834],[21,27,9005],[12,16,3577],[22,31,8758],[30,31,6913],[18,22,5681],[1,2,771],[2,3,1691],[9,21,9058],[4,23,6876],[8,16,1944],[10,16,4348],[10,29,4568],[14,29,2934],[12,27,7860],[16,30,782],[0,8,3510],[10,26,1429],[16,20,6386],[1,9,2029],[20,25,7329],[11,27,4821],[28,31,8321],[20,33,8159],[3,6,6441],[2,19,1904],[3,30,9931],[13,28,7852],[0,4,1734],[23,30,2444],[0,21,6331],[6,26,3297],[0,29,2739],[17,22,8532],[9,23,4221],[26,27,6826],[2,4,8794],[6,7,4729],[7,11,8069],[1,23,8926],[3,7,3517],[13,14,5523],[4,19,7963],[10,14,1686],[2,10,141],[17,27,5684],[18,25,4384],[1,12,925],[8,11,8857],[3,4,7214],[3,23,4913],[7,32,1651],[16,25,3745],[19,28,8324],[1,25,4499],[0,25,4430],[1,13,4037],[5,28,6745],[19,20,2431],[0,31,2134],[9,12,4200],[7,12,3200],[26,32,6681],[14,17,9189],[29,30,9806],[8,28,958],[10,23,8730],[6,9,9978],[12,31,8346],[12,20,2439],[25,33,6780],[22,26,4427],[0,9,4585],[5,25,7867],[18,30,5011],[6,16,4376],[13,29,8050],[12,22,3513],[15,23,8172],[13,23,6025],[0,15,9815],[0,12,7710],[11,16,3960],[31,32,5545],[10,20,2887],[8,10,9925],[13,17,2969],[11,17,9512],[13,31,7392],[1,27,8762],[0,28,2449],[0,18,953],[14,19,8257],[19,33,5342],[1,28,8659],[3,31,2213],[11,15,3493],[5,9,5167],[15,33,8090],[7,23,7871],[14,28,5408],[2,8,1940],[23,32,2096],[7,33,2296],[4,13,4202],[19,30,3687],[7,25,1443],[11,19,8829],[12,24,820],[20,31,9226],[14,20,2820],[21,24,1903],[23,25,3707],[5,13,9229],[6,30,3268],[26,31,8242],[3,33,9300],[9,32,5045],[3,21,6919],[24,31,5369],[15,20,70],[8,20,329],[19,32,5003],[15,28,3609],[6,24,1386],[3,26,3679],[18,31,4591],[19,24,5589],[9,33,4409],[4,31,9850],[11,33,8494],[0,26,6215],[15,16,379],[17,21,1994],[11,32,5405],[6,12,5686],[9,16,2285],[16,32,1858],[30,33,4110],[4,16,2348],[5,21,9405],[3,29,673],[14,23,5686],[16,28,1268],[18,21,1505],[12,17,1691],[12,23,4915],[4,20,5195],[6,29,4079],[1,16,4413],[2,20,8678],[8,32,816],[22,33,5928],[15,24,511],[16,17,1284],[24,33,2278],[5,32,6543],[1,4,6096],[7,14,3966],[10,28,1538],[1,19,5388],[13,16,4484],[12,26,131],[0,24,8442],[17,25,5273],[8,12,1839],[18,29,5774],[8,21,2063],[4,11,9932],[26,33,4442],[2,15,6639],[5,6,1493],[9,27,9448],[7,8,8647],[4,14,7792],[5,29,9248],[0,6,6861],[11,13,8778],[1,6,6452],[2,29,4934],[4,17,3595],[26,28,4959],[11,28,8997],[2,17,2182],[12,33,884],[27,31,9832],[20,27,8332],[11,26,1801],[4,27,2870],[17,18,3942],[11,31,3523],[26,29,7121],[15,22,4498],[1,3,8945],[19,25,328],[22,28,4103],[5,23,8829],[6,31,4439],[7,16,8686],[20,28,4289],[6,23,7754],[12,30,2066],[20,22,6608],[9,18,1700],[6,8,6120],[14,25,1132],[9,20,8917],[12,25,5950],[11,21,8926],[15,32,9102],[26,30,8313],[13,22,9517],[15,30,499],[13,27,5049],[22,25,7299],[9,13,2167],[21,32,2553],[8,9,1219],[3,9,9491],[24,28,2326],[14,16,3544],[14,22,7932],[13,32,5497],[27,28,5982],[11,29,4790],[21,25,2618],[0,2,2550],[10,11,6255],[18,32,7205],[6,19,6647],[21,23,1932],[12,14,9847],[1,26,2379],[8,25,4420],[18,20,4839],[19,21,9891],[14,18,135],[15,26,8803],[5,24,159],[6,28,2173],[9,25,6218]]\n9207
// @lcpr case=end

// @lcpr case=start
// 39\n[[32,33,6066],[9,24,4482],[12,23,1781],[6,25,1897],[7,15,8633],[12,16,2890],[1,30,349],[30,31,9738],[11,33,9791],[12,34,2418],[18,21,4112],[25,29,7258],[1,3,4596],[1,8,2224],[8,17,9142],[13,23,6498],[29,38,9590],[6,28,6956],[4,31,9774],[2,30,3967],[6,19,8528],[11,13,3068],[2,36,2987],[29,37,5395],[14,21,5175],[2,4,3214],[17,29,196],[9,20,4655],[19,36,9637],[15,25,1418],[6,33,5843],[22,27,2500],[13,34,2553],[0,16,1409],[20,30,795],[5,34,8623],[9,33,2352],[21,29,525],[11,30,1720],[14,17,7672],[2,34,8525],[3,29,6520],[26,29,847],[14,18,1323],[27,33,2360],[14,23,4009],[21,37,7194],[14,38,7686],[2,25,8244],[3,21,7009],[20,27,8794],[4,32,1865],[14,20,3548],[2,3,6502],[21,28,1577],[9,15,1030],[24,32,5566],[3,5,4979],[18,26,4109],[25,33,6545],[12,36,5506],[5,33,564],[13,22,691],[8,13,1955],[18,19,4031],[15,37,841],[7,27,318],[1,25,1626],[15,18,7242],[11,12,1446],[24,26,725],[5,24,7100],[7,37,9453],[20,26,2597],[2,10,6982],[19,25,1081],[1,35,7350],[4,37,8618],[4,17,3751],[16,38,1582],[8,15,2040],[18,36,3113],[2,11,4287],[13,28,3813],[0,32,4375],[3,33,5513],[19,26,244],[11,23,2454],[16,28,3209],[3,34,7579],[2,24,6368],[10,25,6483],[8,22,5691],[7,19,4154],[17,23,8757],[7,11,1931],[4,19,7856],[22,32,8456],[2,12,2615],[29,36,4506],[14,37,9937],[11,27,4164],[26,38,7275],[6,11,9853],[3,31,9498],[6,27,835],[6,35,9750],[14,28,2564],[8,21,2069],[3,38,6068],[0,25,2793],[4,23,5182],[15,36,6692],[18,25,8000],[12,31,8724],[15,27,146],[1,7,6611],[1,36,5780],[9,23,5532],[20,28,3097],[30,38,108],[15,17,7243],[6,36,2094],[32,34,6015],[11,26,5442],[16,17,1454],[18,35,5012],[28,38,73],[0,38,5039],[17,33,8088],[33,35,1675],[10,38,2895],[29,31,1275],[13,38,7541],[13,17,3776],[13,26,3980],[0,22,5068],[5,14,420],[11,38,3823],[24,37,6245],[7,18,745],[11,22,894],[14,19,7170],[0,15,7181],[10,18,5059],[0,20,2448],[8,33,9989],[28,30,5110],[6,20,8021],[5,15,4099],[3,37,1375],[8,29,2438],[5,27,3915],[16,37,1430],[10,30,5871],[8,9,4053],[23,24,2305],[23,30,1723],[11,35,43],[23,25,377],[11,28,949],[2,27,2637],[26,36,1856],[9,25,994],[7,8,9375],[19,24,9937],[6,23,1727],[3,10,6053],[22,28,9815],[12,24,1033],[17,30,1795],[2,23,9458],[0,34,4091],[21,34,8096],[1,18,1031],[20,34,944],[2,5,4024],[0,24,285],[11,20,8137],[22,24,4782],[0,17,8309],[15,28,3969],[15,21,2276],[31,34,5448],[10,34,6433],[1,31,1736],[10,16,8362],[16,22,4084],[2,6,7867],[7,32,1865],[2,16,3438],[11,16,1160],[8,32,3509],[6,9,1658],[5,19,2762],[0,5,4162],[19,30,2333],[3,16,3306],[25,27,3425],[22,23,8181],[9,18,3861],[16,34,7057],[14,34,9239],[9,16,1192],[16,32,8649],[23,28,2251],[10,37,9831],[4,36,1830],[0,28,4997],[35,36,1370],[21,38,1609],[4,18,2630],[5,20,8504],[10,22,1379],[26,35,9343],[16,18,2038],[10,23,491],[24,38,6111],[35,38,8084],[8,20,7034]]\n6586
// @lcpr case=end

 */
