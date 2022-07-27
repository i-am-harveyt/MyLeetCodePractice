#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
  int minOperations(vector<string> &logs) {
    stack<string> st;
    for (string s : logs) {
      if (s == "./") {
        continue;
      } else if (s == "../") {
        if (!st.empty())
          st.pop();
      } else {
        st.push(s);
      }
    }
    return st.size();
  }
};

class Solution2 {
public:
  int minOperations(vector<string> &logs) {
    int ret = 0, size = logs.size();

    for (int i = 0; i < size; i++) {
      if (logs[i] == "../") {
        if (ret)
          ret--;
      } else if (logs[i] == "./") {

      } else {
        ret++;
      }
    }

    return ret;
  }
};
