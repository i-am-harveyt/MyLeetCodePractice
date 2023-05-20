#include <string>

using namespace std;

class Solution {
public:
  bool detectCapitalUse(string word) {
    size_t cnt = 0;
    for (auto c : word)
      if (c >= 'A' && c <= 'Z')
        ++cnt;
    return cnt == word.length() || cnt == 0 ||
           (cnt == 1 && word[0] >= 'A' && word[0] <= 'Z');
  }
};
