#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> ds;

  bool isBipartite(vector<vector<int>> &graph) {
    int size = graph.size();

    ds = vector<int>(size, 0);

    for (int i = 0; i < size; i++) {
      if (ds[i])
        continue;

      queue<int> q;
      q.push(i);
      ds[i] = 1;

      while (!q.empty()) {
        int parent = q.front();
        q.pop();
        for (int child : graph[parent]) {
          if (ds[child] == 0) {
            ds[child] = -ds[parent];
            q.push(child);
          } else if (ds[child] == ds[parent])
            return false;
        }
      }
    }
    return true;
  }
};
