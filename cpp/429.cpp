#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vector<int>> ret;
      if (!root)
          return ret;

      queue<Node *> q;
      q.push(root);
      while (!q.empty()) {
          int size = q.size();
          ret.push_back(vector<int>());
          while (size) {
              Node *cur = q.front();
              ret.back().push_back(cur->val);
              int children = cur->children.size();
              int cnt = 0;
              while (cnt < children)
                  q.push(cur->children[cnt++]);
              q.pop();
              size--;
          }
      }

      return ret;
    }
};
