#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &pre) {
    // init & build graph
    vector<vector<int>> g(numCourses, vector<int>());
    vector<int> in_deg(numCourses, 0);
    for (int i = 0; i < pre.size(); i++) {
      g[pre[i][1]].push_back(pre[i][0]);
      ++in_deg[pre[i][0]];
    }

    queue<int> deg0;
    for (int i = 0; i < numCourses; i++)
      if (!in_deg[i])
        deg0.push(i);

    vector<int> seq;
    while (deg0.size()) {
      int cur = deg0.front();
      seq.push_back(cur);
      deg0.pop();

      for (int i = 0; i < g[cur].size(); i++) {
        --in_deg[g[cur][i]];
        if (!in_deg[g[cur][i]])
          deg0.push(g[cur][i]);
      }
    }

    return seq.size() == numCourses;
  }
};
