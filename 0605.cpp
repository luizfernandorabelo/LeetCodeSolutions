class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int size = flowerbed.size();
        int placedCount = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i <= size; i++) {
            if (!flowerbed[i-1] && !flowerbed[i] && !flowerbed[i+1]) {
                flowerbed[i] = 1;
                placedCount++;
            } 
            if (placedCount >= n) return true;
        }
        return false;
    }
};
