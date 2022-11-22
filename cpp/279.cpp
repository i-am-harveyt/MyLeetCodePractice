#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * This code can run, but performance is bad,
 * I think I still need some math analysis skill
 */
class Solution {
public:
  int dp(int n, unordered_map<int, int> mp) {
    if (n == 0)
      return 0;
    if (mp.find(n) != mp.end())
      return mp[n];

    mp[n] = n;
    for (int i = 1; i * i < n; i++) {
      int val = dp(n - i * i, mp);
      mp[n] = (mp[n] < val) ? mp[n] : val;
    }
    return mp[n] + 1;
  }

  int numSquares(int n) {
    unordered_map<int, int> mp;
    return dp(n, mp);
  }
};
