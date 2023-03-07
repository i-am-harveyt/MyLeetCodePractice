#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string replaceWords(vector<string> &d, string s) {
    char *cs = new char[s.length() + 1];
    cs[s.length()] = '\0';
    for (int i = 0; i < s.length(); i++)
      cs[i] = s[i];
    vector<string> tokens;
    for (char *tok = strtok(cs, " "); tok != nullptr;
         tok = strtok(nullptr, " "))
      tokens.push_back(string(tok));

    string ret = "";
    for (int i = 0; i < tokens.size(); i++) {
      for (int j = 0; j < d.size(); j++) {
        auto re = mismatch(d[j].begin(), d[j].end(), tokens[i].begin());
        if (re.first == d[j].end())
          tokens[i] = d[j];
      }
    }
    for (int i = 0; i < tokens.size(); i++) {
      if (ret.size() != 0)
        ret += " ";
      ret += tokens[i];
    }
    return ret;
  }
};
