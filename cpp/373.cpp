#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  // copy from net
  struct hashfunction {
    size_t operator()(const pair<int, int> &x) const {
      return x.first ^ x.second;
    }
  };
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {
    priority_queue<pair<int, pair<int, int>>> heap; // to help me sort them
    unordered_set<pair<int, int>, hashfunction> seen; // to record what I've seen
    vector<vector<int>> ret;
    int lmt = k;
    long long s1 = nums1.size(), s2 = nums2.size(); // to prevent from overflow
    if (k > s1 * s2) // let this algo run minimum round
      lmt = s1 * s2;

    // init
    heap.push(make_pair(0 - nums1[0] - nums2[0], make_pair(0, 0)));
    seen.insert(make_pair(0, 0));
    for (int i = lmt; i > 0; i--) {
      auto top = heap.top();
      ret.push_back({nums1[top.second.first], nums2[top.second.second]});
      heap.pop();

      // to add new pair in
      int i1 = top.second.first, i2 = top.second.second;
      if (i1 + 1 < s1 && seen.find({i1 + 1, i2}) == seen.end()) {
        heap.push({0 - nums1[i1 + 1] - nums2[i2], {i1 + 1, i2}});
        seen.insert({i1 + 1, i2});
      }
      if (i2 + 1 < s2 && seen.find({i1, i2 + 1}) == seen.end()) {
        heap.push({0 - nums1[i1] - nums2[i2 + 1], {i1, i2 + 1}});
        seen.insert({i1, i2 + 1});
      }
    }

    return ret;
  }
};
