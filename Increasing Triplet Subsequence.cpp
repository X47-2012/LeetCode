class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        int first = 0, second = -1;
        for (int i = 0; i < len; i++) {
            if (nums[i] < nums[first]) {
                first = i;
            } else if ((second == -1 && nums[i] > nums[first]) || (nums[i] < nums[second] && nums[i] > nums[first])) {
                second = i;
            } else if (second != -1 && nums[i] > nums[second]) {
                return true;
            }
        }
        return false;
    }
};