class Solution {
private:
    map<char,int> buildExpectedCounts(string const &t) {
        map<char,int> m;
        for (char c : t)
            m[c]++;
        return m;
    }

    string buildStringWindow(string const &s, int start, int end) {
        string window = "";
        for (int i = start; i <= end; i++)
            window += s[i];
        return window;
    }
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return ""; 
        map<char,int> expectedMap = buildExpectedCounts(t);
        map<char,int> currentMap;
        int requiredLetters = expectedMap.size(), obtainedLetters = 0;
        int left = 0, windowStart = 0, windowEnd = -1, minLength = 100001;
        string window = "";
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            currentMap[c]++;
            if (expectedMap[c] != 0 && currentMap[c] == expectedMap[c]) {
                obtainedLetters++;
            }
            while (obtainedLetters == requiredLetters) {
                int newLength = right - left + 1;
                if (newLength < minLength) {
                    minLength = newLength;
                    windowStart = left;
                    windowEnd = right;
                }
                char c = s[left];
                currentMap[c]--;
                if (expectedMap[c] != 0 && currentMap[c] < expectedMap[c]) {
                    obtainedLetters--;
                }
                left++;
            }
        }
        return buildStringWindow(s, windowStart, windowEnd);
    }
};
