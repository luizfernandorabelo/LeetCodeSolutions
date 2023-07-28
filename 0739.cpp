class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> answer(temperatures.size(), 0);
        vector<pair<int,int>> stack;
        stack.push_back({0, temperatures[0]});
        for (int i = 1; i < temperatures.size(); i++) {
            int topIndex = stack.size() - 1;
            while (stack.size() && temperatures[i] > stack[topIndex].second) {
                answer[stack[topIndex].first] = i - stack[topIndex].first;
                topIndex--;
                stack.pop_back();
            }
            stack.push_back({i, temperatures[i]});
        }
        return answer;
    }
};
