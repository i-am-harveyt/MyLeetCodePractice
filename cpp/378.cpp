#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < matrix.size(); i++)
      for (int j = 0; j < matrix[i].size(); j++)
        minH.push(matrix[i][j]);
    for (;k>1;k--)
        minH.pop();
    return minH.top();
  }
};
