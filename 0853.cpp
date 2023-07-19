class Solution {
private:
    vector<pair<int,int>> joinPositionAndSpeed(vector<int> &position, vector<int> &speed) {
        vector<pair<int,int>> v;
        for (int i = 0; i < position.size(); i++) {
            v.push_back({position[i], speed[i]});
        }
        return v;
    }
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        vector<pair<int,int>> v = joinPositionAndSpeed(position, speed);
        sort(v.begin(), v.end());
        vector<pair<int,int>> s;
        s.push_back(v[v.size() - 1]);
        for (int i = v.size() - 2; i >= 0; i--) {
            pair<int,int> back = s.back();
            pair<int,int> current = v[i];
            float arrivalTimeBack = (float) (target - back.first) / back.second;
            float arrivalTimeCurrent = (float) (target - current.first) / current.second;
            if (arrivalTimeCurrent > arrivalTimeBack) {
                s.push_back(current);
            }
        }
        return s.size();
    }
};
