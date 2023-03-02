#define START 0
#define END 1

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> intersection;
        if (firstList.size() != 0 && secondList.size() != 0) {
            int i = 0, j = 0;
            while (i < firstList.size() && j < secondList.size()) {
                int firstStart = firstList[i][START], firstEnd = firstList[i][END];
                int secondStart = secondList[j][START], secondEnd = secondList[j][END];
                if (firstEnd < secondStart) {
                    i++;
                } else if (secondEnd < firstStart) {
                    j++;
                } else {
                    intersection.push_back({max(firstStart, secondStart), min(firstEnd, secondEnd)});
                    if (firstEnd < secondEnd) i++;
                    else j++;
                }
            }
        }
        return intersection;
    }
};
