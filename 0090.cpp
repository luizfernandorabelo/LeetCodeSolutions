class Solution {
private:
    void pushSubsets(vector<int> const &nums, int start, int size, vector<int> currentSubset, set<vector<int>> &s) {
        if (currentSubset.size() == size) {
            sort(currentSubset.begin(), currentSubset.end());
            s.insert(currentSubset);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            currentSubset.push_back(nums[i]);
            pushSubsets(nums, i + 1, size, currentSubset, s);
            currentSubset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subsets;
        for (int size = 0; size <= nums.size(); size++)
            pushSubsets(nums, 0, size, {}, subsets);
        vector<vector<int>> answer(subsets.begin(), subsets.end());
        return answer;  
    }
};
