/*
 * @lc app=leetcode.cn id=826 lang=cpp
 *
 * [826] 安排工作以达到最大收益
 *
 * https://leetcode-cn.com/problems/most-profit-assigning-work/description/
 *
 * algorithms
 * Medium (37.61%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 21.5K
 * Testcase Example:  '[2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]'
 *
 * 有一些工作：difficulty[i] 表示第 i 个工作的难度，profit[i] 表示第 i
 * 个工作的收益。
 *
 * 现在我们有一些工人。worker[i] 是第 i
 * 个工人的能力，即该工人只能完成难度小于等于 worker[i] 的工作。
 *
 * 每一个工人都最多只能安排一个工作，但是一个工作可以完成多次。
 *
 * 举个例子，如果 3 个工人都尝试完成一份报酬为 1 的同样工作，那么总收益为
 * $3。如果一个工人不能完成任何工作，他的收益为 $0 。
 *
 * 我们能得到的最大收益是多少？
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker =
 * [4,5,6,7] 输出: 100 解释: 工人被分配的工作难度是 [4,4,6,6] ，分别获得
 * [20,20,30,30] 的收益。
 *
 * 示例 2:
 *
 *
 * 输入: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
 * 输出: 0
 *
 *
 *
 * 提示:
 *
 *
 * n == difficulty.length
 * n == profit.length
 * m == worker.length
 * 1 <= n, m <= 10^4
 * 1 <= difficulty[i], profit[i], worker[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    if (worker.size() == 0) {
      return 0;
    }
    int result = 0;
    vector<vector<int>> vv;
    for (int i = 0; i < difficulty.size(); i++) {
      vv.push_back(vector<int>{difficulty[i], profit[i]});
    }

    sort(vv.begin(), vv.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] < b[0]) {
        return true;
      }
      return false;
    });

    sort(worker.begin(), worker.end());

    int temp_max = 0;
    int worker_index = 0;
    int temp_w = worker[0];
    for (int j = 0; j < vv.size(); j++) {
      std::cout << "vv:" << vv[j][0] << "," << vv[j][1] << "," << temp_w
                << std::endl;
      if (vv[j][0] <= temp_w) {
        temp_max = max(temp_max, vv[j][1]);
      } else {
        std::cout << temp_w << "," << temp_max << std::endl;
        result += temp_max;
        worker_index++;
        while (worker_index < worker.size() &&
               worker[worker_index] < vv[j][0]) {
          temp_w = worker[worker_index];
          worker_index++;
          result += temp_max;
          std::cout << temp_w << "," << temp_max << std::endl;
                }
        if(worker_index >= worker.size()){
          break;
        }
        temp_w = worker[worker_index];
      }
    }
    result += temp_max * (worker.size() - worker_index);
    return result;
  }
};
// @lc code=end
