class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        int water = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                water += max(maxLeft - height[left], 0);
                maxLeft = max(maxLeft, height[left]);
                left++;
            } else {
                water += max(maxRight - height[right], 0);
                maxRight = max(maxRight, height[right]);
                right--;
            }
        }
        return water;
    }
};
