class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> d;
        vector<int> maxWindow;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            while (!d.empty() && nums[right] > nums[d.back()]) {
                d.pop_back();
            }
            d.push_back(right);
            if (left > d.front()) {
                d.pop_front();
            }
            if (right >= k - 1) {
                maxWindow.push_back(nums[d.front()]);
                left++;
            }
        }
        return maxWindow;
    }
};
