class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> usedChars;
        int left = 0, maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (usedChars.count(s[i])) {
                while (s[left] != s[i]) {
                    usedChars.erase(s[left]);
                    left++;
                }
                left++;
            } else {
                usedChars.insert(s[i]);
                maxLength = max(i - left + 1, maxLength);
            }
        }
        return maxLength;
    }
};
