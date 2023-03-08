#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    long long lb = 0, ub = LONG_LONG_MAX, ret;
    while (ub >= lb) {
      long long mid = lb + (ub - lb) / 2;
      unsigned long long cnt = 0;
      for (int i = 0; i < time.size(); i++)
        cnt += mid / static_cast<long long>(time[i]);
      if (cnt >= totalTrips)
        ret = mid, ub = mid - 1;
      else
        lb = mid + 1;
    }
    return ret;
  }
};
