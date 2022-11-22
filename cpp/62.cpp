#include <iostream>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    double ret = 1;

    --m, --n;
    int all = m + n;
    for (int i = 1; i <= n; i++)
      ret *= i, ret /= i;
    for (int i = 1; i <= m; i++)
      ret *= (n + i), ret /= i;

    return static_cast<int>(ret);
  }
};
