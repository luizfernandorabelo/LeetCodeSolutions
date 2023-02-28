class Solution {
    vector<vector<int>> twoSum(vector<int> const &nums, int target, int start) {
        vector<vector<int>> v;
        int left = start, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] < target) {
                left++;
            } else if (nums[left] + nums[right] > target) {
                right--;
            } else {
                v.push_back({nums[left], nums[right]});
                left++;
                right--;
            }
        }
        return v;
    }
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        set<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() && nums[i] <= 0) {
            int n1 = nums[i];
            vector<vector<int>> v = twoSum(nums, -n1, i+1);
            if (!v.empty()) {
                for (vector<int> triplet : v) {
                    triplet.push_back(n1);
                    triplets.insert(triplet);
                }
            }
            while (i < nums.size() && nums[i] == n1)
                i++;
        }
        vector<vector<int>> answer(triplets.begin(), triplets.end());
        return answer;
    }
};
