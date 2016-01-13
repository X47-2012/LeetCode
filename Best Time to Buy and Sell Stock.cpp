int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int n = prices.size();
    vector<int> dp(n, 0);
    
    int minPrice = prices[0];
    for (int i = 0; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }
        dp[i] = prices[i] - minPrice;
    }
    
    int ans = 0;
    int maxPrice = prices[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        if (prices[i] > maxPrice) {
            maxPrice = prices[i];
        }
        dp[i] += (maxPrice - prices[i]);
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }
    
    return ans;
}