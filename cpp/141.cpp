
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *x{head}, *y{head};
    while (x != nullptr && y != nullptr) {
      if (y->next)
        y = y->next->next;
      else
        break;
      x = x->next;
      if (x == y)
        return true;
    }
    return false;
  }
};
