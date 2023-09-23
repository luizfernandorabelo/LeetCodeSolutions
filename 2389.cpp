class Solution {
private:
    vector<int> buildPrefixSumArray(vector<int> const &nums) {
        vector<int> ps;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ps.push_back(sum);
        }
        return ps;
    }
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        vector<int> answers;
        sort(nums.begin(), nums.end());
        vector<int> ps = buildPrefixSumArray(nums);
        for (int query : queries) {
            int start = 0, end = nums.size() - 1, center;
            while (start <= end) {
                center = (start + end) / 2;
                if (ps[center] > query) {
                    end = center - 1;
                } else if (ps[center] < query) {
                    start = center + 1;
                } else {
                    break;
                }
            }
            int length = ps[center] <= query ? center + 1 : center >= 1 && ps[center-1] <= query ? center : 0;
            answers.push_back(length);
        }
        return answers;
    }
};
