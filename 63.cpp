#include <iostream>
#include <map>
#include <vector>

using namespace std;

// recursive
class Solution1 {
public:
  map<pair<int, int>, int> m = {};

  int get(vector<vector<int>> &obg, pair<int, int> cur, int height, int width) {
    if (m.find(cur) != m.end())
      return m[cur];
    int x = cur.first, y = cur.second;
    if (x >= height || y >= width || obg[x][y] == 1)
      return 0;
    else if (x == height - 1 && y == width - 1) {
      m[cur] = 1;
      return m[cur];
    }
    m[cur] = get(obg, pair<int, int>(x + 1, y), height, width) +
             get(obg, pair<int, int>(x, y + 1), height, width);
    return m[cur];
  }

  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    return get(obstacleGrid, pair<int, int>(0, 0), obstacleGrid.size(),
               obstacleGrid[0].size());
  }
};

// iterative
class Solution2 {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int h = obstacleGrid.size(), w = obstacleGrid[0].size();
    vector<vector<int>> grid =
        vector<vector<int>>(h + 1, vector<int>(w + 1, 0));
    grid[1][1] = 1;
    for (int i = 1; i < h + 1; i++)
      for (int j = 1; j < w + 1; j++)
        if (obstacleGrid[i - 1][j - 1])
          grid[i][j] = 0;
        else
          grid[i][j] += grid[i - 1][j] + grid[i][j - 1];
    return grid[h][w];
  }
};

// example, insane
class Solution3 {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(2, vector<int>(m, 0));
    if (!obstacleGrid[0][0])
      dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + j == 0)
          continue;
        dp[i % 2][j] = 0;
        if (obstacleGrid[i][j])
          continue; // no way to reach here
        if (i)
          dp[i % 2][j] += dp[(i - 1) % 2][j];
        if (j)
          dp[i % 2][j] += dp[i % 2][j - 1];
      }
    }
    return dp[(n - 1) % 2][m - 1];
  }
};
