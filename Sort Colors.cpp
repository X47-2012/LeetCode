class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return;
        }
        int low = 0, mid = 0, high = len - 1;
        while (mid <= high) {
            if (nums[mid] != 0 && nums[mid] != 2) {
                mid++;
            } else if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            } else {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};