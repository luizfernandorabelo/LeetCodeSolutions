class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if (m.find(remaining) != m.end())
                return {i, m[remaining]};
            m[nums[i]] = i;
        }
        return {-1, -1}; 
    }
};
