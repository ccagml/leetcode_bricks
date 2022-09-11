class Solution {
 public:
  int lengthOfLIS(vector<int>& nums, int k) {
    map<int, int> temp;
    set<int> st;
    int result = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      int temp_max = 0;
      int start_s = nums[i] - k;
      auto itlow = temp.lower_bound(start_s);
      for (std::map<int, int>::iterator it = itlow; it != temp.end(); ++it) {
        int stv = it->first;
        if (stv >= nums[i]) {
          break;
        }
        temp_max = max(temp_max, temp[stv]);
      }

      temp[nums[i]] = temp_max + 1;
      result = max(result, temp[nums[i]]);
    }

    return result;
  }
};