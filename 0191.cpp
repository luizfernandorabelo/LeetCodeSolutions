class Solution {
public:
    int hammingWeight(uint32_t n) {
        int onesCount = 0;
        for (int i = 1; i <= 32; i++) {
            onesCount += n & 1;
            n = n >> 1;
        }
        return onesCount; 
    }
};
