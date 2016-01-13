int minCut(string s) {
    if (s.size() <= 1) {
        return 0;
    }
    
    vector<vector<bool> > record(s.size(), vector<bool>(s.size(), false));
    vector<int> dp(s.size() + 1, s.size() + 5);
    dp[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (s[i - 1] == s[j] && (i - j < 3 || record[j + 1][i - 2])) {
                record[j][i - 1] = true;
                if (j == 0) {
                    dp[i] = 0;
                } else {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
    }
    return dp[s.size()];
}