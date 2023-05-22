
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return nullptr;
    ListNode *n{headA}, *m{headB};
    int cnt{0};
    while (cnt < 3) {
      if (!n)
        n = headB, ++cnt;
      if (!m)
        m = headA, ++cnt;
      if (n == m)
        return n;
      n = n->next, m = m->next;
    }
    return nullptr;
  }
};
