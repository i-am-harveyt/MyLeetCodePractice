#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> mat(rowIndex + 1);

    for (int i = 0; i < mat.size(); i++) {
      mat[i].resize(i + 1);
      mat[i][0] = mat[i][i] = 1;

      for (int j = 1; j < i; j++)
        mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }

    return mat[rowIndex];
  }
};
