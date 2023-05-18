#include <algorithm>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3)
      return ret;

    sort(nums.begin(), nums.end());
    size_t r = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
    if (r == nums.size() && nums[r - 1] < 0)
      return ret;

    size_t i = 0;
    while (i < nums.size()) {
      size_t j = i + 1;
      while (j < nums.size()) {

        int n = 0 - nums[i] - nums[j];
        size_t p =
            upper_bound(nums.begin() + j, nums.end(), n) - nums.begin() - 1;
        if (p > j && nums[p] == n) {
          vector<int> tmp({nums[i], nums[j], n});
          ret.push_back(tmp);
        }

        // update j
        ++j;
        while (j < nums.size() - 1 && nums[j] == nums[j - 1])
          ++j;
      }

      // update i
      ++i;
      while (i < nums.size() && nums[i - 1] == nums[i])
        ++i;
    }

    return ret;
  }
};
