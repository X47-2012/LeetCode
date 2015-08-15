#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    if (grid.size() <= 0) return 0;
    int row_num = grid.size();
    if (grid[0].size() <= 0) return 0;
    int col_num = grid[0].size();

    int **dp = new int *[row_num];
    for (int i = 0; i < row_num; i++)
        dp[i] = new int[col_num];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < col_num; i++)
        dp[0][i] = grid[0][i] + dp[0][i - 1];

    for (int i = 1; i < row_num; i++)
        dp[i][0] = grid[i][0] + dp[i - 1][0];

    for (int i = 1; i < row_num; i++)
        for (int j = 1; j < col_num; j++) {
            int min_val = min(dp[i][j - 1], dp[i - 1][j]);
            dp[i][j] = min_val + grid[i][j];
    }

    int ans = dp[row_num - 1][col_num - 1];

    for (int i = 0; i < row_num; i++) {
        delete[] dp[i];
        dp[i] = NULL;
    }

    delete[] dp;
    dp = NULL;

    return ans;
}

int main() {
    vector<vector<int> > grid;
    for (int i = 0; i < 2; i++) {
        vector<int> tmp;
        tmp.push_back(0);
        tmp.push_back(1);
        grid.push_back(tmp);
    }

    cout << minPathSum(grid);
}
