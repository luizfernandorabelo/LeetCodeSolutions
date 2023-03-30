class Solution {
private:
    void pushCombinations(vector<vector<int>> &combinations, vector<int> const &candidates, int start, vector<int> &current, int target) {
        if (target < 0) return;
        if (target == 0) {
            combinations.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            pushCombinations(combinations, candidates, i, current, target - candidates[i]);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> current;
        pushCombinations(combinations, candidates, 0, current, target);
        return combinations;
    }
};
