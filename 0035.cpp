class Solution {
private:
    int binarySearch(vector<int> &nums, int target, int left, int right) {
        int center = (left + right) / 2;
        if (left >= right)
            return target > nums[center] ? center + 1 : center;
        if (target > nums[center])
            return binarySearch(nums, target, center + 1, right);
        if (target < nums[center])
            return binarySearch(nums, target, left, center - 1);
        return center;
    }

public:
    int searchInsert(vector<int> &nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
