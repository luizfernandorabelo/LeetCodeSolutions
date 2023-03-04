class Solution {
private:
    vector<int> buildLongestPreffixSuffixArray(string const &needle) {
        vector<int> lps(needle.length(), 0);
        int preffixIdx = 0, suffixIdx = 1;
        while (suffixIdx < needle.length()) {
            if (needle[preffixIdx] == needle[suffixIdx]) {
                lps[suffixIdx] = preffixIdx + 1;
                preffixIdx++;
                suffixIdx++;
            } else if (preffixIdx != 0) {
                preffixIdx = lps[preffixIdx - 1];
            } else {
                suffixIdx++;
            }
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;
        if (needle.length() == 0) return 0;
        vector<int> lps = buildLongestPreffixSuffixArray(needle);
        int i = 0, j = 0;
        while (i < haystack.length()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
            if (j == needle.length()) {
                return i - needle.length();
            } 
        }
        return -1;
    }
};
