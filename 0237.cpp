/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* previous;
        while (node->next) {
            node->val = node->next->val;
            previous = node;
            node = node->next;
        }
        previous->next = nullptr;
    }
};
