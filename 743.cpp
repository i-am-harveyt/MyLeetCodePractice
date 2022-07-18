#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(0);

    vector<map<int, int>> table = vector<map<int, int>>(n + 1, map<int, int>{});
    vector<int> path = vector<int>(n + 1, INT_MAX);
    path[k] = 0;

    for (vector<int> v : times)
      table[v[0]][v[1]] = v[2];

    queue<int> q;
    q.push(k);
    int cur;

    while (!q.empty()) {
      cur = q.front();
      for (auto itr = table[cur].begin(); itr != table[cur].end(); itr++) {
        int arrival = path[cur] + itr->second;
        if (arrival < path[itr->first]) {
          path[itr->first] = arrival;
          q.push(itr->first);
        }
      }
      q.pop();
    }

    int ret = INT_MIN;

    for (int i = 1; i < n + 1; i++) {
      cout << i << " " << path[i] << endl;
      if (path[i] == INT_MAX)
        return -1;
      else
        ret = max(ret, path[i]);
    }

    return ret;
  }
};
