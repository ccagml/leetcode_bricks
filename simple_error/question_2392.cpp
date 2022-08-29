/*
 * @lc app=leetcode.cn id=2392 lang=cpp
 *
 * [2392] 给定条件下构造矩阵
 *
 * https://leetcode.cn/problems/build-a-matrix-with-conditions/description/
 *
 * algorithms
 * Hard (53.15%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    3.5K
 * Total Submissions: 6.6K
 * Testcase Example:  '3\n[[1,2],[3,2]]\n[[2,1],[3,2]]'
 *
 * 给你一个 正 整数 k ，同时给你：
 *
 *
 * 一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi] 和
 * 一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。
 *
 *
 * 两个数组里的整数都是 1 到 k 之间的数字。
 *
 * 你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。
 *
 * 矩阵还需要满足以下条件：
 *
 *
 * 对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。
 * 对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。
 *
 *
 * 返回满足上述要求的 任意 矩阵。如果不存在答案，返回一个空的矩阵。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
 * 输出：[[3,0,0],[0,0,1],[0,2,0]]
 * 解释：上图为一个符合所有条件的矩阵。
 * 行要求如下：
 * - 数字 1 在第 1 行，数字 2 在第 2 行，1 在 2 的上面。
 * - 数字 3 在第 0 行，数字 2 在第 2 行，3 在 2 的上面。
 * 列要求如下：
 * - 数字 2 在第 1 列，数字 1 在第 2 列，2 在 1 的左边。
 * - 数字 3 在第 0 列，数字 2 在第 1 列，3 在 2 的左边。
 * 注意，可能有多种正确的答案。
 *
 *
 * 示例 2：
 *
 * 输入：k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
 * 输出：[]
 * 解释：由前两个条件可以得到 3 在 1 的下面，但第三个条件是 3 在 1 的上面。
 * 没有符合条件的矩阵存在，所以我们返回空矩阵。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= k <= 400
 * 1 <= rowConditions.length, colConditions.length <= 10^4
 * rowConditions[i].length == colConditions[i].length == 2
 * 1 <= abovei, belowi, lefti, righti <= k
 * abovei != belowi
 * lefti != righti
 *
 *
 */

// @lc code=start
// 像是拓扑排序的东西

// 优先级队列可以直接插入新的计数, 当计数 和 哈希表对的上才处理,否则就是历史数据了

// 错误1:会有重复的情况[5,8][5,8] 这样
class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        unordered_map<int, unordered_set<int>> umii_cnt;
        unordered_map<int, int> umii_b;
        for (int i = 0; i < rowConditions.size(); i++)
        {
            int a = rowConditions[i][0];
            int b = rowConditions[i][1];
            if (umii_cnt[a].count(b) == 0)
            {
                umii_cnt[a].insert(b);
                umii_b[b]++;
            }
        }
        // 小的排前面
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pri_row;
        for (int i = 1; i <= k; i++)
        {
            pri_row.push({umii_b[i], i});
            // std::cout << "(" << umii_b[i] << "," << i << ")|";
        }
        // std::cout << std::endl;
        vector<int> row;
        int last_index = -1;
        while (pri_row.size() > 0)
        {
            pair<int, int> cur = pri_row.top();
            pri_row.pop();

            int cur_cnt = cur.first;
            int cur_number = cur.second;
            if (umii_b[cur.second] >= cur_cnt)
            {
                if (last_index == cur_number)
                {
                    vector<vector<int>> result;
                    // std::cout << "kongrow" << cur_number << std::endl;
                    return result;
                }
                if (umii_b.count(cur.second) > 0)
                {
                    cur_cnt = umii_b[cur.second];
                }
                if (cur_cnt == 0)
                {
                    // std::cout << "出" << cur_number << std::endl;
                    row.push_back(cur_number);
                    for (int a : umii_cnt[cur_number])
                    {
                        umii_b[a]--;
                        pri_row.push({umii_b[a], a});
                    }
                }
                else
                {
                    // std::cout << "新入" << cur_number << ":" << cur_cnt << std::endl;
                    last_index = cur_number;
                    pri_row.push({cur_cnt, cur_number});
                }
            }
        }

        unordered_map<int, unordered_set<int>> umii_cnt1;
        unordered_map<int, int> umii_b1;
        for (int i = 0; i < colConditions.size(); i++)
        {
            int a = colConditions[i][0];
            int b = colConditions[i][1];
            if (umii_cnt1[a].count(b) == 0)
            {
                umii_cnt1[a].insert(b);
                umii_b1[b]++;
            }
        }
        // 小的排前面
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pri_col;
        for (int i = 1; i <= k; i++)
        {
            pri_col.push({umii_b1[i], i});
            // std::cout << "(" << umii_b1[i] << "," << i << ")|";
        }
        // std::cout << std::endl;
        vector<int> col;
        last_index = -1;
        while (pri_col.size() > 0)
        {
            pair<int, int> cur = pri_col.top();
            pri_col.pop();
            int cur_cnt = cur.first;
            int cur_number = cur.second;
            if (umii_b1[cur.second] >= cur_cnt)
            {
                if (last_index == cur_number)
                {
                    vector<vector<int>> result;
                    return result;
                }
                if (umii_b1.count(cur.second) > 0)
                {
                    cur_cnt = umii_b1[cur.second];
                }
                if (cur_cnt == 0)
                {
                    // std::cout << "出" << cur_number << std::endl;
                    col.push_back(cur_number);
                    for (int a : umii_cnt1[cur_number])
                    {
                        umii_b1[a]--;
                        pri_col.push({umii_b1[a], a});
                    }
                }
                else
                {
                    // std::cout << "新入" << cur_number << ":" << cur_cnt << std::endl;
                    last_index = cur_number;
                    pri_col.push({cur_cnt, cur_number});
                }
            }
        }

        // std::cout << "不会是空结果" << std::endl;
        vector<vector<int>> result(k, vector<int>(k));
        // 计算行列
        unordered_map<int, int> row_x;
        unordered_map<int, int> col_y;
        for (int i = 0; i < row.size(); i++)
        {
            row_x[row[i]] = i;
        }
        for (int i = 0; i < col.size(); i++)
        {
            col_y[col[i]] = i;
        }
        for (int i = 1; i <= k; i++)
        {
            result[row_x[i]][col_y[i]] = i;
        }
        return result;
    }
};
// @lc code=end
