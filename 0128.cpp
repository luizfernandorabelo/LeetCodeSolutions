class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int longestLength = 0;
        unordered_set<int> s(begin(nums), end(nums));
        for (int n : s) {
            if (s.find(n-1) != s.end()) continue;
            int currentLength = 1;
            while (s.find(n + currentLength) != s.end())
                currentLength += 1;
            longestLength = max(longestLength, currentLength);
        }
        return longestLength;
    }
};
