#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    vector<int> tmp(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
      tmp[i] = nums[(k + i) % nums.size()];
    nums = tmp;
  }
};
