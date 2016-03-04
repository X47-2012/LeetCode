class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size() + 1, 0); // 前i个房子能得到的最大值
        dp[0] = 0;
        dp[1] = nums[0];
        int max_sum = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            int sum = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
            dp[i] = sum;
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
        return max_sum;
    }
};