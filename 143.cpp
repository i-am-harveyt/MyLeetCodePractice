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
    void reorderList(ListNode* head) {
        if (!head->next)
            return;
        deque<ListNode *> dq;
        ListNode *cur = head;
        while (cur != nullptr) {
            dq.push_back(cur);
            cur = cur -> next;
        }
        
        int count = 0;
        ListNode *next;
        cur = dq.front();
        dq.pop_front();
        while (!dq.empty()) {
            if (count % 2 == 0) {
                next = dq.back();
                dq.pop_back();
            } else {
                next = dq.front();
                dq.pop_front();
            }
            cur->next = next;
            cur = cur->next;
            cur->next = nullptr;
            count++;
        }
        
    }
};
