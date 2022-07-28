#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    int zeros, ones;

    for (string s : strs) {
      zeros = count(s.begin(), s.end(), '0');
      ones = s.size() - zeros;
      for (int i = m; i >= zeros; i--) {
        for (int j = n; j >= ones; j--) {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }

    return dp[m][n];
  }
};
