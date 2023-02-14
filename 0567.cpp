class Solution {
private:
    map<char,int> buildBaseStringMap(string const &s1) {
        map<char,int> m;
        for (char c : s1)
            m[c]++;
        return m;
    }

    map<char,int> buildInitialPermutationMap(string const &s2, int s1Length) {
        map<char,int> m;
        for (int i = 0; i < s1Length; i++)
            m[s2[i]]++;
        return m;
    }

    bool areEqual(map<char,int> &m1, map<char,int> &m2) {
        for (int i = 0; i < 26; i++)
            if (m1[i + 'a'] != m2[i + 'a']) return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        map<char,int> m1 = buildBaseStringMap(s1);
        map<char,int> m2 = buildInitialPermutationMap(s2, s1.length());
        int left = 0, right = s1.length() - 1;
        while (right < s2.length())  {
            if (areEqual(m1, m2)) return true;
            m2[s2[left]]--;
            left++;
            right++;
            m2[s2[right]]++;
        }
        return false;
    }
};
