/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 *
 * https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/description/
 *
 * algorithms
 * Medium (35.45%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 15.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你 n 个项目，编号从 0 到 n - 1 。同时给你一个整数数组 milestones ，其中每个 milestones[i] 表示第 i
 * 个项目中的阶段任务数量。
 *
 * 你可以按下面两个规则参与项目中的工作：
 *
 *
 * 每周，你将会完成 某一个 项目中的 恰好一个 阶段任务。你每周都 必须 工作。
 * 在 连续的 两周中，你 不能 参与并完成同一个项目中的两个阶段任务。
 *
 *
 * 一旦所有项目中的全部阶段任务都完成，或者仅剩余一个阶段任务都会导致你违反上面的规则，那么你将 停止工作
 * 。注意，由于这些条件的限制，你可能无法完成所有阶段任务。
 *
 * 返回在不违反上面规则的情况下你 最多 能工作多少周。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：milestones = [1,2,3]
 * 输出：6
 * 解释：一种可能的情形是：
 * ​​​​- 第 1 周，你参与并完成项目 0 中的一个阶段任务。
 * - 第 2 周，你参与并完成项目 2 中的一个阶段任务。
 * - 第 3 周，你参与并完成项目 1 中的一个阶段任务。
 * - 第 4 周，你参与并完成项目 2 中的一个阶段任务。
 * - 第 5 周，你参与并完成项目 1 中的一个阶段任务。
 * - 第 6 周，你参与并完成项目 2 中的一个阶段任务。
 * 总周数是 6 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：milestones = [5,2,1]
 * 输出：7
 * 解释：一种可能的情形是：
 * - 第 1 周，你参与并完成项目 0 中的一个阶段任务。
 * - 第 2 周，你参与并完成项目 1 中的一个阶段任务。
 * - 第 3 周，你参与并完成项目 0 中的一个阶段任务。
 * - 第 4 周，你参与并完成项目 1 中的一个阶段任务。
 * - 第 5 周，你参与并完成项目 0 中的一个阶段任务。
 * - 第 6 周，你参与并完成项目 2 中的一个阶段任务。
 * - 第 7 周，你参与并完成项目 0 中的一个阶段任务。
 * 总周数是 7 。
 * 注意，你不能在第 8 周参与完成项目 0 中的最后一个阶段任务，因为这会违反规则。
 * 因此，项目 0 中会有一个阶段任务维持未完成状态。
 *
 *
 *
 * 提示：
 *
 *
 * n == milestones.length
 * 1 <= n <= 10^5
 * 1 <= milestones[i] <= 10^9
 *
 *
 */

// 多的先排?优先级队列? 感觉会超时
// 上面的思路好像不太对 类似 [8,8,2,6]
//  [4, 3, 3]

// @lc code=start
// class Solution
// {
// public:
//     long long numberOfWeeks(vector<int> &milestones)
//     {
//         std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> coll;
//         for (int i = 0; i < milestones.size(); i++)
//         {
//             coll.push({milestones[i], i});
//         }
//         long long result = 0;
//         int last = -1;

//         pair<int, int> temp_top11 = coll.top();
//         coll.pop();
//         if (last == -1)
//         {
//             last = temp_top11.second;
//             result++;
//             if (temp_top11.first > 1)
//             {
//                 coll.push({temp_top11.first - 1, temp_top11.second});
//             }
//         }

//         while (coll.size() > 0)
//         {
//             pair<int, int> temp_top = coll.top();
//             coll.pop();

//             if (coll.size() == 0)
//             {
//                 if (temp_top.second != last)
//                 {
//                     result++;
//                 }
//                 break;
//             }

//             if (coll.size() > 0)
//             {
//                 int cur1_num = temp_top.first;
//                 int cur1_id = temp_top.second;
//                 int err_black = true;
//                 while (coll.size() > 0)
//                 {
//                     pair<int, int> temp_top2 = coll.top();
//                     coll.pop();
//                     int cur2_num = temp_top2.first;
//                     int cur2_id = temp_top2.second;
//                     if (cur2_num > cur1_num)
//                     {
//                         coll.push(temp_top2);
//                         if (cur1_num > 0)
//                         {
//                             coll.push({cur1_num, cur1_id});
//                             err_black = false;
//                         }
//                         break;
//                     }
//                     int temp_half = cur2_num;
//                     if (temp_half > 2)
//                     {
//                         temp_half /= 2;
//                     }

//                     result += (2 * temp_half);
//                     cur1_num -= temp_half;
//                     if (last != cur1_id)
//                     {
//                         last = cur2_id;
//                     }
//                     if ((cur2_num - temp_half) > 0)
//                     {

//                         coll.push({(cur2_num - temp_half), cur2_id});
//                     }
//                 }
//                 // 放回去;
//                 if (err_black && cur1_num > 0)
//                 {
//                     coll.push({cur1_num, cur1_id});
//                 }
//             }
//         }
//         return result;
//     }
// };

// @lc code=end
