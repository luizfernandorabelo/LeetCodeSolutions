class Solution {
private:
    map<int,int> buildCountMap(vector<int> const &nums) {
        map<int,int> m;
        for (int num : nums)
            m[num]++;
        return m;
    }

    void pushPermutations(vector<vector<int>> &permutations, int size, map<int,int> &m, vector<int> currentPermutation) {
        if (currentPermutation.size() == size) {
            permutations.push_back(currentPermutation);
            return;
        }
        for (auto p : m) {
            if (p.second) {
                m[p.first]--;
                currentPermutation.push_back(p.first);
                pushPermutations(permutations, size, m, currentPermutation);
                currentPermutation.pop_back();
                m[p.first]++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        map<int,int> m = buildCountMap(nums);
        vector<vector<int>> permutations;
        pushPermutations(permutations, nums.size(), m, {});
        return permutations;
    }
};

