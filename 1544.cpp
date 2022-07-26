#include <string>

using namespace std;

class Solution1 {
public:
  string makeGood(string s) {
    string ret = "";
    for (auto &c : s) {
      if (isupper(ret.back())) {
        if (tolower(ret.back()) == c)
          ret.pop_back();
        else
          ret += c;
      } else {
        if (toupper(ret.back()) == c)
          ret.pop_back();
        else
          ret += c;
      }
    }
    return ret;
  }
};

class Solution2 {
public:
  string makeGood(string s) {
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
      if (ans.size() != 0 && abs(s[i] - ans.back()) == 32) {
        ans.pop_back();
      } else {
        ans.push_back(s[i]);
      }
    }
    return ans;
  }
};
