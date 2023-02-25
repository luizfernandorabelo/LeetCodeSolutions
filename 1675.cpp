typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> MinHeap;

class Solution {
private:
    MinHeap createMinHeap(vector<int> const &nums, int &maxElement) {
        MinHeap mh;
        for (int num : nums) {
            int lowerBound, upperBound;
            if (num % 2 == 0) {
                lowerBound = num;
                while (lowerBound % 2 == 0)
                    lowerBound /= 2;
                upperBound = num;
            } else {
                lowerBound = num;
                upperBound = num * 2;
            }
            mh.push({lowerBound, upperBound});
            maxElement = max(maxElement, lowerBound);
        }
        return mh;
    }
public:
    int minimumDeviation(vector<int> &nums) {
        int maxElement = -1, minDeviation = INT_MAX;
        MinHeap mh = createMinHeap(nums, maxElement);
        while (mh.size() == nums.size()) {
            pair<int,int> top = mh.top(); mh.pop();
            minDeviation = min(minDeviation, maxElement - top.first);
            if (top.first < top.second) {
                mh.push({top.first * 2, top.second});
                maxElement = max(maxElement, top.first * 2);
            }
        }
        return minDeviation;
    }
};
