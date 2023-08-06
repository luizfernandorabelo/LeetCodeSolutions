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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* current = new ListNode;
        ListNode* head = current;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else  {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) current->next = l1;
        if (l2)  current->next = l2;
        return head->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            while (lists.size()) {
                ListNode* l1 = nullptr, *l2 = nullptr;
                l1 = lists.back();
                lists.pop_back();
                if (lists.size()) {
                    l2 = lists.back();
                    lists.pop_back();
                } 
                mergedLists.push_back(merge2Lists(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
