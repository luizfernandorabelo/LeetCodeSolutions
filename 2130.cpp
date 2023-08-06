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
        if (!head) return 0;
        return 1 + evaluateListLength(head->next);
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

    int evaluateMaxPairSum(ListNode* head1, ListNode* head2) {
        int maximum = -1;
        while (head1 && head2) {
            maximum = max(maximum, head1->val + head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }
        return maximum;
    }
public:
    int pairSum(ListNode* head) {
        int n = evaluateListLength(head);
        ListNode *secondHalfHead = head;
        for (int i = 0; i < n / 2; i++) {
            secondHalfHead = secondHalfHead->next;
        }
        return evaluateMaxPairSum(head, reverseList(secondHalfHead));
    }
};
