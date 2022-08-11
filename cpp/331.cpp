#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSerialization(string preorder) {
    int size = preorder.size();
    if (size == 1 && preorder[0] == '#')
        return true;
    vector<int> valid;
    for (int i = 0; i < size; i++) {
      // cout << preorder[i] << " " << valid.size();
      // if (valid.size() > 0)
      //   cout << " " << valid.back() << endl;
      // else
      //   cout << endl;
      if (preorder[i] == ',')
        continue;
      else if (preorder[i] == '#') {
        if (valid.size() == 0)
          return false;
        valid.back()--;
        if (valid.back() == 0)
          valid.pop_back();
        if (valid.size() == 0 && i != size-1)
            return false;
      } else {
        if (valid.size() > 0) {
          valid.back()--;
          if (valid.back() == 0)
            valid.pop_back();
        }
        valid.push_back(2);
        while (i < size && preorder[i] != ',')
          i++;
      }
    }
    if (valid.size() == 0)
      return true;
    return false;
  }
};
