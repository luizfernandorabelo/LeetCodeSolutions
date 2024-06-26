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
    int getMaxIndex(const vector<int> &nums, int start, int end) {
        int index = start; 
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] > nums[index])
                index = i;
        }
        return index;
    }
    
    TreeNode *buildTree(const vector<int> &nums, int start, int end) {
        if (start > end)
            return nullptr;
        int maxIndex = getMaxIndex(nums, start, end);
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = buildTree(nums, start, maxIndex - 1);
        root->right = buildTree(nums, maxIndex + 1, end);
        return root;
    }
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return buildTree(nums, 0, nums.size() - 1); 
    }
};

