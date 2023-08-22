class Solution {
private:
    bool isSpeedViable(vector<int> const &piles, int speed, int h) {
        unsigned int spentTime = 0;
        for (int pile : piles) {
            spentTime += pile / speed;
            if (pile % speed)
                spentTime++;
        }
        return spentTime <= h;
    }
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        unsigned int minK = 1, maxK = *max_element(piles.begin(), piles.end()), avgK;
        unsigned int optimalSpeed = 1000000001;
        while (minK <= maxK) {
            avgK = (minK + maxK) / 2;
            if (isSpeedViable(piles, avgK, h)) {
                optimalSpeed = min(optimalSpeed, avgK);
                maxK = avgK - 1;
            } else {
                minK = avgK + 1;
            }
        }
        return optimalSpeed;
    }
};
