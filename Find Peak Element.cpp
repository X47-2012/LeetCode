class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == len - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (mid != 0 && nums[mid] < nums[mid - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};