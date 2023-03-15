class Solution {
private:
    map<char,int> buildCharCountMap(string const &s) {
        map<char,int> m;
        for (char c : s)
            m[c]++;
        return m;
    }

    bool areMapsEqual(map<char,int> &m1, map<char,int> &m2) {
        for (auto p : m1)
            if (m2[p.first] != p.second) return false;
        return true;
    }
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length()) return false;
        map<char,int> sMap = buildCharCountMap(s);
        map<char,int> tMap = buildCharCountMap(t);
        return areMapsEqual(sMap, tMap);
    }
};
