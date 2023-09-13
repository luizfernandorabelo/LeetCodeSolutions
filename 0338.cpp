class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts;
        for (int i = 0; i <= n; i++) {
            int current = i, count = 0;
            for (int j = 0; j < 32; j++) {
                count += (current & 1) % 2;
                current = current >> 1;
            }
            counts.push_back(count);
        }
        return counts; 
    }
};
