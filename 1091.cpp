typedef pair<int,int> Coord;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        if (grid[0][0] == 0 && grid[n-1][n-1] == 0) {
            vector<Coord> offsets = {{0,1},{1,1},{1,0},{1,-1},{-1,0},{-1,1},{0,-1},{-1,-1}};
            vector<vector<bool>> marks(n, vector<bool>(n, false));
            queue<pair<Coord,int>> q;
            pair<Coord,int> current = {{0,0}, 1};
            q.push(current);
            marks[0][0] = true;
            bool pathFound = false;
            while (!q.empty() && !pathFound) {
                current = q.front(); q.pop();
                for (Coord offset : offsets) {
                    int i = current.first.first + offset.first, j = current.first.second + offset.second;
                    if (min(i,j) >= 0 && max(i,j) < n && !marks[i][j] && grid[i][j] == 0) {
                        q.push({{i,j}, current.second + 1});
                        marks[i][j] = true;
                    }
                }
                pathFound = (current.first.first == n-1 && current.first.second == n-1);
            }
            if (pathFound) return current.second;
        }
        return -1;
    }
};
