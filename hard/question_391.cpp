
/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 *
 * https://leetcode.cn/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (46.13%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 53.6K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi]
 * 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。
 *
 * 如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * 输出：true
 * 解释：5 个矩形一起可以精确地覆盖一个矩形区域。
 *
 *
 * 示例 2：
 *
 *
 * 输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * 输出：false
 * 解释：两个矩形之间有间隔，无法覆盖成一个矩形。
 *
 * 示例 3：
 *
 *
 * 输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * 输出：false
 * 解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 *
 *[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]\n[[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]\n[[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 *
 * 提示：
 *
 *
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 *
 *
 */

// @lc code=start
// 扫描线
// 超时
// 可以把打标记的部分换成线段树再试试看

class segmentTree
{
private:
    class segmentTreeNode
    {
    public:
        segmentTreeNode(int l, int r)
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
        int id;
        int left;
        int right;
        long long val;
        long long sum;
        long long min_val;
        long long max_val;
        segmentTreeNode *left_son;
        segmentTreeNode *right_son;
    };

    int all_left, all_right;

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
    void modify(segmentTreeNode *cur_node, int cur_l, int cur_r, int need_L, int need_R, long long add)
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
        int mid = (cur_l + cur_r) >> 1;
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

    long long query_min(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
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
    long long query_max(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
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
    long long query_sum(segmentTreeNode *cur_node, int cur_l, int cur_r, int NEED_L, int NEED_R)
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
    segmentTree(int left, int right)
    {

        root = new segmentTreeNode(left, right);
        all_left = left;
        all_right = right;
        // build(root, all_left, all_right, _initValue);
    }

    void modify(int l, int r, long long add)
    {
        modify(root, all_left, all_right, l, r, add);
    }

    long long query_min(int l, int r)
    {
        return query_min(root, all_left, all_right, l, r);
    }
    long long query_max(int l, int r)
    {
        return query_max(root, all_left, all_right, l, r);
    }
    long long query_sum(int l, int r)
    {
        return query_sum(root, all_left, all_right, l, r);
    }
};

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        unordered_set<int> si;
        for (int i = 0; i < rectangles.size(); i++)
        {
            si.insert(rectangles[i][1]);
            si.insert(rectangles[i][3]);
        }
        vector<int> vi_height;
        for (auto &get : si)
        {
            vi_height.push_back(get);
        }
        sort(vi_height.begin(), vi_height.end());

        segmentTree *st = new segmentTree(0, vi_height.size() - 1);
        // 左右
        vector<pair<int, int>> vpii;
        for (int i = 0; i < rectangles.size(); i++)
        {
            if (rectangles[i][0] != rectangles[i][2])
            {
                vpii.push_back({rectangles[i][0], i});
                vpii.push_back({rectangles[i][2], i});
            }
        }
        sort(vpii.begin(), vpii.end());
        for (int i = 0; i < vpii.size(); i++)
        {
            int j = i;
            int cur_x = vpii[i].first;
            while (j + 1 < vpii.size() && vpii[j + 1].first == cur_x)
            {
                j++;
            }
            if (j >= vpii.size() - 1)
            {
                break;
            }
            // 打标记

            for (int node_start = i; node_start <= j; node_start++)
            {
                int node_id = vpii[node_start].second;
                bool is_left = (vpii[node_start].first == rectangles[node_id][0]);
                int node_low = rectangles[node_id][1];
                int node_top = rectangles[node_id][3];

                auto lower_low = std::lower_bound(vi_height.begin(), vi_height.end(), node_low);
                auto lower_top = std::lower_bound(vi_height.begin(), vi_height.end(), node_top);
                int st_start = std::distance(vi_height.begin(), lower_low);
                int st_end = std::distance(vi_height.begin(), lower_top);
                st->modify(st_start, st_end - 1, (is_left ? 1 : -1));
                // std::cout << "modify:" << node_id << "-" << node_low << ":" << node_top << "|" << st_start << ":" << st_end - 1 << ":" << (is_left ? 1 : -1) << std::endl;
            }
            int temp_max = st->query_max(0, vi_height.size() - 2);
            int temp_min = st->query_min(0, vi_height.size() - 2);
            // std::cout << temp_max << ":" << temp_min << std::endl;
            if (temp_min != 1 || temp_max != 1)
            {
                return false;
            }
            i = j;
        }

        return true;
    }
};
// @lc code=end
