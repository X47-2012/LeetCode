int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    
    vector<int> dp(n, 1);
    int ans = dp[0];
    
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] < nums[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    return ans;
}