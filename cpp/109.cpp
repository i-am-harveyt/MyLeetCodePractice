#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *build(vector<int> &arr, int l, int r) {
    if (l > r)
      return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = build(arr, l, mid - 1);
    root->right = build(arr, mid + 1, r);
    return root;
  }
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head)
      return nullptr;
    vector<int> arr;
    for (ListNode *cur = head; cur; cur = cur->next)
      arr.push_back(cur->val);
    int size = arr.size();
    return build(arr, 0, size - 1);
  }
};
