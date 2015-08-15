#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int abs(int x) {
    return x >= 0 ? x : -x;
}

bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
    int n = nums.size();

    vector<vector<int> > dp(n, vector<int>(n, -1));

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                if (dp[i - j][i] != -1) {
                    if (dp[i - j][i] <= t)
                        return true;
                } else {
                    int x = abs(nums[i] - nums[i - j]);
                    if (x <= t)
                        return true;
                    dp[i - j][i] = x;
                    dp[i][i - j] = x;
                }
            }

            if (i + j < n) {
                if (dp[i + j][i] != -1) {
                    if (dp[i + j][i] <= t)
                        return true;
                } else {
                    int x = abs(nums[i] - nums[i + j]);
                    if (x <= t)
                        return true;
                    dp[i + j][i] = x;
                    dp[i][i + j] = x;
                }
            }
        }
    }
    return false;
}

bool containsNearbyAlmostDuplicate2(vector<int>& nums, int k, int t) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = 1; (j <= k) && (i - j >= 0) ; j++) {
            if (abs(nums[i] - nums[i - j]) <= t)
                return true;
        }
    }
    return false;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    set<int> record;

    for (int i = 0; i < n; i++) {
        if (i > k) {
            record.erase(nums[i - k - 1]);
        }

        set<int>::iterator lowerBound = record.lower_bound(nums[i] - t);

        record.insert(nums[i]);
    }

    return false;
}

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(4);
    containsNearbyAlmostDuplicate(nums, 2, 1);
}
