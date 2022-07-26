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

// This is the solution I've come up with: maintain a stack to store index
class Solution1 {
public:
  vector<int> preorder(Node *root) {
    vector<int> ret;
    if (!root)
      return ret;

    stack<Node *> stn;
    stn.push(root);
    stack<int> sti;
    sti.push(0);

    Node *cur;
    int idx;
    while (!stn.empty()) {
      cur = stn.top();
      idx = sti.top();
      if (idx == 0)
        ret.push_back(cur->val);
      if (idx < cur->children.size()) {
        stn.push(cur->children[idx]);
        sti.top()++;
        sti.push(0);
      } else {
        stn.pop();
        sti.pop();
      }
    }

    return ret;
  }
};

// This is the way I saw written by other one,
// it is clever to just push all children in reverse order.
// In my opinion, it is clear and simple, however,
// it seems that it might require a large space to make sure that the
// stack is large enought to contain all nodes.
class Solution2 {
public:
  vector<int> preorder(Node *root) {
    vector<int> sol;

    if (!root) {
      return sol;
    }

    stack<Node *> stk;
    stk.push(root);

    while (!stk.empty()) {
      Node *curr = stk.top();
      stk.pop();
      sol.push_back(curr->val);

      for (int i = curr->children.size() - 1; i >= 0; i--) {
        stk.push(curr->children[i]);
      }
    }
    return sol;
  }
};
