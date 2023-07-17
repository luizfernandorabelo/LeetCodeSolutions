#define INFINITY 1000000

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> costs(n, vector<int>(m, INFINITY));       
        costs[0][0] = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) continue;
                int c1 = i > 0 ? costs[i-1][j] : INFINITY;
                int c2 = j > 0 ? costs[i][j-1] : INFINITY;
                costs[i][j] = grid[i][j] + min(c1, c2);
            }
        }
        return costs[n-1][m-1];
    }
};
