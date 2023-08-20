class Solution {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        vector<int> indices;
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1, center;
        while (start <= end) {
            center = (start + end) / 2;
            if (target > nums[center]) start = center + 1;
            else if (target < nums[center]) end = center - 1;
            else break;
        }
        while (center >= 0 && nums[center] == target) center--;
        for (int i = center + 1; i < nums.size(); i++) {
            if (nums[i] != target) break;
            indices.push_back(i);
        }
        return indices;
    }
};
