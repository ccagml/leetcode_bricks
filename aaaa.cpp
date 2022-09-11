class Solution {
 public:
  int n;
  int ma[2000009];
  int b[250009];

  void build(int k, int l, int r) {
    if (l == r) {
      if (l > n) return;
      // scanf("%d", &ma[k]);
      return;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    ma[k] = max(ma[k << 1], ma[k << 1 | 1]);
  }

  int query(int k, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) return ma[k];
    int ma = -1, mid = (l + r) >> 1;
    if (mid >= ll) ma = max(ma, query(k << 1, l, mid, ll, rr));
    if (rr > mid) ma = max(ma, query(k << 1 | 1, mid + 1, r, ll, rr));
    return ma;
  }

  void update(int k, int l, int r, int p, int val) {
    if (l == r) {
      ma[k] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update(k << 1, l, mid, p, val);
    else
      update(k << 1 | 1, mid + 1, r, p, val);
    ma[k] = max(ma[k << 1], ma[k << 1 | 1]);
  }

  int lengthOfLIS(vector<int>& nums, int k) {
    build(1, 0, 100001);

    int result = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      int start_s = nums[i] - k;
      int temp_max = query(1, 0, 100001, start_s, nums[i] - 1);
      update(1, 0, 100001, nums[i], temp_max + 1);
    }

    return query(1, 0, 100001, 0, 100001);
  }
};