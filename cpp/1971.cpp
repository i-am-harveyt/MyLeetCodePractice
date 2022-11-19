#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // path compression
  int root(unordered_map<int, int> &mp, int cur) {
    if (mp.find(cur) == mp.end())
      mp[cur] = -1;

    if (mp[cur] <= -1)
      return cur;

    mp[cur] = root(mp, mp[cur]);
    return mp[cur];
  }

  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {

    unordered_map<int, int> mp;

    for (int i = 0; i < edges.size(); i++) {
      int r1 = root(mp, edges[i][0]), r2 = root(mp, edges[i][1]);
      if (r1 != r2) {
        if (mp[r1] > mp[r2])
          mp[r2] += mp[r1], mp[r1] = r2;
        else
          mp[r1] += mp[r2], mp[r2] = r1;
      }
    }

    return root(mp, source) == root(mp, destination);
  }
};
