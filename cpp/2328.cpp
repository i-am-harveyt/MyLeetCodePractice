#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  const int MOD = 1e9 + 7;

public:
  map<pair<int, int>, int> memo;
  int helper(vector<vector<int>> &grid, int r = 0, int c = 0, int prev = 0) {
    pair<int, int> key = {r, c};
    if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size())
      return 0;
    else if (grid[r][c] <= prev) // not strictly increase
      return 0;
    else if (memo.find(key) != memo.end())
      return memo[key] % MOD;

    memo[key] = ((((1 + helper(grid, r, c + 1, grid[r][c])) % MOD +
                   helper(grid, r, c - 1, grid[r][c])) %
                      MOD +
                  helper(grid, r + 1, c, grid[r][c])) %
                     MOD +
                 helper(grid, r - 1, c, grid[r][c])) %
                MOD;

    return memo[key];
  }
  int countPaths(vector<vector<int>> &grid) {
    int ret = 0;
    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        ret = (ret + helper(grid, i, j)) % MOD;
    return ret;
  }
};
