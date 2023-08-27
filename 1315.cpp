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
    int evaluateSum(TreeNode* current, TreeNode* parent, TreeNode* grandParent) {
        if (!current) return 0;
        int leftSum = evaluateSum(current->left, current, parent);
        int rightSum = evaluateSum(current->right, current, parent);
        int currentSum = grandParent && grandParent->val % 2 == 0 ? current->val : 0;
        return leftSum + currentSum + rightSum;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        return evaluateSum(root, nullptr, nullptr);
    }
};
