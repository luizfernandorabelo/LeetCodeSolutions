#define INF 1000000000

class Solution {
private:
    vector<pair<int,int>> findAllZeroPositions(vector<vector<int>> const &mat) {
        vector<pair<int,int>> zeroPositions;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0)
                    zeroPositions.push_back({i, j});
            }
        }
        return zeroPositions;
    }

    bool isValidPosition(int i, int j, vector<vector<bool>> const &marks) {
        return i >= 0 && i < marks.size() && j >= 0 && j < marks[0].size();
    }

    void fillDistances(vector<vector<int>> &dists,  vector<vector<int>> const &mat) {
        vector<vector<bool>> marks(mat.size(), vector<bool>(mat[0].size(), false));
        vector<pair<int,int>> offsets = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        vector<pair<int,int>> zeroPositions = findAllZeroPositions(mat);
        queue<pair<int,int>> q;
        for (auto zeroPos : zeroPositions) {
            dists[zeroPos.first][zeroPos.second] = 0;
            q.push(zeroPos);
        }
        while (!q.empty()) {
            pair<int,int> front = q.front(); q.pop();
            marks[front.first][front.second] = true;
            for (auto offset : offsets) {
                int i = front.first + offset.first;
                int j = front.second + offset.second;
                if (isValidPosition(i, j, marks)) {
                    dists[front.first][front.second] = min(dists[front.first][front.second], dists[i][j] + 1);
                    if (!marks[i][j]) q.push({i, j});
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        vector<vector<int>> distances(mat.size(), vector<int>(mat[0].size(), INF));
        fillDistances(distances, mat);
        return distances;
    }
};

