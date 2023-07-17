class Solution {
public:
    bool canJump(vector<int> &nums) {
        int endIdx = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
            if (i + nums[i] >= endIdx)
                endIdx = i;
        return endIdx == 0;
    }
};
