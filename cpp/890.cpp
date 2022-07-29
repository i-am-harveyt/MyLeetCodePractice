#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    map<char, char> p2s, s2p;
    int size = pattern.size(), i;
    vector<string> ret;
    for (string s : words) {
      for (i = 0; i < size; i++) {
        if (s2p.find(s[i]) == s2p.end() && p2s.find(pattern[i]) == p2s.end()) {
          s2p[s[i]] = pattern[i];
          p2s[pattern[i]] = s[i];
          continue;
        }
        if (s2p[s[i]] != pattern[i] || p2s[pattern[i]] != s[i])
          break;
      }
      if (i == size)
        ret.push_back(s);
      p2s.clear(), s2p.clear();
    }
    return ret;
  }
};
