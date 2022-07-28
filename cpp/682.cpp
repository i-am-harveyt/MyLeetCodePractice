#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int calPoints(vector<string> &ops) {
    vector<int> st;
    for (string str : ops) {
      if (str == "+") {
        st.push_back(st[st.size() - 1] + st[st.size() - 2]);
      } else if (str == "D") {
        st.push_back(st[st.size() - 1] * 2);
      } else if (str == "C") {
        st.pop_back();
      } else {
        st.push_back(stoi(str));
      }
    }

    int ret = 0;
    for (int num : st)
      ret += num;
    return ret;
  }
};
