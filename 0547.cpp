class Solution {
private:
    void connectProvince(vector<vector<int>> const &isConnected, vector<bool> &marks, int city) {
        marks[city] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[city][neighbor] && !marks[neighbor])
                connectProvince(isConnected, marks, neighbor);
        }
    }
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<bool> marks(n, false);
        int circleCount = 0;
        for (int city = 0; city < n; city++) {
            if (!marks[city]) {
                connectProvince(isConnected, marks, city);
                circleCount++;
            }
        }
        return circleCount;
    }
};
