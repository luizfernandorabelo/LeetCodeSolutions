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
    void listToStackRec(ListNode* l, vector<int> &s) {
        if (!l) return;
        s.push_back(l->val);
        listToStackRec(l->next, s);
    }

    vector<int> listToStack(ListNode* l) {
        vector<int> s;
        listToStackRec(l, s);
        return s;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        vector<int> s1 = listToStack(l1);
        vector<int> s2 = listToStack(l2);
        ListNode* previous = new ListNode;
        ListNode* current = new ListNode;
        int carry = 0;
        while (s1.size() && s2.size()) {
            current->val = (s1.back() + s2.back() + carry) % 10;
            carry = (s1.back() + s2.back() + carry) / 10;
            s1.pop_back();
            s2.pop_back();
            if (s1.size() || s2.size()) {
                previous->next = current;
                current = previous;
                previous = new ListNode;
            }
        }
        while (s1.size()) {
            current->val = (s1.back() + carry) % 10;
            carry = (s1.back() + carry) / 10;
            s1.pop_back();
            if (s1.size()) {
                previous->next = current;
                current = previous;
                previous = new ListNode;
            }
        }
        while (s2.size()) {
            current->val = (s2.back() + carry) % 10;
            carry = (s2.back() + carry) / 10;
            s2.pop_back();
            if (s2.size()) {
                previous->next = current;
                current = previous;
                previous = new ListNode;
            }
        }
        if (carry) {
            previous->val = carry;
            previous->next = current;
            return previous;
        }
        return current;
    }
};
