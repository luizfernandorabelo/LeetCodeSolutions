/*
    -> 1929. Concatenation of Array
    - Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
    - Specifically, ans is the concatenation of two nums arrays.
*/

#include <vector>

class Solution {

public:

    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        return ans;
    }

};