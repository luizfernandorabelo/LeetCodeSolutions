class Solution {
private:
    int countOccurrences(vector<int> const &v, int start) {
        int end = start + 1;
        while (end < v.size() && v[end] == v[start]) end++;
        return end - start;
    }
    
    void pushCombinations(vector<vector<int>> &combinations, vector<int> const &candidates, int start, vector<int> &current, int target) {
        if (target < 0) return;
        if (target == 0) {
            combinations.push_back(current);
            return;
        }
        int i = start;
        while (i < candidates.size()) {
            current.push_back(candidates[i]);
            pushCombinations(combinations, candidates, i + 1, current, target - candidates[i]);
            current.pop_back();
            i += countOccurrences(candidates, i);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> combinations;
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        pushCombinations(combinations, candidates, 0, current, target);
        return combinations;
    }
};
