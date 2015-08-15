#include <vector>
#include <math.h>
using namespace std;

int maximalSquare(vector<vector<char> >& matrix) {
    int m = matrix.size();
    if (m == 0)
        return 0;

    int n = matrix[0].size();

    vector<vector<int> > dp(m, vector<int>(n));
    int max_ans = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[0][i] == '1') {
            dp[0][i] = 1;
            max_ans = 1;
        }
        else
            dp[0][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == '1') {
            dp[i][0] = 1;
            max_ans = 1;
        }
        else
            dp[i][0] = 0;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                int ans;
                if (dp[i - 1][j - 1] == 0) {
                    ans = 1;
                } else {
                    int range = sqrt(dp[i - 1][j - 1]);
                    int k;
                    for (k = 1; k <= range; k++) {
                        if (matrix[i - k][j] == '0' || matrix[i][j - k] == '0') {
                            break;
                        }
                    }
                    ans = k * k;
                }
                if (ans > max_ans)
                    max_ans = ans;
                dp[i][j] = ans;
            }
        }
    }
    return max_ans;
}

int main() {

}
