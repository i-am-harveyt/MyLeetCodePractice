#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int getMaximumGenerated(int n) {

    if (n == 0)
      return 0;

    ++n;
    vector<int> vec(n, 0);
    vec[1] = 1;

    int ret = 1;
    for (int i = 2; i < n; i++) {
      if (i % 2)
        vec[i] = vec[i / 2] + vec[i / 2 + 1];
      else
        vec[i] = vec[i / 2];
      if (vec[i] > ret)
        ret = vec[i];
    }

    return ret;
  }
};
