class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        long long start = 0, end = nums.size() - 1, center;
        while (start <= end) {
            center = (start + end) / 2;
            long long leftValue = center > 0 ? nums[center-1] : - LONG_MAX;
            long long rightValue = center < nums.size() - 1 ? nums[center+1] : LONG_MAX;
            if (leftValue < nums[center] && rightValue < nums[center])
                break;
            if (leftValue < nums[center] && nums[center] < rightValue)
                start = center + 1;
            else
                end = center - 1; 
        }
        return center;
    }
};
