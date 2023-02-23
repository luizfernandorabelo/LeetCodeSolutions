class Solution {
private:
    void pushPermutations(vector<string> &permutations, string current, string const &s) {
        int currLength = current.length();
        if (currLength == s.size()) {
            permutations.push_back(current);
            return;
        }
        if (s[currLength] != tolower(s[currLength]))
            pushPermutations(permutations, current + (char) tolower(s[currLength]), s);
        else if (s[currLength] != toupper(s[currLength]))
            pushPermutations(permutations, current + (char) toupper(s[currLength]), s);
        pushPermutations(permutations, current + s[currLength], s);
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> permutations;
        pushPermutations(permutations, "", s);
        return permutations;
    }
};
