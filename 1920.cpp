/*
    -> 1920. Build Array from Permutation
    - Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
    - A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
*/

#include <vector>

class Solution {

public:

    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> array;
        for (auto i = 0; i < nums.size(); i++) {
            array.push_back(nums[nums[i]]);
        }
        return array;
    }

};

