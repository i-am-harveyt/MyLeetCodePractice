#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    unordered_map <int, Node*> table;

    void func(Node *root, int layer) {
        if (root == NULL) return;
        if (table.find(layer) == table.end()) root->next = NULL;
        else root->next = table[layer];
        table[layer] = root;
        func(root->right, layer+1);
        func(root->left, layer+1);
        return;
    }

    Node *connect(Node *root) {
      func(root, 1);
      return root;
    }
};
