class Solution {
private:
    void pushSubsets(vector<int> const &nums, int start, int size, vector<int> currentSubset, vector<vector<int>> &s) {
        if (currentSubset.size() == size) {
            s.push_back(currentSubset);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            currentSubset.push_back(nums[i]);
            pushSubsets(nums, i + 1, size, currentSubset, s);
            currentSubset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> s;
        for (int size = 0; size <= nums.size(); size++)
            pushSubsets(nums, 0, size, {}, s); 
        return s;
    }
};
