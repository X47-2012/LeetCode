#include <iostream>
#include <vector>
using namespace std;

// O(n2)
int maxSubArray1(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return 0;

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j)
                dp[i][j] = nums[i];
            else {
                dp[i][j] = dp[i][j - 1] + nums[j];
            }
        }
    }

    int max_val = dp[0][0];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (dp[i][j] > max_val)
                max_val = dp[i][j];

    for (int i = 0; i < n; i++) {
        delete[] dp[i];
        dp[i] = NULL;
    }

    delete[] dp;
    dp = NULL;

    return max_val;
}

// dp O(n)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return 0;

    vector<int> dp(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);

    int ans = dp[0];
    for (int i = 1; i < n; i++)
        if (dp[i] > ans)
            ans = dp[i];

    return ans;
}

int main() {

}
