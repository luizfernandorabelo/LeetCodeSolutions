#define UNCAPTURED 'C'

class Solution {
private:
    void visitUncapturedRegion(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j) {
        visited[i][j] = true;
        board[i][j] = UNCAPTURED;
        vector<pair<int,int>> offsets = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for (auto offset : offsets) {
            int ni = i + offset.first, nj = j + offset.second;
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[i].size() && board[ni][nj] == 'O' && !visited[ni][nj])
                visitUncapturedRegion(board, visited, ni, nj);
        }
    }

    void visitBorders(vector<vector<char>> &board, vector<vector<bool>> &visited) {
        int topRow = 0, bottomRow = board.size() - 1;
        for (int col = 0; col < board[0].size(); col++) {
            if (!visited[topRow][col] && board[topRow][col] == 'O')
                visitUncapturedRegion(board, visited, topRow, col);
            if (!visited[bottomRow][col] && board[bottomRow][col] == 'O')
                visitUncapturedRegion(board, visited, bottomRow, col);
        }
        int leftCol = 0, rightCol = board[0].size() - 1;
        for (int row = 0; row < board.size(); row++) {
            if (!visited[row][leftCol] && board[row][leftCol] == 'O')
                visitUncapturedRegion(board, visited, row, leftCol);
            if (!visited[row][rightCol] && board[row][rightCol] == 'O')
                visitUncapturedRegion(board, visited, row, rightCol);
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        visitBorders(board, visited);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                board[i][j] = board[i][j] == UNCAPTURED ? 'O' : 'X';
    }
};
