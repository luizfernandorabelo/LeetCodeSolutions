class Solution {
private:
    void setMin(vector<int> const &nums, int start, int end, int &currentMin) {
        if (start > end) return;
        int center = (start + end) / 2;
        if (start == end || nums[start] <= nums[end])
            currentMin = min(currentMin, nums[start]);
        else if (nums[center] <= nums[end])
            setMin(nums, start + 1, center, currentMin);
        else
            setMin(nums, center + 1, end, currentMin);
    }
public:
    int findMin(vector<int> &nums) {
        int foundMin = INT_MAX;
        setMin(nums, 0, nums.size() - 1, foundMin);
        return foundMin;
    }
};
