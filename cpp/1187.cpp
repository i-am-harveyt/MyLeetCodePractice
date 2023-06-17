#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  map<pair<int, int>, int> mem;

  int helper(vector<int> &arr1, vector<int> &arr2, size_t i1 = 0,
             int prev = -1) {
    if (i1 == arr1.size()) // hurray
      return 0;
    else if (mem.find({i1, prev}) != mem.end())
      return mem[{i1, prev}];

    int change = INT_MAX - 1, notchange = INT_MAX - 1;
    /* change */
    size_t i = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
    if (i != arr2.size())
      change = 1 + helper(arr1, arr2, i1 + 1, arr2[i]);

    /* not change */
    if (arr1[i1] > prev)
      notchange = helper(arr1, arr2, i1 + 1, arr1[i1]);

    mem[{i1, prev}] = min(change, notchange);
    return mem[{i1, prev}];
  }

  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    // sort arr2
    std::sort(arr2.begin(), arr2.end());
    int ret = helper(arr1, arr2);

    return ret == INT_MAX - 1 ? -1 : ret;
  }
};
