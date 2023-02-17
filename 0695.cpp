class Solution {
private:
    int evaluateIslandArea(vector<vector<int>> const &grid, vector<vector<bool>> &marks, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0 || marks[i][j]) return 0;
        
        marks[i][j] = true;
        
        int area = 0;
        vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        for (auto d : directions)
            area += evaluateIslandArea(grid, marks, i + d.first, j + d.second);
            
        return area + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        vector<vector<bool>> marks(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!marks[i][j] && grid[i][j]) {
                    int currentArea = evaluateIslandArea(grid, marks, i, j);
                    maxArea = max(currentArea, maxArea);
                }
            }
        }
        return maxArea; 
    }
