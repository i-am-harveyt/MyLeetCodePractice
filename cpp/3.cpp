#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ret = 0;
    int l = -1, r = 0;
    unordered_set<char> seen;
    while (r < s.size()) {
      while (seen.find(s[r]) != seen.end())
        seen.erase(s[++l]);
      r - l > ret ? ret = r - l : ret = ret;
      seen.insert(s[r++]);
    }
    return ret;
  }
};
