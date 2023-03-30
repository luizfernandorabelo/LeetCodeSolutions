/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    string serializeTree(TreeNode* root, map<TreeNode*,string> &serializations) {
        if (!root) return "_";
        string left = serializations[root->left];
        string right = serializations[root->right];
        if (!left.length()) {
            left = serializeTree(root->left, serializations);
            serializations[root->left] = left;
        }
        if (!right.length()) {
            right = serializeTree(root->right, serializations);
            serializations[root->right] = right;
        }
        return to_string(root->val) + "," + left + "," + right;
    }

    void pushDuplicates(vector<TreeNode*> &d, TreeNode* r, map<TreeNode*,string> &s, map<string,int> &o) {
        if (!r) return;
        pushDuplicates(d, r->left, s, o);
        pushDuplicates(d, r->right, s, o);
        string serialized = serializeTree(r, s);
        o[serialized]++;
        if (o[serialized] == 2) d.push_back(r);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        map<TreeNode*,string> serializations;
        map<string,int> occurrences;
        pushDuplicates(duplicates, root, serializations, occurrences);
        return duplicates;
    }
};
