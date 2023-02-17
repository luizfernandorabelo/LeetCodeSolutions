class Solution {
private:
    vector<int> generatePerfectSquares(int n) {
        int upperBound = (int) sqrt(n) + 1;
        vector<int> perfectSquares;
        for (int i = 1; i <= upperBound; i++)
            perfectSquares.push_back(i * i);
        return perfectSquares;
    }
public:
    int numSquares(int n) {
        vector<int> perfectSquares = generatePerfectSquares(n);
        queue<pair<int,int>> q;
        q.push({n, 0});
        while (!q.empty()) {
            pair<int,int> front = q.front(); q.pop();
            for (int pSquare : perfectSquares) {
                if (pSquare > front.first) break;
                if (front.first - pSquare == 0) return front.second + 1;
                q.push({front.first - pSquare, front.second + 1});
            }
        }
        return -1;
    }
};
