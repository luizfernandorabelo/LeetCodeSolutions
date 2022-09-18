class Solution {
public:
    map<int,int> mapOccurrences(const vector<int> &nums) {
        map<int,int> occurrences;
        for (int num : nums) {
            if (occurrences.find(num) == occurrences.end())
                occurrences[num] = 1;
            else
                occurrences[num] += 1;
        }
        return occurrences;
    }
    
    vector<vector<int>> buildFrequencies(const map<int,int> &occurrences, int n) {
        vector<vector<int>> frequencies(n + 1, vector<int>());
        for (auto p : occurrences)
            frequencies[p.second].push_back(p.first);
        return frequencies;
    }
    
    void pushTopKFrequent(vector<int> &topK, int k, vector<vector<int>> &frequencies) {
        for (int i = frequencies.size() - 1; i >= 0; i--) {
            for (int val : frequencies[i]) {
                topK.push_back(val);
                if (topK.size() == k)
                    return;
            }
        }
    }
    
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int,int> occurrences = mapOccurrences(nums);
        vector<vector<int>> frequencies = buildFrequencies(occurrences, nums.size()); 
        vector<int> topK;
        pushTopKFrequent(topK, k, frequencies);
        return topK;
    }
};