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
    bool areEqualTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return areEqualTrees(root1->left, root2->left) && areEqualTrees(root1->right, root2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (areEqualTrees(root, subRoot)) return true;
        if (root) return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return false;
    }
};
