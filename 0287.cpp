class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        int duplicated = 0;
        while (duplicated != slow) {
            duplicated = nums[duplicated];
            slow = nums[slow];
        }
        return duplicated;
    }
};
