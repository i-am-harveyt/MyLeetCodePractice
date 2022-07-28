#include <map>
#include <string>

using namespace std;

// My way, use std::map
class Solution1 {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    map<char, int> m;
    int size = s.size();
    for (int i = 0; i < size; i++) {
      if (m.find(s[i]) == m.end())
        m[s[i]] = 1;
      else
        m[s[i]]++;
    }
    for (int i = 0; i < size; i++) {
      if (m.find(t[i]) == m.end()) {
        break;
      } else {
        m[t[i]]--;
        if (m[t[i]] == 0)
          m.erase(t[i]);
      }
    }
    if (m.size() == 0)
      return true;
    return false;
  }
};

// The speed 100% way, use an array and detect index
class Solution {
public:
  bool isAnagram(string s, string t) {
    int maps[29] = {
        0,
    };

    for (auto c : s) {
      maps[c - 'a']++;
    }
    for (auto c : t) {
      if (maps[c - 'a'] == 0)
        return false;
      maps[c - 'a']--;
    }

    for (auto map : maps) {
      if (map > 0)
        return false;
    }

    return true;
  }
};
