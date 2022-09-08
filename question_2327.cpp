/*
 * @lc app=leetcode.cn id=2327 lang=cpp
 *
 * [2327] 知道秘密的人数
 *
 * https://leetcode.cn/problems/number-of-people-aware-of-a-secret/description/
 *
 * algorithms
 * Medium (45.46%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 17.9K
 * Testcase Example:  '6\n2\n4'
 *
 * 在第 1 天，有一个人发现了一个秘密。
 *
 * 给你一个整数 delay ，表示每个人会在发现秘密后的 delay 天之后，每天 给一个新的人 分享 秘密。同时给你一个整数 forget
 * ，表示每个人在发现秘密 forget 天之后会 忘记 这个秘密。一个人 不能 在忘记秘密那一天及之后的日子里分享秘密。
 *
 * 给你一个整数 n ，请你返回在第 n 天结束时，知道秘密的人数。由于答案可能会很大，请你将结果对 10^9 + 7 取余 后返回。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 6, delay = 2, forget = 4
 * 输出：5
 * 解释：
 * 第 1 天：假设第一个人叫 A 。（一个人知道秘密）
 * 第 2 天：A 是唯一一个知道秘密的人。（一个人知道秘密）
 * 第 3 天：A 把秘密分享给 B 。（两个人知道秘密）
 * 第 4 天：A 把秘密分享给一个新的人 C 。（三个人知道秘密）
 * 第 5 天：A 忘记了秘密，B 把秘密分享给一个新的人 D 。（三个人知道秘密）
 * 第 6 天：B 把秘密分享给 E，C 把秘密分享给 F 。（五个人知道秘密）
 *
 *
 * 示例 2：
 *
 * 输入：n = 4, delay = 1, forget = 3
 * 输出：6
 * 解释：
 * 第 1 天：第一个知道秘密的人为 A 。（一个人知道秘密）
 * 第 2 天：A 把秘密分享给 B 。（两个人知道秘密）
 * 第 3 天：A 和 B 把秘密分享给 2 个新的人 C 和 D 。（四个人知道秘密）
 * 第 4 天：A 忘记了秘密，B、C、D 分别分享给 3 个新的人。（六个人知道秘密）
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n <= 1000
 * 1 <= delay < forget <= n
 *
 *
 */

// @lc code=start

// 滚动数据?
// 第n天

// class Solution
// {
// public:
//     int peopleAwareOfSecret(int n, int delay, int forget)
//     {
//         int MOD = ((int)1e9 + 7);
//         ;
//         vector<long long> all(n);
//         all[0] = 1; // 第一天 一个人知道
//         vector<long long> day_add(n);
//         day_add[0] = 1;
//         // long long temp = 1; // 当前知道的人数

//         for (int i = 1; i < n; i++)
//         {
//             // std::cout << "\n第" << i + 1 << "天";
//             // 今天的遗忘数
//             long long today_forget = 0;
//             if (i >= forget)
//             {
//                 today_forget = day_add[i - forget];
//             }

//             today_forget %= MOD;

//             // temp -= today_forget;

//             // std::cout << "遗忘:" << today_forget << "当前知道:" << temp << "人|";

//             if (i < delay)
//             {
//                 all[i] = all[i - 1];
//                 // std::cout << "还没开始传播" << "|";
//             }
//             else
//             {
//                 int new_add = all[i - delay];
//                 if (i >= forget)
//                 {
//                     new_add -= all[i - forget];
//                 }
//                 // temp += new_add;
//                 // temp %= MOD;
//                 // std::cout << "今日新增:" << new_add << "现在知道:" << temp;
//                 all[i] = all[i - 1] + new_add;
//                 day_add[i] = new_add;
//             }
//         }
//         int result = 0;
//         for (int i = day_add.size() - 1; i >= day_add.size() - forget; i--)
//         {
//             result += day_add[i];
//         }
//         return result;
//     }
};
// @lc code=end
