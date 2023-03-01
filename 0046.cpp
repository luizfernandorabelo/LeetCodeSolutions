class Solution {
private:
    void pushPermutations(vector<vector<int>> &permutations, vector<int> &nums, vector<int> &current, set<int> &s) {
        if (current.size() == nums.size()) {
            permutations.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) == s.end()) {
                current.push_back(nums[i]);        
                s.insert(nums[i]);
                pushPermutations(permutations, nums, current, s);
                s.erase(nums[i]);
                current.pop_back();        
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> current; set<int> s;
        pushPermutations(permutations, nums, current, s);
        return permutations;
    }
};

