#define EMPTY 0
#define FRESH 1
#define ROTTEN 2

class Solution {
private:
    void pushRottenOranges(queue<pair<pair<int,int>,int>> &q, vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == ROTTEN) q.push({{i,j}, 0});
    }

    bool isThereFreshOrange(vector<vector<int>> const &grid) {
        for (auto v : grid)
            for (auto fruit : v)
                if (fruit == FRESH) return true;
        return false;
    }
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int elapsedTime = 0;                
        vector<vector<bool>> marks(grid.size(), vector<bool>(grid[0].size(), false));
        vector<pair<int,int>> offsets = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        queue<pair<pair<int,int>,int>> q;
        pushRottenOranges(q, grid);
        while (!q.empty()) {
            pair<pair<int,int>,int> front = q.front(); q.pop();
            int row = front.first.first;
            int col = front.first.second;
            if (!marks[row][col]) {
                marks[row][col] = true;
                grid[row][col] = ROTTEN;
                elapsedTime = front.second;
                for (auto offset : offsets) {
                    int i = row + offset.first, j = col + offset.second;
                    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size()) {
                        if (grid[i][j] == EMPTY)
                            marks[i][j] = true;
                        else if (grid[i][j] == FRESH)
                            q.push({{i,j}, elapsedTime + 1});
                    }
                }
            }
        }
        return isThereFreshOrange(grid) ? -1 : elapsedTime;
    }
};
