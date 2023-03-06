/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* parent = root;
        Node* nextChild = root->left;
        while (parent && nextChild) {
            parent->left->next = parent->right;
            if (parent->next) {
                parent->right->next = parent->next->left;
            }
            parent = parent->next;
            if (!parent) {
                parent = nextChild;
                nextChild = parent->left;
            }
        }
        return root;
    }
};
