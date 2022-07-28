#include <stack>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> postorder(Node *root) {
    vector<int> ret;
    if (!root)
      return ret;

    stack<Node *> st;
    st.push(root);
    stack<int> sti;
    sti.push(0);
    Node *cur;
    int idx;
    while (!st.empty()) {
      cur = st.top();
      idx = sti.top();
      if (idx == cur->children.size()) {
        ret.push_back(cur->val);
        st.pop();
        sti.pop();
      } else {
        st.push(cur->children[sti.top()++]);
        sti.push(0);
      }
    }

    return ret;
  }
};
