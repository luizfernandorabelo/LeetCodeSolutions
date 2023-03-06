class Solution {
private:
    bool isSorted(vector<int> &nums) {
        int previous = nums[0];
        for (int num : nums) {
            if (num < previous) return false;
            previous = num;
        }
        return true;
    }
    
    void swap(vector<int> &nums, int i, int j) {
        int value = nums[i];
        nums[i] = nums[j];
        nums[j] = value;
    }

    void shuffleArray(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            swap(nums, i, rand() % nums.size());
    }

    int partition(vector<int> &nums, int start, int end) {
        int pivot = end;
        int left = start - 1, right = start;
        while (right <= end) {
            if (nums[right] <= nums[pivot]) {
                swap(nums, right, left+1);
                left++;
            }
            right++;
        }
        return left;
    }

    void quickSort(vector<int> &nums, int start, int end) {
        if (start >= end) return;
        int sortedIndex = partition(nums, start, end);
        quickSort(nums, start, sortedIndex - 1);
        quickSort(nums, sortedIndex + 1, end);
    }
public:
    vector<int> sortArray(vector<int> &nums) {
        vector<int> sorted = nums; 
        if (!isSorted(nums)) {
            shuffleArray(sorted);
            quickSort(sorted, 0, nums.size() - 1);
        }
        return sorted;
    }
};
