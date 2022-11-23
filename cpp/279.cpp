#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * This code can run, but performance is bad,
 * I think I still need some math analysis skill
 */
class SolutionOld {
public:
  int dp(int n, unordered_map<int, int> &mp) {
    if (n == 0)
      return 0;
    if (mp.find(n) != mp.end())
      return mp[n];

    mp[n] = n;
    for (int i = 1; i * i <= n; i++) {
      int val = dp(n - i * i, mp);
      mp[n] = (mp[n] < val) ? mp[n] : val;
    }
    ++mp[n];
    return mp[n];
  }

  int numSquares(int n) {
    unordered_map<int, int> mp;
    dp(n, mp);
    return mp[n];
  }
};

// interative method
class Solution {
public:
  int numSquares(int n) {
    vector<int> arr(n + 1);
    for (int i = 0; i < arr.size(); i++)
      arr[i] = i;

    for (int i = 0; i <= n; i++)
      for (int j = 1; j * j <= i; j++)
        if (arr[i - j * j] + 1 < arr[i])
          arr[i] = arr[i - j * j] + 1;

    return arr[n];
  }
};
