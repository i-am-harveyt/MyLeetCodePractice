#include <string>

using namespace std;

class Solution {
public:
  string removeDuplicates(string s) {
    string ret = "";

    for (int i = 0; i < s.size(); i++) {
      if (ret.size() && s[i] == ret.back())
        ret.pop_back();
      else
        ret += s[i];
    }

    return ret;
  }
};
