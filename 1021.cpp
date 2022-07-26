#include <stack>
#include <string>

using namespace std;

// my way, ordinal stack
class Solution1 {
public:
  string removeOuterParentheses(string s) {
    stack<int> st;
    string ret = s;
    int removed = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
      } else if (s[i] == ')') {
        if (st.size() == 1) {
          ret.erase(st.top() - removed, 1);
          removed++;
          ret.erase(i - removed, 1);
          removed++;
        }
        st.pop();
      }
    }
    return ret;
  }
};

// they way produced by other one, just consider index
class Solution2 {
public:
  string removeOuterParentheses(string s) {
    int count = 0;
    string res;
    for (char letter : s) {
      if (letter == '(')
        count++;
      if (count > 1)
        res += letter;
      if (letter == ')')
        count--;
    }
    return res;
  }
};
