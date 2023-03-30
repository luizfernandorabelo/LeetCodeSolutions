class Solution {
private:
    void pushCombinations(vector<string> &combinations, string current, int openCount, int closeCount, int n) {
        if (openCount > n) return;
        if (openCount == n && closeCount == n) {
            combinations.push_back(current);
        } else if (openCount == closeCount) {
            pushCombinations(combinations, current + "(", openCount + 1, closeCount, n);
        } else if (openCount > closeCount) {
            pushCombinations(combinations, current + "(", openCount + 1, closeCount, n);
            pushCombinations(combinations, current + ")", openCount, closeCount + 1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        pushCombinations(combinations, "", 0, 0, n);
        return combinations;
    }
};
