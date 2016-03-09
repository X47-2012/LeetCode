class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) {
            return len;
        }
        int i = 0, j = 0;
        while (j < len) {
            if (j <= 1 || nums[i - 2] != nums[j]) {
                swap(nums[i++], nums[j++]);
            } else {
                j++;
            }
        }
        return i;
    }
};