#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    ret.push_back(vector<int>());
    ret[0].push_back(1);

    if (numRows == 1)
      return ret;

    for (int i = 1; i < numRows; i++) {
      ret.push_back(vector<int>());
      ret[i].push_back(1);

      for (int j = 1; j < i; j++)
        ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);

      ret[i].push_back(1);
    }

    return ret;
  }
};

class FastestSol {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret(numRows);

    for (int i = 0; i < numRows; i++) {
      ret[i].resize(i + 1);
      ret[i][0] = ret[i][i] = 1;
      for (int j = 1; j < i; j++)
        ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
    }

    return ret;
  }
};
