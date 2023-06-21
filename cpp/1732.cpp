class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int max = 0, cur = 0;
    for (auto n : gain) {
      cur += n;
      if (cur > max)
        max = cur;
    }
    return max;
  }
};
