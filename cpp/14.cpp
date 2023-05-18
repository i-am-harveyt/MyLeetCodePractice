#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1)
      return strs[0];

    std::sort(strs.begin(), strs.end());

    for (size_t i = 0; i < strs[0].size(); i++)
      if (strs.front()[i] != strs.back()[i])
        return std::string(strs.front().begin(), strs.front().begin() + i);
    return strs.front();
  }
};

int main(void) {}
