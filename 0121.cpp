class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int low = 0, high = 0;
        int maximum = 0;
        for (int yesterday = 0, today = 1; today < prices.size(); yesterday++, today++) {
            if (prices[today] > prices[yesterday]) {
                high = today;
            } else if (prices[today] < prices[low]) {
                low = today;
                high = today;
            }
            maximum = max(maximum, prices[high] - prices[low]);
        }
        return maximum;
    }
};
