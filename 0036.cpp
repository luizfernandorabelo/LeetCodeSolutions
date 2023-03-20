#define EMPTY '.'

class Solution {
private:
    bool isValidRow(vector<vector<char>> const &board, int row) {
        map<char,int> m;
        for (int j = 0; j < 9; j++) {
            char c = board[row][j];
            if (c == EMPTY) continue;
            m[c]++;
            if (m[c] > 1) return false;
        }
        return true;
    }

    bool isValidColumn(vector<vector<char>> const &board, int col) {
        map<char,int> m;
        for (int i = 0; i < 9; i++) {
            char c = board[i][col];
            if (c == EMPTY) continue;
            m[c]++;
            if (m[c] > 1) return false;
        }
        return true;
    }
    
    bool isValidSquare(vector<vector<char>> const &board, int square) {
        int startRow = (square / 3) * 3, startCol = (square % 3) * 3;
        map<char,int> m;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c = board[startRow+i][startCol+j];
                if (c == EMPTY) continue;
                m[c]++;
                if (m[c] > 1) return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            if (!isValidRow(board, i)) return false;
            if (!isValidColumn(board, i)) return false;
            if (!isValidSquare(board, i)) return false;
        }
        return true;
    }
};
