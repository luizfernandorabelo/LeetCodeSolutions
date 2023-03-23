class Solution {
private:
    bool binarySearch(vector<vector<int>> const &matrix, int target, int start, int end) {
        if (start > end) return false;
        int center = (start + end) / 2;
        int row = center / matrix[0].size(), col = center % matrix[0].size();
        if (target < matrix[row][col])
            return binarySearch(matrix, target, start, center - 1);
        if (target > matrix[row][col])
            return binarySearch(matrix, target, center + 1, end);
        return true;
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        return binarySearch(matrix, target, 0, matrix.size() * matrix[0].size() - 1);
    }
};
