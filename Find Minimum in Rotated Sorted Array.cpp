class Solution {
public:
    int findMin(vector<int>& nums) {
        int len =  nums.size();
        int left = 0, right = len - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= nums[len - 1]) {
                if (mid > 0 && nums[mid - 1] > nums[mid]) {
                    return nums[mid];
                } else {
                    right = mid - 1;
                }
            } else {
                if (mid < len - 1 && nums[mid + 1] < nums[mid]) {
                    return nums[mid + 1];
                } else {
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};