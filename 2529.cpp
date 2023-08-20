class Solution {
private:
    int estimateZeroIndex(vector<int> const &nums) {
        int start = 0, end = nums.size() - 1, center;
        while (start <= end) {
            center = (start + end) / 2;
            if (0 > nums[center]) start = center + 1;
            else if (0 < nums[center]) end = center - 1;
            else break;
        }
        return center;
    }
public:
    int maximumCount(vector<int> &nums) {
        int zeroIndex = estimateZeroIndex(nums);
        int left = zeroIndex, right = zeroIndex;
        while (left >= 0 && nums[left] >= 0) left--;
        while (right < nums.size() && nums[right] <= 0) right++;
        return max((unsigned long) left + 1, nums.size() - right);
    }
};
