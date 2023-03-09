class Solution {
private:
    vector<pair<int,int>> sortProjectsByCapital(vector<int> const &profits, vector<int> const &capital) {
        vector<pair<int,int>> projects;
        for (int i = 0; i < profits.size(); i++)
            projects.push_back({capital[i], profits[i]});
        sort(projects.begin(), projects.end());
        return projects;
    }

    int findFirstUnavailableIndex(vector<pair<int,int>> const &projects, int previousIndex, int w) {
        int unavailable = previousIndex;
        while (unavailable < projects.size() && projects[unavailable].first <= w)
            unavailable++;
        return unavailable;
    }

    void insertProfitsToQueue(vector<pair<int,int>> const &projects, int startIndex, int endIndex, priority_queue<int> &pq) {
        for (int i = startIndex; i <= endIndex; i++)
            pq.push(projects[i].second);
    }
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        vector<pair<int,int>> projects = sortProjectsByCapital(profits, capital);
        int firstUnavailableIndex, previousUnavailableIndex = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            firstUnavailableIndex = findFirstUnavailableIndex(projects, previousUnavailableIndex, w);
            insertProfitsToQueue(projects, previousUnavailableIndex, firstUnavailableIndex - 1, pq);
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            previousUnavailableIndex = firstUnavailableIndex;
        }
        return w;
    }
};
