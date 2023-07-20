class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        vector<pair<int,int>> s;  // index, height
        s.push_back({0, heights[0]});
        int maxArea = 0;
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] >= s.back().second) {
                s.push_back({i, heights[i]});
            } else {
                int startIndex = i;
                while (s.size() && heights[i] < s.back().second) {
                    int width = i - s.back().first, height = s.back().second;
                    maxArea = max(maxArea, width * height);
                    startIndex = s.back().first;
                    s.pop_back();
                }
                s.push_back({startIndex, heights[i]});
            }
        }
        while (s.size()) {
            int width = heights.size() - s.back().first, height = s.back().second;
            maxArea = max(maxArea, height * width);
            s.pop_back();
        }
        return maxArea;
    }
};
