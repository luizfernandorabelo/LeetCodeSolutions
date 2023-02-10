class Solution {
private:
    void swapElements(vector<int> &nums, int i, int j) {
        int swapped = nums[i];
        nums[i] = nums[j];
        nums[j] = swapped;
    }
    
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int i = start - 1;
        for (int j = start; j < end; j++) {
            if (nums[j] <= pivot) {
                swapElements(nums, ++i, j);
            }
        }
        swapElements(nums, ++i, end);
        return i;
    }
    
    int findKthLargestRec(vector<int> &nums, int k, int start, int end) {
        if (start == end)
            return nums[start];
        int pivotIdx = partition(nums, start, end);
        if (nums.size() - k > pivotIdx)
            return findKthLargestRec(nums, k, pivotIdx + 1, end);
        if (nums.size() - k < pivotIdx)
            return findKthLargestRec(nums, k, start, pivotIdx - 1);
        return nums[pivotIdx];   
    }
public:
    int findKthLargest(vector<int> &nums, int k) {
        return findKthLargestRec(nums, k, 0, nums.size() - 1);
    }
};

