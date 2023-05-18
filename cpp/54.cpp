#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret(matrix.size() * matrix[0].size(), 0);
    size_t idx = 0;
    size_t l = 0, r = matrix[0].size(), u = 0, d = matrix.size();
    bool right = true, down = false;
    while (true) {
      while (l <= r) {
      }
      while (u <= d) {
      }
    }

    return ret;
  }
};
