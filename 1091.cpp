#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    // do

    queue<pair<pair<int, int>, int>> q;
    map<pair<int, int>, bool> seen;
    int size = grid.size();

    if (grid[0][0] == 1 || grid[size - 1][size - 1] == 1)
      return -1;

    int ret = -1;
    pair<int, int> cur = pair<int, int>(0, 0);
    q.push(pair<pair<int, int>, int>(cur, 0));
    seen[cur] = true;

    int pathLen, x, y;
    while (!q.empty()) {
      cur = q.front().first;
      x = cur.first;
      y = cur.second;
      pathLen = q.front().second;
      q.pop();

      if (x == size - 1 && y == size - 1)
        return pathLen + 1;

      if (x + 1 < size) {
        if (y + 1 < size) {
          if (seen.find(pair<int, int>(x + 1, y + 1)) == seen.end()) {
            if (grid[x + 1][y + 1] == 0)
              q.push(pair<pair<int, int>, int>(pair<int, int>(x + 1, y + 1),
                                               pathLen + 1));
            seen[pair<int, int>(x + 1, y + 1)] = true;
          }
        }
        if (seen.find(pair<int, int>(x + 1, y)) == seen.end()) {
          if (grid[x + 1][y] == 0)
            q.push(pair<pair<int, int>, int>(pair<int, int>(x + 1, y),
                                             pathLen + 1));
          seen[pair<int, int>(x + 1, y)] = true;
        }
        if (y - 1 >= 0) {
          if (seen.find(pair<int, int>(x + 1, y - 1)) == seen.end()) {
            if (grid[x + 1][y - 1] == 0)
              q.push(pair<pair<int, int>, int>(pair<int, int>(x + 1, y - 1),
                                               pathLen + 1));
            seen[pair<int, int>(x + 1, y - 1)] = true;
          }
        }
      }

      if (y + 1 < size) {
        if (seen.find(pair<int, int>(x, y + 1)) == seen.end()) {
          if (grid[x][y + 1] == 0)
            q.push(pair<pair<int, int>, int>(pair<int, int>(x, y + 1),
                                             pathLen + 1));
          seen[pair<int, int>(x, y + 1)] = true;
        }
      }

      if (y - 1 >= 0) {
        if (seen.find(pair<int, int>(x, y - 1)) == seen.end()) {
          if (grid[x][y - 1] == 0)
            q.push(pair<pair<int, int>, int>(pair<int, int>(x, y - 1),
                                             pathLen + 1));
          seen[pair<int, int>(x, y - 1)] = true;
        }
      }

      if (x - 1 >= 0) {
        if (y + 1 < size) {
          if (seen.find(pair<int, int>(x - 1, y + 1)) == seen.end()) {
            if (grid[x - 1][y + 1] == 0)
              q.push(pair<pair<int, int>, int>(pair<int, int>(x - 1, y + 1),
                                               pathLen + 1));
            seen[pair<int, int>(x - 1, y + 1)] = true;
          }
        }
        if (seen.find(pair<int, int>(x - 1, y)) == seen.end()) {
          if (grid[x - 1][y] == 0)
            q.push(pair<pair<int, int>, int>(pair<int, int>(x - 1, y),
                                             pathLen + 1));
          seen[pair<int, int>(x - 1, y)] = true;
        }
        if (y - 1 >= 0) {
          if (seen.find(pair<int, int>(x - 1, y - 1)) == seen.end()) {
            if (grid[x - 1][y - 1] == 0)
              q.push(pair<pair<int, int>, int>(pair<int, int>(x - 1, y - 1),
                                               pathLen + 1));
            seen[pair<int, int>(x - 1, y - 1)] = true;
          }
        }
      }
    }
    return ret;
  }
};
