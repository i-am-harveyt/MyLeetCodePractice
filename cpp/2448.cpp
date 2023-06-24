#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  long long minCost(vector<int> &nums, vector<int> &cost) {
    vector<pair<int, int>> vec;
    for (size_t i = 0; i < nums.size(); i++)
      vec.push_back({nums[i], cost[i]});
    sort(vec.begin(), vec.end());

    /* odd */
    if (nums.size() % 2) {
      long long ret = 0;
      int num = vec[nums.size() / 2 + 1].first;
      for (size_t i = 0; i < vec.size(); i++)
        ret += abs(vec[i].first - num) * vec[i].second;
      return ret;
    }

    long long n1 = 0, n2 = 0;

    int del1 = vec[nums.size() / 2 + 1].first;
    int del2 = vec[nums.size() / 2].first;
    for (size_t i = 0; i < vec.size(); i++) {
      n1 += abs(vec[i].first - del1) * vec[i].second;
      n2 += abs(vec[i].first - del2) * vec[i].second;
    }
    return n1 < n2 ? n1 : n2;
  }
};
