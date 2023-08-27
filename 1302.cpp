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
    int evaluateTreeDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = evaluateTreeDepth(root->left);
        int rightDepth = evaluateTreeDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int sumDeepestLeaves(TreeNode* root, int currentDepth, int maxDepth) {
        if (!root) return 0;
        if (currentDepth == maxDepth) return root->val;
        int leftSum = sumDeepestLeaves(root->left, currentDepth + 1, maxDepth);
        int rightSum = sumDeepestLeaves(root->right, currentDepth + 1, maxDepth);
        return leftSum + rightSum;

    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int treeDepth = evaluateTreeDepth(root); 
        return sumDeepestLeaves(root, 1, treeDepth);
    }
};
