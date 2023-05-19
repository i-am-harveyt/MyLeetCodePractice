#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    vector<bool> have_in(n, false);
    vector<int> ret;

    for (const auto &edge : edges)
      have_in[edge[1]] = true;

    for (int i = 0; i < n; i++)
      if (have_in[i] == 0)
        ret.push_back(i);

    return ret;
  }
};
