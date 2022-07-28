#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> vec(n, vector<int>(n, 0));

    int count = 1, row = 0, col = 0, rowLB = 0, rowUB = n, colLB = -1,
        colUB = n - 1, horiMov = 1, vertMov = 0;

    while (count <= n * n) {
      vec[row][col] = count++;
      if (col == colLB && row == rowLB) {
        horiMov = 1, vertMov = 0;
      } else if (col == colLB && row == rowUB) {
        rowLB++, colUB--;
        horiMov = 0, vertMov = -1;
      } else if (col == colUB && row == rowLB) {
        rowUB--, colLB++;
        horiMov = 0, vertMov = 1;
      } else if (col == colUB && row == rowUB) {
        horiMov = -1, vertMov = 0;
      }
      row += vertMov, col += horiMov;
    }

    return vec;
  }
};
