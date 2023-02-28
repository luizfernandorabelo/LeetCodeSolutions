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
    ListNode* reverseListRec(ListNode* current, ListNode* previous) {
        if (current == nullptr) return previous;
        ListNode* newRoot = reverseListRec(current->next, current);
        current->next = previous;
        return newRoot;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverseListRec(head, nullptr);
    }
};
