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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* inputCurrent = head->next;
        ListNode* outputCurrent = nullptr, *outputNext = nullptr, *answer = nullptr;
        while (inputCurrent != nullptr) {
            if (!outputCurrent) {
                outputCurrent = new ListNode;
                answer = outputCurrent;
            } else {
                outputNext = new ListNode;
                outputCurrent->next = outputNext;
                outputCurrent = outputNext;
            }
            while (inputCurrent->val != 0) {
                outputCurrent->val += inputCurrent->val;
                inputCurrent = inputCurrent->next;
            }
            inputCurrent = inputCurrent->next;
        }
        return answer;
    }
};
