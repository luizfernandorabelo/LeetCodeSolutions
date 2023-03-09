class Solution {
private:
    bool verifyExistence(vector<vector<char>> const &board, vector<vector<bool>> &visited, string &current, string const &target, int i, int j) {
        if (current.length() == target.length()) return true;
        if (board[i][j] == target[current.length()]) {
            current.push_back(board[i][j]);
            visited[i][j] = true;
            if (current == target) return true;
            vector<pair<int,int>> offsets = {{-1,0}, {0,1}, {1,0}, {0,-1}};
            for (auto offset : offsets) {
                int ni = i + offset.first, nj = j + offset.second;
                if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[i].size() && !visited[ni][nj]) {
                    if (verifyExistence(board, visited, current, target, ni, nj))
                        return true;
                }
            }
            current.pop_back();
            visited[i][j] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                string current = "";
                if (verifyExistence(board, visited, current, word, i, j))
                    return true;
            }
        }
        return false;
    }
};
