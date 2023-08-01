class Solution {
private:
    int rob1(vector<int> const &nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if (n > 1) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        return dp[n-1];
    }
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> v1(nums.begin() + 1, nums.end());
        vector<int> v2(nums.begin(), nums.end() - 1);
        return max(rob1(v1), rob1(v2));
    }
};
