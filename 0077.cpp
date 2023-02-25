class Solution {
private:
    void pushCombinations(vector<vector<int>> &combinations, vector<int> currentCombination, int start, int n, int k) {
        if (currentCombination.size() == k) {
            combinations.push_back(currentCombination);
            return;
        }
        for (int i = start; i <= n; i++) {
            currentCombination.push_back(i);
            pushCombinations(combinations, currentCombination, i+1, n, k);
            currentCombination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        pushCombinations(combinations, {}, 1, n, k);
        return combinations;
    }
};
