#include <iostream>
#include <vector>
using namespace std;

int numTreesHelper(int start, int end, vector<vector<int> > &dp) {
    if (start > end) {
        return 0;
    } else if (dp[start][end] != -1) {
        return dp[start][end];
    } else {
        int sum = numTreesHelper(start + 1, end, dp) + numTreesHelper(start, end - 1, dp);
        for (int i = start + 1; i <= end - 1; i++) {
            sum += (numTreesHelper(start, i - 1, dp) * numTreesHelper(i + 1, end, dp));
        }
        dp[start][end] = sum;
        return sum;
    }
}

int numTrees(int n) {
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    return numTreesHelper(1, n, dp);
}

int main() {
    cout << numTrees(3) << endl;
}
