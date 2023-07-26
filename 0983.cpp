#define UNKNOWN -1

class Solution {
private:
    int getNextDayIndex(vector<int> const &days, int currentIndex, int daysCount) {
        int nextIndex = currentIndex;
        while (nextIndex < days.size() && days[nextIndex] < days[currentIndex] + daysCount)
            nextIndex++;
        return nextIndex;
    }

    int evaluateMinCost(vector<int> const &days, vector<int> const &costs, vector<int> &cache, int currentIndex) {
        if (currentIndex == days.size()) return 0;
        if (cache[currentIndex] == UNKNOWN) {
            int c1 = evaluateMinCost(days, costs, cache, getNextDayIndex(days, currentIndex, 1)) + costs[0];
            int c7 = evaluateMinCost(days, costs, cache, getNextDayIndex(days, currentIndex, 7)) + costs[1];
            int c30 = evaluateMinCost(days, costs, cache, getNextDayIndex(days, currentIndex, 30)) + costs[2];
            cache[currentIndex] = min(c1, min(c7, c30));
        }
        return cache[currentIndex];
    }
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int n = days.size();
        vector<int> cache(n, UNKNOWN);
        return evaluateMinCost(days, costs, cache, 0);
    }
};
