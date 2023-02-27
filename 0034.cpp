class Solution {
    int binarySearch(vector<int> const &nums, int target, int start, int end) {
        if (start > end) return -1;
        int center = (start + end) / 2;
        if (target > nums[center])
            return binarySearch(nums, target, center + 1, end);
        if (target < nums[center])
            return binarySearch(nums, target, start, center - 1);
        return center;
    }
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int foundIndex = binarySearch(nums, target, 0, nums.size() - 1); 
        if (foundIndex == -1)
            return {-1, -1};
        int first = foundIndex, upperBound;
        while (first != -1) {
            upperBound = first - 1;
            first = binarySearch(nums, target, 0, upperBound);
        }
        int last = foundIndex, lowerBound;
        while (last != -1) {
            lowerBound = last + 1;
            last = binarySearch(nums, target, lowerBound, nums.size() - 1);
        }
        return {upperBound + 1, lowerBound - 1};
    }
};
