int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    if (n == 0 && amount != 0) {
        return -1;
    }
    
    vector<int> dp(amount + 1, amount + 5);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }
    if (dp[amount] == amount + 5) {
        return -1;
    } else {
        return dp[amount];
    }
}