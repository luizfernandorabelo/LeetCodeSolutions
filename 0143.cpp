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
    int evaluateListLength(ListNode* head) {
        return head ? 1 + evaluateListLength(head->next) : 0;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* current = head, *previous = nullptr, *next = nullptr;
        while (current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }

    pair<ListNode*,ListNode*> splitLists(ListNode* head) {
        int n = evaluateListLength(head);
        int steps = n / 2;
        ListNode* current = head;
        for (int i = 1; i <= steps; i++) {
            current = current->next;
        }
        ListNode* l1 = head;
        ListNode* l2 = reverseList(current->next);
        current->next = nullptr;
        return {l1, l2};
    }
public:
    void reorderList(ListNode* head) {
        pair<ListNode*,ListNode*> lists = splitLists(head);  // original first half, reversed second half
        ListNode* l1 = lists.first, *l2 = lists.second, *next1, *next2;
        while (l1 && l2) {
            next1 = l1->next;
            l1->next = l2; 
            next2 = l2->next; 
            l2->next = next1;
            l1 = next1;
            l2 = next2;
        }
    }
};
