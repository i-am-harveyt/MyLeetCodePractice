#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *clone(unordered_map<int, Node *> &mem, Node *n) {
    if (!n)
      return nullptr;
    if (mem.find(n->val) != mem.end())
      return mem[n->val];

    mem[n->val] =
        new Node(n->val, vector<Node *>(n->neighbors.size(), nullptr));
    for (int i = 0; i < n->neighbors.size(); i++)
      mem[n->val]->neighbors[i] = clone(mem, n->neighbors[i]);

    return mem[n->val];
  }

  Node *cloneGraph(Node *node) {
    unordered_map<int, Node *> mem;
    return clone(mem, node);
  }
};
