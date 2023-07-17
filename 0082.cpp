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
private:
    ListNode* getNext(ListNode* current) {
        if (!current->next || current->next->val != current->val) return current;
        int currentVal = current->val;
        while (current->next && current->next->val == currentVal)
            current = current->next;
        return current->next ? getNext(current->next) : nullptr;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* newHead = getNext(head);
        if (newHead) newHead->next = deleteDuplicates(newHead->next);
        return newHead;
     }
};
