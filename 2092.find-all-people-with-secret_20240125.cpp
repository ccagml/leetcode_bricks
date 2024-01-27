// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2092 lang=cpp
 * @lcpr version=30113
 *
 * [2092] 找出知晓秘密的所有专家
 *
 * https://leetcode.cn/problems/find-all-people-with-secret/description/
 *
 * algorithms
 * Hard (29.88%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 22.7K
 * Testcase Example:  '6\n[[1,2,5],[2,3,8],[1,5,10]]\n1'
 *
 * 给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号。另外给你一个下标从 0 开始的二维整数数组 meetings ，其中
 * meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会。一个专家可以同时参加 多场会议
 * 。最后，给你一个整数 firstPerson 。
 *
 * 专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson
 * 。接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播。更正式的表达是，每次会议，如果专家 xi 在时间 timei
 * 时知晓这个秘密，那么他将会与专家 yi 分享这个秘密，反之亦然。
 *
 * 秘密共享是 瞬时发生 的。也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享。
 *
 * 在所有会议都结束之后，返回所有知晓这个秘密的专家列表。你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
 * 输出：[0,1,2,3,5]
 * 解释：
 * 时间 0 ，专家 0 将秘密与专家 1 共享。
 * 时间 5 ，专家 1 将秘密与专家 2 共享。
 * 时间 8 ，专家 2 将秘密与专家 3 共享。
 * 时间 10 ，专家 1 将秘密与专家 5 共享。
 * 因此，在所有会议结束后，专家 0、1、2、3 和 5 都将知晓这个秘密。
 *
 *
 * 示例 2：
 *
 * 输入：n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
 * 输出：[0,1,3]
 * 解释：
 * 时间 0 ，专家 0 将秘密与专家 3 共享。
 * 时间 2 ，专家 1 与专家 2 都不知晓这个秘密。
 * 时间 3 ，专家 3 将秘密与专家 0 和专家 1 共享。
 * 因此，在所有会议结束后，专家 0、1 和 3 都将知晓这个秘密。
 *
 *
 * 示例 3：
 *
 * 输入：n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
 * 输出：[0,1,2,3,4]
 * 解释：
 * 时间 0 ，专家 0 将秘密与专家 1 共享。
 * 时间 1 ，专家 1 将秘密与专家 2 共享，专家 2 将秘密与专家 3 共享。
 * 注意，专家 2 可以在收到秘密的同一时间分享此秘密。
 * 时间 2 ，专家 3 将秘密与专家 4 共享。
 * 因此，在所有会议结束后，专家 0、1、2、3 和 4 都将知晓这个秘密。
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 10^5
 * 1 <= meetings.length <= 10^5
 * meetings[i].length == 3
 * 0 <= xi, yi <= n - 1
 * xi != yi
 * 1 <= timei <= 10^5
 * 1 <= firstPerson <= n - 1
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start

class unionFind
{
public:
    unordered_map<int, int> v_father;
    unionFind()
    {
        // for (int i = 0; i < n; i++)
        // {
        //     v_father.push_back(i);
        // }
    }
    int get(int i)
    {
        if (v_father.count(i) == 0)
        {
            v_father[i] = i;
            return i;
        }
        if (v_father[i] == i)
        {
            return i;
        }
        v_father[i] = get(v_father[i]);
        return v_father[i];
    }
    void set(int a, int b)
    {
        int fa = get(a);
        int fb = get(b);
        if (fa > fb)
        {
            v_father[fa] = fb;
        }
        else if (fb >= fa)
        {
            v_father[fb] = fa;
        }
    }
};

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        // 看上去像是并查集
        unionFind *uf = new unionFind();
        uf->set(0, 0);
        uf->set(0, firstPerson);

        std::sort(meetings.begin(), meetings.end(),
                  [](const vector<int> &left, const vector<int> &right)
                  {
                      // true使得left排前面
                      if (left[2] < right[2])
                      {
                          return true;
                      }
                      return false;
                  });

        int i = 0;

        while (i < meetings.size())
        {
            vector<pair<int, int>> temp;
            vector<int> v_i = meetings[i];
            int jjjj = v_i[2];
            while (i < meetings.size())
            {
                if (meetings[i][2] == jjjj)
                {
                    temp.push_back({meetings[i][0], meetings[i][1]});
                    i++;
                }
                else
                {
                    break;
                }
            }

            // 处理这个时间点的会议
            unionFind *uf_temp = new unionFind();
            for (int j = 0; j < temp.size(); j++)
            {
                pair<int, int> vj = temp[j];
                int j0_baba = uf->get(vj.first);
                int j1_baba = uf->get(vj.second);
                uf_temp->set(vj.first, j0_baba);
                uf_temp->set(vj.second, j1_baba);
                uf_temp->set(vj.first, vj.second);
            }
            for (int j = 0; j < temp.size(); j++)
            {
                pair<int, int> vj = temp[j];
                int j0_baba = uf_temp->get(vj.first);
                int j1_baba = uf_temp->get(vj.second);
                if (j0_baba == 0 || j1_baba == 0)
                {
                    uf->set(vj.first, 0);
                    uf->set(vj.second, 0);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            if (uf->get(i) == 0)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findAllPeople
// paramTypes= ["number","number[][]","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// 6\n[[1,2,5],[2,3,8],[1,5,10]]\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[3,1,3],[1,2,2],[0,3,3]]\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[3,4,2],[1,2,1],[2,3,1]]\n1\n
// @lcpr case=end

 */
