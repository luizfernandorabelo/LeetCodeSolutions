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
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        int n1 = 0, n2 = 0;
        TreeNode* left1 = nullptr, *left2 = nullptr;
        TreeNode* right1 = nullptr, *right2 = nullptr;

        if (root1 != nullptr) {
            n1 = root1->val;    
            left1 = root1->left;
            right1 = root1->right;
        } 

        if (root2 != nullptr) {
            n2 = root2->val;    
            left2 = root2->left;
            right2 = root2->right;
        } 

        if (root1 != nullptr || root2 != nullptr) {
            TreeNode* newRoot = new TreeNode(n1 + n2);
            newRoot->left = mergeTrees(left1, left2);
            newRoot->right = mergeTrees(right1, right2);
            return newRoot;
        } else {
            return nullptr;
        }
    }
};
