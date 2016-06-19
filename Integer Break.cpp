class Solution {
public:
    int integerBreak(int n) {
        vector<int> record(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                record[i] = max(record[i], max(j, record[j]) * max(i - j, record[i - j]));
            }
        }
        return record[n];
    }
};