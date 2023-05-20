class Solution {
public:
    int jump(vector<int> &nums) {
        int jumpsCount = 0;
        int left = 0, right = 0;
        while (right < nums.size() - 1) {
            int maxAchievingIndex = 0;
            for (int i = left; i <= right; i++)
                maxAchievingIndex = max(maxAchievingIndex, i + nums[i]);
            left = right + 1;
            right = maxAchievingIndex;
            jumpsCount++;
        }
        return jumpsCount;
    }
};
