#include <string>

using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int lc = 0, rc = 0, size = s.size(), ret = 0;
    for (int i = 0; i < size; i++) {
      if (s[i] == '(')
        lc++;
      else if (s[i] == ')')
        rc++;
      if (lc - rc > ret)
        ret = lc - rc;
    }
    return ret;
  }
};
