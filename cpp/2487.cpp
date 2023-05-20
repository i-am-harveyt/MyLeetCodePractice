#include <vector>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    if (!head)
      return nullptr;
    std::vector<ListNode *> ms; // monotonic stack
    ListNode *cur = head;

    while (cur) {

      // if the property will be break if cur node push into
      while (ms.size() && cur->val > ms.back()->val)
        ms.pop_back();

      ms.push_back(cur);
      cur = cur->next;
    }
    // link them
    for (size_t i = 0; i < ms.size() - 1; i++)
      ms[i]->next = ms[i + 1];
    ms.back()->next = nullptr;
    return ms[0];
  }
};
