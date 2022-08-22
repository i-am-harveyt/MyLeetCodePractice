#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> m(nums.begin(), nums.end());
    int ret = 0;
    for (int n : nums) {
      if (m.find(n - 1) == m.end()) {
        int tmp = n + 1;
        while (m.find(tmp) != m.end()) {
          tmp += 1;
        }
        if (tmp-n > ret)
          ret = tmp-n;
      }
    }
    return ret;
  }
};
