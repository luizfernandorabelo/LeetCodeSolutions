#define EMPTY '-'

struct Node {
    vector<char> keys;
    vector<Node*> children;
    vector<bool> isEnd;
    Node() : keys(26,EMPTY), children(26,nullptr), isEnd(26,false) {}
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node; 
    }
    
    void insert(string word) {
        Node *current = root;
        for (int i = 0; i < word.length() - 1; i++) {
            char c = word[i];
            current->keys[c-'a'] = c;
            if (!current->children[c-'a']) current->children[c-'a'] = new Node;
            current = current->children[c-'a'];
        }
        char lastC = word[word.length() - 1];
        current->keys[lastC-'a'] = lastC;
        current->isEnd[lastC-'a'] = true;
    }
    
    bool search(string word) {
        Node *current = root;
        for (int i = 0; i < word.length() - 1; i++) {
            char c = word[i];
            if (current->keys[c-'a'] != c) return false;
            if (!current->children[c-'a']) return false;
            current = current->children[c-'a'];
        }
        char lastC = word[word.length() - 1];
        return current->keys[lastC-'a'] != EMPTY && current->isEnd[lastC-'a'];
    }
    
    bool startsWith(string prefix) {
        Node *current = root;
        for (int i = 0; i < prefix.length() - 1; i++) {
            char c = prefix[i];
            if (current->keys[c-'a'] != c) return false;
            if (!current->children[c-'a']) return false;
            current = current->children[c-'a'];
        }
        char lastC = prefix[prefix.length() - 1];
        return current->keys[lastC-'a'] != EMPTY;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
