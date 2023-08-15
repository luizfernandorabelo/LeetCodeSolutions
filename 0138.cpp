/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* makeTrivialCopy(Node* head, map<Node*,Node*> &m) {
        Node* copyHead = new Node(head->val);
        m[head] = copyHead;
        Node* originalCurrent = head->next, *copyCurrent = copyHead;
        while (originalCurrent) {
            Node* newNode = new Node(originalCurrent->val);
            m[originalCurrent] = newNode;
            copyCurrent->next = newNode;
            originalCurrent = originalCurrent->next;
            copyCurrent = copyCurrent->next;
        }
        return copyHead;
    }

    void assignRandomPointers(Node* originalHead, Node* newHead, map<Node*,Node*> &m) {
        while (originalHead) {
            newHead->random = m[originalHead->random];
            originalHead = originalHead->next;
            newHead = newHead->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        map<Node*,Node*> m;  // original -> copy
        Node* newHead = makeTrivialCopy(head, m);
        assignRandomPointers(head, newHead, m);
        return newHead;
    }
};
