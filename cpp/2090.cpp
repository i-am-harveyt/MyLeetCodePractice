#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getAverages(vector<int> &nums, int k) {
    if (k == 0) {
      vector<int> ret = nums;
      return ret;
    }
    vector<int> ret = vector<int>(nums.size(), -1);
    if (2 * k >= nums.size())
      return ret;
    long long cur = 0;
    for (size_t i = 0; i <= 2 * k; i++)
      cur += nums[i];
    int mod = 2 * k + 1;
    ret[k] = cur / mod;
    for (size_t i = 1; i < nums.size() - 2 * k; i++)
      cur += nums[2 * k + i] - nums[i - 1], ret[k + i] = cur / mod;
    return ret;
  }
};
