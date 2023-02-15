class Solution {
private:
    void makeItRain(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int minRow = 0, minCol = 0;
        int maxRow = image.size() - 1, maxCol = image[0].size() - 1; 
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        if (sr-1 >= minRow && image[sr-1][sc] == oldColor)
            makeItRain(image, sr-1, sc, newColor);
        if (sc+1 <= maxCol && image[sr][sc+1] == oldColor)
            makeItRain(image, sr, sc+1, newColor);
        if (sr+1 <= maxRow && image[sr+1][sc] == oldColor)
            makeItRain(image, sr+1, sc, newColor);
        if (sc-1 >= minCol && image[sr][sc-1] == oldColor)
            makeItRain(image, sr, sc-1, newColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        vector<vector<int>> newImage = image;
        if (image[sr][sc] != color)
            makeItRain(newImage, sr, sc, color);
        return newImage;
    }
};
