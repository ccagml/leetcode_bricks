/*
 * @lc app=leetcode.cn id=LCP 30 lang=cpp
 * @lcpr version=30116
 *
 * [LCP 30] 魔塔游戏
 *
 * https://leetcode.cn/problems/p0NxJO/description/
 *
 * algorithms
 * Medium (38.09%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    20.5K
 * Total Submissions: 46.1K
 * Testcase Example:  '[100,100,100,-250,-60,-140,-50,-50,100,150]'
 *
 * 小扣当前位于魔塔游戏第一层，共有 `N` 个房间，编号为 `0 ~ N-1`。每个房间的补血道具/怪物对于血量影响记于数组
 * `nums`，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，即血量减少对应数值；`0` 表示房间对血量无影响。
 *
 * **小扣初始血量为
 * 1，且无上限**。假定小扣原计划按房间编号升序访问所有房间补血/打怪，**为保证血量始终为正值**，小扣需对房间访问顺序进行调整，**每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾**。请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回
 * -1。
 *
 *
 * **示例 1：**
 * >输入：`nums = [100,100,100,-250,-60,-140,-50,-50,100,150]`
 * >
 * >输出：`1`
 * >
 * >解释：初始血量为 1。至少需要将 nums[3] 调整至访问顺序末尾以满足要求。
 *
 * **示例 2：**
 * >输入：`nums = [-200,-300,400,0]`
 * >
 * >输出：`-1`
 * >
 * >解释：调整访问顺序也无法完成全部房间的访问。
 *
 * **提示：**
 * - `1 <= nums.length <= 10^5`
 * - `-10^5 <= nums[i] <= 10^5`
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
class Solution
{
public:
    int magicTower(vector<int> &nums)
    {
        long long sum = 1;
        for (int i : nums)
        {
            sum += i;
        }
        if (sum < 1)
        {
            return -1;
        }
        std::priority_queue<int, std::vector<int>, std::less<int>> q2;
        int result = 0;
        long long hp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            if (cur < 0)
            {
                q2.push(abs(cur));
            }
            hp += cur;
            while (hp < 1)
            {
                int q_t = q2.top();
                q2.pop();
                hp += q_t;
                result++;
            }
        }
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100,100,100,-250,-60,-140,-50,-50,100,150]\n
// @lcpr case=end

// @lcpr case=start
// [-200,-300,400,0]\n
// @lcpr case=end

 */
