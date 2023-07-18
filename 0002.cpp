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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode; 
        ListNode* current = l3;
        int carry = 0;
        while (l1 && l2) {
            current->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            if (l1 || l2) {
                current->next = new ListNode;
                current = current->next;
            }
        }
        while (l1) {
            current->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            if (l1) {
                current->next = new ListNode;
                current = current->next;
            }
        }
        while (l2) {
            current->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            if (l2) {
                current->next = new ListNode;
                current = current->next;
            }
        }
        if (carry) {
            current->next = new ListNode(carry);
        }
        return l3;
    }
};
