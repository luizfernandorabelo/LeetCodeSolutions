// 1920. Build Array from Permutation

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

