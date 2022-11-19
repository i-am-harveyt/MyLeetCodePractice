#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findCenter(vector<vector<int>> &edges) {
    int n = 0;
    for (int i = 0; i < edges.size(); i++) {
      int max = (edges[i][0] > edges[i][1]) ? edges[i][0] : edges[i][1];
      n = (max > n) ? max : n;
    }

    vector<int> arr(n + 1, 0);
    for (int i = 0; i < edges.size(); i++)
      ++arr[edges[i][0]], ++arr[edges[i][1]];

    int t = n - 1;
    for (int i = 1; i <= n; i++)
      if (arr[i] == t)
        return i;

    return -1;
  }
};
