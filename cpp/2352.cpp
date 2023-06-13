#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>> &grid) {
    unordered_map<unsigned int, vector<size_t>> mp;
    for (size_t i = 0; i < grid.size(); i++) {
      int val{0};
      for (size_t j = 0; j < grid[0].size(); j++)
        val += grid[i][j];
      if (mp.find(val) != mp.end())
        mp[val].push_back(i);
      else
        mp[val] = vector<size_t>({i});
    }

    int ret = 0;
    for (size_t i = 0; i < grid[0].size(); i++) {
      int val{0};
      for (size_t j = 0; j < grid.size(); j++)
        val += grid[j][i];
      if (mp.find(val) == mp.end())
        continue;

      for (size_t j = 0; j < mp[val].size(); j++) {
        size_t k = 0;
        for (; k < grid.size(); k++)
          if (grid[k][i] != grid[mp[val][j]][k])
            break;
        if (k == grid.size())
          ret++;
      }
    }

    return ret;
  }
};
