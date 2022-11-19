#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {

    vector<int> vec(n + 1, 0);

    for (int i = 0; i < trust.size(); i++) {
      vec[trust[i][0]] = trust[i][1];
      --vec[trust[i][1]];
    }

    int everyoneExcept = -(n - 1);
    for (int i = 1; i <= n; i++)
      if (vec[i] == everyoneExcept)
        return i;

    return -1;
  }
};
