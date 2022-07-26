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
  void rec(Node *cur, vector<int> &ret) {
    for (Node *child : cur->children)
      rec(child, ret);
    ret.push_back(cur->val);
  }
  vector<int> postorder(Node *root) {
    vector<int> ret;
    if (!root)
      return ret;
    rec(root, ret);
    return ret;
  }
};
