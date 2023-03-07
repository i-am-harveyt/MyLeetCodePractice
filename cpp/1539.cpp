#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    int cnt = 0, cur = 0;
    for (int i = 0; i < arr.size(); i++) {
      while (arr[i] != cur + 1) {
        ++cur, ++cnt;
        if (cnt == k)
          return cur;
      }
      ++cur;
    }
    return cur + k - cnt;
  }
};
