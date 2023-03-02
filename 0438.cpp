class Solution {
private:
    map<char,int> buildExpectedMap(string const &p) {
        map<char,int> m;
        for (char c : p)
            m[c]++;
        return m;
    }

    map<char,int> buildComparisonMap(string const &s, string const &p) {
        map<char,int> m;
        for (int i = 0; i < p.length(); i++)
            m[s[i]]++;
        return m;
    }

    bool areMapsEqual(map<char,int> &m1, map<char,int> &m2) {
        for (auto p : m1)
            if (p.second != m2[p.first]) return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.length() > s.length()) return {};
        vector<int> indices;
        map<char,int> expected = buildExpectedMap(p);
        map<char,int> current = buildComparisonMap(s, p);
        if (areMapsEqual(expected, current)) indices.push_back(0);
        for (int left = 0, right = p.length(); right < s.length(); left++, right++) {
            current[s[left]]--;
            current[s[right]]++;
            if (areMapsEqual(expected, current))
                indices.push_back(left+1);
        }
        return indices;
    }
};
