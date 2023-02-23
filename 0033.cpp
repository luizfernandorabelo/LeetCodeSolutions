class Solution {
private:
    int binarySearch(vector<int> const &nums, int target, int start, int end) {
        if (start > end) return -1;
        int center = (start + end) / 2;
        if (nums[start] > nums[end]) {
            if (nums[center] == target) return center;
            int leftIndex = binarySearch(nums, target, start, center - 1);
            if (leftIndex != -1) return leftIndex;
            int rightIndex = binarySearch(nums, target, center + 1, end);
            return rightIndex;
        }
        if (target < nums[center])
            return binarySearch(nums, target, start, center - 1);
        if (target > nums[center])
            return binarySearch(nums, target, center + 1, end);
        return center;
    }
public:
    int search(vector<int> &nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);        
    }
};
