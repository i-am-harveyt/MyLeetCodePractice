#include <math.h>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
  bool operator()(pair<vector<int>, double> &a, pair<vector<int>, double> &b) {
    return a.second > b.second;
  }
};
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> ret;
    priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>,
                   Compare>
        pq;
    for (size_t i = 0; i < points.size(); i++)
      pq.push({points[i], sqrt(points[i][0] * points[i][0] +
                               points[i][1] * points[i][1])});
    for (size_t i = 0; i < k; i++) {
      ret.push_back(pq.top().first);
      pq.pop();
    }
    return ret;
  }
};
