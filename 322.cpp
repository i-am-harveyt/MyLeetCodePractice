#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;
    vector<int> dp = vector<int>(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
      for (int coin : coins)
        if (i - coin < 0)
          continue;
        else
          dp[i] = min(dp[i], dp[i - coin] + 1);
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
