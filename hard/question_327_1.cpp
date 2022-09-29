/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 *
 * https://leetcode.cn/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (41.21%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    34.1K
 * Total Submissions: 82.7K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * 给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和
 * upper）之内的 区间和的个数 。
 *
 * 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-2,5,-1], lower = -2, upper = 2
 * 输出：3
 * 解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0], lower = 0, upper = 0
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -2^31
 * -10^5
 * 题目数据保证答案是一个 32 位 的整数
 *
 * [-1,1]\n0\n0\n[-2,5,-1]\n-2\n2\n[0]\n0\n0\n[2147483647,-2147483648,-1,0]\n-1\n0
 */

// @lc code=start
// 前缀和 两重循环 超时
// class Solution
// {
// public:
//     long long count_u = 0;
//     long long countRangeSum(vector<long long> &nums, long long lower, long long upper)
//     {
//         long long n = nums.size();
//         vector<long long> vi;
//         long long s = 0;
//         vi.push_back(s);
//         for (long long i = 0; i < n; i++)
//         {
//             s += nums[i];
//             vi.push_back(s);
//             // std::cout << s << ",";
//         }
//         long long result = 0;
//         for (long long i = 1; i <= n; i++)
//         {
//             for (long long j = i; j <= n; j++)
//             {
//                 long long a = vi[i - 1];
//                 long long b = vi[j];
//                 long long sum = b - a;
//                 // std::cout << i << ":" << j << ":" << sum << std::endl;
//                 if (sum >= lower && sum <= upper)
//                 {
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };

/*
思考1:
    [-2, 5, -1], -2, 2
    # 前缀和 -2  寻找 -2 - -2 和 -2 - 2 之间的前缀和
    # 前缀和  3  寻找  3 - -2 和  3 - 2 之间的前缀和
    # 前缀和  2  寻找  2 - -2 和  2 - 2 之间的前缀和
    例如 前缀和x 位置的a 那么代表 从0索引到a索引的和是 x
        要是有一个前缀和b在(x - low, x - up)内, 那么说明从0索引到b索引的前缀和是符合值 y
        b+1 到 a 的值 就是 x - y

=====================================

*/

class segmentTree
{
private:
    class segmentTreeNode
    {
    public:
        segmentTreeNode(long long l, long long r)
        {
            left = l;
            right = r;
            val = 0;
            sum = 0;
            min_val = 0;
            max_val = 0;
            left_son = nullptr;
            right_son = nullptr;
        }
        long long id;
        long long left;
        long long right;
        long long val;
        long long sum;
        long long min_val;
        long long max_val;
        segmentTreeNode *left_son;
        segmentTreeNode *right_son;
    };

    long long all_left, all_right;

    void pushup(segmentTreeNode *cur_node)
    {
        cur_node->sum = (cur_node->left_son->sum + cur_node->right_son->sum);
        cur_node->min_val = std::min(cur_node->left_son->min_val, cur_node->right_son->min_val);
        cur_node->max_val = std::max(cur_node->left_son->max_val, cur_node->right_son->max_val);
    }

    void pushdown(segmentTreeNode *cur_node, long long add)
    {
        update(cur_node->left_son, add);
        update(cur_node->right_son, add);
    }
    void modify(segmentTreeNode *cur_node, long long cur_l, long long cur_r, long long need_L, long long need_R, long long add)
    {
        //  cur_r needl  needr cur_l
        if (cur_l > need_R || cur_r < need_L)
        {
            return;
        }
        //   need_l  cur_l  cur_r  need_r
        // std::cout << (cur_node == nullptr) << ":" << cur_l << ":" << cur_r << ":" << need_L << ":" << need_R << ":" << add << std::endl;
        if (need_L <= cur_l && cur_r <= need_R)
        {
            update(cur_node, (add * (cur_r - cur_l + 1)));
        }
        // 到底了
        if (cur_l == cur_r)
        {
            return;
        }

        // pushdown(node_index, add);
        long long mid = (cur_l + cur_r) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        modify(cur_node->left_son, cur_l, mid, need_L, need_R, add);
        modify(cur_node->right_son, mid + 1, cur_r, need_L, need_R, add);
        pushup(cur_node);
    }

    long long query_min(segmentTreeNode *cur_node, long long cur_l, long long cur_r, long long NEED_L, long long NEED_R)
    {
        if (cur_node == nullptr)
            return LLONG_MAX;
        if (cur_l > NEED_R || cur_r < NEED_L)
            return LLONG_MAX;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->min_val;
        long mid = (cur_l + cur_r) >> 1;
        // pushdown(cur_node, 0);
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        return std::min(query_min(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_min(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
    }
    long long query_max(segmentTreeNode *cur_node, long long cur_l, long long cur_r, long long NEED_L, long long NEED_R)
    {
        // std::cout << cur_l << ":" << cur_r << ":" << NEED_L << ":" << NEED_R << ":" << std::endl;
        if (cur_node == nullptr)
            return LLONG_MIN;
        if (cur_l > NEED_R || cur_r < NEED_L)
            return LLONG_MIN;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->max_val;
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        return std::max(query_max(cur_node->left_son, cur_l, mid, NEED_L, NEED_R), query_max(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R));
    }
    long long query_sum(segmentTreeNode *cur_node, long long cur_l, long long cur_r, long long NEED_L, long long NEED_R)
    {
        if (cur_l > NEED_R || cur_r < NEED_L)
            return 0;
        if (NEED_L <= cur_l && cur_r <= NEED_R)
            return cur_node->sum;
        // pushdown(cur_node, 0);
        long mid = (cur_l + cur_r) >> 1;
        if (cur_node->left_son == nullptr)
        {
            cur_node->left_son = new segmentTreeNode(cur_l, mid);
        }
        if (cur_node->right_son == nullptr)
        {
            cur_node->right_son = new segmentTreeNode((mid + 1), cur_r);
        }
        return query_sum(cur_node->left_son, cur_l, mid, NEED_L, NEED_R) + query_sum(cur_node->right_son, mid + 1, cur_r, NEED_L, NEED_R);
    }
    // 更新某个点?
    void update(segmentTreeNode *node, long long add)
    {
        node->val += add;
        node->sum = node->val;
        node->min_val = node->val;
        node->max_val = node->val;
    }
    segmentTreeNode *root;

public:
    segmentTree(long long left, long long right)
    {

        root = new segmentTreeNode(left, right);
        all_left = left;
        all_right = right;
        // build(root, all_left, all_right, _initValue);
    }

    void modify(long long l, long long r, long long add)
    {
        modify(root, all_left, all_right, l, r, add);
    }

    long long query_min(long long l, long long r)
    {
        return query_min(root, all_left, all_right, l, r);
    }
    long long query_max(long long l, long long r)
    {
        return query_max(root, all_left, all_right, l, r);
    }
    long long query_sum(long long l, long long r)
    {
        return query_sum(root, all_left, all_right, l, r);
    }
};
// [-1,1]\n0\n0\n[-2,5,-1]\n-2\n2\n[0]\n0\n0\n[2147483647,-2147483648,-1,0]\n-1\n0
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        long long s = 0;
        vector<long long> vll;
        vll.push_back(0);
        for (long long i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            vll.push_back(s);
        }
        sort(vll.begin(), vll.end());
        unordered_map<long long, int> um;
        for (int i = 0; i < vll.size(); i++)
        {
            um[vll[i]] = i;
            std::cout << vll[i] << ",";
        }
        std::cout << std::endl;

        segmentTree *root = new segmentTree(0, vll.size());
        root->modify(um[0], um[0], 1);
        s = 0;
        long long result = 0;
        for (long long i : nums)
        {
            long long a = 0;
            long long b = 0;
            if (s - lower > s - upper)
            {
                a = s - upper;
                b = s - lower;
            }
            else
            {
                b = s - upper;
                a = s - lower;
            }
            auto a_lower = std::lower_bound(vll.begin(), vll.end(), a);
            auto b_lower = std::upper_bound(vll.begin(), vll.end(), b);
            if (a_lower != vll.end() && b_lower != vll.end())
            {
                int a_left = um[*a_lower];
                int b_right = um[*b_lower];
                std::cout << "查找" << a << "->" << b << "|" << std::distance(vll.begin(), a_lower) << ":" << std::distance(vll.begin(), a_lower) << std::endl;
                result += root->query_sum(a_left, b_right - 1);
            }
            else if (a_lower != vll.end())
            {
                int a_left = um[*a_lower];
                std::cout << "查找" << a << "->" << b << "|" << std::distance(vll.begin(), a_lower) << ":" << std::endl;
                result += root->query_sum(a_left, vll.size());
            }
            root->modify(s, s, 1);
        }
        return result;
    }
};
// @lc code=end
