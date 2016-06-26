class Solution {
public:
    // time out
    bool canJump(vector<int>& nums) {
        int maxEnd = 0;
        for(int i = 0; i < nums.size() && i <= maxEnd; ++i) {
            maxEnd = max(maxEnd, i + nums[i]);
        }
        return maxEnd >= nums.size()-1;
    }
};