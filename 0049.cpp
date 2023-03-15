class Solution {
private:
    vector<int> buildCharCountMap(string const &s) {
        vector<int> m(26, 0);
        for (char c : s)
            m[c-'a']++;
        return m;
    }

    vector<vector<string>> extractAnagrams(map<vector<int>,vector<string>> const &groups) {
        vector<vector<string>> anagrams;
        for (auto p : groups)
            anagrams.push_back(p.second);
        return anagrams;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> groups;
        for (string s : strs) {
            vector<int> charCountM = buildCharCountMap(s);
            groups[charCountM].push_back(s);
        }
        return extractAnagrams(groups);
    }
};
