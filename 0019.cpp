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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* shiftedNode = head;
        for (int i = 0; i < n; i++)
            shiftedNode = shiftedNode->next;
        ListNode* headPointer = new ListNode(0, head);
        ListNode* currentNode = headPointer;
        while (shiftedNode != nullptr) {
            currentNode = currentNode->next;
            shiftedNode = shiftedNode->next;
        }
        currentNode->next = currentNode->next->next;
        return headPointer->next;
    }
};

