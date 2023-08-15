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
    bool hasCycle(ListNode *head) {
        // set<ListNode*> insertedNodes;       
        // while (head) {
        //     if (insertedNodes.contains(head))
        //         return true;
        //     insertedNodes.insert(head);
        //     head = head->next;
        // }
        // return false;
        ListNode* slow = head, *fast = head ? head->next : nullptr;
        while (true) {
            if (!fast || !fast->next) return false;
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
        }
        return false;
    }
};
