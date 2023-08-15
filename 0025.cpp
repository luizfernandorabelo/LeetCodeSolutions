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
ListNode* reverseList(ListNode* head, ListNode* tail) {
    ListNode* current = head, *previous = nullptr, *next = nullptr;
    while (current != tail) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    current->next = previous;
    return current;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode *current = head, *tail = nullptr;
        int length = 0;
        while (current && length < k) {
            tail = current;
            current = current->next;
            length++;
        }
        if (length == k) {
            head = reverseList(head, tail);
            tail = head;
            for (int i = 0; i < k - 1; i++)
                tail = tail->next;
            tail->next = reverseKGroup(current, k);
        }
        return head;
    }
};
