#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> neighbors;
  vector<int> firstTime, minTime;
  vector<bool> visited;
  vector<vector<int>> ret;
  int time = 1;

  void dfs(int cur, int parent = -1) {
    firstTime[cur] = minTime[cur] = time++;
    visited[cur] = true;
    for (int n : neighbors[cur]) {
      if (n == parent)
        continue;

      if (!visited[n])
        dfs(n, cur);

      minTime[cur] = min(minTime[n], minTime[cur]);

      if (firstTime[cur] < minTime[n])
        ret.push_back({cur, n});
    }
    return;
  }

  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    neighbors = vector<vector<int>>(n, vector<int>{});

    for (vector<int> c : connections) {
      neighbors[c[0]].push_back(c[1]);
      neighbors[c[1]].push_back(c[0]);
    }

    firstTime = vector<int>(n, INT_MAX);
    minTime = vector<int>(n, INT_MAX);
    visited = vector<bool>(n, false);

    dfs(0);

    return ret;
  }
};
