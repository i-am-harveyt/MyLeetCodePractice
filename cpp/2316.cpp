#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int find(int n, vector<long> &set) {
    if (set[n] < 0)
      return n;
    set[n] = find(set[n], set);
    return set[n];
  }

  void uni(int p, int q, vector<long> &set) {
    int p1 = find(p, set), p2 = find(q, set);
    if (p1 == p2)
      return;
    if (set[p1] <= set[p2])
      set[p1] += set[p2], set[p2] = p1;
    else
      set[p2] += set[p1], set[p1] = p2;
  }

  long long countPairs(int n, vector<vector<int>> &edges) {
    vector<long> ds(n, -1);
    for (int i = 0; i < edges.size(); i++)
      uni(edges[i][0], edges[i][1], ds);

    long long a = 0, b = 0;
    for (int i = 0; i < n; i++)
      if (ds[i] < 0)
        a += ds[i], b += ds[i] * ds[i];
    return (a * a - b) / 2;
  }
};
