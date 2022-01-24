/*
    -> 1480. Running Sum of 1d Array
    - Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
    - Return the running sum of nums.
*/

#include <vector>

class Solution {

public:

    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> ans;
        int currSum = 0;
        for (int num : nums) {
            currSum += num;
            ans.push_back(currSum);
        }
        return ans;
    }

};