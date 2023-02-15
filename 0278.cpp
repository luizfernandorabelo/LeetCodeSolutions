// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int findBadVersion(unsigned int left, unsigned int right) {
        unsigned int average = (left + right) / 2;
        if (isBadVersion(average)) return average;
        return findBadVersion(average + 1, right);
    }
public:
    int firstBadVersion(int n) {
        int previousBadVersion = 0;
        int currentBadVersion = findBadVersion(1, n);
        while (previousBadVersion != currentBadVersion) {
            previousBadVersion = currentBadVersion;
            currentBadVersion = findBadVersion(1, previousBadVersion);
        }
        return currentBadVersion;
    }  
};

