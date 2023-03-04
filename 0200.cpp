#define WATER '0'
#define LAND '1'

class Solution {
private:
    void visitIsland(vector<vector<char>> const &grid, vector<vector<bool>> &marks, int i, int j) {
        marks[i][j] = true;
        vector<pair<int,int>> offsets = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for (auto offset : offsets) {
            int nI = i + offset.first, nJ = j + offset.second;
            if (nI >= 0 && nI < grid.size() && nJ >= 0 && nJ < grid[0].size() && grid[nI][nJ] == LAND && !marks[nI][nJ])
                visitIsland(grid, marks, nI, nJ);
        }
    }
public:
    int numIslands(vector<vector<char>> &grid) {
        vector<vector<bool>> marks(grid.size(), vector<bool>(grid[0].size(), false));
        int islandsCount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == LAND && !marks[i][j]) {
                    visitIsland(grid, marks, i, j);
                    islandsCount++;
                }
            }
        }
        return islandsCount;
    }
};
