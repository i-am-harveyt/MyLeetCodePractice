#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    vector<int> qd;
    vector<int> qr;
    int size = senate.size();
    for (int i = 0; i < size; i++) {
      if (senate[i] == 'R') {
        qr.push_back(i);
      } else {
        qd.push_back(i);
      }
    }
    while (qd.size() > 0 && qr.size() > 0) {
        if (qd[0] < qr[0]) {
            qd.push_back(qd[0] + size);
            qd.erase(qd.begin());
            qr.erase(qr.begin());
        } else {
            qr.push_back(qr[0] + size);
            qd.erase(qd.begin());
            qr.erase(qr.begin());
        }
    }
    if (qd.size() > 0)
        return "Dire";
    return "Radiant";
  }
};
