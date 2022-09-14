class Solution {
public:
    TreeNode *buildTree(vector<int> &nums, int start, int end) {
        if (start > end) 
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return buildTree(nums, 0, nums.size() - 1);     
    }
};
