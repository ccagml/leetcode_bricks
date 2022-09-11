class Solution {
 public:
  int lengthOfLIS(vector<int>& nums, int k) {
    unordered_map<int, int> temp;
    vector<int> temp_v;
    int result = 0;
    int n = nums.size();
    bool flag = true;
    if (k < 1000) {
      flag = false;
    }
    for (int i = 0; i < nums.size(); i++) {
      int temp_max = 0;

      if (flag) {
        if (temp.count(nums[i]) < 1) {
          temp_v.push_back(nums[i]);
          sort(temp_v.begin(), temp_v.end());
        }
        int start_s = nums[i] - k;
        auto lower = std::lower_bound(temp_v.begin(), temp_v.end(), start_s);

        if (lower != temp_v.end()) {
          int index = std::distance(temp_v.begin(), lower);
          for (int jj = index; jj < temp_v.size(); jj++) {
            int check = temp_v[jj];
            if (check >= nums[i]) {
              break;
            }
            temp_max = max(temp_max, temp[check]);
          }
        }
      } else {
        for (int s = nums[i] - k; s < nums[i]; s++) {
          temp_max = max(temp_max, temp[s]);
        }
      }

      temp[nums[i]] = temp_max + 1;
      result = max(result, temp[nums[i]]);
    }

    return result;
  }
};