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
private:
    void makeConnections(Node* currentChild, Node* &nextChild, Node* &previous) {
        if (!currentChild) return;
        if (!nextChild) nextChild = currentChild;
        if (previous) previous->next = currentChild;
        previous = currentChild;
    }
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* nextChild = root;
        while (nextChild) {
            Node* current = nextChild;
            Node* previous = nullptr;
            nextChild = nullptr;
            while (current) {
                makeConnections(current->left, nextChild, previous);
                makeConnections(current->right, nextChild, previous);
                current = current->next;
            }
        }
        return root;
    }
};
