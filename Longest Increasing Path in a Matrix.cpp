class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& weight, int i, int j, int len) {
        weight[i][j] = len;
        if (i > 0 && matrix[i - 1][j] > matrix[i][j] && len + 1 > weight[i - 1][j]) {
            dfs(matrix, weight, i - 1, j, len + 1);
        }
        if (i < matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j] && len + 1 > weight[i + 1][j]) {
            dfs(matrix, weight, i + 1, j, len + 1);
        }
        
        if (j > 0 && matrix[i][j - 1] > matrix[i][j] && len + 1 > weight[i][j - 1]) {
            dfs(matrix, weight, i, j - 1, len + 1);
        }
        if (j < matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j] && len + 1 > weight[i][j + 1]) {
            dfs(matrix, weight, i, j + 1, len + 1);
        }
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> weight(m, vector<int>(n, 1));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (weight[i][j] <= 1) {
                    dfs(matrix, weight, i, j, 1);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (weight[i][j] > ans) {
                    ans = weight[i][j];
                }
            }
        }
        
        return ans;
    }
};