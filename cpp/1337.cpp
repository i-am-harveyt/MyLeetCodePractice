#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<int> ret;
    priority_queue<pair<int, int>> heap; // pair(strength, row_index)
    int cur;
    for (int i = 0; i < mat.size(); i++) {
      cur = 0;
      for (int n : mat[i])
        cur += n;
      heap.push(make_pair(cur, i));
      if (heap.size() > k) // update if size is too big
        heap.pop();
    }
    for (; k > 0; k--) {
      ret.push_back(heap.top().second);
      heap.pop();
    }
    reverse(ret.begin(), ret.end()); // from weak to strong order
    return ret;
  }
};
