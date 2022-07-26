#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    string push = "Push", pop = "Pop";
    vector<string> ret;

    int size = target.size(), idx = 0;
    for (int i = 1; i <= n; i++) {
      if (idx == size)
        break;
      if (i == target[idx]) {
        ret.push_back(push);
        idx++;
      } else {
        ret.push_back(push);
        ret.push_back(pop);
      }
    }

    return ret;
  }
};
