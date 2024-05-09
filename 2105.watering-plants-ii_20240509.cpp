// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 * @lcpr version=30201
 *
 * [2105] 给植物浇水 II
 *
 * https://leetcode.cn/problems/watering-plants-ii/description/
 *
 * algorithms
 * Medium (52.42%)
 * Likes:    34
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 39.1K
 * Testcase Example:  '[2,2,3,3]\n5\n5'
 *
 * Alice 和 Bob 打算给花园里的 n 株植物浇水。植物排成一行，从左到右进行标记，编号从 0 到 n - 1 。其中，第 i 株植物的位置是 x
 * = i 。
 *
 * 每一株植物都需要浇特定量的水。Alice 和 Bob 每人有一个水罐，最初是满的 。他们按下面描述的方式完成浇水：
 *
 *
 * Alice 按 从左到右 的顺序给植物浇水，从植物 0 开始。Bob 按 从右到左 的顺序给植物浇水，从植物 n - 1 开始。他们 同时
 * 给植物浇水。
 * 无论需要多少水，为每株植物浇水所需的时间都是相同的。
 * 如果 Alice/Bob 水罐中的水足以 完全 灌溉植物，他们 必须 给植物浇水。否则，他们 首先（立即）重新装满罐子，然后给植物浇水。
 * 如果 Alice 和 Bob 到达同一株植物，那么当前水罐中水 更多 的人会给这株植物浇水。如果他俩水量相同，那么 Alice 会给这株植物浇水。
 *
 *
 * 给你一个下标从 0 开始的整数数组 plants ，数组由 n 个整数组成。其中，plants[i] 为第 i 株植物需要的水量。另有两个整数
 * capacityA 和 capacityB 分别表示 Alice 和 Bob 水罐的容量。返回两人浇灌所有植物过程中重新灌满水罐的 次数 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：plants = [2,2,3,3], capacityA = 5, capacityB = 5
 * 输出：1
 * 解释：
 * - 最初，Alice 和 Bob 的水罐中各有 5 单元水。
 * - Alice 给植物 0 浇水，Bob 给植物 3 浇水。
 * - Alice 和 Bob 现在分别剩下 3 单元和 2 单元水。
 * - Alice 有足够的水给植物 1 ，所以她直接浇水。Bob 的水不够给植物 2 ，所以他先重新装满水，再浇水。
 * 所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 0 + 1 + 0 = 1 。
 *
 * 示例 2：
 *
 * 输入：plants = [2,2,3,3], capacityA = 3, capacityB = 4
 * 输出：2
 * 解释：
 * - 最初，Alice 的水罐中有 3 单元水，Bob 的水罐中有 4 单元水。
 * - Alice 给植物 0 浇水，Bob 给植物 3 浇水。
 * - Alice 和 Bob 现在都只有 1 单元水，并分别需要给植物 1 和植物 2 浇水。
 * - 由于他们的水量均不足以浇水，所以他们重新灌满水罐再进行浇水。
 * 所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 + 1 + 1 + 0 = 2 。
 *
 * 示例 3：
 *
 * 输入：plants = [5], capacityA = 10, capacityB = 8
 * 输出：0
 * 解释：
 * - 只有一株植物
 * - Alice 的水罐有 10 单元水，Bob 的水罐有 8 单元水。因此 Alice 的水罐中水更多，她会给这株植物浇水。
 * 所以，两人浇灌所有植物过程中重新灌满水罐的次数 = 0 。
 *
 *
 *
 * 提示：
 *
 *
 * n == plants.length
 * 1 <= n <= 10^5
 * 1 <= plants[i] <= 10^6
 * max(plants[i]) <= capacityA, capacityB <= 10^9
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
class Solution
{
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB)
    {

        int result = 0;
        int left = 0;
        int right = plants.size() - 1;
        int cur_a = capacityA;
        int cur_b = capacityB;
        while (left <= right)
        {
            if (left == right)
            {
                bool is_a = cur_a >= cur_b;

                if (is_a)
                {
                    if (cur_a < plants[left])
                    {
                        cur_a = capacityA;
                        result++;
                    }
                    cur_a -= plants[left];
                }
                else
                {
                    if (cur_b < plants[left])
                    {
                        cur_b = capacityB;
                        result++;
                    }
                    cur_b -= plants[left];
                }
                left++;
                right--;
            }
            else
            {
                if (cur_a < plants[left])
                {
                    cur_a = capacityA;
                    result++;
                }
                cur_a -= plants[left];
                if (cur_b < plants[right])
                {
                    cur_b = capacityB;
                    result++;
                }
                cur_b -= plants[right];
                left++;
                right--;
            }
        }

        return result;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=minimumRefill
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [2,2,3,3]\n5\n5\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n10\n8\n
// @lcpr case=end

 */
