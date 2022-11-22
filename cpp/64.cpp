#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size() + 1, m = grid[0].size() + 1;
    vector<vector<int>> mtx(n, vector<int>(m, INT_MAX));
    mtx[0][1] = mtx[1][0] = 0;

    --m, --n;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        mtx[i][j] = (mtx[i - 1][j] < mtx[i][j - 1])
                        ? mtx[i - 1][j] + grid[i - 1][j - 1]
                        : mtx[i][j - 1] + grid[i - 1][j - 1];

    return mtx[n][m];
  }
};
