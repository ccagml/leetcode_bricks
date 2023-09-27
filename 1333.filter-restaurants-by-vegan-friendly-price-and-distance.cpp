// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1333 lang=cpp
 * @lcpr version=21917
 *
 * [1333] 餐厅过滤器
 *
 * https://leetcode.cn/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/
 *
 * algorithms
 * Medium (67.92%)
 * Likes:    57
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 32.9K
 * Testcase Example:  '[[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n1\n50\n10'
 *
 * 给你一个餐馆信息数组 restaurants，其中  restaurants[i] = [idi, ratingi, veganFriendlyi,
 * pricei, distancei]。你必须使用以下三个过滤器来过滤这些餐馆信息。
 * 
 * 其中素食者友好过滤器 veganFriendly 的值可以为 true 或者 false，如果为 true 就意味着你应该只包括
 * veganFriendlyi 为 true 的餐馆，为 false 则意味着可以包括任何餐馆。此外，我们还有最大价格 maxPrice 和最大距离
 * maxDistance 两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。
 * 
 * 过滤后返回餐馆的 id，按照 rating 从高到低排序。如果 rating 相同，那么按 id 从高到低排序。简单起见， veganFriendlyi
 * 和 veganFriendly 为 true 时取值为 1，为 false 时，取值为 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：restaurants =
 * [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]],
 * veganFriendly = 1, maxPrice = 50, maxDistance = 10
 * 输出：[3,1,5] 
 * 解释： 
 * 这些餐馆为：
 * 餐馆 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
 * 餐馆 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
 * 餐馆 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
 * 餐馆 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
 * 餐馆 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
 * 在按照 veganFriendly = 1, maxPrice = 50 和 maxDistance = 10 进行过滤后，我们得到了餐馆 3, 餐馆
 * 1 和 餐馆 5（按评分从高到低排序）。 
 * 
 * 
 * 示例 2：
 * 
 * 输入：restaurants =
 * [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]],
 * veganFriendly = 0, maxPrice = 50, maxDistance = 10
 * 输出：[4,3,2,1,5]
 * 解释：餐馆与示例 1 相同，但在 veganFriendly = 0 的过滤条件下，应该考虑所有餐馆。
 * 
 * 
 * 示例 3：
 * 
 * 输入：restaurants =
 * [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]],
 * veganFriendly = 0, maxPrice = 30, maxDistance = 3
 * 输出：[4,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= restaurants.length <= 10^4
 * restaurants[i].length == 5
 * 1 <= idi, ratingi, pricei, distancei <= 10^5
 * 1 <= maxPrice, maxDistance <= 10^5
 * veganFriendlyi 和 veganFriendly 的值为 0 或 1 。
 * 所有 idi 各不相同。
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
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < restaurants.size(); i++){
            vector<int> vv = restaurants[i];
            bool can = true;
            if((veganFriendly == 1 && vv[2] == 0) || (maxPrice < vv[3]) || (maxDistance < vv[4])){
                can = false;
            }
            if(can){
                temp.push_back({vv[1], vv[0]});
            }
        }
        sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int,int>b){
            if((a.first > b.first) || (a.first == b.first && a.second > b.second)){
                return true;
            }
            return false;
        });
        vector<int> result;
        for(int i = 0; i < temp.size(); i++){
            result.push_back(temp[i].second);
        }
        return result;

    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=filterRestaurants
// paramTypes= ["number[][]","number","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n1\n50\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n50\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]]\n0\n30\n3\n
// @lcpr case=end

 */

