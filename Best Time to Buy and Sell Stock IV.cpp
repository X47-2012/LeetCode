class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        
        if (k >= n / 2) {
            int sum = 0;
            for (int i = 1; i < n; i++){
                if (prices[i] > prices[i-1]) {
                    sum += prices[i] - prices[i-1];
                }
            }
            return sum;
        }
        
        vector<vector<int>> record(k + 1, vector<int>(n, 0));
        int max_prof = 0;
        for (int i = 1; i <= k; i++) {
            int max_tmp = record[i - 1][0] - prices[0];
            for (int j = 1; j < n; j++) {
                record[i][j] = max(record[i][j - 1], prices[j] + max_tmp);
                max_tmp = max(max_tmp, record[i - 1][j] - prices[j]);
                max_prof = max(max_prof, record[i][j]);
            }
        }
        return max_prof;
    }
};