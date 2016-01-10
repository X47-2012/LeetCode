int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int max_sum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        int sum = max(dp[i - 1], nums[i]);
        for (int j = i - 2; j >= 0; j--) {
            if (nums[i] + dp[j] > sum) {
                sum = nums[i] + dp[j];
            }
        }
        dp[i] = sum;
        if (sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}