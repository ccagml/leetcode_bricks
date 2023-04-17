// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2409 lang=cpp
 * @lcpr version=21906
 *
 * [2409] 统计共同度过的日子数
 *
 * https://leetcode.cn/problems/count-days-spent-together/description/
 *
 * algorithms
 * Easy (48.65%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 19K
 * Testcase Example:  '"08-15"\n"08-18"\n"08-16"\n"08-19"'
 *
 * Alice 和 Bob 计划分别去罗马开会。
 *
 * 给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期
 * arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob
 * 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。
 *
 * 请你返回 Alice和 Bob 同时在罗马的天数。
 *
 * 你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30,
 * 31, 30, 31] 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16",
 * leaveBob = "08-19"
 * 输出：3
 * 解释：Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月
 * 16、17 和 18 号。所以答案为 3 。
 *
 *
 * 示例 2：
 *
 * 输入：arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01",
 * leaveBob = "12-31"
 * 输出：0
 * 解释：Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 所有日期的格式均为 "MM-DD" 。
 * Alice 和 Bob 的到达日期都 早于或等于 他们的离开日期。
 * 题目测试用例所给出的日期均为 非闰年 的有效日期。
 *
 *
 */
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
// @lc code=start
class Solution
{
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {
        vector<int> datesOfMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefixSum(1, 0);
        for (int date : datesOfMonths)
        {
            prefixSum.emplace_back(prefixSum.back() + date);
        }

        int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
        int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
        int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
        int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
        return max(0, min(leaveAliceDay, leaveBobDay) - max(arriveAliceDay, arriveBobDay) + 1);
    }

    int calculateDayOfYear(string day, const vector<int> &prefixSum)
    {
        int month = stoi(day.substr(0, 2));
        int date = stoi(day.substr(3));
        return prefixSum[month - 1] + date;
    }
};

// @lc code=end

// @lcpr-div-debug-arg-start
// funName=countDaysTogether
// paramTypes= ["string","string","string","string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "08-15"\n"08-18"\n"08-16"\n"08-19"\n
// @lcpr case=end

// @lcpr case=start
// "10-01"\n"10-31"\n"11-01"\n"12-31"\n
// @lcpr case=end

// @lcpr case=start
//"09-01"\n"10-19"\n"06-19"\n"10-20"\n
// @lcpr case=end

 */
