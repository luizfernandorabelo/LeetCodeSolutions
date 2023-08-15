#define NOT_FOUND -1

class Node {
public:
    int key, value;
    Node* next;
    Node* previous;

    Node(int k, int v) : key(k), value(v), next(nullptr), previous(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    Node *least, *last;
    unordered_map<int,Node*> m;

    void insertNode(Node* node) {
        node->next = last;
        node->previous = last->previous;
        this->last->previous->next = node;
        this->last->previous = node;
    }

    void removeNode(Node* node) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->least = new Node(0, 0);
        this->last = new Node(0, 0);
        this->least->next = last;
        this->last->previous = least;
    }
    
    int get(int key) {
        if (this->m.find(key) == this->m.end()) return NOT_FOUND;
        Node* retrieved = this->m[key];
        removeNode(retrieved);
        insertNode(retrieved);
        return retrieved->value;
    }
    
    void put(int key, int value) {
        if (this->m.find(key) != this->m.end()) {
            Node* updated = this->m[key];
            removeNode(updated);
            delete updated;
        } 
        Node* inserted = new Node(key, value);
        insertNode(inserted);
        this->m[key] = inserted;
        if (this->m.size() > this->capacity) {
            Node* removed = least->next;
            removeNode(removed);
            this->m.erase(removed->key);
            delete removed;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
