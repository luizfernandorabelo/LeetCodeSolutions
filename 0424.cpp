class Solution {
private:
    int getMostFrequentCount(map<char,int> &occurrences) {
        int maxOccurrence = 0;
        for (char c = 'A'; c <= 'Z'; c++) 
            maxOccurrence = max(maxOccurrence, occurrences[c]);
        return maxOccurrence;
    }
public:
    int characterReplacement(string s, int k) {
        if (!s.length()) return 0;
        int start = 0, maxLength = 0;
        map<char,int> occurrences;
        for (int end = 0; end < s.length(); end++) {
            occurrences[s[end]]++;
            int mostFrequentCount = getMostFrequentCount(occurrences);
            int currentLength = end - start + 1;
            int replacements = currentLength - mostFrequentCount; 
            if (replacements <= k) {
                maxLength = max(maxLength, currentLength);
            } else {
                while (start < end && replacements > k) {
                    occurrences[s[start]]--;
                    start++;
                    currentLength--;
                    mostFrequentCount = getMostFrequentCount(occurrences);
                    replacements = currentLength - mostFrequentCount;
                }
            }
        }
        return maxLength;
    }
};
