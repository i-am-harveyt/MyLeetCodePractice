#include <iostream>
#include <vector>

using namespace std;

// my sol
class Solution1 {
public:
  vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<int>> starts;
  vector<vector<int>> all;
  int m, n;

  int dfs(int x, int y) {
    int largest = 0;
    for (vector<int> d : dir) {
      int nextX = x + d[0], nextY = y + d[1];
      if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
        if (all[nextX][nextY] > all[x][y]) {
          if (starts[nextX][nextY] == 0)
            largest = max(dfs(nextX, nextY), largest);
          else
            largest = max(starts[nextX][nextY], largest);
        }
      }
    }
    starts[x][y] = largest;
    return starts[x][y] + 1;
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    all = matrix;
    m = matrix.size(), n = matrix[0].size();
    starts = vector<vector<int>>(m, vector<int>(n, 0));
    int ret = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (starts[i][j] == 0)
          ret = max(dfs(i, j), ret);
    return ret;
  }
};

// example
class Solution2 {
public:
  int m, n;
  int memo[201][201];
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    m = matrix.size();
    n = matrix[0].size();
    int ans = 0;
    for (int r = 0; r < m; ++r)
      for (int c = 0; c < n; ++c)
        ans = max(ans, dfs(matrix, r, c));
    return ans;
  }
  int DIR[5] = {0, 1, 0, -1, 0};
  int dfs(vector<vector<int>> &matrix, int r, int c) {
    if (memo[r][c] != 0)
      return memo[r][c];
    int ans = 1;
    for (int i = 0; i < 4; ++i) {
      int nr = r + DIR[i], nc = c + DIR[i + 1];
      if (nr < 0 || nr == m || nc < 0 || nc == n ||
          matrix[nr][nc] <= matrix[r][c])
        continue;
      ans = max(ans, dfs(matrix, nr, nc) + 1);
    }
    return memo[r][c] = ans;
  }
};
