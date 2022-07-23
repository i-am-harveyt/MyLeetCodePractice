/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head->next == nullptr)
      return true;

    // get total size
    int size = 0;
    ListNode *cur = head;
    while (cur) {
      size++;
      cur = cur->next;
    }

    // calculate mid
    int mid;
    bool midIsOdd = true;
    if (size % 2 == 0) {
      mid = size / 2;
      midIsOdd = false;
    } else {
      mid = size / 2 + 1;
    }

    // check
    stack<int> st;
    size = 0;
    cur = head;
    while (cur) {
      size++;
      if (size < mid) { // not mid yet
        st.push(cur->val);
      } else if (size == mid) { // mid
        if (!midIsOdd)
          st.push(cur->val);
      } else { // after mid
        if (cur->val != st.top())
          return false;
        st.pop();
      }
      cur = cur->next;
    }
    return true;
  }
};
