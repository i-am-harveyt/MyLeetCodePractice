#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    // init
    vector<vector<int>> ret;
    for (int i = 0; i < mat.size(); i++)
      ret.push_back(vector<int>(mat[0].size(), INT_MAX));

    queue<pair<pair<int, int>, int>> q; // x, y, step
    for (int i = 0; i < mat.size(); i++)
      for (int j = 0; j < mat[i].size(); j++)
        if (mat[i][j] == 0)
          q.push({{i, j}, 0});

    while (q.size() > 0) {
      auto cur = q.front();
      int i = cur.first.first, j = cur.first.second, d = cur.second;
      q.pop();
      if (i < 0 || i == mat.size() || j < 0 || j == mat[0].size())
        continue;
      bool update = false;
      if (d < ret[i][j]) {
        ret[i][j] = d;
        update = true;
      }
      if (!update)
        continue;
      q.push({{i - 1, j}, d + 1});
      q.push({{i + 1, j}, d + 1});
      q.push({{i, j + 1}, d + 1});
      q.push({{i, j - 1}, d + 1});
    }

    // return
    return ret;
  }
};
