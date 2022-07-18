#include <iostream>

using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int ret = 0;
    int l, r, n = s.size();
    for (int i = 0; i < n; i++) {
      l = i, r = i;
      while (l > -1 && r < n && s[l] == s[r])
        ret++, l--, r++;
      l = i, r = i + 1;
      while (l > -1 && r < n && s[l] == s[r])
        ret++, l--, r++;
    }
    return ret;
  }
};
