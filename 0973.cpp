typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> MinHeap;

class Solution {
private:
    int evaluateDistanceToOrigin(vector<int> const &point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    MinHeap buildMinHeap(vector<vector<int>> const &points) {
        MinHeap h;
        for (int i = 0; i < points.size(); i++) {
            int distance = evaluateDistanceToOrigin(points[i]);
            h.push({distance, i});
        }
        return h;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        MinHeap h = buildMinHeap(points);
        vector<vector<int>> answer(k);
        for (int i = 0; i < k; i++) {
            answer[i] = points[h.top().second];
            h.pop();
        }
        return answer;
    }
};
