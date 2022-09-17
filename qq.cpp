#include <algorithm>
#include <array>
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
class segmentTree
{
private:
    class segmentTreeNode
    {
    public:
        int id, left, right;
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

    void build(segmentTreeNode *cur_node, int l, int r, long long initValue)
    {
        // std::cout << (cur_node == nullptr) << ":" << l << ":" << r << ":" << initValue << std::endl;
        cur_node->left = l;
        cur_node->right = r;
        cur_node->sum = 0;
        cur_node->min_val = 0;
        cur_node->max_val = 0;

        if (l == r)
            cur_node->val = initValue;
        else
        {
            if (cur_node->left_son == nullptr)
            {
                cur_node->left_son = new segmentTreeNode();
            }
            if (cur_node->right_son == nullptr)
            {
                cur_node->right_son = new segmentTreeNode();
            }
            int mid = (l + r) >> 1;
            build(cur_node->left_son, l, mid, initValue);
            build(cur_node->right_son, mid + 1, r, initValue);
            pushup(cur_node);
        }
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
    segmentTree(int left, int right, long long _initValue)
    {

        root = new segmentTreeNode();
        all_left = left;
        all_right = right;
        build(root, all_left, all_right, _initValue);
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

int main(int argc, char const *argv[])
{
    segmentTree *st = new segmentTree(1, 100, 0);
    // std::cout << st->query_max(1, 100) << std::endl;
    // std::cout << st->query_min(1, 100) << std::endl;
    // std::cout << st->query_sum(1, 100) << std::endl;
    std::cout << "修改前" << std::endl;
    st->modify(2, 10, 1);
    st->modify(5, 20, 3);
    std::cout << "修改后" << std::endl;
    // std::cout << st->query_max(1, 100) << std::endl;
    // std::cout << st->query_min(1, 100) << std::endl;
    // std::cout << st->query_sum(1, 100) << std::endl;
    // std::cout << st->query_max(2, 9) << std::endl;
    // std::cout << st->query_min(21, 100) << std::endl;
    // std::cout << st->query_sum(1, 16) << std::endl;
    for (int i = 1; i < 22; i++)
    {
        for (int j = i; j < 22; j++)
        {
            std::cout << i << ":" << j << ":" << st->query_max(i, j) << std::endl;
        }
    }
    // std::cout << st->query_max(5, 5) << std::endl;
    // std::cout << st->query_min(5, 5) << std::endl;
    // std::cout << st->query_sum(5, 5) << std::endl;
    // std::cout << st->query_sum(5, 6) << std::endl;
    // std::cout << st->query_sum(5, 7) << std::endl;
    // std::cout << st->query_sum(5, 8) << std::endl;

    return 0;
}

// g++ -std=c++11 quick_start.cpp