class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        vector<int> rotated(nums.size(), 0);
        if (k > nums.size())
            k = k % nums.size();
        for (int i = 0; i < k; i++)
            rotated[i] = nums[nums.size() - k + i];
        for (int i = k, j = 0; i < nums.size(); i++, j++)
            rotated[i] = nums[j];
        for (int i = 0; i < nums.size(); i++)
            nums[i] = rotated[i];
    }
};
