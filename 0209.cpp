class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, right = 0;
        int minLen = INT_MAX, currentSum = 0;
        while (right < nums.size()) {
            currentSum += nums[right];
            while (currentSum >= target && left <= right) {
                minLen = min(minLen, right - left + 1);
                currentSum -= nums[left];
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
