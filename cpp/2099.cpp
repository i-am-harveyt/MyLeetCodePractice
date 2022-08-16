#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  static bool compare(pair<int, int> &i, pair<int, int> &j) {
    return i.second < j.second;
  }
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    vector<int> ret;
    priority_queue<pair<int, int>> heap;
    for (int i = 0; i < nums.size(); i++) {
      heap.push(make_pair(0-nums[i], i));
      if (heap.size() > k)
        heap.pop();
    }
    vector<pair<int, int>> tmp;
    for (; heap.size() > 0;) {
      tmp.push_back(heap.top());
      heap.pop();
    }
    sort(tmp.begin(), tmp.end(), compare);
    for (int i = 0; i < k; i++) {
      ret.push_back(0-tmp[i].first);
    }
    return ret;
  }
};
